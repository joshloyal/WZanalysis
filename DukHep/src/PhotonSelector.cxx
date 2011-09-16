//----------------------------------------------------------------------------------------------
//
// #Name: PhotonSelectorClass.cxx
// #Description: Defines the methods for the PhotonSelector class
//
// #Author: Joshua Loyal
// #Updated: 6/20/2011
//
//----------------------------------------------------------------------------------------------

// Analysis tools
#include "DukHep/include/AnalysisUtils.h"

// Photon include(s)
#include "DukHep/include/PhotonSelector.h"
#include "DukHep/include/Photon.h"
#include "DukHep/include/PhotonReader.h"

// utility include(s)
#include "DukHep/src/checkOQ.h"

using AnalysisUtils::dR;

// this method is run in the constructor to PhotonSelector
void PhotonSelector::initializeCutFlow() { 
    photonCutFlow.addCut(0,"no");
    photonCutFlow.addCut(1,"eta");
    photonCutFlow.addCut(2,"dR");
    photonCutFlow.addCut(3,"pt");
    photonCutFlow.addCut(4,"OTX");

    return;
}

// method that returns a vector with all the 'good' photons in the event
bool PhotonSelector::getGoodPhotons(photonIter aphoton, photonIter endPhoton, Muon *firstMuon, Muon *secondMuon, std::vector<Photon*> &outVec) {
    bool hasGoodPhotons; // boolean returned from the function

    // loop over the photons and place the good photons in a vector
    for( /* initialized in the function */ ;  aphoton != endPhoton; ++aphoton) {
        photonCutFlow.resetCutFlow();
        photonCutFlow.passCut();

        float aEta = fabs( (*aphoton)->etaCluster );
        if( (aEta >= Max_Eta) || ( (aEta >= Eta_CrackMin) && (aEta <= Eta_CrackMax) ) ) continue;
        photonCutFlow.passCut();
        
        if( (dR(firstMuon, *aphoton) <= Min_dR) || (dR(secondMuon, *aphoton) <= Min_dR) ) continue;
        photonCutFlow.passCut();
        
        // energy correction
        if( (*aphoton)->ptCluster <= Max_Et ) continue;
        photonCutFlow.passCut();
        
        unsigned int photonOTX = (*aphoton)->OQ & 34214;
        if( photonOTX != 0 ) continue;
        photonCutFlow.passCut();

        outVec.push_back(*aphoton);
    }

    hasGoodPhotons = !outVec.empty(); // check to see if the output vector is empty
    return hasGoodPhotons; 
}

bool PhotonSelector::getGoodPhotons(photonIter aphoton, photonIter endPhoton, muonIter amuon, muonIter endmuon, std::vector<Photon*> &outVec) {
    bool hasGoodPhotons; // boolean returned from the function

    // loop over the photons and place the good photons in a vector
    for( /* initialized in the function */ ;  aphoton != endPhoton; ++aphoton) {
        photonCutFlow.resetCutFlow();
        photonCutFlow.passCut();

        float aEta = fabs( (*aphoton)->etaCluster );
        if( (aEta >= Max_Eta) || ( (aEta >= Eta_CrackMin) && (aEta <= Eta_CrackMax) ) ) continue;
        photonCutFlow.passCut();
        
        (*aphoton)->checkIsolation(amuon, endmuon, Min_dR);
        if( !(*aphoton)->IsIsolated ) continue;
        photonCutFlow.passCut();
        
        // energy correction
        if( (*aphoton)->ptCluster <= Max_Et ) continue;
        photonCutFlow.passCut();
        
        unsigned int photonOTX = (*aphoton)->OQ & 34214;
        if( photonOTX != 0 ) continue;
        photonCutFlow.passCut();

        outVec.push_back(*aphoton);
    }

    hasGoodPhotons = !outVec.empty(); // check to see if the output vector is empty
    return hasGoodPhotons; 
}

bool PhotonSelector::getGoodPhotons(UInt_t RunNumber, photonIter aphoton, photonIter endPhoton, Muon *firstMuon, Muon *secondMuon, std::vector<Photon*> &outVec) {
    bool hasGoodPhotons; // boolean returned from the function

    // loop over the photons and place the good photons in a vector
    for( /* initialized in the function */ ;  aphoton != endPhoton; ++aphoton) {
        photonCutFlow.resetCutFlow();
        photonCutFlow.passCut();

        float aEta = fabs( (*aphoton)->etaCluster );
        if( (aEta >= Max_Eta) || ( (aEta >= Eta_CrackMin) && (aEta <= Eta_CrackMax) ) ) continue;
        photonCutFlow.passCut();
        
        if( (dR(firstMuon, *aphoton) <= Min_dR) || (dR(secondMuon, *aphoton) <= Min_dR) ) continue;
        photonCutFlow.passCut();
 
        // energy correction
        if( (*aphoton)->ptCluster <= Max_Et ) continue;
        photonCutFlow.passCut();
        
        egammaOQ myOQ;
        unsigned int OQ = myOQ.checkOQClusterPhoton(RunNumber, (*aphoton)->etaCluster, (*aphoton)->phiCluster, (*aphoton)->isConversion);
        if( OQ == 3 ) continue;

        unsigned int photonOTX = (*aphoton)->OQ & 34214;
        if( photonOTX != 0 ) continue;
        photonCutFlow.passCut();

        outVec.push_back(*aphoton);
    }

    hasGoodPhotons = !outVec.empty(); // check to see if the output vector is empty
    return hasGoodPhotons; 
}

bool PhotonSelector::getGoodPhotons(UInt_t RunNumber, photonIter aphoton, photonIter endPhoton, muonIter amuon, muonIter endmuon, std::vector<Photon*> &outVec) {
    bool hasGoodPhotons; // boolean returned from the function

    // loop over the photons and place the good photons in a vector
    for( /* initialized in the function */ ;  aphoton != endPhoton; ++aphoton) {
        photonCutFlow.resetCutFlow();
        photonCutFlow.passCut();

        float aEta = fabs( (*aphoton)->etaCluster );
        if( (aEta >= Max_Eta) || ( (aEta >= Eta_CrackMin) && (aEta <= Eta_CrackMax) ) ) continue;
        photonCutFlow.passCut();
        
        (*aphoton)->checkIsolation(amuon, endmuon, Min_dR);
        if( !(*aphoton)->IsIsolated ) continue;
        photonCutFlow.passCut();
        
        // energy correction
        if( (*aphoton)->ptCluster <= Max_Et ) continue;
        photonCutFlow.passCut();
        
        egammaOQ myOQ;
        unsigned int OQ = myOQ.checkOQClusterPhoton(RunNumber, (*aphoton)->etaCluster, (*aphoton)->phiCluster, (*aphoton)->isConversion);
        if( OQ == 3 ) continue;

        unsigned int photonOTX = (*aphoton)->OQ & 34214;
        if( photonOTX != 0 ) continue;
        photonCutFlow.passCut();

        outVec.push_back(*aphoton);
    }

    hasGoodPhotons = !outVec.empty(); // check to see if the output vector is empty
    return hasGoodPhotons; 
}

bool PhotonSelector::getTightPhotons(photonIter aphoton, photonIter endPhoton, std::vector<Photon*> &outVec) {
    bool hasTightPhotons; // boolean returned from the function

    // loop over photons and select the PhotonIDTool::Tight(6) photons
    for( /* initialized in the function */;  aphoton != endPhoton; ++aphoton) {
        if(! (*aphoton)->isTight()  ) continue;
        outVec.push_back(*aphoton);
    }

    hasTightPhotons = !outVec.empty(); // check to see if the output vector is empty
    return hasTightPhotons;
}

bool PhotonSelector::getIsolatedPhotons(photonIter aphoton, photonIter endphoton, const std::vector<int> *vxp_nTracks, std::vector<Photon*> &outVec, bool isMC) {
    bool hasIsolatedPhotons; // boolean returned from the function
    unsigned int nPV(0);     // variable to count the number of primary verticies in the event with at least 2 associated tracks

    // count the number of primary verticies in the event with at least 2 associated tracks
    for(unsigned int i = 0; i < vxp_nTracks->size(); i++) {
        if(vxp_nTracks->at(i) >= 2) nPV++;
    }

    // loop over the photons and select the isolated ones
    for( /* intialized in the funtion */ ; aphoton != endphoton; ++aphoton) {
        if( (*aphoton)->getConeCorrected(nPV, isMC) >= Min_Cone ) continue;
        outVec.push_back(*aphoton);
    }

    hasIsolatedPhotons = !outVec.empty(); // check to see if the output vector is empty
    return hasIsolatedPhotons;
}


