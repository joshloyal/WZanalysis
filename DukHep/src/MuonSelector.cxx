//--------------------------------------------------------------------------------------
//
// #Name: MuonSelectorClass.cxx
// #Description: Defines the methods for the MuonSelector class
//
// #Creator: Joshua Loyal
// #Updated: 06/20/2011
//
//---------------------------------------------------------------------------------------

// Muon include(s)
#include "DukHep/include/MuonSelector.h"
#include "DukHep/include/Muon.h"
#include "DukHep/include/MuonReader.h"

// This method is run in the constructor.
void MuonSelector::initializeCutFlow() {

    muonCutFlow.addCut(0, "before");
    muonCutFlow.addCut(1, "author");
    muonCutFlow.addCut(2, "combined");
    muonCutFlow.addCut(3, "pt");
    muonCutFlow.addCut(4, "BLayer");
    muonCutFlow.addCut(5, "Pixel");
    muonCutFlow.addCut(6, "SCT");
    muonCutFlow.addCut(7, "Holes");
    muonCutFlow.addCut(8, "TRT");
    muonCutFlow.addCut(9, "eta");
    muonCutFlow.addCut(10, "z0");
    muonCutFlow.addCut(11, "d0");
    muonCutFlow.addCut(12, "cone");

    return;
}

// returns a vector with all the 'good' muons in the event
void MuonSelector::getGoodMuons(muonIter amuon, muonIter endMuon, std::vector<Muon*> &outVec) {

    for( /* initalized in the function */ ; amuon != endMuon; ++amuon) {
        muonCutFlow.resetCutFlow();
        muonCutFlow.passCut();

        if( ( (*amuon)->Author != 1) && ( (*amuon)->Author != 6) ) continue;
        muonCutFlow.passCut();

        if( (*amuon)->IsCombined != 1 ) continue;
        muonCutFlow.passCut();

        if( (*amuon)->Pt <= Minimum_Pt ) continue;
        muonCutFlow.passCut();

        if( ((*amuon)->expectBLayerHit) && ((*amuon)->nBLHits <= 0) ) continue;
        muonCutFlow.passCut();

        if( ((*amuon)->nPixHits + (*amuon)->nPixelDeadSensors) <= 1 ) continue;
        muonCutFlow.passCut();

        if( ((*amuon)->nSCTHits + (*amuon)->nSCTDeadSensors) < 6 ) continue;
        muonCutFlow.passCut();

        if( ((*amuon)->nPixHoles + (*amuon)->nSCTHoles) >= 2) continue;
        muonCutFlow.passCut();
        
        double aEta = fabs((*amuon)->Eta);
        double n = (*amuon)->nTRTOutliers + (*amuon)->nTRTHits;
        if(aEta < 1.9) {
            if( (n <= 5) || ((*amuon)->nTRTOutliers >= 0.9*n) ) continue;
        }
        if( (aEta >= 1.9) && (n > 5) ) {
            if( (*amuon)->nTRTOutliers >= 0.9*n  ) continue;
        }
        muonCutFlow.passCut();

        if( aEta >= Max_Eta ) continue;
        muonCutFlow.passCut();

        if( fabs((*amuon)->InnerDetector_z0_exPV) >= Max_z0) continue;
        muonCutFlow.passCut();

        if( fabs((*amuon)->InnerDetector_d0_exPV) >= Max_d0*sqrt((*amuon)->InnerDetector_cov_d0_exPV) ) continue;
        muonCutFlow.passCut();

        if((*amuon)->PtCone20 >= Cone_dR*(*amuon)->Pt) continue;
        muonCutFlow.passCut();
        
        outVec.push_back(*amuon);
    }

    return;
}
    

