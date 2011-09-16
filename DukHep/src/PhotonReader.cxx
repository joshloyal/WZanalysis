////../bin/dukhep_create_reader.py -n PhotonReader PhotonReaderMacrosFilter.dat
#include "DukHep/include/PhotonReader.h"
#include <cmath>

PhotonReader::PhotonReader(SCycleBaseNTuple * ownr) : owner(ownr), isMC(false),
PhotonE(0),
PhotonEt(0),
PhotonPt(0),
PhotonEta(0),
PhotonPhi(0),
PhotonPx(0),
PhotonPy(0),
PhotonPz(0),
PhotonAuthor(0),
PhotonOQ(0),
PhotonIsConv(0),
PhotonEthad(0),
PhotonEthad1(0),
PhotonF1(0),
PhotonEmins1(0),
PhotonFside(0),
PhotonEmax2(0),
PhotonWs3(0),
PhotonWstot(0),
PhotonEmaxs1(0),
PhotonE233(0),
PhotonE237(0),
PhotonE277(0),
PhotonWeta2(0),
PhotonEtcone20(0),
PhotonEtcone40(0),
PhotonEtcone20_ptCorrected(0),
PhotonEtcone40_ptCorrected(0),
PhotonEtcone40_Corrected(0),
PhotonEtap(0),
PhotonClusterE(0),
PhotonClusterPt(0),
PhotonClusterEta(0),
PhotonClusterPhi(0),
PhotonEtas2(0),
NumberofPhotons(0)
{}

void PhotonReader::ConnectVariables(std::string treename){
  owner->ConnectVariable( treename.c_str(), VarName("ph_E").c_str(), PhotonE );
  owner->ConnectVariable( treename.c_str(), VarName("ph_Et").c_str(), PhotonEt );
  owner->ConnectVariable( treename.c_str(), VarName("ph_pt").c_str(), PhotonPt );
  owner->ConnectVariable( treename.c_str(), VarName("ph_eta").c_str(), PhotonEta );
  owner->ConnectVariable( treename.c_str(), VarName("ph_phi").c_str(), PhotonPhi );
  owner->ConnectVariable( treename.c_str(), VarName("ph_px").c_str(), PhotonPx );
  owner->ConnectVariable( treename.c_str(), VarName("ph_py").c_str(), PhotonPy );
  owner->ConnectVariable( treename.c_str(), VarName("ph_pz").c_str(), PhotonPz );
  owner->ConnectVariable( treename.c_str(), VarName("ph_author").c_str(), PhotonAuthor );
  owner->ConnectVariable( treename.c_str(), VarName("ph_OQ").c_str(), PhotonOQ );
  owner->ConnectVariable( treename.c_str(), VarName("ph_isConv").c_str(), PhotonIsConv );
  owner->ConnectVariable( treename.c_str(), VarName("ph_Ethad").c_str(), PhotonEthad );
  owner->ConnectVariable( treename.c_str(), VarName("ph_Ethad1").c_str(), PhotonEthad1 );
  owner->ConnectVariable( treename.c_str(), VarName("ph_f1").c_str(), PhotonF1 );
  owner->ConnectVariable( treename.c_str(), VarName("ph_Emins1").c_str(), PhotonEmins1 );
  owner->ConnectVariable( treename.c_str(), VarName("ph_fside").c_str(), PhotonFside );
  owner->ConnectVariable( treename.c_str(), VarName("ph_Emax2").c_str(), PhotonEmax2 );
  owner->ConnectVariable( treename.c_str(), VarName("ph_ws3").c_str(), PhotonWs3 );
  owner->ConnectVariable( treename.c_str(), VarName("ph_wstot").c_str(), PhotonWstot );
  owner->ConnectVariable( treename.c_str(), VarName("ph_emaxs1").c_str(), PhotonEmaxs1 );
  owner->ConnectVariable( treename.c_str(), VarName("ph_E233").c_str(), PhotonE233 );
  owner->ConnectVariable( treename.c_str(), VarName("ph_E237").c_str(), PhotonE237 );
  owner->ConnectVariable( treename.c_str(), VarName("ph_E277").c_str(), PhotonE277 );
  owner->ConnectVariable( treename.c_str(), VarName("ph_weta2").c_str(), PhotonWeta2 );
  owner->ConnectVariable( treename.c_str(), VarName("ph_Etcone20").c_str(), PhotonEtcone20 );
  owner->ConnectVariable( treename.c_str(), VarName("ph_Etcone40").c_str(), PhotonEtcone40 ); 
  owner->ConnectVariable( treename.c_str(), VarName("ph_Etcone20_pt_corrected").c_str(), PhotonEtcone20_ptCorrected );
  owner->ConnectVariable( treename.c_str(), VarName("ph_Etcone40_pt_corrected").c_str(), PhotonEtcone40_ptCorrected );
  owner->ConnectVariable( treename.c_str(), VarName("ph_Etcone40_corrected").c_str(), PhotonEtcone40_Corrected );
  owner->ConnectVariable( treename.c_str(), VarName("ph_etap").c_str(), PhotonEtap );
  owner->ConnectVariable( treename.c_str(), VarName("ph_cl_E").c_str(), PhotonClusterE );
  owner->ConnectVariable( treename.c_str(), VarName("ph_cl_pt").c_str(), PhotonClusterPt );
  owner->ConnectVariable( treename.c_str(), VarName("ph_cl_eta").c_str(), PhotonClusterEta );
  owner->ConnectVariable( treename.c_str(), VarName("ph_cl_phi").c_str(), PhotonClusterPhi );
  owner->ConnectVariable( treename.c_str(), VarName("ph_etas2").c_str(), PhotonEtas2 );
  owner->ConnectVariable( treename.c_str(), VarName("ph_n").c_str(), NumberofPhotons );
}
void PhotonReader::DeclareVariables(){
  owner->DeclareVariable( o_PhotonE, "ph_E" );
  owner->DeclareVariable( o_PhotonEt, "ph_Et" );
  owner->DeclareVariable( o_PhotonPt, "ph_pt" );
  owner->DeclareVariable( o_PhotonEta, "ph_eta" );
  owner->DeclareVariable( o_PhotonPhi, "ph_phi" );
  owner->DeclareVariable( o_PhotonPx, "ph_px" );
  owner->DeclareVariable( o_PhotonPy, "ph_py" );
  owner->DeclareVariable( o_PhotonPz, "ph_pz" );
  owner->DeclareVariable( o_PhotonAuthor, "ph_author" );
  owner->DeclareVariable( o_PhotonOQ, "ph_OQ" );
  owner->DeclareVariable( o_PhotonIsConv, "ph_isConv" );
  owner->DeclareVariable( o_PhotonEthad, "ph_Ethad" );
  owner->DeclareVariable( o_PhotonEthad1, "ph_Ethad1" );
  owner->DeclareVariable( o_PhotonF1, "ph_f1" );
  owner->DeclareVariable( o_PhotonEmins1, "ph_Emins1" );
  owner->DeclareVariable( o_PhotonFside, "ph_fside" );
  owner->DeclareVariable( o_PhotonEmax2, "ph_Emax2" );
  owner->DeclareVariable( o_PhotonWs3, "ph_ws3" );
  owner->DeclareVariable( o_PhotonWstot, "ph_wstot" );
  owner->DeclareVariable( o_PhotonEmaxs1, "ph_emaxs1" );
  owner->DeclareVariable( o_PhotonE233, "ph_E233" );
  owner->DeclareVariable( o_PhotonE237, "ph_E237" );
  owner->DeclareVariable( o_PhotonE277, "ph_E277" );
  owner->DeclareVariable( o_PhotonWeta2, "ph_weta2" );
  owner->DeclareVariable( o_PhotonEtcone20, "ph_Etcone20" );
  owner->DeclareVariable( o_PhotonEtcone40, "ph_Etcone40" );
  owner->DeclareVariable( o_PhotonEtcone20_ptCorrected, "ph_Etcone20_pt_corrected" );
  owner->DeclareVariable( o_PhotonEtcone40_ptCorrected, "ph_Etcone40_pt_corrected" );
  owner->DeclareVariable( o_PhotonEtcone40_Corrected, "ph_Etcone40_corrected" );
  owner->DeclareVariable( o_PhotonEtap, "ph_etap" );
  owner->DeclareVariable( o_PhotonClusterE, "ph_cl_E" );
  owner->DeclareVariable( o_PhotonClusterPt, "ph_cl_pt" );
  owner->DeclareVariable( o_PhotonClusterEta, "ph_cl_eta" );
  owner->DeclareVariable( o_PhotonClusterPhi, "ph_cl_phi" );
  owner->DeclareVariable( o_PhotonEtas2, "ph_etas2" );
  owner->DeclareVariable( o_NumberofPhotons, "ph_n" );
}

void PhotonReader::Reset(){
 o_PhotonE.clear();
 o_PhotonEt.clear();
 o_PhotonPt.clear();
 o_PhotonEta.clear();
 o_PhotonPhi.clear();
 o_PhotonPx.clear();
 o_PhotonPy.clear();
 o_PhotonPz.clear();
 o_PhotonAuthor.clear();
 o_PhotonOQ.clear();
 o_PhotonIsConv.clear();
 o_PhotonEthad.clear();
 o_PhotonEthad1.clear();
 o_PhotonF1.clear();
 o_PhotonEmins1.clear();
 o_PhotonFside.clear();
 o_PhotonEmax2.clear();
 o_PhotonWs3.clear();
 o_PhotonWstot.clear();
 o_PhotonEmaxs1.clear();
 o_PhotonE233.clear();
 o_PhotonE237.clear();
 o_PhotonE277.clear();
 o_PhotonWeta2.clear();
 o_PhotonEtcone20.clear();
 o_PhotonEtcone40.clear();
 o_PhotonEtcone20_ptCorrected.clear();
 o_PhotonEtcone40_ptCorrected.clear();
 o_PhotonEtcone40_Corrected.clear();
 o_PhotonEtap.clear();
 o_PhotonClusterE.clear();
 o_PhotonClusterPt.clear();
 o_PhotonClusterEta.clear();
 o_PhotonClusterPhi.clear();
 o_PhotonEtas2.clear();
 o_NumberofPhotons= -999;
  }

void PhotonReader::CopyToOutput(){
 o_PhotonE = std::vector<float>(*PhotonE);
 o_PhotonEt = std::vector<float>(*PhotonEt);
 o_PhotonPt = std::vector<float>(*PhotonPt);
 o_PhotonEta = std::vector<float>(*PhotonEta);
 o_PhotonPhi = std::vector<float>(*PhotonPhi);
 o_PhotonPx = std::vector<float>(*PhotonPx);
 o_PhotonPy = std::vector<float>(*PhotonPy);
 o_PhotonPz = std::vector<float>(*PhotonPz);
 o_PhotonAuthor = std::vector<int>(*PhotonAuthor);
 o_PhotonOQ = std::vector<unsigned int>(*PhotonOQ);
 o_PhotonIsConv = std::vector<int>(*PhotonIsConv);
 o_PhotonEthad = std::vector<float>(*PhotonEthad);
 o_PhotonEthad1 = std::vector<float>(*PhotonEthad1);
 o_PhotonF1 = std::vector<float>(*PhotonF1);
 o_PhotonEmins1 = std::vector<float>(*PhotonEmins1);
 o_PhotonFside = std::vector<float>(*PhotonFside);
 o_PhotonEmax2 = std::vector<float>(*PhotonEmax2);
 o_PhotonWs3 = std::vector<float>(*PhotonWs3);
 o_PhotonWstot = std::vector<float>(*PhotonWstot);
 o_PhotonEmaxs1 = std::vector<float>(*PhotonEmaxs1);
 o_PhotonE233 = std::vector<float>(*PhotonE233);
 o_PhotonE237 = std::vector<float>(*PhotonE237);
 o_PhotonE277 = std::vector<float>(*PhotonE277);
 o_PhotonWeta2 = std::vector<float>(*PhotonWeta2);
 o_PhotonEtcone20 = std::vector<float>(*PhotonEtcone20);
 o_PhotonEtcone40 = std::vector<float>(*PhotonEtcone40);
 o_PhotonEtcone20_ptCorrected = std::vector<float>(*PhotonEtcone20_ptCorrected);
 o_PhotonEtcone40_ptCorrected = std::vector<float>(*PhotonEtcone40_ptCorrected);
 o_PhotonEtcone40_Corrected = std::vector<float>(*PhotonEtcone40_Corrected);
 o_PhotonEtap = std::vector<float>(*PhotonEtap);
 o_PhotonClusterE = std::vector<float>(*PhotonClusterE);
 o_PhotonClusterPt = std::vector<float>(*PhotonClusterPt);
 o_PhotonClusterEta = std::vector<float>(*PhotonClusterEta);
 o_PhotonClusterPhi = std::vector<float>(*PhotonClusterPhi);
 o_PhotonEtas2 = std::vector<float>(*PhotonEtas2);
 o_NumberofPhotons = NumberofPhotons;
  }

void PhotonReader::getPhotons(std::vector<Photon*> &photonVec, Int_t EventNumber) {
    // loop over all the photons and place them in photonVec (notice the reference!)
    for( int i = 0; i < NumberofPhotons; i++) {
        
        // calulate the different et variables
        float photon_et     = std::cosh(PhotonEta->at(i)) != 0. ? PhotonE->at(i)/std::cosh(PhotonEta->at(i)) : 0.;
        float photon_cl_et  = std::cosh(PhotonClusterEta->at(i)) != 0. ? PhotonClusterE->at(i)/std::cosh(PhotonClusterEta->at(i)) : 0.;
        float photon_sh_et  = std::cosh(PhotonEtas2->at(i)) != 0. ? PhotonClusterE->at(i)/std::cosh(PhotonEtas2->at(i)) : 0.; 

        Photon *photon = new Photon(photon_cl_et, PhotonClusterEta->at(i), PhotonClusterPhi->at(i), PhotonClusterE->at(i));


        photon->E       = PhotonE->at(i);
        photon->Pt      = PhotonPt->at(i);
        photon->Et      = photon_et;
        photon->Eta     = PhotonEta->at(i);
        photon->Phi     = PhotonPhi->at(i);
        photon->Px      = PhotonPx->at(i);
        photon->Py      = PhotonPy->at(i);
        photon->Pz      = PhotonPz->at(i);
        photon->Author  = PhotonAuthor->at(i);
        photon->OQ      = PhotonOQ->at(i);
        photon->isConversion        = PhotonIsConv->at(i);
        photon->Etas2       = PhotonEtas2->at(i);
        photon->Ethad       = PhotonEthad->at(i);
        photon->Ethad1      = PhotonEthad1->at(i);
        photon->E277        = PhotonE277->at(i);
        photon->E237        = PhotonE237->at(i);
        photon->E233        = PhotonE233->at(i);
        photon->Weta2       = PhotonWeta2->at(i);
        photon->F1          = PhotonF1->at(i);
        photon->Emaxs1      = PhotonEmaxs1->at(i);
        photon->Emax2       = PhotonEmax2->at(i);
        photon->Emins1      = PhotonEmins1->at(i);
        photon->Fside       = PhotonFside->at(i);
        photon->Wstot       = PhotonWstot->at(i);
        photon->Ws3         = PhotonWs3->at(i);
        photon->eCluster        = PhotonClusterE->at(i);
        photon->etCluster       = photon_cl_et;
        photon->ptCluster       = photon_cl_et;
        photon->etaCluster      = PhotonClusterEta->at(i);
        photon->phiCluster      = PhotonClusterPhi->at(i);
        photon->etShower        = photon_sh_et;
        photon->etaPointing     = PhotonEtap->at(i);
        photon->etCone20        = PhotonEtcone20->at(i);
        photon->etCone40        = PhotonEtcone40->at(i);
        photon->etCone20_ptCorrected = PhotonEtcone20_ptCorrected->at(i);
        photon->etCone40_ptCorrected = PhotonEtcone40_ptCorrected->at(i);
        photon->etCone40_Corrected   = PhotonEtcone40_Corrected->at(i);
        photon->Index           = i;
        photon->unCorrectedPx   = photon->TLorentzVector::Px();
        photon->unCorrectedPy   = photon->TLorentzVector::Py();

        // correct photon energy
        if(isMC)  
            photon->CorrectEnergy(EventNumber, false); 
        else 
            photon->CorrectEnergy("UNCONVERTED_PHOTON");
            
            


        photonVec.push_back(photon);
    }
    return;
}

Photon* PhotonReader::getPhoton(Int_t EventNumber, Int_t i) { 
    // calulate the different et variables
    float photon_et     = std::cosh(PhotonEta->at(i)) != 0. ? PhotonE->at(i)/std::cosh(PhotonEta->at(i)) : 0.;
    float photon_cl_et  = std::cosh(PhotonClusterEta->at(i)) != 0. ? PhotonClusterE->at(i)/std::cosh(PhotonClusterEta->at(i)) : 0.;
    float photon_sh_et  = std::cosh(PhotonEtas2->at(i)) != 0. ? PhotonClusterE->at(i)/std::cosh(PhotonEtas2->at(i)) : 0.; 

    Photon *photon = new Photon(photon_cl_et, PhotonClusterEta->at(i), PhotonClusterPhi->at(i), PhotonClusterE->at(i));

    photon->E       = PhotonE->at(i);
    photon->Pt      = PhotonPt->at(i);
    photon->Et      = photon_et;
    photon->Eta     = PhotonEta->at(i);
    photon->Phi     = PhotonPhi->at(i);
    photon->Px      = PhotonPx->at(i);
    photon->Py      = PhotonPy->at(i);
    photon->Pz      = PhotonPz->at(i);
    photon->Author  = PhotonAuthor->at(i);
    photon->OQ      = PhotonOQ->at(i);
    photon->isConversion        = PhotonIsConv->at(i);
    photon->Etas2       = PhotonEtas2->at(i);
    photon->Ethad       = PhotonEthad->at(i);
    photon->Ethad1      = PhotonEthad1->at(i);
    photon->E277        = PhotonE277->at(i);
    photon->E237        = PhotonE237->at(i);
    photon->E233        = PhotonE233->at(i);
    photon->Weta2       = PhotonWeta2->at(i);
    photon->F1          = PhotonF1->at(i);
    photon->Emaxs1      = PhotonEmaxs1->at(i);
    photon->Emax2       = PhotonEmax2->at(i);
    photon->Emins1      = PhotonEmins1->at(i);
    photon->Fside       = PhotonFside->at(i);
    photon->Wstot       = PhotonWstot->at(i);
    photon->Ws3         = PhotonWs3->at(i);
    photon->eCluster        = PhotonClusterE->at(i);
    photon->etCluster       = photon_cl_et;
    photon->ptCluster       = photon_cl_et;
    photon->etaCluster      = PhotonClusterEta->at(i);
    photon->phiCluster      = PhotonClusterPhi->at(i);
    photon->etShower        = photon_sh_et;
    photon->etaPointing     = PhotonEtap->at(i);
    photon->etCone20        = PhotonEtcone20->at(i);
    photon->etCone40        = PhotonEtcone40->at(i);
    photon->etCone20_ptCorrected = PhotonEtcone20_ptCorrected->at(i);
    photon->etCone40_ptCorrected = PhotonEtcone40_ptCorrected->at(i);
    photon->etCone40_Corrected   = PhotonEtcone40_Corrected->at(i);
    photon->Index           = i;

    // correct photon energy
    if(isMC)  
        photon->CorrectEnergy(EventNumber, false); 
    else 
        photon->CorrectEnergy("UNCONVERTED_PHOTON");

    return photon;
}
