//-----------------------------------------------------------------------------------------------
//
// #Name: PhotonSelectorClass.h
// #Description: This class is designed to apply the good photon selection to a vector of photons
//               Right now I am going to apply the good photon definition as defined by the Wg/Zg
//               group. This class also owns a CutFlow object in order to log how many photons
//               pass certain cuts.
//
// #Author: Joshua Loyal
// #Updated: 6/20/2011
//
//-----------------------------------------------------------------------------------------------

#ifndef PhotonSelectorClass_H
#define PhotonSelectorClass_H

// STL include(s):
#include <vector>

// Event Selection include(s)
#include "CutFlow.h"

// class declarations
class Photon;
class Muon;
class PhotonReader;

class PhotonSelector {
    public:
    typedef std::vector<Photon*>::const_iterator photonIter;
    typedef std::vector<Muon*>::const_iterator muonIter;

    // constructor: initializes CutFlow object and initializes the cut values
    PhotonSelector(float eta = 2.37, float minEta = 1.37, float maxEta = 1.52, float dR = 0.7, float et = 15000., float cone = 5000.) :
    photonCutFlow("Photon"), nCuts(0), 
    Max_Eta(eta), Eta_CrackMin(minEta), Eta_CrackMax(maxEta), Min_dR(dR), Max_Et(et), Min_Cone(cone) { 
        initializeCutFlow();
        nCuts = photonCutFlow.nCuts;
    }

    // destructor: default
    ~PhotonSelector() { }

    // This method is a filter that returns all the 'good' photons in the event
    //--
    bool getGoodPhotons(photonIter aphoton  ,           // iterator pointing to first element in input vector
                        photonIter endPhoton,           // iterator pointing to one past the last element in the input vector
                        Muon *firstMoun     ,           // pointers to the two muons to apply overlap removal (
                        Muon *secondMuon    ,           // (make this more general if necessary)
                        std::vector<Photon*> &outVec);  // the vector to store the output in
    
    // same method but adds some additions for monte carlo
    bool getGoodPhotons(UInt_t RunNumber    ,
                        photonIter aphoton  ,           // iterator pointing to first element in input vector
                        photonIter endPhoton,           // iterator pointing to one past the last element in the input vector
                        Muon *firstMoun     ,           // pointers to the two muons to apply overlap removal (
                        Muon *secondMuon    ,           // (make this more general if necessary)
                        std::vector<Photon*> &outVec);  // the vector to store the output in
    
    // same method but adds some additions for monte carlo
    bool getGoodPhotons(UInt_t RunNumber    ,
                        photonIter aphoton  ,           // iterator pointing to first element in input vector
                        photonIter endPhoton,           // iterator pointing to one past the last element in the input vector
                        muonIter amuon      ,           // pointers to the two muons to apply overlap removal (
                        muonIter endmuon    ,           // (make this more general if necessary)
                        std::vector<Photon*> &outVec);  // the vector to store the output in
    
    // same method but adds some generality
    bool getGoodPhotons(photonIter aphoton  ,           // iterator pointing to first element in input vector
                        photonIter endPhoton,           // iterator pointing to one past the last element in the input vector
                        muonIter amuon      ,           // iterator to the first element in the muon vector
                        muonIter endmuon    ,           // iterator to the last element in the muon vector
                        std::vector<Photon*> &outVec);  // the vector to store the output in
    
    // This method is a filter that returns all the tight photons in the event
    bool getTightPhotons(photonIter aphoton, photonIter endPhoton, std::vector<Photon*> &outVec);

    // This method is a filter that returns all the isolated photons in the event
    bool getIsolatedPhotons(photonIter aphoton, photonIter endphoton, const std::vector<int> *vxp_nTracks, std::vector<Photon*> &outVec, bool isMC);

    // This method prints the photon cut flow
    void printPhotonCutFlow() { photonCutFlow.printCutFlow(); }

    // This method returns the number of objects which have passed cut cutidx
    unsigned int passedCut(unsigned int cutidx) { return photonCutFlow.passedCut(cutidx); }

    // This method initializes the cut flow
    void initializeCutFlow();

    //------members------//

    // cut flow members
    private:
    CutFlow photonCutFlow;

    public:
    unsigned int nCuts;
    
    // cut value members
    private:
    float Max_Eta;
    float Eta_CrackMin;
    float Eta_CrackMax;
    float Min_dR;
    float Max_Et;
    float Min_Cone;
    
};

#endif
