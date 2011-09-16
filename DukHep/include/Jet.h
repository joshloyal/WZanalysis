//----------------------------------------------------------------------------------------------
//
// #Name: JetClass.h
// #Description: This class is inherated from TLorentzVector. The purpose was to pass the jet 
//               information to this class, so as to make them easier to work with. It is
//               designed to act like a TLorentzVector with additional jet data.
// 
// #Author: Joshua Loyal
// #Updated: 6/21/2011
//
//----------------------------------------------------------------------------------------------

#ifndef JETCLASS_H
#define JETCLASS_H

// STL include(s)
#include <vector>

// Root include(s)
#include <TLorentzVector.h>

// particle include(s)
#include "Photon.h"
#include "Muon.h"

class Jet : public TLorentzVector {

    public:

    // constructor: The jets will be initialized by an object of JetReader (whose job is to link
    //              the tree variables to the Jet object) and the index of the jet.

    Jet(float pt=-999, float eta=-999, float phi=-999, float m=-999) :
        TLorentzVector(), // the default constructor is called here (0,0,0,0). I will actually set it in the constructor body.
        IsIsolated(true)
        {
            this->TLorentzVector::SetPtEtaPhiM(pt, eta, phi, m);
        }

    // destructor: default
    ~Jet() { }
    
    // method returning the output to JetID::isBadJet()
    bool isBadLoose() const;

    // overloaded method that checks the jets isolation
    void checkIsolation(std::vector<Muon*>::const_iterator amuon, std::vector<Muon*>::const_iterator endmuon);
    void checkIsolation(std::vector<Photon*>::const_iterator aphoton, std::vector<Photon*>::const_iterator endphoton);

    public:

    //------members------//

    // kinematic variables
    float E;
    float Pt;
    float Eta;
    float Phi;
    float M;

    // emscale variables
    float eEmscale;
    float ptEmscale;
    float etaEmscale;
    float phiEmscale;

    // isBad variables
    float Emfrac;
    float Hecf;
    float LArQuality;
    float HECQuality;
    float Timing;
    float sumPtTrk;
    float fracSamplingMax;
    float NegativeE;

    // other identification variables
    int IsUgly;
    bool IsIsolated;
    Int_t Index;
    
};

#endif 
