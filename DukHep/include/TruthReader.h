////../bin/dukhep_create_reader.py -n TruthReader TruthMacros.dat
#ifndef TRUTHREADER
#define TRUTHREADER 1
#include <vector>
#include <string>
#include "core/include/SCycleBaseNTuple.h"

class Muon;
class Photon;

class TruthReader {
  public:
    
    // constructor
    TruthReader(SCycleBaseNTuple * owner, std::string mcsample="pythia");
    
    // destructor: default
    virtual ~TruthReader(){};
    
    //------Tree Connection Methods------//
    std::string VarName(const char * s) {return std::string(s);};
    void ConnectVariables(std::string treename);
    void DeclareVariables();
    void Reset();
    void CopyToOutput();

    //------Getter Functions------//
    std::vector<Muon*>   getTruthMuons();
    std::vector<Photon*> getTruthPhotons();
    
  public:

    //------D3PD Variables------//
    SCycleBaseNTuple * owner;    
    Int_t mcNumber;
    Int_t o_mcNumber;
    std::vector<float>* mcPt;
    std::vector<float> o_mcPt;
    std::vector<float>* mcM;
    std::vector<float> o_mcM;
    std::vector<float>* mcEta;
    std::vector<float> o_mcEta;
    std::vector<float>* mcPhi;
    std::vector<float> o_mcPhi;
    std::vector<int>* mcStatus;
    std::vector<int> o_mcStatus;
    std::vector<int>* mcBarCode;
    std::vector<int> o_mcBarCode;
    std::vector<std::vector<int> >* mcParents;
    std::vector<std::vector<int> > o_mcParents;
    std::vector<std::vector<int> >* mcChildren;
    std::vector<std::vector<int> > o_mcChildren;
    std::vector<int>* mcPdgID;
    std::vector<int> o_mcPdgID;
    std::vector<float>* mcCharge;
    std::vector<float> o_mcCharge;
    std::vector<float>* mcVx_x;
    std::vector<float> o_mcVx_x;
    std::vector<float>* mcVx_y;
    std::vector<float> o_mcVx_y;
    std::vector<float>* mcVx_z;
    std::vector<float> o_mcVx_z;
    std::vector<std::vector<int> >* mcChild_index;
    std::vector<std::vector<int> > o_mcChild_index;
    std::vector<std::vector<int> >* mcParent_index;
    std::vector<std::vector<int> > o_mcParent_index; 

    //------Additional Information------//
    bool pythia;
    bool alpgen;
    bool madgraph;
    bool sherpa;
};
#endif
