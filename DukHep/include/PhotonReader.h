////../bin/dukhep_create_reader.py -n PhotonReader PhotonReaderMacrosFilter.dat
#ifndef PHOTONREADER
#define PHOTONREADER 1
#include <vector>
#include <string>
#include <iostream>
#include "core/include/SCycleBaseNTuple.h"
#include "Photon.h"

class PhotonReader {
  public:

    // constructor
    PhotonReader(SCycleBaseNTuple * ownr);

    // destructor: default
    virtual ~PhotonReader(){};

    //-----Collection Definition Methods-----//
    std::string VarName(const char * s) {return std::string(s);};

    //-----Tree Connection Methods-----//
    void ConnectVariables(std::string treename);
    void DeclareVariables();
    void Reset();
    void CopyToOutput();

    //define your getters/setters here

    // set the MC status
    void setMC(bool MC) {
        isMC = MC;
        if(MC) 
            std::cout << "PhotonReader: isMC set to true" << std::endl;
        else
            std::cout << "PhotonReader: isMC set to false" << std::endl;

    }

    void getPhotons(std::vector<Photon*> &photonVec, Int_t EventNumber);
    Photon* getPhoton(Int_t EventNumber, Int_t i);

  public:

    //-----Members-----//
    SCycleBaseNTuple * owner;

    std::vector<float>* PhotonE;
    std::vector<float> o_PhotonE;
    std::vector<float>* PhotonEt;
    std::vector<float> o_PhotonEt;
    std::vector<float>* PhotonPt;
    std::vector<float> o_PhotonPt;
    std::vector<float>* PhotonEta;
    std::vector<float> o_PhotonEta;
    std::vector<float>* PhotonPhi;
    std::vector<float> o_PhotonPhi;
    std::vector<float>* PhotonPx;
    std::vector<float> o_PhotonPx;
    std::vector<float>* PhotonPy;
    std::vector<float> o_PhotonPy;
    std::vector<float>* PhotonPz;
    std::vector<float> o_PhotonPz;
    std::vector<int>* PhotonAuthor;
    std::vector<int> o_PhotonAuthor;
    std::vector<unsigned int>* PhotonOQ;
    std::vector<unsigned int> o_PhotonOQ;
    std::vector<int>* PhotonIsConv;
    std::vector<int> o_PhotonIsConv;
    std::vector<float>* PhotonEthad;
    std::vector<float> o_PhotonEthad;
    std::vector<float>* PhotonEthad1;
    std::vector<float> o_PhotonEthad1;
    std::vector<float>* PhotonF1;
    std::vector<float> o_PhotonF1;
    std::vector<float>* PhotonEmins1;
    std::vector<float> o_PhotonEmins1;
    std::vector<float>* PhotonFside;
    std::vector<float> o_PhotonFside;
    std::vector<float>* PhotonEmax2;
    std::vector<float> o_PhotonEmax2;
    std::vector<float>* PhotonWs3;
    std::vector<float> o_PhotonWs3;
    std::vector<float>* PhotonWstot;
    std::vector<float> o_PhotonWstot;
    std::vector<float>* PhotonEmaxs1;
    std::vector<float> o_PhotonEmaxs1;
    std::vector<float>* PhotonE233;
    std::vector<float> o_PhotonE233;
    std::vector<float>* PhotonE237;
    std::vector<float> o_PhotonE237;
    std::vector<float>* PhotonE277;
    std::vector<float> o_PhotonE277;
    std::vector<float>* PhotonWeta2;
    std::vector<float> o_PhotonWeta2;
    std::vector<float>* PhotonEtcone20;
    std::vector<float> o_PhotonEtcone20;
    std::vector<float>* PhotonEtcone40;
    std::vector<float> o_PhotonEtcone40;
    std::vector<float>* PhotonEtcone20_ptCorrected;
    std::vector<float> o_PhotonEtcone20_ptCorrected;
    std::vector<float>* PhotonEtcone40_ptCorrected;
    std::vector<float> o_PhotonEtcone40_ptCorrected;
    std::vector<float>* PhotonEtcone40_Corrected;
    std::vector<float> o_PhotonEtcone40_Corrected;
    std::vector<float>* PhotonEtap;
    std::vector<float> o_PhotonEtap;
    std::vector<float>* PhotonClusterE;
    std::vector<float> o_PhotonClusterE;
    std::vector<float>* PhotonClusterPt;
    std::vector<float> o_PhotonClusterPt;
    std::vector<float>* PhotonClusterEta;
    std::vector<float> o_PhotonClusterEta;
    std::vector<float>* PhotonClusterPhi;
    std::vector<float> o_PhotonClusterPhi;
    std::vector<float>* PhotonEtas2;
    std::vector<float> o_PhotonEtas2;
    Int_t NumberofPhotons;
    Int_t o_NumberofPhotons;
    bool isMC;
};
#endif
