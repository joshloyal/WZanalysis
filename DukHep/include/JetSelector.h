//-----------------------------------------------------------------------------------------------
//
// #Name: JetSelectorClass.h
// #Description: This class is designed to apply the good jet selection to a vector of jets.
//               The class also owns a CutFlow object to log how many photons pass certain cuts.
//
// #Author: Joshua Loyal
// #Updated: 6/21/2011
//
//-----------------------------------------------------------------------------------------------

#ifndef JetSelectorClass_H
#define JetSelectorClass_H

// STL include(s)

// CutFlow include(s)
#include "CutFlow.h"

// particle include(s)
#include "DukHep/include/Jet.h"

// class declarations
class Jet;
class JetReader;

class JetSelector {
    public:
    typedef std::vector<Jet*>::const_iterator jetIter;
    typedef std::vector<Muon*>::const_iterator muonIter;
    typedef std::vector<Photon*>::const_iterator photonIter;

    // constructor: initializes CutFlow object and initializes the cut values
    JetSelector(float pt = 20000., float eta = 4.4) : 
    jetCutFlow("Jet"), nCuts(0), Min_Pt(pt), Max_Eta(eta)
    {
        initializeCutFlow();
        nCuts = jetCutFlow.nCuts;
    }

    // destructor: default
    ~JetSelector() { }

    // This method is a filter that returns all the 'good' jets in the event
    bool getGoodJets(jetIter ajet, jetIter endJet, muonIter amuon, muonIter endmuon, photonIter aphoton, photonIter endphoton, std::vector<Jet*> &outVec);

    // This method checks the Jet Quality of the jets (isBadLoose and isUgly)
    bool isBadUglyJets(jetIter ajet, jetIter endjet);

    // This method prints the photon cut flow
    void printJetCutFlow() { jetCutFlow.printCutFlow(); }

    // This method returns the number of objects which have passed cut cutidx
    unsigned int passedCut(unsigned int cutidx) { return jetCutFlow.passedCut(cutidx); }

    // This method initializes the cut flow
    void initializeCutFlow();
    
    //------members------//

    // cut flow members
    private:
    CutFlow jetCutFlow;

    public:
    unsigned int nCuts;
    
    // cut value members
    private:
    float Min_Pt;
    float Max_Eta;

};

#endif
