////../bin/dukhep_create_reader.py -n MuonReader MuonReaderMacros.dat
#include "DukHep/include/MuonReader.h"
#include <cmath>
#include <iostream>

MuonReader::MuonReader(SCycleBaseNTuple *ownr, const char *collname): owner(ownr), cname(collname), isMC(false),
MuonE(0),
MuonPt(0),
MuonMass(0),
MuonEta(0),
MuonPhi(0),
MuonPx(0),
MuonPy(0),
MuonPz(0),
MuonCharge(0),
MuonAuthor(0),
MuonEtCone20(0),
MuonPtCone20(0),
MuonIsCombined(0),
MuonTight(0),
MuonInnerD0exPV(0),
MuonInnerZ0exPV(0),
MuonInnerCovD0exPV(0),
MuonInnerCovZ0exPV(0),
MuonNumBLHits(0),
MuonNumPixHits(0),
MuonNumSCTHits(0),
MuonNumTRTHits(0),
MuonNumPixHoles(0),
MuonNumSCTHoles(0),
MuonNumTRTOutliers(0),
MuonNumPixelDeadSensors(0),
MuonNumSCTDeadSensors(0),
MuonExpectedBLayerHit(0),
MuonInnerQOverP(0),
MuonInnerPhi(0),
MuonInnerTheta(0),
MuonMEQOverP(0),
MuonMEPhi(0),
MuonMETheta(0),
NumberofMuons(0)
{
    std::cout << "MuonReader: Collection name is " << cname << std::endl;
}

void MuonReader::ConnectVariables(std::string treename){
  owner->ConnectVariable( treename.c_str(), VarName("mu_E").c_str(), MuonE );
  owner->ConnectVariable( treename.c_str(), VarName("mu_pt").c_str(), MuonPt );
  owner->ConnectVariable( treename.c_str(), VarName("mu_m").c_str(), MuonMass );
  owner->ConnectVariable( treename.c_str(), VarName("mu_eta").c_str(), MuonEta );
  owner->ConnectVariable( treename.c_str(), VarName("mu_phi").c_str(), MuonPhi );
  owner->ConnectVariable( treename.c_str(), VarName("mu_px").c_str(), MuonPx );
  owner->ConnectVariable( treename.c_str(), VarName("mu_py").c_str(), MuonPy );
  owner->ConnectVariable( treename.c_str(), VarName("mu_pz").c_str(), MuonPz );
  owner->ConnectVariable( treename.c_str(), VarName("mu_charge").c_str(), MuonCharge );
  owner->ConnectVariable( treename.c_str(), VarName("mu_author").c_str(), MuonAuthor );
  owner->ConnectVariable( treename.c_str(), VarName("mu_etcone20").c_str(), MuonEtCone20 );
  owner->ConnectVariable( treename.c_str(), VarName("mu_ptcone20").c_str(), MuonPtCone20 );
  owner->ConnectVariable( treename.c_str(), VarName("mu_isCombinedMuon").c_str(), MuonIsCombined );
  owner->ConnectVariable( treename.c_str(), VarName("mu_tight").c_str(), MuonTight );
  owner->ConnectVariable( treename.c_str(), VarName("mu_id_d0_exPV").c_str(), MuonInnerD0exPV );
  owner->ConnectVariable( treename.c_str(), VarName("mu_id_z0_exPV").c_str(), MuonInnerZ0exPV );
  owner->ConnectVariable( treename.c_str(), VarName("mu_id_cov_d0_exPV").c_str(), MuonInnerCovD0exPV );
  owner->ConnectVariable( treename.c_str(), VarName("mu_id_cov_z0_exPV").c_str(), MuonInnerCovZ0exPV );
  owner->ConnectVariable( treename.c_str(), VarName("mu_nBLHits").c_str(), MuonNumBLHits );
  owner->ConnectVariable( treename.c_str(), VarName("mu_nPixHits").c_str(), MuonNumPixHits );
  owner->ConnectVariable( treename.c_str(), VarName("mu_nSCTHits").c_str(), MuonNumSCTHits );
  owner->ConnectVariable( treename.c_str(), VarName("mu_nTRTHits").c_str(), MuonNumTRTHits );
  owner->ConnectVariable( treename.c_str(), VarName("mu_nPixHoles").c_str(), MuonNumPixHoles );
  owner->ConnectVariable( treename.c_str(), VarName("mu_nSCTHoles").c_str(), MuonNumSCTHoles );
  owner->ConnectVariable( treename.c_str(), VarName("mu_nTRTOutliers").c_str(), MuonNumTRTOutliers );
  owner->ConnectVariable( treename.c_str(), VarName("mu_nPixelDeadSensors").c_str(), MuonNumPixelDeadSensors );
  owner->ConnectVariable( treename.c_str(), VarName("mu_nSCTDeadSensors").c_str(), MuonNumSCTDeadSensors );
  owner->ConnectVariable( treename.c_str(), VarName("mu_expectBLayerHit").c_str(), MuonExpectedBLayerHit );
  
  if(isMC) { 
    owner->ConnectVariable( treename.c_str(), VarName("mu_id_qoverp").c_str(), MuonInnerQOverP );
    owner->ConnectVariable( treename.c_str(), VarName("mu_id_phi").c_str(), MuonInnerPhi );
    owner->ConnectVariable( treename.c_str(), VarName("mu_id_theta").c_str(), MuonInnerTheta );
    owner->ConnectVariable( treename.c_str(), VarName("mu_me_qoverp").c_str(), MuonMEQOverP );
    owner->ConnectVariable( treename.c_str(), VarName("mu_me_phi").c_str(), MuonMEPhi );
    owner->ConnectVariable( treename.c_str(), VarName("mu_me_theta").c_str(), MuonMETheta );
  }

  owner->ConnectVariable( treename.c_str(), VarName("mu_n").c_str(), NumberofMuons );
}

void MuonReader::DeclareVariables(){
  owner->DeclareVariable( o_MuonE, "mu_E" );
  owner->DeclareVariable( o_MuonPt, "mu_pt" );
  owner->DeclareVariable( o_MuonMass, "mu_m" );
  owner->DeclareVariable( o_MuonEta, "mu_eta" );
  owner->DeclareVariable( o_MuonPhi, "mu_phi" );
  owner->DeclareVariable( o_MuonPx, "mu_px" );
  owner->DeclareVariable( o_MuonPy, "mu_py" );
  owner->DeclareVariable( o_MuonPz, "mu_pz" );
  owner->DeclareVariable( o_MuonCharge, "mu_charge" );
  owner->DeclareVariable( o_MuonAuthor, "mu_author" );
  owner->DeclareVariable( o_MuonEtCone20, "mu_etcone20" );
  owner->DeclareVariable( o_MuonPtCone20, "mu_ptcone20" );
  owner->DeclareVariable( o_MuonIsCombined, "mu_isCombinedMuon" );
  owner->DeclareVariable( o_MuonTight, "mu_tight" );
  owner->DeclareVariable( o_MuonInnerD0exPV, "mu_id_d0_exPV" );
  owner->DeclareVariable( o_MuonInnerZ0exPV, "mu_id_z0_exPV" );
  owner->DeclareVariable( o_MuonInnerCovD0exPV, "mu_id_cov_d0_exPV" );
  owner->DeclareVariable( o_MuonInnerCovZ0exPV, "mu_id_cov_z0_exPV" );
  owner->DeclareVariable( o_MuonNumBLHits, "mu_nBLHits" );
  owner->DeclareVariable( o_MuonNumPixHits, "mu_nPixHits" );
  owner->DeclareVariable( o_MuonNumSCTHits, "mu_nSCTHits" );
  owner->DeclareVariable( o_MuonNumTRTHits, "mu_nTRTHits" );
  owner->DeclareVariable( o_MuonNumPixHoles, "mu_nPixHoles" );
  owner->DeclareVariable( o_MuonNumSCTHoles, "mu_nSCTHoles" );
  owner->DeclareVariable( o_MuonNumTRTOutliers, "mu_nTRTOutliers" );
  owner->DeclareVariable( o_MuonNumPixelDeadSensors, "mu_nPixelDeadSensors" );
  owner->DeclareVariable( o_MuonNumSCTDeadSensors, "mu_nSCTDeadSensors" );
  owner->DeclareVariable( o_MuonExpectedBLayerHit, "mu_expectBLayerHit" ); 
  owner->DeclareVariable( o_MuonInnerQOverP, "mu_id_qoverp" );
  owner->DeclareVariable( o_MuonInnerPhi, "mu_id_phi" );
  owner->DeclareVariable( o_MuonInnerTheta, "mu_id_theta" );
  owner->DeclareVariable( o_MuonMEQOverP, "mu_me_qoverp" );
  owner->DeclareVariable( o_MuonMEPhi, "mu_me_phi" );
  owner->DeclareVariable( o_MuonMETheta, "mu_me_theta" );
  owner->DeclareVariable( o_NumberofMuons, "mu_n" );
}

void MuonReader::Reset(){
 o_MuonE.clear();
 o_MuonPt.clear();
 o_MuonMass.clear();
 o_MuonEta.clear();
 o_MuonPhi.clear();
 o_MuonPx.clear();
 o_MuonPy.clear();
 o_MuonPz.clear();
 o_MuonCharge.clear();
 o_MuonAuthor.clear();
 o_MuonEtCone20.clear();
 o_MuonPtCone20.clear();
 o_MuonIsCombined.clear();
 o_MuonTight.clear();
 o_MuonInnerD0exPV.clear();
 o_MuonInnerZ0exPV.clear();
 o_MuonInnerCovD0exPV.clear();
 o_MuonInnerCovZ0exPV.clear();
 o_MuonNumBLHits.clear();
 o_MuonNumPixHits.clear();
 o_MuonNumSCTHits.clear();
 o_MuonNumTRTHits.clear();
 o_MuonNumPixHoles.clear();
 o_MuonNumSCTHoles.clear();
 o_MuonNumTRTOutliers.clear();
 o_MuonNumPixelDeadSensors.clear();
 o_MuonNumSCTDeadSensors.clear();
 o_MuonExpectedBLayerHit.clear();
 o_MuonInnerQOverP.clear();
 o_MuonInnerPhi.clear();
 o_MuonInnerTheta.clear();
 o_MuonMEQOverP.clear();
 o_MuonMEPhi.clear();
 o_MuonMETheta.clear();
 o_NumberofMuons= -999;
  }

void MuonReader::CopyToOutput(){
 o_MuonE = std::vector<float>(*MuonE);
 o_MuonPt = std::vector<float>(*MuonPt);
 o_MuonMass = std::vector<float>(*MuonMass);
 o_MuonEta = std::vector<float>(*MuonEta);
 o_MuonPhi = std::vector<float>(*MuonPhi);
 o_MuonPx = std::vector<float>(*MuonPx);
 o_MuonPy = std::vector<float>(*MuonPy);
 o_MuonPz = std::vector<float>(*MuonPz);
 o_MuonCharge = std::vector<float>(*MuonCharge);
 o_MuonAuthor = std::vector<int>(*MuonAuthor);
 o_MuonEtCone20 = std::vector<float>(*MuonEtCone20);
 o_MuonPtCone20 = std::vector<float>(*MuonPtCone20);
 o_MuonIsCombined = std::vector<int>(*MuonIsCombined);
 o_MuonTight = std::vector<int>(*MuonTight);
 o_MuonInnerD0exPV = std::vector<float>(*MuonInnerD0exPV);
 o_MuonInnerZ0exPV = std::vector<float>(*MuonInnerZ0exPV);
 o_MuonInnerCovD0exPV = std::vector<float>(*MuonInnerCovD0exPV);
 o_MuonInnerCovZ0exPV = std::vector<float>(*MuonInnerCovZ0exPV);
 o_MuonNumBLHits = std::vector<int>(*MuonNumBLHits);
 o_MuonNumPixHits = std::vector<int>(*MuonNumPixHits);
 o_MuonNumSCTHits = std::vector<int>(*MuonNumSCTHits);
 o_MuonNumTRTHits = std::vector<int>(*MuonNumTRTHits);
 o_MuonNumPixHoles = std::vector<int>(*MuonNumPixHoles);
 o_MuonNumSCTHoles = std::vector<int>(*MuonNumSCTHoles);
 o_MuonNumTRTOutliers = std::vector<int>(*MuonNumTRTOutliers);
 o_MuonNumPixelDeadSensors = std::vector<int>(*MuonNumPixelDeadSensors);
 o_MuonNumSCTDeadSensors = std::vector<int>(*MuonNumSCTDeadSensors);
 o_MuonExpectedBLayerHit = std::vector<int>(*MuonExpectedBLayerHit);
 
 if(isMC) {
    o_MuonInnerQOverP = std::vector<float>(*MuonInnerQOverP);
    o_MuonInnerPhi = std::vector<float>(*MuonInnerPhi);
    o_MuonInnerTheta = std::vector<float>(*MuonInnerTheta);
    o_MuonMEQOverP = std::vector<float>(*MuonMEQOverP);
    o_MuonMEPhi = std::vector<float>(*MuonMEPhi);
    o_MuonMETheta = std::vector<float>(*MuonMETheta);
 }

 o_NumberofMuons = NumberofMuons;
}

void MuonReader::getMuons(Int_t EventNumber, std::vector<Muon*> &muonVec) {
    // loop over all the muons and place them in muonVec (notice the reference!)
    for( int i = 0; i < NumberofMuons; i++) {

        Muon *muon = new Muon(MuonPt->at(i), MuonEta->at(i), MuonPhi->at(i), MuonE->at(i), MuonCharge->at(i));
        
        // set muon variables
        muon->Mass             = MuonMass->at(i);
        muon->Author        = MuonAuthor->at(i);
        muon->IsCombined    = MuonIsCombined->at(i);
        muon->EtCone20      = MuonEtCone20->at(i);
        
        muon->PtCone20          = MuonPtCone20->at(i);
        muon->Tight             = MuonTight->at(i);
        
        muon->InnerDetector_d0_exPV         = MuonInnerD0exPV->at(i);
        muon->InnerDetector_cov_d0_exPV     = MuonInnerCovD0exPV->at(i);
        muon->InnerDetector_z0_exPV         = MuonInnerZ0exPV->at(i);
        
        if(isMC) {
            muon->InnerQOverP       = MuonInnerQOverP->at(i);
            muon->InnerPhi          = MuonInnerPhi->at(i);
            muon->InnerTheta        = MuonInnerTheta->at(i);
            muon->InnerP            = (muon->Charge/muon->InnerQOverP);
            muon->InnerPt           = muon->InnerP * std::sin(muon->InnerTheta);

            muon->MSExtrapolatedQOverP      = MuonMEQOverP->at(i);
            muon->MSExtrapolatedPhi         = MuonMEPhi->at(i);
            muon->MSExtrapolatedTheta       = MuonMETheta->at(i);
            muon->MSExtrapolatedP           = (muon->Charge/muon->InnerQOverP);
            muon->MSExtrapolatedPt          = muon->MSExtrapolatedP * std::sin(muon->MSExtrapolatedTheta);
        }

        muon->expectBLayerHit   = MuonExpectedBLayerHit->at(i);
        muon->nBLHits           = MuonNumBLHits->at(i);
        muon->nPixHits          = MuonNumPixHits->at(i);
        muon->nPixelDeadSensors = MuonNumPixelDeadSensors->at(i);
        muon->nSCTHits          = MuonNumSCTHits->at(i);
        muon->nSCTDeadSensors   = MuonNumSCTDeadSensors->at(i);
        muon->nPixHoles         = MuonNumPixHoles->at(i);
        muon->nSCTHoles         = MuonNumSCTHoles->at(i);
        muon->nTRTOutliers      = MuonNumTRTOutliers->at(i);
        muon->nTRTHits          = MuonNumTRTHits->at(i);
        muon->Index             = i;
        muon->unCorrectedPx     = muon->TLorentzVector::Px();
        muon->unCorrectedPy     = muon->TLorentzVector::Py();
       
       if(isMC) {
            muon->SmearPt(EventNumber);
        }
        
        // place the muons in a vector
        muonVec.push_back(muon);
    
    }
    return;
}

Muon* MuonReader::getMuon(Int_t EventNumber, Int_t i) {

    Muon *muon = new Muon(MuonPt->at(i), MuonEta->at(i), MuonPhi->at(i), MuonE->at(i), MuonCharge->at(i));
        
    // set muon variables
    muon->Mass          = MuonMass->at(i);
    muon->Author        = MuonAuthor->at(i);
    muon->IsCombined    = MuonIsCombined->at(i);
    muon->EtCone20      = MuonEtCone20->at(i);
        
    muon->PtCone20          = MuonPtCone20->at(i);
    muon->Tight             = MuonTight->at(i);
        
    muon->InnerDetector_d0_exPV         = MuonInnerD0exPV->at(i);
    muon->InnerDetector_cov_d0_exPV     = MuonInnerCovD0exPV->at(i);
    muon->InnerDetector_z0_exPV         = MuonInnerZ0exPV->at(i);
        
    if(isMC) {
        muon->InnerQOverP       = MuonInnerQOverP->at(i);
        muon->InnerPhi          = MuonInnerPhi->at(i);
        muon->InnerTheta        = MuonInnerTheta->at(i);
        muon->InnerP            = (muon->Charge/muon->InnerQOverP);
        muon->InnerPt           = muon->InnerP * std::sin(muon->InnerTheta);

        muon->MSExtrapolatedQOverP      = MuonMEQOverP->at(i);
        muon->MSExtrapolatedPhi         = MuonMEPhi->at(i);
        muon->MSExtrapolatedTheta       = MuonMETheta->at(i);
        muon->MSExtrapolatedP           = (muon->Charge/muon->InnerQOverP);
        muon->MSExtrapolatedPt          = muon->MSExtrapolatedP * std::sin(muon->MSExtrapolatedTheta);
    }

    muon->expectBLayerHit   = MuonExpectedBLayerHit->at(i);
    muon->nBLHits           = MuonNumBLHits->at(i);
    muon->nPixHits          = MuonNumPixHits->at(i);
    muon->nPixelDeadSensors = MuonNumPixelDeadSensors->at(i);
    muon->nSCTHits          = MuonNumSCTHits->at(i);
    muon->nSCTDeadSensors   = MuonNumSCTDeadSensors->at(i);
    muon->nPixHoles         = MuonNumPixHoles->at(i);
    muon->nSCTHoles         = MuonNumSCTHoles->at(i);
    muon->nTRTOutliers      = MuonNumTRTOutliers->at(i);
    muon->nTRTHits          = MuonNumTRTHits->at(i);
    muon->Index             = i;
    
    if(isMC) {
        muon->SmearPt(EventNumber);
    }
    
    return muon;
}
