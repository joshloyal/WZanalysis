// $Id: dukheputils.py 163843 2011-05-27 18:22:01Z ayana $

// base class definition (Makefile.common must have ../ in include path):
#include "../include/WgmunuCycle.h"

// STL include(s)
#include <algorithm>
#include <iostream>

// This line determines which ExecuteEvent method to use
#define WGMUNU_TYPE 0
#define WMUNU_TYPE 1
#define TRUTH_TYPE 2
#define ANALYSIS_TYPE TRUTH_TYPE

using AnalysisUtils::dR;

ClassImp( WgmunuCycle );

// Section: Constructor/Destructor Definitions {{{1

WgmunuCycle::WgmunuCycle()
  : DukHepFilter(),
    // Macro initializing the stl vectors that access the tree
    INIT_NULLS_CTOR,
    m_MuonReader(this, "mu_staco"), 
    m_PhotonReader(this), 
    m_JetReader(this, "jet_AntiKt4TopoEM"), // for some data it is jet_AntiKt4TopoEM or jet_akt4topoem
    m_METReader(this),
    m_TruthReader(this, "pythia"),  // include what monte carlo you are using
    vertex(false), Wtransmass(-9999), eventCutFlow("Event"), RunNumber(0), isMC(false)  
{
  DeclareProperty( "IgnoreGRL", m_prop_skipgrl );
  SetLogName( GetName() );
}

WgmunuCycle::~WgmunuCycle() {}

// Section: Data/File Setup {{{1

// BeginCycle()___________________________________________________________________________________
void WgmunuCycle::BeginCycle() throw( SError ) {   
    DukHepFilter::setupGRL();
    return; 
}

// EndCycle()_____________________________________________________________________________________
void WgmunuCycle::EndCycle() throw( SError ) {  return; }


// BeginInputData()_______________________________________________________________________________
void WgmunuCycle::BeginInputData( const SInputData& ) throw( SError ) {
  // say something for debugging
  m_logger << DEBUG << "Hello from BeginInputData." << SLogger::endmsg;
  
  //------event cut flow setup------//
  eventCutFlow.addCut(0,"no");             // count the total number of events
  eventCutFlow.addCut(1,"GRL");            // events passing GRL
  eventCutFlow.addCut(2,"Trigger");        // events passing Muon Trigger
  eventCutFlow.addCut(3,"Vertex");         // events passing primary vertex cut
  eventCutFlow.addCut(4,"clean up");       // events passing jet cleaning
  eventCutFlow.addCut(5,"one muon");       // events with at least one good muon
  eventCutFlow.addCut(6,"MET");            // events pass MET cut off
  eventCutFlow.addCut(7,"transverse mass");// events passing transverse mass cut
  eventCutFlow.addCut(8,"good photon");    // events with one good photon
  eventCutFlow.addCut(9,"tight");          // events with one PhotonIDTool::Tight(6) photon
  eventCutFlow.addCut(10,"Cone");          // events with one photon passing cone isolation cut
  
  //This declares the variables that go in the output tree
  m_MuonReader.DeclareVariables();
  m_PhotonReader.DeclareVariables();
  m_JetReader.DeclareVariables();
  m_METReader.DeclareVariables();
  m_TruthReader.DeclareVariables();
  DeclareVariable(o_Wtransmass, "Wtransmass");
  DeclareVariable(o_muonIndex, "mu_index");
  DeclareVariable(o_photonIndex, "ph_index");
  DeclareVariable(o_MET, "met_et");
  DeclareVariable(o_METphi, "met_phi");
  DECLARE("zgmumuSkimmed")
    ;
    
  return;
}

// EndInputData()_________________________________________________________________________________
void WgmunuCycle::EndInputData( const SInputData& ) throw( SError ) {   return; }

  
// BeginInputFile()_______________________________________________________________________________
void WgmunuCycle::BeginInputFile( const SInputData& inputData) throw( SError ) {
  int intype = STree::INPUT_TREE & STree::EVENT_TREE;
  if (! inputData.GetTrees(intype) ) {
      m_logger << ERROR << "WgmunuCycle needs an input tree!" << SLogger::endmsg;
      throw SError( SError::SkipCycle );
  }
  else if (inputData.GetTrees(intype)->size() != 1) {
      m_logger << ERROR << "WgmunuCycle got too many (" << inputData.GetTrees(intype)->size() << ")input trees." << SLogger::endmsg;
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
      m_METReader.ConnectVariables( treename.Data() );
      m_TruthReader.ConnectVariables( treename.Data() );
      CONNECT( treename.Data() ) 
        ;
  //connect any mutable branches (e.g. trigger or MET) which are set by job options
  //ConnectVariable( treename.Data(), m_prop_triggername.c_str(), m_MuonTrigger );

  }
   return;
}

// Section: Event Execution {{{1_________________________________________________________

// Subsection: W->munu + g
#if ANALYSIS_TYPE == WGMUNU_TYPE
void WgmunuCycle::ExecuteEvent( const SInputData &inputData, Double_t ) throw( SError ) {
   
   m_logger << DEBUG << "** Executing Event Selection **" << SLogger::endmsg;
   
  // Subsection: clear and (re)set all objects used in the event analysis {{{2
 
  // macro of commands to clear the output tree vectors. (delete if you dont want an output tree)
  RESETVAR
    ;
  
  // clear particle reader variables
  m_MuonReader.Reset();
  m_PhotonReader.Reset();
  m_JetReader.Reset();
  m_METReader.Reset();

  // clear and (re)set all objects used in the event analysis
  // --
  vertex = false;
  Wtransmass  = -999;
  allMuons.clear();
  goodMuons.clear();
  allPhotons.clear();
  goodPhotons.clear();
  tightPhotons.clear();
  isolatedPhotons.clear();
  allJets.clear();
  goodJets.clear();
  eventCutFlow.resetCutFlow();
  o_Wtransmass = -999;
  o_muonIndex.clear();
  o_photonIndex.clear();
  o_MET = -999;
  o_METphi = -999;

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

  // Subsection: Particle Selection / Jet Cleaning
  
  // good muon selection___________________________________________________________________________________________________________
  m_MuonReader.getMuons(m_EventNumber, allMuons);                           // places all the muons in the event in a vector
  muSelector.getGoodMuons(allMuons.begin(), allMuons.end(), goodMuons);     // select all the good muons and place them in a vector

  // good photon selection_________________________________________________________________________________________________________
  m_PhotonReader.getPhotons(allPhotons,m_EventNumber);    // place all the photons in the event in a vector
  if(isMC) 
      photonSelector.getGoodPhotons(RunNumber, allPhotons.begin(), allPhotons.end(), goodMuons.begin(), goodMuons.end(), goodPhotons);
  else
      photonSelector.getGoodPhotons(allPhotons.begin(), allPhotons.end(), goodMuons.begin(), goodMuons.end(), goodPhotons);     

  // isolated photon selection_____________________________________________________________________________________________________
  photonSelector.getTightPhotons(goodPhotons.begin(), goodPhotons.end(), tightPhotons);
  photonSelector.getIsolatedPhotons(tightPhotons.begin(), tightPhotons.end(), m_vxp_nTracks, isolatedPhotons, isMC);
  
  if(!isMC) {
      // good jet selection / MET cleaning_____________________________________________________________________________________________
      m_JetReader.getJets(allJets);                                         // place all the remaining jets in the event in a vector
      jetSelector.getGoodJets(  allJets.begin(), 
                                allJets.end(),
                                goodMuons.begin(),
                                goodMuons.end(),
                                isolatedPhotons.begin(),
                                isolatedPhotons.end(),
                                goodJets);                                  // place all the 'good' jets in the event in a vector 

      if( jetSelector.isBadUglyJets(goodJets.begin(), goodJets.end()) ) throw SError( SError::SkipEvent );

      m_logger << DEBUG << "** Passed check quality cut **" << SLogger::endmsg;

      // check Lar noise warning flag is ok
      if( m_larError ) throw SError( SError::SkipEvent );

      m_logger << DEBUG << "** Passed larError flag **" << SLogger::endmsg;

      // check locohadtop is positive
      if( m_METReader.getSumET() < 0. ) throw SError( SError::SkipEvent );
    }
    
  // get the MET for this event (for MC this must be done after Muons::getMuons is called (to correct for oversmearing)
  TLorentzVector MET = m_METReader.getMuonMET(goodMuons.begin(), 
                                              goodMuons.end(), 
                                              isolatedPhotons.begin(), 
                                              isolatedPhotons.end());
  eventCutFlow.passCut();

  m_logger << DEBUG << "** Passed Cleaning Cuts **" << SLogger::endmsg;

  // Subsection: Muon Selection
  if( goodMuons.size() < 1 ) throw SError( SError::SkipEvent );

  // get the highest pt muon
  sort(goodMuons.rbegin(), goodMuons.rend(), AnalysisUtils::ptMuonSort); // sorts muons in descending order in terms of pt
  Muon *muon = goodMuons.at(0);
  eventCutFlow.passCut();
  
  m_logger << DEBUG << "** Found at least one good muon **" << SLogger::endmsg;

  // Subsection: MET Cut
  if( MET.Pt() < 25000. ) throw SError( SError::SkipEvent );
  eventCutFlow.passCut();

  m_logger << DEBUG << "** Passed MET Cut **" << SLogger::endmsg;

  // Subsection: W Boson Selection
  TLorentzVector wT4vector = MET + muon->getTransverseFourVector();
  Wtransmass = wT4vector.M()/1000.;

  // apply mass cut
  if( Wtransmass <= 40. ) throw SError( SError::SkipEvent );
  eventCutFlow.passCut();

  m_logger << DEBUG << "** Found a W **" << SLogger::endmsg;
  
  // Subsection: Photon Selection

  if( goodPhotons.size() < 1 ) throw SError( SError::SkipEvent );
  eventCutFlow.passCut();

  m_logger << DEBUG << "** Selected at Least One Good Photon **" << SLogger::endmsg;

  // Subsection: Isolated Photon Selection
  if( tightPhotons.size() < 1 ) throw SError( SError::SkipEvent );                  // at least one TIGHT photon 
  sort(tightPhotons.rbegin(), tightPhotons.rend(), AnalysisUtils::ptPhotonSort);    // sort the tight photons in descending order in terms of pt
  Photon *photon = tightPhotons.at(0);                                              // select the highest pt, tight photon
  eventCutFlow.passCut();
  
  // check cone isolation for the leading pt tight photon
  if( photon->getConeCorrected(m_vxp_nTracks, isMC) >= 5000. ) throw SError( SError::SkipEvent );
  eventCutFlow.passCut();
 
  m_logger << DEBUG << "** Selected Isolated Photon **" << SLogger::endmsg;
  
  m_logger << DEBUG << "Event passed.  Copying variables to output tree." << SLogger::endmsg;


  Book(TH1F("wmass", "Invariant Mass of the Truth W Boson;m_{#mu#nu} [GeV]; number of events / 1 GeV", 165, 35, 120))->Fill(Wtransmass);
  
  // copy output variables to the output tree
  COPYVAR
    ;

  m_MuonReader.CopyToOutput();
  m_PhotonReader.CopyToOutput(); 
  m_JetReader.CopyToOutput();
  m_METReader.CopyToOutput();

 
  o_Wtransmass = Wtransmass;
  o_muonIndex.push_back(muon->Index);
  o_photonIndex.push_back(photon->Index);
  o_MET = MET.Pt();
  o_METphi = MET.Phi();

  return;
}

// Subsection: W->munu 
#elif ANALYSIS_TYPE == WMUNU_TYPE
void WgmunuCycle::ExecuteEvent( const SInputData &inputData, Double_t ) throw( SError ) {
    
    m_logger << DEBUG << "** Executing Event Selection **" << SLogger::endmsg;
    
    // Subsection: clear and (re)set all objects used in the event analysis
    RESETVAR
      ;

    // clear particle reader variables
    m_MuonReader.Reset();
    m_METReader.Reset();

    // clear and (re)set all objects used in the event analysis
    // --
    vertex = false;
    Wtransmass = -999;
    allMuons.clear();
    goodMuons.clear();
    eventCutFlow.resetCutFlow();

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
        if( (m_vxp_trk_n->at(t) >= 2) && (fabs(m_vxp_z->at(t)) < 200) ) { // m_vxp_type->at(t) == 1 ? (make sure the vertex is primary)
            vertex = true;
            break;
        }
    } 
    if(!vertex) throw SError( SError::SkipEvent );
    eventCutFlow.passCut();

    m_logger << DEBUG << "** Passed PreSelection **" << SLogger::endmsg;

    // Subsection: Particle Selection 

    // good muon selection
    m_MuonReader.getMuons(m_EventNumber, allMuons);                         // places all the muons in the event in a vector
    muSelector.getGoodMuons(allMuons.begin(), allMuons.end(), goodMuons);   // select all the good muons and place them in a vector
    
  
    // get the MET for this event (for MC this must be done after Muons::getMuons is called -- to correct for oversmearing)
    TLorentzVector MET = m_METReader.getMET();
    METReader::correctMuonMET(MET, goodMuons.begin(), goodMuons.end());
    eventCutFlow.passCut();

    // Subsection: Muon Selection
    if( goodMuons.size() != 1 ) throw SError( SError::SkipEvent );

    // get the highest pt muon
    sort(goodMuons.rbegin(), goodMuons.rend(), AnalysisUtils::ptMuonSort);  // sort muons in descending order in terms of pt
    Muon *muon = goodMuons.at(0);
    eventCutFlow.passCut();

    m_logger << DEBUG << "** Found at least one god muon **" << SLogger::endmsg;

    // Subsection: MET Cut
    if( MET.Pt() < 25000. ) throw SError( SError::SkipEvent );
    eventCutFlow.passCut();

    m_logger << DEBUG << "** Passed MET Cut **" << SLogger::endmsg;

    // Subsection: W Boson Selection
    TLorentzVector wT4vector = MET + muon->getTransverseFourVector();
    Wtransmass = wT4vector.M()/1000.;

    // apply mass cut
    if( Wtransmass <= 40. ) throw SError( SError::SkipEvent );
    eventCutFlow.passCut();

    m_logger << DEBUG << "** Found a W **" << SLogger::endmsg;

    m_logger << DEBUG << "Event passed. Copying variables to output tree." << SLogger::endmsg;

    Book(TH1F("wmass", "Invariant Mass of the Truth W Boson;m_{#mu#nu} [GeV]; number of events / 1 GeV", 165, 35, 200))->Fill(Wtransmass);
    Book(TH1F("met", "Missing Transverse Energy;E_{T} [GeV]; number of events", 100, 0, 200))->Fill(MET.Pt()/1000.);
    Book(TH1F("muonPt", "Muon Pt Distribution;P_{T} [GeV]; number of events", 60, 0, 120))->Fill(muon->TLorentzVector::Pt()/1000.);
    // copy output variables to the output tree
    COPYVAR
        ;

    m_MuonReader.CopyToOutput();
    m_METReader.CopyToOutput();

 
    o_Wtransmass = Wtransmass;
    o_muonIndex.push_back(muon->Index);
    o_MET = MET.Pt();
    o_METphi = MET.Phi();

    return;
}

// Subsection: W->munu truth
#elif ANALYSIS_TYPE == TRUTH_TYPE
void WgmunuCycle::ExecuteEvent( const SInputData &inputData, Double_t ) throw( SError ) {
    
    m_logger << DEBUG << "** Executing Event Selection **" << SLogger::endmsg;

    // Subsection: clear and (re)set all objects used in the event analysis
    truthMuons.clear();
    truthNuetrinos.clear();

    // get the muon coming from the W in the truth bank
    truthMuons = m_TruthReader.getTruthMuons();
    if ( truthMuons.size() != 1 ) throw SError( SError::SkipEvent );
    
    // TruthReader returns the muons sorted in descending order in terms of pt
    Muon *muon = truthMuons.at(0);
    
    // get the truth nuetrino coming from the W
    truthNuetrinos = m_TruthReader.getTruthNuetrinos();
    if ( truthNuetrinos.size() != 1 ) throw SError( SError::SkipEvent );
    
    // TruthReader returns the nuetrinos sorted in descending order in terms of pt
    TLorentzVector *nuetrino = truthNuetrinos.at(0);

    // lets see if these particles construct the W mass peak
    TLorentzVector w4vector = *muon + *nuetrino;
    float wMass = w4vector.M()/1000.;
    Book(TH1F("wmass", "Invariant Mass of the Truth W Boson;m_{#mu#nu} [GeV]; number of events / 1 GeV", 165, 35, 120))->Fill(wMass);
    
    // now lets transform to the W boson rest frame
    AnalysisUtils::cmTransformation(*muon, w4vector);
    AnalysisUtils::cmTransformation(*nuetrino, w4vector);

    // plot the cos(dt*) distribution of the muon
    if ( muon->Charge < 0 )
        Book(TH1F("muon_costheta", "Cos(#theta*);Cos(#theta*);Events", 220, -1.1, 1.1))->Fill(muon->CosTheta());
    if ( muon->Charge > 0 )
        Book(TH1F("amuon_costheta", "Cos(#theta*);Cos(#theta*);Events", 220, -1.1, 1.1))->Fill(muon->CosTheta());
    
    return;
}
#endif

// Section: Cut Flow Logging {{{1_______________________________________________________________
void WgmunuCycle::EndMasterInputData( const SInputData& ) throw( SError ) {
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

    return;
}

