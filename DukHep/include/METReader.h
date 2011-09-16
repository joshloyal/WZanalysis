////../bin/dukhep_create_reader.py -n METReader METMacros.dat
#ifndef METREADER
#define METREADER 1
#include <vector>
#include <string>
#include "TLorentzVector.h"
#include "core/include/SCycleBaseNTuple.h"

class Muon;
class Photon;

class METReader {
  public:

    typedef std::vector<Muon*>::const_iterator muonIter;
    typedef std::vector<Photon*>::const_iterator photonIter;
    
    // constructor
    METReader(SCycleBaseNTuple * owner);

    // destructor: default
    virtual ~METReader(){};

    std::string VarName(const char * s) {return std::string(s);};

    //------Tree Connection Methods------//
    void ConnectVariables(std::string treename);
    void DeclareVariables();
    void Reset();
    void CopyToOutput();

    //------Getter Functions------//
    TLorentzVector getMuonMET(muonIter amuon, muonIter endmuon, photonIter aphoton, photonIter endphoton);
    Float_t getSumET() { return m_MET_LocHadTopo_sumet; }

  public:
    SCycleBaseNTuple * owner;    
    Float_t m_MET_MuonBoy_phi;
    Float_t o_m_MET_MuonBoy_phi;
    Float_t m_MET_MuonBoy_et;
    Float_t o_m_MET_MuonBoy_et;
    Float_t m_MET_MuonBoy_sumet;
    Float_t o_m_MET_MuonBoy_sumet;
    Float_t m_MET_RefMuon_Track_phi;
    Float_t o_m_MET_RefMuon_Track_phi;
    Float_t m_MET_RefMuon_Track_et;
    Float_t o_m_MET_RefMuon_Track_et;
    Float_t m_MET_RefMuon_Track_sumet;
    Float_t o_m_MET_RefMuon_Track_sumet;
    Float_t m_MET_LocHadTopo_phi;
    Float_t o_m_MET_LocHadTopo_phi;
    Float_t m_MET_LocHadTopo_et;
    Float_t o_m_MET_LocHadTopo_et;
    Float_t m_MET_LocHadTopo_sumet;
    Float_t o_m_MET_LocHadTopo_sumet;
};
    #endif
