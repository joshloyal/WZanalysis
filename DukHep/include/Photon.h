//-----------------------------------------------------------------------------------------------
//
// #Name: PhotonClass.h
// #Description: This class is inhereted from TLorentzVector. The purpose was to pass the photon
//               information to this class, so as to make them easier to work with. It is 
//               designed to act like a TLorentzVector with additional photon data.
//
// #Author: Joshua Loyal
// #Updated: 6/21/2011
//
// ----------------------------------------------------------------------------------------------

#ifndef PHOTONCLASS_H
#define PHOTONCLASS_H

// STL include(s)
#include <vector>
#include <cmath>

// particle include(s)
#include "Muon.h"

// Root include(s)
#include <TLorentzVector.h>

// utility include(s)
#include "DukHep/include/AnalysisUtils.h"

class Photon : public TLorentzVector {
    public:

    // constructor: The photons will be initialized by an object of PhotonReader (whose job is to link 
    //               the tree variables to the Photon object) and the index of the photon.

    Photon(float et=-999, float eta=-999, float phi=-999, float e=-999) :  
        TLorentzVector(), // default iniatilization (see constructor body).
        IsIsolated(true)
        {   
            // set the photon 4Vector
            this->SetPtEtaPhiE(et, eta, phi, e);
            Pt = et;
            Eta = eta;
            Phi = phi;
            E = e;
        }

    // destructor: default
    ~Photon() { }
    
    //-------------------------------------------------------------------------------------------------
    // Energy rescaling and smearing methods
    //
    // part-type could be ELECTRON, UNCONVERTED_PHOTON, CONVERTED_PHOTON
    // in the current implementation there is no difference between the two photon types.
    // The EventNumber and offset are just used to calculate the RandomSeed in the MC energy smearing.
    //-------------------------------------------------------------------------------------------------

    // energy rescaling (Data only!). returns the correction factor
    double CorrectEnergy(std::string part_type="UNCONVERTED_PHOTON");

    // energy smearing (MC only!) returns the correction factor
    double CorrectEnergy(Int_t EventNumber, bool mcWithConstantTerm);

    // calculation of a 'tight' photon
    bool isTight() const;

    // calculation of the corrected Et cone
    float getConeCorrected(const std::vector<int> *vxp_nTracks, bool isMC) const; 
    float getConeCorrected(unsigned int nPV, bool isMC) const;

    // check the isolation of the photon
    void checkIsolation(std::vector<Muon*>::const_iterator amuon, std::vector<Muon*>::const_iterator endmuon, float mindR);

    public:
    
    //------members------//

    // kinematic variables
    float E;
    float Et;
    float Pt;
    float Eta;
    float Phi;
    float Px;
    float Py;
    float Pz;

    // reconstruction variables
    int Author;
    int OQ;
    int isConversion;

    // tight variables
    float Etas2;
    float Ethad;
    float Ethad1;
    float E277;
    float E237;
    float E233;
    float Weta2;
    float F1;
    float Emaxs1;
    float Emax2;
    float Emins1;
    float Fside;
    float Wstot;
    float Ws3;

    // cluster variables
    float eCluster;
    float etCluster;
    float ptCluster;
    float etaCluster;
    float phiCluster;

    // shower variables
    float etShower;

    // isolation variables
    float etaPointing;
    float etCone20;
    float etCone40;
    float etCone20_ptCorrected;
    float etCone40_ptCorrected;
    float etCone40_Corrected;
    float IsIsolated;

    // identification variables
    Int_t Index;

    // MET correction variable (static because each photon adds to it)
    float unCorrectedPx;
    float unCorrectedPy;
    static float ph_dpx;
    static float ph_dpy;

};

#endif




