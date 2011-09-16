// $Id: dukheputils.py 163843 2011-05-27 18:22:01Z ayana $

// base class definition (Makefile.common must have ../ in include path):
#include "../include/MCAnalysisCycle.h"

// Root include(s)
#include "TVector2.h"
#include "TMath.h"

// pileup include(s)
#include "../PileupReweighting/PileupReweighting/TPileupReweighting.h"

// STL include(s)
#include <algorithm>
#include <iostream>

using AnalysisUtils::dR;

ClassImp( MCAnalysisCycle );

// Section: Constructor/Destructor Definitions {{{1

MCAnalysisCycle::MCAnalysisCycle()
  : DukHepFilter(),
    // Macro initializing the stl vectors that access the tree
    INIT_NULLS_CTOR,
    m_Zmass(0), m_mu_index(0), m_ph_index(0),
    m_MuonReader(this, "mu"), 
    m_PhotonReader(this), 
    m_JetReader(this, "jet"), // for some data it is jet_AntiKt4TopoEM or jet_akt4topoem
    m_TruthReader(this, "sherpa"),
    m_tPileUp(0),
    m_dataRootFileName("RootFiles/muMatrix/ilumicalc_histograms_EF_mu18_MG_178044-184169.root"),
    m_dataRootHistName("avgintperbx"),
    m_mcRootFileName("RootFiles/muMatrix/mu_mc10b.root"),
    m_mcRootHistName("mu_mc10b")
{   
  DeclareProperty( "IgnoreGRL", m_prop_skipgrl );
  SetLogName( GetName() );
}

MCAnalysisCycle::~MCAnalysisCycle() {}

// Section: Data/File Setup {{{1
// BeginCycle()
void MCAnalysisCycle::BeginCycle() throw( SError ) {   
    DukHepFilter::setupGRL();
    return; 
}

// EndCycle()
void MCAnalysisCycle::EndCycle() throw( SError ) {  return; }


// BeginInputData()
void MCAnalysisCycle::BeginInputData( const SInputData& ) throw( SError ) {
  // say something for debugging
  m_logger << DEBUG << "Hello from BeginInputData." << SLogger::endmsg;
  
  
  //This declares the variables that go in the output tree
  m_MuonReader.DeclareVariables();
  m_PhotonReader.DeclareVariables();
  m_JetReader.DeclareVariables();
  m_TruthReader.DeclareVariables();
  DeclareVariable(o_muonIndex, "mu_index");
  DeclareVariable(o_photonIndex, "ph_index");
  DECLARE("zgmumuSkimmed")
    ;
  
  // pileup reweighting tool
  m_tPileUp = new TPileupReweighting( "PileupReweightingTool" );
  int isGood = m_tPileUp->initialize( m_dataRootFileName,
                                      m_dataRootHistName,
                                      m_mcRootFileName,
                                      m_mcRootHistName );
  if( isGood == 0 ) std::cout << "Initialization of TPileupReweighting tool successful!" << std::endl; 
  
  return;
}

// EndInputData()
void MCAnalysisCycle::EndInputData( const SInputData& ) throw( SError ) {   return; }

  
// BeginInputFile()
void MCAnalysisCycle::BeginInputFile( const SInputData& inputData) throw( SError ) {
  int intype = STree::INPUT_TREE & STree::EVENT_TREE;
  if (! inputData.GetTrees(intype) ) {
      m_logger << ERROR << "MCAnalysisCycle needs an input tree!" << SLogger::endmsg;
      throw SError( SError::SkipCycle );
  }
  else if (inputData.GetTrees(intype)->size() != 1) {
      m_logger << ERROR << "MCAnalysisCycle got too many (" << inputData.GetTrees(intype)->size() << ")input trees." << SLogger::endmsg;
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
      m_TruthReader.ConnectVariables( treename.Data() );
      CONNECT( treename.Data() ) 
        ;
  //connect any mutable branches (e.g. trigger or MET) which are set by job options
  //ConnectVariable( treename.Data(), m_prop_triggername.c_str(), m_MuonTrigger );
  ConnectVariable( treename.Data(), "Zmass", m_Zmass);
  ConnectVariable( treename.Data(), "mu_index", m_mu_index);
  ConnectVariable( treename.Data(), "ph_index", m_ph_index);
  }
  
  return;
}

// Section: Event Execution {{{1
void MCAnalysisCycle::ExecuteEvent( const SInputData &inputData, Double_t ) throw( SError ) {
   
   m_logger << DEBUG << "** Executing Event Selection **" << SLogger::endmsg;
   
  // Subsection: clear and (re)set all objects used in the event analysis {{{2
 
  // macro of commands to clear the output tree vectors. (delete if you dont want an output tree)
  RESETVAR
    ;
  
  // clear particle reader variables
  m_MuonReader.Reset();
  m_PhotonReader.Reset();
  m_JetReader.Reset();
  m_TruthReader.Reset();

  // loop through the truth particles
  TruthMuons = m_TruthReader.getTruthMuons();

  if (TruthMuons.size() != 2) throw SError( SError::SkipEvent );

  Muon *truthmuon1 = TruthMuons.at(0);
  Muon *truthmuon2 = TruthMuons.at(1);
  
  // clear and (re)set all objects used in the event analysis
  // --
  float pileupEventWeight(-1.0);
  float evtweight(1);
   
  // loop over muons and get the ones I need
  if(m_mu_index->size() != 2) {
      m_logger << INFO << "mu_index->size() != 2!" << SLogger::endmsg;
      throw SError( SError::SkipEvent );
  }

  Muon *muon1 = m_MuonReader.getMuon(m_EventNumber, m_mu_index->at(0));
  Muon *muon2 = m_MuonReader.getMuon(m_EventNumber, m_mu_index->at(1));
  Muon *antimuon = 0;
  Muon *muon     = 0;
  if(muon1->Charge > 0) {
      antimuon = muon1;
      muon     = muon2;
  }
  else{
      antimuon = muon2;
      muon     = muon1;
  }

  // loop over the photons and get the ones I need
  if(m_ph_index->size() != 1) {
      m_logger << INFO << "ph_index->size() != 1!" << SLogger::endmsg;
      throw SError( SError::SkipEvent );
  }
      
  Photon *photon = m_PhotonReader.getPhoton(m_EventNumber, m_ph_index->at(0));

  // calculate pileup weight
  int isGoodWeight = m_tPileUp->getPileupWeight(m_lbn, pileupEventWeight);
  if( pileupEventWeight == -1.0) pileupEventWeight = 0;

  // get event weight
  evtweight = (m_mcevt_weight->at(0)).at(0);

  // calculations and histograms
  
  TLorentzVector z4vector = *muon + *antimuon;

  //------z mass histograms------//
  Book(TH1F("zmasstotal", "Invariant Mass of the Z Boson;m_{#mu#mu} [GeV];number of events / 1 GeV", 165, 35, 200))->Fill(m_Zmass); // includes FSR

  //------Remove FSR------//
  TLorentzVector mmg4vec = *muon + *antimuon + *photon;
  float M3 = mmg4vec.M()/1000.;

  // scatter plot 
  Book(TH2F("massplot", "m_{#mu#mu#gamma} vs. m_{#mu#mu};m_{#mu#mu};m_{#mu#mu#gamma}", 270, 35, 305, 270, 35, 305))->Fill(m_Zmass, M3); 
  
  if( M3 >= 110. ) {
    Book(TH1F("zmass", "Invariant Mass of the Z Boson;m_{#mu#mu} [GeV];number of events / 1 GeV", 165, 35, 120))->Fill(m_Zmass, evtweight*pileupEventWeight);       // no FSR
    Book(TH1F("3mass","Three Body Invariant Mass;m_{#mu#mu#gamma} [GeV];number of events / 1 GeV", 270, 35, 305))->Fill(M3);         // three body invariant mass
  
    //-----photon histograms-----//
    Book(TH1F("photonmomentum", "Photon P_{T} Distribution;P_{T} [GeV];number of events / 1 GeV", 120, 0, 120))->Fill(photon->etCluster/1000.);
    Book(TH1F("photoneta", "Photon #eta Distribution;#eta;Events", 30, -1.5, 1.5))->Fill(photon->etaCluster);
    Book(TH1F("photonphi", "Photon #phi Distribution;#phi;Events", 70, -3.5, 3.5))->Fill(photon->phiCluster);
  
    //------muon histograms------//  
    Book(TH1F("mumomentum", "Muon P_{T} Distribution;P_{T} [GeV];Events", 100, 0, 100))->Fill(muon->Pt/1000.);           // pt distribution
    Book(TH1F("amumomentum", "Muon P_{T} Distribution;P_{T} [GeV];Events", 100, 0, 100))->Fill(antimuon->Pt/1000.);           
    Book(TH1F("muoneta", "Muon #eta Distribution;#eta;Events", 50, -2.5, 2.5))->Fill(muon->Eta); // eta distribution
    Book(TH1F("amuoneta", "Muon #eta Distribution;#eta;Events", 50, -2.5, 2.5))->Fill(antimuon->Eta);
    Book(TH1F("muonphi", "Muon #phi Distribution;#phi;Events", 70, -3.5, 3.5))->Fill(muon->Phi); // phi distribution
    Book(TH1F("amuonphi", "Muon #phi Distribution;#phi;Events", 70, -3.5, 3.5))->Fill(antimuon->Phi);
    
    //-----polarization study-----//
    
    Book(TH1F("labcostheta", "Cos(#theta);Cos(#theta);Events", 220, -1.1, 1.1))->Fill(muon->CosTheta());
    Book(TH1F("alabcostheta", "Cos(#theta);Cos(#theta);Events", 220, -1, 1))->Fill(antimuon->CosTheta());
    
    // transform the particles into the qqbar frame 
    AnalysisUtils::cmTransformation(*muon, mmg4vec);
    AnalysisUtils::cmTransformation(*antimuon, mmg4vec);
    AnalysisUtils::cmTransformation(z4vector, mmg4vec);
    AnalysisUtils::cmTransformation(mmg4vec, mmg4vec);
    Book(TH1F("qqbarCMEnergy", "Center of Mass Energy of the q#bar{q} System;E_{CM}(#mu#mu#gamma) [GeV];number of events/1 GeV", 250, 100, 350))->Fill(mmg4vec.E()/1000.0);
    Book(TH1F("qqbarcostheta", "Cos(#theta);Cos(#theta);Events", 220, -1.1, 1.1))->Fill(muon->CosTheta());
    Book(TH1F("aqqbarcostheta", "Cos(#theta);Cos(#theta);Events", 220, -1, 1))->Fill(antimuon->CosTheta());

    // rotate the vectors so that the z direction is the Z boson direction
    AnalysisUtils::cmRotation(*muon, z4vector);
    AnalysisUtils::cmRotation(*antimuon, z4vector);
    Book(TH1F("zcostheta", "Cos(#theta);Cos(#theta);Events", 220, -1.1, 1.1))->Fill(muon->CosTheta());
    Book(TH1F("azcostheta", "Cos(#theta);Cos(#theta);Events", 220, -1.1, 1.1))->Fill(antimuon->CosTheta());
    
    // transform the Z cm frame
    AnalysisUtils::cmBoost(*muon, z4vector);
    AnalysisUtils::cmBoost(*antimuon, z4vector);
    AnalysisUtils::cmTransformation(z4vector, z4vector);
    Book(TH1F("costheta", "Cos(#theta*);Cos(#theta*);Events", 220, -1.1, 1.1))->Fill(muon->CosTheta());  
    Book(TH1F("acostheta", "Cos(#theta*);Cos(#theta*);Events", 220, -1.1, 1.1))->Fill(antimuon->CosTheta());
  }
  else 
    Book(TH1F("zmassFSR", "Invariant Mass of the Z Boson;m_{#mu#mu} [GeV];number of events/1 GeV", 24, 35, 120))->Fill(m_Zmass); // includes FSR
  

  m_logger << DEBUG << "Event passed.  Copying variables to output tree." << SLogger::endmsg;

  // copy output variables to the output tree
  COPYVAR
    ;

  m_MuonReader.CopyToOutput();
  m_PhotonReader.CopyToOutput();
  m_JetReader.CopyToOutput();

  o_muonIndex.push_back(muon->Index);
  o_muonIndex.push_back(antimuon->Index);
  o_photonIndex.push_back(photon->Index);

  return;
}

// Section: Cut Flow Logging {{{1
void MCAnalysisCycle::EndMasterInputData( const SInputData& ) throw( SError ) {
    m_logger << INFO << "End of input data." << SLogger::endmsg;
    delete m_tPileUp;
    m_tPileUp = 0;
    return;
}

