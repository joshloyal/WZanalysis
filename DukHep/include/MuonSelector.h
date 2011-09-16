//-----------------------------------------------------------------------------------------------
//
// #Name: MuonSelectorClass.h
// #Description: This class is designed to apply the good muon selection to a vector of muons.
//               Right now I am going to apply the good muon definition as defined by the Wg/Zg
//               group. This class will also own a CutFlow object in order to log how many muons
//               pass certain cuts.
//
//  #Creator: Joshua Loyal
//  #Updated: 6/18/2011
//
//-----------------------------------------------------------------------------------------------

#ifndef MuonSelectorClass_H
#define MuonSelectorClass_H

// STL include(s):
#include <vector>

// class include(s):
#include "CutFlow.h"

// class declarations
class Muon;
class MuonReader;

class MuonSelector {
    public:

    typedef std::vector<Muon*>::const_iterator muonIter;
    
    // constructor : initializes MuonSelector object with a CutFlow object and initialzes the cut values.
    MuonSelector(double pt = 20000., double eta = 2.4, double d0 = 10., double z0 = 10., double drCone = 0.1) : 
    muonCutFlow("Muon"), nCuts(0), 
    Minimum_Pt(pt), Max_Eta(eta), Max_d0(d0), Max_z0(z0), Cone_dR(drCone) { 
        initializeCutFlow();
        nCuts = muonCutFlow.nCuts;

    }

    // destructor : default
    ~MuonSelector() { }
    
    // This method is a filter that returns all the 'good' muons in the event.
    void getGoodMuons(muonIter amuon, muonIter endMuon, std::vector<Muon*> &outVec);

    // This method prints the muon cut flow
    void printMuonCutFlow() { muonCutFlow.printCutFlow(); }

    // This method returns the number of objects which have passed cut cutidx
    unsigned int passedCut(unsigned int cutidx) { return muonCutFlow.passedCut(cutidx); }

    // This method initalizes the cut flow
    void initializeCutFlow();
    
    //------members------//
    
    // cut flow members
    private:
    CutFlow muonCutFlow;

    public:
    unsigned int nCuts;
    
    // cut value members
    private:
    double Minimum_Pt;
    double Max_Eta;
    double Max_d0;
    double Max_z0;
    double Cone_dR;

};

#endif
    
