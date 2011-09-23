// $Id: dukheputils.py 163843 2011-05-27 18:22:01Z ayana $

// base class definition (Makefile.common must have ../ in include path):
#include "../include/AnalysisCycle.h"

// STL include(s)
#include <algorithm>
#include <iostream>

// This line determines which ExecuteEvent method to use
#define ZGMUMU_TYPE 0 
#define TRUTH_TYPE 1
#define ANALYSIS_TYPE TRUTH_TYPE

using AnalysisUtils::dR;

ClassImp( AnalysisCycle );

// Section: Constructor/Destructor Definitions {{{1

AnalysisCycle::AnalysisCycle()
  : DukHepFilter(),
    // Macro initializing the stl vectors that access the tree
    INIT_NULLS_CTOR,
    m_MuonReader(this, "mu_staco"), 
    m_PhotonReader(this), 
    m_JetReader(this, "jet_AntiKt4TopoEM"), // for some data it is jet_AntiKt4TopoEM or jet_akt4topoem
    m_TruthReader(this, "sherpa"),          // include what monte carlo you are using
    vertex(false), Zmass(-9999), eventCutFlow("Event"), RunNumber(0), isMC(false)
{
  DeclareProperty( "IgnoreGRL", m_prop_skipgrl );
  SetLogName( GetName() );
}

AnalysisCycle::~AnalysisCycle() {}

// Section: Data/File Setup {{{1
// BeginCycle()
void AnalysisCycle::BeginCycle() throw( SError ) {   
    DukHepFilter::setupGRL();
    return; 
}

// EndCycle()
void AnalysisCycle::EndCycle() throw( SError ) {  return; }


// BeginInputData()
void AnalysisCycle::BeginInputData( const SInputData& ) throw( SError ) {
  // say something for debugging
  m_logger << DEBUG << "Hello from BeginInputData." << SLogger::endmsg;
  
  //------event cut flow setup------//
  eventCutFlow.addCut(0,"no");            // count the total number of events
  eventCutFlow.addCut(1,"GRL");           // events passing GRL
  eventCutFlow.addCut(2,"Trigger");       // events passing Muon Trigger
  eventCutFlow.addCut(3,"Vertex");        // events passing primary vertex cut
  eventCutFlow.addCut(4,"two muon");      // events with two good muons
  eventCutFlow.addCut(5,"Z Mass");        // events passing Z mass window
  eventCutFlow.addCut(6,"good photon");   // events with one good photon
  eventCutFlow.addCut(7,"tight");         // events with one PhotonIDTool::Tight(6) photon
  eventCutFlow.addCut(8,"Cone");          // events with one photon passing cone isolation cut
  eventCutFlow.addCut(9,"good jet");      // events with at least one good jet
  eventCutFlow.addCut(10,"isolated jet"); // events with at least one isolated jet
  
  //This declares the variables that go in the output tree
  m_MuonReader.DeclareVariables();
  m_PhotonReader.DeclareVariables();
  m_JetReader.DeclareVariables();
  m_TruthReader.DeclareVariables();
  DeclareVariable(o_Zmass, "Zmass");
  DeclareVariable(o_muonIndex, "mu_index");
  DeclareVariable(o_photonIndex, "ph_index");
  DECLARE("zgmumuSkimmed")
    ;
    
  return;
}

// EndInputData()
void AnalysisCycle::EndInputData( const SInputData& ) throw( SError ) {   return; }

  
// BeginInputFile()
void AnalysisCycle::BeginInputFile( const SInputData& inputData) throw( SError ) {
  int intype = STree::INPUT_TREE & STree::EVENT_TREE;
  if (! inputData.GetTrees(intype) ) {
      m_logger << ERROR << "AnalysisCycle needs an input tree!" << SLogger::endmsg;
      throw SError( SError::SkipCycle );
  }
  else if (inputData.GetTrees(intype)->size() != 1) {
      m_logger << ERROR << "AnalysisCycle got too many (" << inputData.GetTrees(intype)->size() << ")input trees." << SLogger::endmsg;
      throw SError( SError::SkipCycle );
  }
  else {
      m_logger << DEBUG << "Connecting Variables..." << SLogger::endmsg;

      // initialize MC flags
      if( inputData.GetType() == "MC" ) {
          isMC = true;
          m_MuonReader.setMC(true);
          m_PhotonReader.setMC(true);
      }
      else {
          m_MuonReader.setMC(false);
          m_PhotonReader.setMC(false);
      }

      TString treename(inputData.GetTrees(intype)->at(0).treeName);
      m_MuonReader.ConnectVariables( treename.Data() );
      m_PhotonReader.ConnectVariables( treename.Data() );
      m_JetReader.ConnectVariables( treename.Data() );
      m_TruthReader.ConnectVariables( treename.Data() );
      CONNECT( treename.Data() ) 
        ;
  //connect any mutable branches (e.g. trigger or MET) which are set by job options
  //ConnectVariable( treename.Data(), m_prop_triggername.c_str(), m_MuonTrigger );

  }
   return;
}

// Section: Event Execution {{{1

// Subsection: Zgmumu Analysis
#if ANALYSIS_TYPE == ZGMUMU_TYPE
void AnalysisCycle::ExecuteEvent( const SInputData &inputData, Double_t ) throw( SError ) {
   
   m_logger << DEBUG << "** Executing Event Selection **" << SLogger::endmsg;
   
  // Subsection: clear and (re)set all objects used in the event analysis {{{2
 
  // macro of commands to clear the output tree vectors. (delete if you dont want an output tree)
  RESETVAR
    ;
  
  // clear particle reader variables
  m_MuonReader.Reset();
  m_PhotonReader.Reset();
  m_JetReader.Reset();
  
  // clear and (re)set all objects used in the event analysis
  // --
  vertex = false;
  Zmass  = -9999;
  allMuons.clear();
  goodMuons.clear();
  allPhotons.clear();
  goodPhotons.clear();
  tightPhotons.clear();
  allJets.clear();
  goodJets.clear();
  isolatedJets.clear();
  eventCutFlow.resetCutFlow();
  o_Zmass = -999;
  o_muonIndex.clear();
  o_photonIndex.clear();

  // used in mc to correct for Lar problem
  if( inputData.GetType() == "MC") {
    mc_dataperiod.SetSeed(m_EventNumber);
    RunNumber = mc_dataperiod.GetDataPeriod();
  }
  // --

  eventCutFlow.passCut();

  // Subsection: Check GoodRunsList {{{2

  // check whether we are running over data or monte carlo
  if( !( m_prop_skipgrl ) && ( ( inputData.GetType() == "data" ) || ( inputData.GetType() == "Data" )) ) {
      if( ! testGRL(m_RunNumber, m_lbn) ) throw SError( SError::SkipEvent );
  }
  eventCutFlow.passCut();

  m_logger << DEBUG << "** Passed goodrun cut **" << SLogger::endmsg;

  // Subsection: Check Trigger {{{2
  //--
  if( (!m_EF_mu18_MG) && (!m_EF_mu40_MSonly_barrel) ) throw SError( SError::SkipEvent );
  eventCutFlow.passCut();

  // Subsection: Vertex Selection {{{2 
  //--
  // require the first vertex to be good? (put this in latter)
  for(int t = 0; t < m_vxp_n; t++) {
      if( (m_vxp_trk_n->at(t) > 2) && (fabs(m_vxp_z->at(t)) < 200) ) { // m_vxp_type->at(t) == 1 ? (make sure the vertex is primary)
          vertex = true;
          break;
      }
  } 
  if(!vertex) throw SError( SError::SkipEvent );
  eventCutFlow.passCut();

  m_logger << DEBUG << "** Passed PreSelection **" << SLogger::endmsg;

  // Subsection: Muon Selection
  
  m_MuonReader.getMuons(m_EventNumber, allMuons);                           // places all the muons in the event in a vector
  muSelector.getGoodMuons(allMuons.begin(), allMuons.end(), goodMuons);     // select all the good muons and place them in a vector
  
  // require only 2 good muons in the event
  if( goodMuons.size() != 2 ) throw SError( SError::SkipEvent );
  sort(goodMuons.rbegin(), goodMuons.rend(), AnalysisUtils::ptMuonSort);
  
  // get the good muons, so we can use them
  Muon *muon1  = goodMuons.at(0);
  Muon *muon2  = goodMuons.at(1);

  m_logger << DEBUG << "/** select two muons **/" << SLogger::endmsg;
 
  // check to see that the muons are oppositely charged
  if( (muon1->Charge) != -1*(muon2->Charge) ) throw SError( SError::SkipEvent ); 
  eventCutFlow.passCut();

  m_logger << DEBUG << "** Found Two Good Muons **" << SLogger::endmsg;
 
  // Subsection: Z Boson Selection
  
  // get the Z boson four vector and calculate its mass
  TLorentzVector z4vector = *muon1 + *muon2; 
  Zmass = z4vector.M()/1000.; 
  
  // apply mass window cut
  if(Zmass < 40.) throw SError( SError::SkipEvent );
  eventCutFlow.passCut();

  m_logger << DEBUG << "** Found a Z! **" << SLogger::endmsg;
 
  // Subsection: Photon Selection

  m_PhotonReader.getPhotons(allPhotons,m_EventNumber);    // place all the photons in the event in a vector
  
  // place all the good photons in the event in a vector (different for MC and Data)
  if(inputData.GetType() == "MC") 
  {
      if(! photonSelector.getGoodPhotons(RunNumber, allPhotons.begin(), allPhotons.end(), muon1, muon2, goodPhotons) ) throw SError( SError::SkipEvent );     
  } 
  else
  {
      if(! photonSelector.getGoodPhotons(allPhotons.begin(), allPhotons.end(), muon1, muon2, goodPhotons) ) throw SError( SError::SkipEvent );     
  }
  sort(goodPhotons.rbegin(), goodPhotons.rend(), AnalysisUtils::ptPhotonSort);
  //Photon *photon = goodPhotons.at(0);

  eventCutFlow.passCut();                   // check if the event has at least one good photon

  m_logger << DEBUG << "** Selected at Least One Good Photon **" << SLogger::endmsg;

  // Subsection: Isolated Photon Selection
  if( !photonSelector.getTightPhotons(goodPhotons.begin(), goodPhotons.end(), tightPhotons) ) throw SError( SError::SkipEvent ); // select the photons that pass the PhotonIDTool::Tight(6) criteria
  sort(tightPhotons.rbegin(), tightPhotons.rend(), AnalysisUtils::ptPhotonSort);                                                 // sort the tight photons in descending order in terms of pt
  Photon *photon = tightPhotons.at(0);                                                                                           // select the highest pt, tight photon
  eventCutFlow.passCut();
  
  // check cone isolation for the leading pt tight photon
  if( photon->getConeCorrected(m_vxp_nTracks, isMC) >= 5000. ) throw SError( SError::SkipEvent );
  eventCutFlow.passCut();
 
  m_logger << DEBUG << "** Selected Isolated Photon **" << SLogger::endmsg;

  m_logger << DEBUG << "Event passed.  Copying variables to output tree." << SLogger::endmsg;

  // copy output variables to the output tree
  COPYVAR
    ;

  m_MuonReader.CopyToOutput();
  m_PhotonReader.CopyToOutput();
  m_JetReader.CopyToOutput();

  o_Zmass = Zmass;

  // split the muons by charge
  Muon *antimuon = 0;
  Muon *muon     = 0;
  if(muon1->Charge > 0) {
      antimuon = muon1;
      muon     = muon2;
  }
  else {
      antimuon = muon2;
      muon     = muon1;
  }
  o_muonIndex.push_back(muon->Index);
  o_muonIndex.push_back(antimuon->Index);
  o_photonIndex.push_back(photon->Index);

  return; 
}

// Subsecion: Truth Analysis
#elif ANALYSIS_TYPE == TRUTH_TYPE
void AnalysisCycle::ExecuteEvent( const SInputData &inputData, Double_t ) throw( SError ) {
    
    m_logger << DEBUG << "** Executing Event Selection **" << SLogger::endmsg;

    // Subsection: clear and (re)set all objects used in the event analysis
    TruthMuons.clear();
    
    // Get the two muons coming from the Z in the truth bank
    TruthMuons = m_TruthReader.getTruthMuons();
    if ( TruthMuons.size() != 2 ) throw SError( SError::SkipEvent );
    
    // TruthReader returns the muons sorted in descending order in terms of pt
    Muon *muon1 = TruthMuons.at(0);
    Muon *muon2 = TruthMuons.at(1);

    // get the truth truth photon
    //TruthPhotons = m_TruthReader.getTruthPhotons();
    //if ( TruthPhotons.size() != 1 ) throw SError( SError::SkipEvent );
    //Photon *photon = TruthPhotons.at(0);

    // lets see if this event as FSR photons
    //if ( m_TruthReader.hasFSRPhoton() ) throw SError( SError::SkipEvent );
    
    // lets construct the three body mass so we can remove the ISR
    //TLorentzVector mmg4vector = *muon1 + *muon2 + *photon;
    //float threeBodyMass = mmg4vector.M()/1000.;

    //if (threeBodyMass <= 110.) throw SError( SError::SkipEvent );
    
    // lets see if these two muons construct the Z mass peak
    TLorentzVector z4vector = *muon1 + *muon2;
    float zMass = z4vector.M()/1000.;
    Book(TH1F("zmass", "Invariant Mass of the Truth Z Boson;m_{#mu#mu} [GeV];number of events / 1 GeV", 165, 35, 120))->Fill(zMass);
    
    // now lets transform to the Z boson rest frame
    //AnalysisUtils::cmTransformation(*muon1, mmg4vector);
    //AnalysisUtils::cmTransformation(*muon2, mmg4vector);
    //AnalysisUtils::cmTransformation(z4vector, mmg4vector);
    AnalysisUtils::cmTransformation(*muon1, z4vector);
    AnalysisUtils::cmTransformation(*muon2, z4vector);

    // plot the cos(dt*) distribution of the muon
    if (muon1->Charge < 0. )
        Book(TH1F("costheta", "Cos(#theta*);Cos(#theta*);Events", 220, -1.1, 1.1))->Fill(muon1->CosTheta());
    else
        Book(TH1F("costheta", "Cos(#theta*);Cos(#theta*);Events", 220, -1.1, 1.1))->Fill(muon2->CosTheta());

    return;
}

#endif



// Section: Cut Flow Logging {{{1
void AnalysisCycle::EndMasterInputData( const SInputData& ) throw( SError ) {
    m_logger << INFO << "End of input data." << SLogger::endmsg;

    //-------cut flow printing------//
    eventCutFlow.printCutFlow();
    muSelector.printMuonCutFlow();
    photonSelector.printPhotonCutFlow();
    jetSelector.printJetCutFlow();
    
    // loop over the event cut flow and place it in a histogram for latter access
    for(unsigned int i = 0; i < eventCutFlow.nCuts; i++) {
        Book(TH1F("cutflow","Event Cut Flow", eventCutFlow.nCuts, 0, eventCutFlow.nCuts))->Fill(i,eventCutFlow.passedCut(i));
    }

    // loop over the muon cut flow and place it in a histogram for latter access
    for(unsigned int i = 0; i < muSelector.nCuts; i++) {
        Book(TH1F("mucutflow", "Muon Cut Flow", muSelector.nCuts, 0, muSelector.nCuts))->Fill(i,muSelector.passedCut(i));
    }

    // loop over the photon cut flow and place it in a histogram for latter access
    for(unsigned int i = 0; i < photonSelector.nCuts; i++) {
        Book(TH1F("photoncutflow", "Photon Cut Flow", photonSelector.nCuts, 0, photonSelector.nCuts))->Fill(i,photonSelector.passedCut(i));
    }

    // loop over the jet cut flow and place it in a histogram for latter access
    for(unsigned int i = 0; i < jetSelector.nCuts; i++) {
        Book(TH1F("jetcutflow", "Jet Cut Flow", jetSelector.nCuts, 0, jetSelector.nCuts))->Fill(i,jetSelector.passedCut(i));
    }
/*
    std::sort(EventVector.begin(),EventVector.end());
    for(std::vector<std::pair<Int_t,Int_t> >::const_iterator eventnumber = EventVector.begin(); eventnumber != EventVector.end(); ++eventnumber) {
        std::cout << eventnumber->second << "\t" << eventnumber->first << std::endl;
    }
*/
    return;
}

