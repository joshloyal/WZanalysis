////../bin/dukhep_create_reader.py -n JetReader JetReaderMacrosFilter.dat
#ifndef JETREADER
#define JETREADER 1
#include <vector>
#include <string>
#include <iostream>
#include "core/include/SCycleBaseNTuple.h"
#include "Jet.h"

class JetReader {
  public:
    
    // constructor
    JetReader(SCycleBaseNTuple * owner, const char *collname="jet");
    
    // destructor: default
    virtual ~JetReader(){};

    //-----Collection Definition Methods-----//
    void SetColl(const char * collname) {
      cname = std::string(collname);
      std::cout << "Using jet collection name " << cname << std::endl;
    };
    
    std::string VarName(const char * s){
        std::string tmp(s); 
        if (tmp.find("jet_")==0) {
            std::cout << "JetReader: replacing jet in " << tmp << std::endl;	
            return std::string(tmp.replace(0,3,cname)); 
        }
        return std::string(s);
    };    

    //-----Tree Connection Methods-----//
    void ConnectVariables(std::string treename);
    void DeclareVariables();
    void Reset();
    void CopyToOutput();
    
    //-----Getter Functions-----//
    void getJets(std::vector<Jet*> &jetVec);

    public:

    //-----Members-----//
    SCycleBaseNTuple * owner;
    std::string cname;

    std::vector<float>* JetE;
    std::vector<float> o_JetE;
    std::vector<float>* JetPt;
    std::vector<float> o_JetPt;
    std::vector<float>* JetMass;
    std::vector<float> o_JetMass;
    std::vector<float>* JetEta;
    std::vector<float> o_JetEta;
    std::vector<float>* JetPhi;
    std::vector<float> o_JetPhi;
    std::vector<float>* JetTiming;
    std::vector<float> o_JetTiming;
    std::vector<float>* JetLArQuality;
    std::vector<float> o_JetLArQuality;
    std::vector<float>* JetsumPtTrk;
    std::vector<float> o_JetsumPtTrk;
    std::vector<float>* JetHECQuality;
    std::vector<float> o_JetHECQuality;
    std::vector<float>* JetNegativeE;
    std::vector<float> o_JetNegativeE;
    std::vector<float>* JetFracSamplingMax;
    std::vector<float> o_JetFracSamplingMax;
    std::vector<float>* JetHecf;
    std::vector<float> o_JetHecf;
    std::vector<float>* JetEmfrac;
    std::vector<float> o_JetEmfrac;
    std::vector<float>* JetEmscaleE;
    std::vector<float> o_JetEmscaleE;
    std::vector<float>* JetEmscalePt;
    std::vector<float> o_JetEmscalePt;
    std::vector<float>* JetEmscaleEta;
    std::vector<float> o_JetEmscaleEta;
    std::vector<float>* JetEmscalePhi;
    std::vector<float> o_JetEmscalePhi;
    std::vector<int>* JetIsUgly;
    std::vector<int> o_JetIsUgly;
    Int_t NumberofJets;
    Int_t o_NumberofJets;
};
#endif
