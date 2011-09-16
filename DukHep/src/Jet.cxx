//-----------------------------------------------------------------------------------------------
//
// #Name: JetClass.cxx
// #Description: Source file for the Jet class. Contains a few methods that calculate
//               properties of the jets.
//
// #Author: Joshua Loyal
// #Updated: 6/21/2011
//
//-----------------------------------------------------------------------------------------------

// JetID include(s)
#include "DukHep/include/JetID_v2.0.h"

// class include(s)
#include "DukHep/include/Jet.h"

// utility include(s)
#include "DukHep/include/AnalysisUtils.h"

using AnalysisUtils::dR;

bool Jet::isBadLoose() const {
      // calculate parameter using JetID function.
      bool Jet_IsBad_Loose = JetID::isBadJet( JetID::LooseBad,
                                              Emfrac         ,  // electromagnetic fraction of the jet
                                              Hecf           ,  // energy fraction in the HEC
                                              LArQuality     ,  // jet quality is the fraction of LAr cells with a cell Q-factor greater than 4000. (See HowToCleanJets Twiki)
                                              HECQuality     ,  // Same as LArQuality, expect calculated only with HEC
                                              Timing         ,  // jet time computed as the energy squared cells mean time
                                              sumPtTrk/1000. ,  // what it sounds like...
                                              etaEmscale     ,  // eta at the emscale
                                              this->TLorentzVector::Pt()/1000.,  // ...
                                              fracSamplingMax,  // maximum energy fraction in one calorimeter layer
                                              NegativeE      ); // negative energy in the jet.

    return Jet_IsBad_Loose;
}

//------object overlap methods------//
void Jet::checkIsolation(std::vector<Muon*>::const_iterator amuon, std::vector<Muon*>::const_iterator endmuon) {
    // loop though the muon container
    for( /*initialized in the function*/ ; amuon != endmuon; ++amuon) {
        // check the eta-phi separation
        if( dR(this, *amuon) < 0.3 ) {
            IsIsolated = false;
            return;
        }
    }
    return;
}

void Jet::checkIsolation(std::vector<Photon*>::const_iterator aphoton, std::vector<Photon*>::const_iterator endphoton) {
    // loop through the photon container
    for( /*initialized in the function*/ ; aphoton != endphoton; ++aphoton) {
        // check the eta-phi separation
        if( dR(this, *aphoton) < 0.3 ) {
            IsIsolated = false;
            return;
        }
    }
    return;
}
