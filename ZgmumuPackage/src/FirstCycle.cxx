// $Id: dukheputils.py 163843 2011-05-27 18:22:01Z ayana $

// base class definition (Makefile.common must have ../ in include path):
#include "../include/FirstCycle.h"

// STL include(s)
#include <algorithm>
#include <iostream>

using AnalysisUtils::dR;

ClassImp( FirstCycle );

// Section: Constructor/Destructor Definitions {{{1

FirstCycle::FirstCycle()
  : DukHepFilter(),
    // Macro initializing the stl vectors that access the tree
    INIT_NULLS_CTOR,
    m_MuonReader(this, "mu_staco"), 
    m_PhotonReader(this), 
    m_JetReader(this, "jet_AntiKt4TopoEM"), // for some data it is jet_AntiKt4TopoEM or jet_akt4topoem
    vertex(false), Zmass(-9999), eventCutFlow("Event")  
{
  DeclareProperty( "IgnoreGRL", m_prop_skipgrl );
  SetLogName( GetName() );
}

FirstCycle::~FirstCycle() {}

// Section: Data/File Setup {{{1
// BeginCycle()
void FirstCycle::BeginCycle() throw( SError ) {   
    DukHepFilter::setupGRL();
    return; 
}

// EndCycle()
void FirstCycle::EndCycle() throw( SError ) {  return; }


// BeginInputData()
void FirstCycle::BeginInputData( const SInputData& ) throw( SError ) {
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
  DECLARE("zgmumuSkimmed")
    ;
    
  return;
}

// EndInputData()
void FirstCycle::EndInputData( const SInputData& ) throw( SError ) {   return; }

  
// BeginInputFile()
void FirstCycle::BeginInputFile( const SInputData& inputData) throw( SError ) {
  int intype = STree::INPUT_TREE & STree::EVENT_TREE;
  if (! inputData.GetTrees(intype) ) {
      m_logger << ERROR << "FirstCycle needs an input tree!" << SLogger::endmsg;
      throw SError( SError::SkipCycle );
  }
  else if (inputData.GetTrees(intype)->size() != 1) {
      m_logger << ERROR << "FirstCycle got too many (" << inputData.GetTrees(intype)->size() << ")input trees." << SLogger::endmsg;
      throw SError( SError::SkipCycle );
  }
  else {
      m_logger << DEBUG << "Connecting Variables..." << SLogger::endmsg;

      // initialize MC flags
      if( inputData.GetType() == "MC" ) {
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
      CONNECT( treename.Data() ) 
        ;
  //connect any mutable branches (e.g. trigger or MET) which are set by job options
  //ConnectVariable( treename.Data(), m_prop_triggername.c_str(), m_MuonTrigger );

  }
   return;
}

// Section: Event Execution {{{1
void FirstCycle::ExecuteEvent( const SInputData &inputData, Double_t ) throw( SError ) {
   
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

  if(! photonSelector.getGoodPhotons(allPhotons.begin(), allPhotons.end(), muon1, muon2, goodPhotons) ) throw SError( SError::SkipEvent );    // place all the good photons in the event in a vector 
  eventCutFlow.passCut();                                                                                                                     // check if the event has at least one good photon

  m_logger << DEBUG << "** Selected at Least One Good Photon **" << SLogger::endmsg;

  // Subsection: Isolated Photon Selection
  if( !photonSelector.getTightPhotons(goodPhotons.begin(), goodPhotons.end(), tightPhotons) ) throw SError( SError::SkipEvent ); // select the photons that pass the PhotonIDTool::Tight(6) criteria
  sort(tightPhotons.rbegin(), tightPhotons.rend(), AnalysisUtils::ptPhotonSort);                                                 // sort the tight photons in descending order in terms of pt
  Photon *photon = tightPhotons.at(0);                                                                                           // select the highest pt, tight photon
  eventCutFlow.passCut();
  
  // check cone isolation for the leading pt tight photon
  if( photon->getConeCorrected(m_vxp_nTracks, false) >= 5000. ) throw SError( SError::SkipEvent );
  eventCutFlow.passCut();
 
  m_logger << DEBUG << "** Selected Isolated Photon **" << SLogger::endmsg;

  // Subsection: MC Cleanup/Histograms
  
  //------z mass histograms------//
  Book(TH1F("zmasstotal", "Invariant Mass of the Z Boson;m_{#mu#mu} [GeV];Events", 24, 35, 120))->Fill(Zmass); // includes FSR

  //------Remove FSR------//
  TLorentzVector mmg4vec = *muon1 + *muon2 + *photon;
  float M3 = mmg4vec.M()/1000.;

  // uncut three body mass
  Book(TH1F("uncut3mass", "Three Body Invariant Mass;m_{#mu#mu#gamma} [GeV];Events", 90, 35, 305))->Fill(M3);
 
 // scatter plot (possibley)
  Book(TH2F("massplot", "m_{#mu#mu#gamma} vs. m_{#mu#mu};m_{#mu#mu};m_{#mu#mu#gamma}", 90, 35, 305, 90, 35, 305))->Fill(Zmass, M3); 
  
  if( M3 >= 100. ) {
    Book(TH1F("zmass", "Invariant Mass of the Z Boson;m_{#mu#mu} [GeV];Events", 24, 35, 120))->Fill(Zmass); // no FSR
    Book(TH1F("3mass","Three Body Invariant Mass;m_{#mu#mu#gamma} [GeV];Events", 90, 35, 305))->Fill(M3);         // three body invariant mass
  }
  else 
    Book(TH1F("zmassFSR", "Invariant Mass of the Z Boson;m_{#mu#mu} [GeV];Events", 24, 35, 120))->Fill(Zmass); // includes FSR
  
  //------muon histograms------//  
  Book(TH1F("mumomentum", "Muon P_{T} Distribution;P_{T} [GeV];Events", 40, 0, 100))->Fill(muon1->Pt/1000.);           // pt distribution
  Book(TH1F("mumomentum", "Muon P_{T} Distribution;P_{T} [GeV];Events", 40, 0, 100))->Fill(muon2->Pt/1000.);           
  Book(TH1F("muoneta", "Muon #eta Distribution;#eta;Events", 50, -2.5, 2.5))->Fill(muon1->Eta); // eta distribution
  Book(TH1F("muoneta", "Muon #eta Distribution;#eta;Events", 50, -2.5, 2.5))->Fill(muon2->Eta);
  Book(TH1F("muonphi", "Muon #phi Distribution;#phi;Events", 70, -3.5, 3.5))->Fill(muon1->Phi); // phi distribution
  Book(TH1F("muonphi", "Muon #phi Distribution;#phi;Events", 70, -3.5, 3.5))->Fill(muon2->Phi);

  //-----photon histograms-----//
  Book(TH1F("photonmomentum", "Photon P_{T} Distribution;P_{T} [GeV];Events", 40, 0, 120))->Fill(photon->etCluster/1000.);
  Book(TH1F("photoneta", "Photon #eta Distribution;#eta;Events", 30, -1.5, 1.5))->Fill(photon->etaCluster);
  Book(TH1F("photonphi", "Photon #phi Distribution;#phi;Events", 70, -3.5, 3.5))->Fill(photon->phiCluster);
/*
  // Subsection: Jet Selection
  
  m_JetReader.getJets(allJets);                                                                                  // place all the remaining jets in the event in a vector
  if( !jetSelector.getGoodJets(allJets.begin(), allJets.end(), goodJets) ) throw SError( SError::SkipEvent );    // place all the 'good' jets in the event in a vector 
  eventCutFlow.passCut();                                                                                        // pass cut if goodJets is non-empty

  m_logger << DEBUG << "** Have Some Good Jets! **" << SLogger::endmsg;

  // Subsection: Overlap Removal
  for(std::vector<Jet*>::const_iterator ajet = goodJets.begin(); ajet != goodJets.end(); ++ajet) {
      // check the dR separation between the selected photon
      if( dR(*ajet, photon) <= 0.6 ) continue;
      isolatedJets.push_back(*ajet);
  }

  if( isolatedJets.size() < 1 ) throw SError( SError::SkipEvent );
  eventCutFlow.passCut();

  m_logger << DEBUG << "** Found an Isolated Jet  **" << SLogger::endmsg;

  // Subsection: Jet Histogram Booking
  Book(TH1F("jetn", "Jet Multiplicity Distribution",7,0,7))->Fill(m_JetReader.NumberofJets);
*/
  m_logger << DEBUG << "Event passed.  Copying variables to output tree." << SLogger::endmsg;


  // copy output variables to the output tree
  COPYVAR
    ;

  m_MuonReader.CopyToOutput();
  m_PhotonReader.CopyToOutput();
  m_JetReader.CopyToOutput();

  return;
}

// Section: Cut Flow Logging {{{1
void FirstCycle::EndMasterInputData( const SInputData& ) throw( SError ) {
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

