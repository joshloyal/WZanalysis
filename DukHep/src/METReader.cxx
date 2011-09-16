////../bin/dukhep_create_reader.py -n METReader METMacros.dat
#include "include/METReader.h"
#include <cmath>

// particle includes
#include "include/Photon.h"
#include "include/Muon.h"

METReader::METReader(SCycleBaseNTuple * ownr): owner(ownr),
m_MET_MuonBoy_phi(0),
m_MET_MuonBoy_et(0),
m_MET_MuonBoy_sumet(0),
m_MET_RefMuon_Track_phi(0),
m_MET_RefMuon_Track_et(0),
m_MET_RefMuon_Track_sumet(0),
m_MET_LocHadTopo_phi(0),
m_MET_LocHadTopo_et(0),
m_MET_LocHadTopo_sumet(0)
{}
void METReader::ConnectVariables(std::string treename){
  owner->ConnectVariable( treename.c_str(), VarName("MET_MuonBoy_phi").c_str(), m_MET_MuonBoy_phi );
  owner->ConnectVariable( treename.c_str(), VarName("MET_MuonBoy_et").c_str(), m_MET_MuonBoy_et );
  owner->ConnectVariable( treename.c_str(), VarName("MET_MuonBoy_sumet").c_str(), m_MET_MuonBoy_sumet );
  owner->ConnectVariable( treename.c_str(), VarName("MET_RefMuon_Track_phi").c_str(), m_MET_RefMuon_Track_phi );
  owner->ConnectVariable( treename.c_str(), VarName("MET_RefMuon_Track_et").c_str(), m_MET_RefMuon_Track_et );
  owner->ConnectVariable( treename.c_str(), VarName("MET_RefMuon_Track_sumet").c_str(), m_MET_RefMuon_Track_sumet );
  owner->ConnectVariable( treename.c_str(), VarName("MET_LocHadTopo_phi").c_str(), m_MET_LocHadTopo_phi );
  owner->ConnectVariable( treename.c_str(), VarName("MET_LocHadTopo_et").c_str(), m_MET_LocHadTopo_et );
  owner->ConnectVariable( treename.c_str(), VarName("MET_LocHadTopo_sumet").c_str(), m_MET_LocHadTopo_sumet );
}
void METReader::DeclareVariables(){
  owner->DeclareVariable( o_m_MET_MuonBoy_phi, "MET_MuonBoy_phi" );
  owner->DeclareVariable( o_m_MET_MuonBoy_et, "MET_MuonBoy_et" );
  owner->DeclareVariable( o_m_MET_MuonBoy_sumet, "MET_MuonBoy_sumet" );
  owner->DeclareVariable( o_m_MET_RefMuon_Track_phi, "MET_RefMuon_Track_phi" );
  owner->DeclareVariable( o_m_MET_RefMuon_Track_et, "MET_RefMuon_Track_et" );
  owner->DeclareVariable( o_m_MET_RefMuon_Track_sumet, "MET_RefMuon_Track_sumet" );
  owner->DeclareVariable( o_m_MET_LocHadTopo_phi, "MET_LocHadTopo_phi" );
  owner->DeclareVariable( o_m_MET_LocHadTopo_et, "MET_LocHadTopo_et" );
  owner->DeclareVariable( o_m_MET_LocHadTopo_sumet, "MET_LocHadTopo_sumet" );
}
void METReader::Reset(){
 o_m_MET_MuonBoy_phi= -999;
 o_m_MET_MuonBoy_et= -999;
 o_m_MET_MuonBoy_sumet= -999;
 o_m_MET_RefMuon_Track_phi= -999;
 o_m_MET_RefMuon_Track_et= -999;
 o_m_MET_RefMuon_Track_sumet= -999;
 o_m_MET_LocHadTopo_phi= -999;
 o_m_MET_LocHadTopo_et= -999;
 o_m_MET_LocHadTopo_sumet= -999;
  }
void METReader::CopyToOutput(){
 o_m_MET_MuonBoy_phi = m_MET_MuonBoy_phi;
 o_m_MET_MuonBoy_et = m_MET_MuonBoy_et;
 o_m_MET_MuonBoy_sumet = m_MET_MuonBoy_sumet;
 o_m_MET_RefMuon_Track_phi = m_MET_RefMuon_Track_phi;
 o_m_MET_RefMuon_Track_et = m_MET_RefMuon_Track_et;
 o_m_MET_RefMuon_Track_sumet = m_MET_RefMuon_Track_sumet;
 o_m_MET_LocHadTopo_phi = m_MET_LocHadTopo_phi;
 o_m_MET_LocHadTopo_et = m_MET_LocHadTopo_et;
 o_m_MET_LocHadTopo_sumet = m_MET_LocHadTopo_sumet;
  }

TLorentzVector METReader::getMuonMET(muonIter amuon, muonIter endmuon, photonIter aphoton, photonIter endphoton) {
    // initialize some variables needed for the calculation
    TLorentzVector MET;
    Float_t myMET_LocHadTopo_etx(0), myMET_LocHadTopo_ety(0);
    Float_t myMET_MuonBoy_etx(0), myMET_MuonBoy_ety(0);
    Float_t myMET_RefMuon_Track_etx(0), myMET_RefMuon_Track_ety(0);
    Float_t myStaco_EvtMETx(0), myStaco_EvtMETy(0), myStaco_EvtMET(0);

    // LocalHadTopo coordinate decomposition
    myMET_LocHadTopo_etx = m_MET_LocHadTopo_et*(std::cos(m_MET_LocHadTopo_phi)) - Muon::mu_dpx; 
    myMET_LocHadTopo_ety = m_MET_LocHadTopo_et*(std::sin(m_MET_LocHadTopo_phi)) - Muon::mu_dpy; 
    
    // MuonBoy coordinate decomposition
    myMET_MuonBoy_etx = m_MET_MuonBoy_et*(std::cos(m_MET_MuonBoy_phi)); 
    myMET_MuonBoy_ety = m_MET_MuonBoy_et*(std::sin(m_MET_MuonBoy_phi)); 
    
    // RefMuon_Track coordinate decomposition
    myMET_RefMuon_Track_etx = m_MET_RefMuon_Track_et*(std::cos(m_MET_RefMuon_Track_phi)); 
    myMET_RefMuon_Track_ety = m_MET_RefMuon_Track_et*(std::sin(m_MET_RefMuon_Track_phi)); 

    // sum LocHadTopo and MuonBoy and subtract off RefMuon_Track
    myStaco_EvtMETx = myMET_LocHadTopo_etx + myMET_MuonBoy_etx - myMET_RefMuon_Track_etx; 
    myStaco_EvtMETy = myMET_LocHadTopo_ety + myMET_MuonBoy_ety - myMET_RefMuon_Track_ety; 

    // loop over final selected muon candidates and apply correction
    for( /* initialized in function */ ; amuon != endmuon; ++amuon ) {
        Muon::mu_dpx += ( (*amuon)->TLorentzVector::Px() - (*amuon)->unCorrectedPx);
        Muon::mu_dpy += ( (*amuon)->TLorentzVector::Py() - (*amuon)->unCorrectedPy);
    }

    // loop over final selected photon candidates and apply correction
    for( /* initialised in function */ ; aphoton != endphoton; ++aphoton ) {
        Photon::ph_dpx += ( (*aphoton)->TLorentzVector::Px() - (*aphoton)->unCorrectedPx);
        Photon::ph_dpy += ( (*aphoton)->TLorentzVector::Py() - (*aphoton)->unCorrectedPy);
    }
    
    // apply correction to the components of the MET
    myStaco_EvtMETx -= ( Muon::mu_dpx + Photon::ph_dpx );
    myStaco_EvtMETy -= ( Muon::mu_dpy + Photon::ph_dpy );

    // add in quadrature to get MET
    myStaco_EvtMET  = std::sqrt( (myStaco_EvtMETx*myStaco_EvtMETx) + (myStaco_EvtMETy*myStaco_EvtMETy) );
    
    // set the four vector to the correct values
    MET.SetPxPyPzE(myStaco_EvtMETx, myStaco_EvtMETy, 0, myStaco_EvtMET);

    return MET;
}

