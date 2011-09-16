//----------------------------------------------------------------------------------------------------------------
// #Name: MuonClass.h
// #Description: This class is inhereted from TLorentzVector. The purpose was to pass on the muon information
//               to this class, so as to make them easier to work with. Another class MuonReader will 
//               actually handle this process.
// 
// #Note: This class does not define a copy constructor! Therefore, when passing muons to a STL container or 
//        anyother place where it may be copied use a reference or a pointer (this prevents copying and 
//        truthfully will probably increase speed anyway).
//
// #Author: Joshua Loyal
//
// #Updated: 6/13/2011
//
//---------------------------------------------------------------------------------------------------------------
#ifndef Muon_h
#define Muon_h

// STL/Root include(s)
#include <vector>
#include <TLorentzVector.h>

class Muon : public TLorentzVector {
    public:
    
    // constructor: uses the TLorentzVector default constructor, up to the user to invoke the TLorentzVector::SetXXXX method.
    Muon(float q) : TLorentzVector(), Charge(q), unCorrectedPx(0), unCorrectedPy(0) {}
    
    // construct: uses the standard TLorentzVector::SetPtEtaPhiE method
    Muon(float pt, float eta, float phi, float e, float q) : TLorentzVector(), 
    Pt(pt), Eta(eta), Phi(phi), E(e), Charge(q),
    unCorrectedPx(0), unCorrectedPy(0)
    {
        this->SetPtEtaPhiE(pt, eta, phi, e);
    }

    // destructor : TLorentzVector default
    ~Muon() { }

    public:

    //-----methods-----//

    // apply pt smearing (MC only!)
    void SmearPt(Int_t EventNumber);

    // get the transverse component of the four vector
    TLorentzVector getTransverseFourVector();

    //-----members-----//

    // Kinematic Variables
    float Pt;
    float Eta;
    float Phi;
    float E;
    float M;
    float Charge;

    // Reconstruction Variables
    int   Author;
    int   IsCombined;
    
    // Isolation Variables
    float EtCone20;
    float PtCone20;
    float Tight;

    // Track Variables wrt. Primary Vertex (inner detector)
    float InnerDetector_d0_exPV;
    float InnerDetector_cov_d0_exPV;
    float InnerDetector_z0_exPV;

    // Inner detector variables
    float InnerQOverP;
    float InnerPhi;
    float InnerTheta;
    float InnerP;
    float InnerPt;

    // MS Extrapolated variables
    float MSExtrapolatedQOverP;
    float MSExtrapolatedPhi;
    float MSExtrapolatedTheta;
    float MSExtrapolatedP;
    float MSExtrapolatedPt;


    // Detector Variables
    int expectBLayerHit;
    int nBLHits;
    int nPixHits;
    int nPixelDeadSensors;
    int nSCTHits;
    int nSCTDeadSensors;
    int nPixHoles;
    int nSCTHoles;
    int nTRTOutliers;
    int nTRTHits; 

    // Identification Variables
    Int_t Index;

    // MET correction variable (static because each muon adds to it)
    float unCorrectedPx;
    float unCorrectedPy;
    static float mu_dpx;
    static float mu_dpy;

};

#endif
    


