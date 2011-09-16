// $Id: dukheputils.py 163843 2011-05-27 18:22:01Z ayana $

// base class definition (Makefile.common must have ../ in include path):
#include "../include/DataAnalysisCycle.h"

// Root include(s)
#include "TVector2.h"
#include "TMath.h"

// STL include(s)
#include <algorithm>
#include <iostream>

using AnalysisUtils::dR;

ClassImp( DataAnalysisCycle );

// Section: Constructor/Destructor Definitions {{{1

DataAnalysisCycle::DataAnalysisCycle()
  : DukHepFilter(),
    // Macro initializing the stl vectors that access the tree
    INIT_NULLS_CTOR,
    m_Zmass(0), m_mu_index(0), m_ph_index(0),
    m_MuonReader(this, "mu"), 
    m_PhotonReader(this), 
    m_JetReader(this, "jet") // for some data it is jet_AntiKt4TopoEM or jet_akt4topoem
{   
  DeclareProperty( "IgnoreGRL", m_prop_skipgrl );
  SetLogName( GetName() );
}

DataAnalysisCycle::~DataAnalysisCycle() {}

// Section: Data/File Setup {{{1
// BeginCycle()
void DataAnalysisCycle::BeginCycle() throw( SError ) {   
    DukHepFilter::setupGRL();
    return; 
}

// EndCycle()
void DataAnalysisCycle::EndCycle() throw( SError ) {  return; }


// BeginInputData()
void DataAnalysisCycle::BeginInputData( const SInputData& ) throw( SError ) {
  // say something for debugging
  m_logger << DEBUG << "Hello from BeginInputData." << SLogger::endmsg;
  
  
  //This declares the variables that go in the output tree
  m_MuonReader.DeclareVariables();
  m_PhotonReader.DeclareVariables();
  m_JetReader.DeclareVariables();
  DeclareVariable(o_muonIndex, "mu_index");
  DeclareVariable(o_photonIndex, "ph_index");
  DECLARE("zgmumuSkimmed")
    ;
   
  return;
}

// EndInputData()
void DataAnalysisCycle::EndInputData( const SInputData& ) throw( SError ) {   return; }

  
// BeginInputFile()
void DataAnalysisCycle::BeginInputFile( const SInputData& inputData) throw( SError ) {
  int intype = STree::INPUT_TREE & STree::EVENT_TREE;
  if (! inputData.GetTrees(intype) ) {
      m_logger << ERROR << "DataAnalysisCycle needs an input tree!" << SLogger::endmsg;
      throw SError( SError::SkipCycle );
  }
  else if (inputData.GetTrees(intype)->size() != 1) {
      m_logger << ERROR << "DataAnalysisCycle got too many (" << inputData.GetTrees(intype)->size() << ")input trees." << SLogger::endmsg;
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
  ConnectVariable( treename.Data(), "Zmass", m_Zmass);
  ConnectVariable( treename.Data(), "mu_index", m_mu_index);
  ConnectVariable( treename.Data(), "ph_index", m_ph_index);
  }
  
  return;
}

// Section: Event Execution {{{1
void DataAnalysisCycle::ExecuteEvent( const SInputData &inputData, Double_t ) throw( SError ) {
   
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

  // calculations and histograms
  
  TLorentzVector z4vector = *muon1 + *muon2;

  //------z mass histograms------//
  Book(TH1F("zmasstotal", "Invariant Mass of the Z Boson;m_{#mu#mu} [GeV];number of events / 1 GeV", 165, 35, 200))->Fill(m_Zmass); // includes FSR

  //------Remove FSR------//
  TLorentzVector mmg4vec = *muon1 + *muon2 + *photon;
  float M3 = mmg4vec.M()/1000.;

  // scatter plot 
  Book(TH2F("massplot", "m_{#mu#mu#gamma} vs. m_{#mu#mu};m_{#mu#mu};m_{#mu#mu#gamma}", 270, 35, 305, 270, 35, 305))->Fill(m_Zmass, M3); 
  
  if( M3 >= 110. ) {
    Book(TH1F("zmass", "Invariant Mass of the Z Boson;m_{#mu#mu} [GeV];number of events / 1 GeV", 90, 30, 120))->Fill(m_Zmass);       // no FSR
    Book(TH1F("3mass","Three Body Invariant Mass;m_{#mu#mu#gamma} [GeV];number of events / 1 GeV", 270, 35, 305))->Fill(M3);         // three body invariant mass
  
    //-----photon histograms-----//
    Book(TH1F("photonmomentum", "Photon P_{T} Distribution;P_{T} [GeV];number of events / 1 GeV", 120, 0, 120))->Fill(photon->etCluster/1000.);
    Book(TH1F("photoneta", "Photon #eta Distribution;#eta;Events", 30, -1.5, 1.5))->Fill(photon->etaCluster);
    Book(TH1F("photonphi", "Photon #phi Distribution;#phi;Events", 70, -3.5, 3.5))->Fill(photon->phiCluster);
  
    //------muon histograms------//  
    Book(TH1F("mumomentum", "Muon P_{T} Distribution;P_{T} [GeV];Events", 100, 0, 100))->Fill(muon1->Pt/1000.);           // pt distribution
    Book(TH1F("muoneta", "Muon #eta Distribution;#eta;Events", 50, -2.5, 2.5))->Fill(muon1->Eta); // eta distribution
    Book(TH1F("muonphi", "Muon #phi Distribution;#phi;Events", 70, -3.5, 3.5))->Fill(muon1->Phi); // phi distribution
    
    //-----polarization study-----//
    
    Book(TH1F("labcostheta", "Cos(#theta);Cos(#theta);Events", 100, -1, 1))->Fill(muon1->CosTheta());
    
    // transform the particles into the qqbar frame 
    AnalysisUtils::cmTransformation(*muon1, mmg4vec);
    AnalysisUtils::cmTransformation(*muon2, mmg4vec);
    AnalysisUtils::cmTransformation(z4vector, mmg4vec);
    Book(TH1F("zmomentum","Momentum of the Z Boson;P^{Z} [GeV];number of events / 1 GeV", 150, 0, 150))->Fill((z4vector.Vect()).Mag()/1000.);
    Book(TH1F("zpt","Transverse Momentum of the Z Boson;P^{Z}_{T} [GeV];number of events / 1 GeV", 150, 0, 150))->Fill(z4vector.Pt()/1000.); 
    Book(TH1F("qqbarcostheta", "Cos(#theta);Cos(#theta);Events", 100, -1, 1))->Fill(muon1->CosTheta());

    // rotate the vectors so that the z direction is the Z boson direction
    AnalysisUtils::cmRotation(*muon1, z4vector);
    AnalysisUtils::cmRotation(*muon2, z4vector);
    Book(TH1F("zcostheta", "Cos(#theta);Cos(#theta);Events", 100, -1, 1))->Fill(muon1->CosTheta());
    
    // transform the Z cm frame
    AnalysisUtils::cmBoost(*muon1, z4vector);
    AnalysisUtils::cmBoost(*muon2, z4vector);
    AnalysisUtils::cmTransformation(z4vector, z4vector);
    Book(TH1F("cmzp", "Momentum of the Z in the CM Frame;P^{Z} [GeV];number of events / 1 GeV", 200, -1, 1))->Fill((z4vector.Vect()).Mag()/1000.);
    Book(TH1F("muondp", "Difference Between Muon P in CM Frame;|p_{#mu^{-}} - p_{#mu^{+}}| [GeV];number of events", 200, -1, 1))->Fill( (muon1->Vect()).Mag() - (muon2->Vect()).Mag() );
    Book(TH1F("costheta", "Cos(#theta*);Cos(#theta*);Events", 100, -1, 1))->Fill(muon1->CosTheta());  
    Float_t atheta1 = fabs(TVector2::Phi_mpi_pi(muon1->Theta()));
    Float_t atheta2 = fabs(TVector2::Phi_mpi_pi(muon2->Theta()));
    Float_t dtheta  = TMath::Pi() - (atheta1 + atheta2);
    Book(TH1F("dtheta", "#pi - #Delta#theta*;#pi - #Delta#theta*;Events", 200, -1, 1))->Fill(dtheta);
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

  o_muonIndex.push_back(muon1->Index);
  o_muonIndex.push_back(muon2->Index);
  o_photonIndex.push_back(photon->Index);

  return;
}

// Section: Cut Flow Logging {{{1
void DataAnalysisCycle::EndMasterInputData( const SInputData& ) throw( SError ) {
    m_logger << INFO << "End of input data." << SLogger::endmsg;
    return;
}

