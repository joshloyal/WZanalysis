//-----------------------------------------------------------------------------------------------
//
// #Name: JetSelectorClass.cxx
// #Description: Defines the methods for the JetSelector class
//
// #Author: Joshua Loyal
// #Updated: 6/21/2011
//
//-----------------------------------------------------------------------------------------------

// Jet include(s)
#include "DukHep/include/JetSelector.h"
#include "DukHep/include/JetReader.h"

void JetSelector::initializeCutFlow() {
    jetCutFlow.addCut(0,"no");
    jetCutFlow.addCut(1,"negative energy");
    jetCutFlow.addCut(2,"pt");
    jetCutFlow.addCut(3,"object overlap");
}

bool JetSelector::getGoodJets(jetIter ajet, jetIter endJet, muonIter amuon, muonIter endmuon, photonIter aphoton, photonIter endphoton, std::vector<Jet*> &outVec) {
    bool hasGoodJets; // boolean returned by the function

    // loop over the photons and place the good photons in a vector
    for( /* initialized in the function */ ; ajet != endJet; ++ajet) {
        jetCutFlow.resetCutFlow();
        jetCutFlow.passCut();

        if( (*ajet)->E < 0. ) continue; // remove problematic jets
        jetCutFlow.passCut();

        // apply jet cuts
        if( (*ajet)->TLorentzVector::Pt() <= Min_Pt ) continue; // see if jet has pt(EM+JES) > 20 GeV
        jetCutFlow.passCut();

        // object overlap removal
        (*ajet)->checkIsolation(amuon, endmuon);
        (*ajet)->checkIsolation(aphoton, endphoton);
        if( !(*ajet)->IsIsolated ) continue;
        jetCutFlow.passCut();

        outVec.push_back(*ajet);
    }

    hasGoodJets = !outVec.empty(); // check if the returned vector is not empty
    return hasGoodJets;            // returns true if outVec is non-empty
}

bool JetSelector::isBadUglyJets(jetIter ajet, jetIter endjet) {
    // loop over the jets and check isBadLoose and isUgly
    for( /*initialized in function*/ ; ajet != endjet; ++ajet ) {
        if( ( (*ajet)->isBadLoose() ) || ( (*ajet)->IsUgly ) ) return true;
    }
    return false;
}
