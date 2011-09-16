////../bin/dukhep_create_reader.py -n MuonReader MuonReaderMacros.dat
#ifndef MUONREADER
#define MUONREADER 1
#include <vector>
#include <string>
#include <iostream>
#include "core/include/SCycleBaseNTuple.h"
#include "Muon.h"
#include "SmearingClass.h"

class MuonReader {
  public:
    
    // constructor
    MuonReader(SCycleBaseNTuple *owner, const char *collname="mu");
    
    // destructor: default
    virtual ~MuonReader(){};
    
    //-----Collection Definition Methods-----//
    void SetColl(const char * collname) {
      cname = std::string(collname);
      std::cout << "Using muon collection name " << cname << std::endl;
    };


    std::string VarName(const char * s) {
        std::string tmp(s); 
        if ((tmp.find("mu_")==0) && (tmp.find("staco")!=3) && (tmp.find("muid")!=3))
	    return std::string(tmp.replace(0,2,cname)); 
        return std::string(s);
    }
    
    //-----Tree Connection Methods-----//
    void ConnectVariables(std::string treename);
    void DeclareVariables();
    void Reset();
    void CopyToOutput();
    
    //-----Getter/Setter Functions-----//
    
    // set the MC status
    void setMC(bool MC) {
        isMC = MC;
        if(MC)
            std::cout << "MuonReader: isMC set to true" << std::endl;
        else
            std::cout << "MuonReader: isMC set to false" << std::endl;
    }

    // places all the muons in the event in a vector
    void getMuons(Int_t EventNumber, std::vector<Muon*> &muonVec);

    // get a pointer to a single muon
    Muon* getMuon(Int_t EventNumber, Int_t i);

    public:

    //-----Members-----//
    SCycleBaseNTuple * owner;    
    std::string cname;

    std::vector<float>* MuonE;
    std::vector<float> o_MuonE;
    std::vector<float>* MuonPt;
    std::vector<float> o_MuonPt;
    std::vector<float>* MuonEta;
    std::vector<float> o_MuonEta;
    std::vector<float>* MuonPhi;
    std::vector<float> o_MuonPhi;
    std::vector<float>* MuonPx;
    std::vector<float> o_MuonPx;
    std::vector<float>* MuonPy;
    std::vector<float> o_MuonPy;
    std::vector<float>* MuonPz;
    std::vector<float> o_MuonPz;
    std::vector<float>* MuonCharge;
    std::vector<float> o_MuonCharge;
    std::vector<int>* MuonAuthor;
    std::vector<int> o_MuonAuthor;
    std::vector<float>* MuonEtCone20;
    std::vector<float> o_MuonEtCone20;
    std::vector<float>* MuonPtCone20;
    std::vector<float> o_MuonPtCone20;
    std::vector<int>* MuonIsCombined;
    std::vector<int> o_MuonIsCombined;
    std::vector<int>* MuonTight;
    std::vector<int> o_MuonTight;
    std::vector<float>* MuonInnerD0exPV;
    std::vector<float> o_MuonInnerD0exPV;
    std::vector<float>* MuonInnerZ0exPV;
    std::vector<float> o_MuonInnerZ0exPV;
    std::vector<float>* MuonInnerCovD0exPV;
    std::vector<float> o_MuonInnerCovD0exPV;
    std::vector<float>* MuonInnerCovZ0exPV;
    std::vector<float> o_MuonInnerCovZ0exPV;
    std::vector<int>* MuonNumBLHits;
    std::vector<int> o_MuonNumBLHits;
    std::vector<int>* MuonNumPixHits;
    std::vector<int> o_MuonNumPixHits;
    std::vector<int>* MuonNumSCTHits;
    std::vector<int> o_MuonNumSCTHits;
    std::vector<int>* MuonNumTRTHits;
    std::vector<int> o_MuonNumTRTHits;
    std::vector<int>* MuonNumPixHoles;
    std::vector<int> o_MuonNumPixHoles;
    std::vector<int>* MuonNumSCTHoles;
    std::vector<int> o_MuonNumSCTHoles;
    std::vector<int>* MuonNumTRTOutliers;
    std::vector<int> o_MuonNumTRTOutliers;
    std::vector<int>* MuonNumPixelDeadSensors;
    std::vector<int> o_MuonNumPixelDeadSensors;
    std::vector<int>* MuonNumSCTDeadSensors;
    std::vector<int> o_MuonNumSCTDeadSensors;
    std::vector<int>* MuonExpectedBLayerHit;
    std::vector<int> o_MuonExpectedBLayerHit;
    std::vector<float>* MuonInnerQOverP;
    std::vector<float> o_MuonInnerQOverP;
    std::vector<float>* MuonInnerPhi;
    std::vector<float> o_MuonInnerPhi;
    std::vector<float>* MuonInnerTheta;
    std::vector<float> o_MuonInnerTheta;
    std::vector<float>* MuonMEQOverP;
    std::vector<float> o_MuonMEQOverP;
    std::vector<float>* MuonMEPhi;
    std::vector<float> o_MuonMEPhi;
    std::vector<float>* MuonMETheta;
    std::vector<float> o_MuonMETheta;
    Int_t NumberofMuons;
    Int_t o_NumberofMuons;

    // additional members for getter methods
    bool isMC;
};
#endif
