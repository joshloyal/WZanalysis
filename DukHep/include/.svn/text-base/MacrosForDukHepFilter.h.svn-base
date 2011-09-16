#undef INIT_NULLS_CTOR
#undef DUKEHEPHEADER_MEMBERS
#undef CONNECT
#undef DECLARE
#undef RESETVAR
#undef COPYVAR

#define DEF_FILTER 1
#define ELE_FILTER 2
#define WELE_FILTER 3
//begin macro definitions

#if DUKHEPFILTER_TYPE == DEF_FILTER
#define INIT_NULLS_CTOR		\
m_RunNumber(0),	\
o_m_RunNumber(0),	\
m_EventNumber(0),	\
o_m_EventNumber(0),	\
m_LumiBlock(0),	\
o_m_LumiBlock(0),	\
m_NumElectrons(0),	\
o_m_NumElectrons(0),	\
m_MCEventWeight(0),	\
o_m_MCEventWeight(0),	\
m_PrimaryVertexType(0),	\
o_m_PrimaryVertexType(0),	\
m_PrimaryVertexNumTracks(0),	\
o_m_PrimaryVertexNumTracks(0),	\
m_ElectronAuthor(0),	\
o_m_ElectronAuthor(0),	\
m_ElectronEta(0),	\
o_m_ElectronEta(0),	\
m_ElectronPt(0),	\
o_m_ElectronPt(0),	\
m_ElectronPhi(0),	\
o_m_ElectronPhi(0),	\
m_ElectronClusterE(0),	\
o_m_ElectronClusterE(0),	\
m_ElectronClusterEta(0),	\
o_m_ElectronClusterEta(0),	\
m_ElectronClusterPhi(0),	\
o_m_ElectronClusterPhi(0),	\
m_JetPt(0),	\
o_m_JetPt(0),	\
m_JetEta(0),	\
o_m_JetEta(0),	\
m_JetPhi(0),	\
o_m_JetPhi(0),	\
m_JetE(0),	\
o_m_JetE(0),	\
m_JetPullMag(0),	\
o_m_JetPullMag(0),	\
m_JetPullPhi(0),	\
o_m_JetPullPhi(0),	\
m_JetWeightSV0(0),	\
o_m_JetWeightSV0(0),	\
m_JetIsUgly(0),	\
o_m_JetIsUgly(0),	\
m_JetIsBad(0),	\
o_m_JetIsBad(0),	\
m_MetForTopAna(0),	\
o_m_MetForTopAna(0),	\
m_MetForTopAnaPhi(0),	\
o_m_MetForTopAnaPhi(0),	\
m_MuonAuthor(0),	\
m_MuonEta(0),	\
m_MuonStacoMatchChi2(0),	\
m_MuonStacoMatchDOF(0),	\
m_MuonIsoEtCone20(0),	\
m_MuonIsoPtCone30(0),	\
m_MuonPt(0),	\
m_MuonPhi(0),	\
m_NumTopElectrons(0),	\
m_NumTopMuons(0),	\
m_NumTopJets(0),	\
m_IndexTopElectron(0),	\
m_IndexTopMuon(0),	\
m_IndexTopJet(0),	\
m_UseTopJet(0),	\
m_TopEleInTrigger(0),	\
m_TopMuInTrigger(0),	\
m_OverlapEleMu(0),	\
m_NumPrimaryVertices(0),	\
o_m_NumPrimaryVertices(0),	\
m_NumJets(0),	\
o_m_NumJets(0),	\
m_NumMuons(0),	\
o_m_NumMuons(0),	\
m_NumTruth(0),	\
m_TruthStatus(0),	\
m_TruthPdgId(0),	\
m_TruthBarcode(0),	\
m_TruthParents(0),	\
m_TruthChildren(0),	\
m_TruthParentIndex(0),	\
m_TruthChildIndex(0),	\
m_TruthPt(0),	\
m_TruthEta(0),	\
m_TruthPhi(0),	\
m_TruthMass(0),	\
m_NumTruthJets(0),	\
m_TruthJetPt(0),	\
m_TruthJetEta(0),	\
m_TruthJetPhi(0),	\
m_TruthJetE(0),	\
m_TruthJetPullMag(0),	\
m_TruthJetPullPhi(0)
#endif


#if DUKHEPFILTER_TYPE == DEF_FILTER
#define DUKEHEPHEADER_MEMBERS                          \
UInt_t m_RunNumber;	\
UInt_t o_m_RunNumber;	\
UInt_t m_EventNumber;	\
UInt_t o_m_EventNumber;	\
UInt_t m_LumiBlock;	\
UInt_t o_m_LumiBlock;	\
Int_t m_NumElectrons;	\
Int_t o_m_NumElectrons;	\
Float_t m_MCEventWeight;	\
Float_t o_m_MCEventWeight;	\
std::vector<int>* m_PrimaryVertexType;	\
std::vector<int> o_m_PrimaryVertexType;	\
std::vector<int>* m_PrimaryVertexNumTracks;	\
std::vector<int> o_m_PrimaryVertexNumTracks;	\
std::vector<int>* m_ElectronAuthor;	\
std::vector<int> o_m_ElectronAuthor;	\
std::vector<float>* m_ElectronEta;	\
std::vector<float> o_m_ElectronEta;	\
std::vector<float>* m_ElectronPt;	\
std::vector<float> o_m_ElectronPt;	\
std::vector<float>* m_ElectronPhi;	\
std::vector<float> o_m_ElectronPhi;	\
std::vector<float>* m_ElectronClusterE;	\
std::vector<float> o_m_ElectronClusterE;	\
std::vector<float>* m_ElectronClusterEta;	\
std::vector<float> o_m_ElectronClusterEta;	\
std::vector<float>* m_ElectronClusterPhi;	\
std::vector<float> o_m_ElectronClusterPhi;	\
std::vector<float>* m_JetPt;	\
std::vector<float> o_m_JetPt;	\
std::vector<float>* m_JetEta;	\
std::vector<float> o_m_JetEta;	\
std::vector<float>* m_JetPhi;	\
std::vector<float> o_m_JetPhi;	\
std::vector<float>* m_JetE;	\
std::vector<float> o_m_JetE;	\
std::vector<float>* m_JetPullMag;	\
std::vector<float> o_m_JetPullMag;	\
std::vector<float>* m_JetPullPhi;	\
std::vector<float> o_m_JetPullPhi;	\
std::vector<double>* m_JetWeightSV0;	\
std::vector<double> o_m_JetWeightSV0;	\
std::vector<int>* m_JetIsUgly;	\
std::vector<int> o_m_JetIsUgly;	\
std::vector<int>* m_JetIsBad;	\
std::vector<int> o_m_JetIsBad;	\
float m_MetForTopAna;	\
float o_m_MetForTopAna;	\
float m_MetForTopAnaPhi;	\
float o_m_MetForTopAnaPhi;	\
std::vector<int>* m_MuonAuthor;	\
std::vector<float>* m_MuonEta;	\
std::vector<float>* m_MuonStacoMatchChi2;	\
std::vector<int>* m_MuonStacoMatchDOF;	\
std::vector<float>* m_MuonIsoEtCone20;	\
std::vector<float>* m_MuonIsoPtCone30;	\
std::vector<float>* m_MuonPt;	\
std::vector<float>* m_MuonPhi;	\
Int_t m_NumTopElectrons;	\
Int_t m_NumTopMuons;	\
Int_t m_NumTopJets;	\
std::vector<int>* m_IndexTopElectron;	\
std::vector<int>* m_IndexTopMuon;	\
std::vector<int>* m_IndexTopJet;	\
std::vector<int>* m_UseTopJet;	\
std::vector<int>* m_TopEleInTrigger;	\
std::vector<int>* m_TopMuInTrigger;	\
std::vector<int>* m_OverlapEleMu;	\
Int_t m_NumPrimaryVertices;	\
Int_t o_m_NumPrimaryVertices;	\
Int_t m_NumJets;	\
Int_t o_m_NumJets;	\
Int_t m_NumMuons;	\
Int_t o_m_NumMuons;	\
Int_t m_NumTruth;	\
std::vector<int>* m_TruthStatus;	\
std::vector<int>* m_TruthPdgId;	\
std::vector<int>* m_TruthBarcode;	\
std::vector<std::vector<int> >* m_TruthParents;	\
std::vector<std::vector<int> >* m_TruthChildren;	\
std::vector<std::vector<int> >* m_TruthParentIndex;	\
std::vector<std::vector<int> >* m_TruthChildIndex;	\
std::vector<float>* m_TruthPt;	\
std::vector<float>* m_TruthEta;	\
std::vector<float>* m_TruthPhi;	\
std::vector<float>* m_TruthMass;	\
Int_t m_NumTruthJets;	\
std::vector<float>* m_TruthJetPt;	\
std::vector<float>* m_TruthJetEta;	\
std::vector<float>* m_TruthJetPhi;	\
std::vector<float>* m_TruthJetE;	\
std::vector<float>* m_TruthJetPullMag;	\
std::vector<float>* m_TruthJetPullPhi;
#endif


#if DUKHEPFILTER_TYPE == DEF_FILTER
#define CONNECT( stringTREENAME )                      \
  {    ConnectVariable( (stringTREENAME), "RunNumber", m_RunNumber );	\
    ConnectVariable( (stringTREENAME), "EventNumber", m_EventNumber );	\
    ConnectVariable( (stringTREENAME), "lbn", m_LumiBlock );	\
    ConnectVariable( (stringTREENAME), "el_n", m_NumElectrons );	\
    ConnectVariable( (stringTREENAME), "mcevt_weight", m_MCEventWeight );	\
    ConnectVariable( (stringTREENAME), "vxp_type", m_PrimaryVertexType );	\
    ConnectVariable( (stringTREENAME), "vxp_nTracks", m_PrimaryVertexNumTracks );	\
    ConnectVariable( (stringTREENAME), "el_author", m_ElectronAuthor );	\
    ConnectVariable( (stringTREENAME), "el_eta", m_ElectronEta );	\
    ConnectVariable( (stringTREENAME), "el_pt", m_ElectronPt );	\
    ConnectVariable( (stringTREENAME), "el_phi", m_ElectronPhi );	\
    ConnectVariable( (stringTREENAME), "el_cl_E", m_ElectronClusterE );	\
    ConnectVariable( (stringTREENAME), "el_cl_eta", m_ElectronClusterEta );	\
    ConnectVariable( (stringTREENAME), "el_cl_phi", m_ElectronClusterPhi );	\
    ConnectVariable( (stringTREENAME), "jet_pt", m_JetPt );	\
    ConnectVariable( (stringTREENAME), "jet_eta", m_JetEta );	\
    ConnectVariable( (stringTREENAME), "jet_phi", m_JetPhi );	\
    ConnectVariable( (stringTREENAME), "jet_E", m_JetE );	\
    ConnectVariable( (stringTREENAME), "jet_PullMag", m_JetPullMag );	\
    ConnectVariable( (stringTREENAME), "jet_PullPhi", m_JetPullPhi );	\
    ConnectVariable( (stringTREENAME), "jet_flavor_weight_SV0", m_JetWeightSV0 );	\
    ConnectVariable( (stringTREENAME), "jet_isUgly", m_JetIsUgly );	\
    ConnectVariable( (stringTREENAME), "jet_isBadLoose", m_JetIsBad );	\
    ConnectVariable( (stringTREENAME), "topMET_et", m_MetForTopAna );	\
    ConnectVariable( (stringTREENAME), "topMET_phi", m_MetForTopAnaPhi );	\
    ConnectVariable( (stringTREENAME), "mu_author", m_MuonAuthor );	\
    ConnectVariable( (stringTREENAME), "mu_eta", m_MuonEta );	\
    ConnectVariable( (stringTREENAME), "mu_matchchi2", m_MuonStacoMatchChi2 );	\
    ConnectVariable( (stringTREENAME), "mu_matchndof", m_MuonStacoMatchDOF );	\
    ConnectVariable( (stringTREENAME), "mu_etcone20", m_MuonIsoEtCone20 );	\
    ConnectVariable( (stringTREENAME), "mu_etcone30", m_MuonIsoPtCone30 );	\
    ConnectVariable( (stringTREENAME), "mu_pt", m_MuonPt );	\
    ConnectVariable( (stringTREENAME), "mu_phi", m_MuonPhi );	\
    ConnectVariable( (stringTREENAME), "topEl_n", m_NumTopElectrons );	\
    ConnectVariable( (stringTREENAME), "topMu_n", m_NumTopMuons );	\
    ConnectVariable( (stringTREENAME), "topJet_n", m_NumTopJets );	\
    ConnectVariable( (stringTREENAME), "topEl_index", m_IndexTopElectron );	\
    ConnectVariable( (stringTREENAME), "topMu_index", m_IndexTopMuon );	\
    ConnectVariable( (stringTREENAME), "topJet_index", m_IndexTopJet );	\
    ConnectVariable( (stringTREENAME), "topJet_use", m_UseTopJet );	\
    ConnectVariable( (stringTREENAME), "topEl_inTrigger", m_TopEleInTrigger );	\
    ConnectVariable( (stringTREENAME), "topMu_inTrigger", m_TopMuInTrigger );	\
    ConnectVariable( (stringTREENAME), "top_isEleMuOverlap", m_OverlapEleMu );	\
    ConnectVariable( (stringTREENAME), "vxp_n", m_NumPrimaryVertices );	\
    ConnectVariable( (stringTREENAME), "jet_n", m_NumJets );	\
    ConnectVariable( (stringTREENAME), "mu_n", m_NumMuons );	\
    ConnectVariable( (stringTREENAME), "mc_n", m_NumTruth );	\
    ConnectVariable( (stringTREENAME), "mc_status", m_TruthStatus );	\
    ConnectVariable( (stringTREENAME), "mc_pdgId", m_TruthPdgId );	\
    ConnectVariable( (stringTREENAME), "mc_barcode", m_TruthBarcode );	\
    ConnectVariable( (stringTREENAME), "mc_parents", m_TruthParents );	\
    ConnectVariable( (stringTREENAME), "mc_children", m_TruthChildren );	\
    ConnectVariable( (stringTREENAME), "mc_parent_index", m_TruthParentIndex );	\
    ConnectVariable( (stringTREENAME), "mc_child_index", m_TruthChildIndex );	\
    ConnectVariable( (stringTREENAME), "mc_pt", m_TruthPt );	\
    ConnectVariable( (stringTREENAME), "mc_eta", m_TruthEta );	\
    ConnectVariable( (stringTREENAME), "mc_phi", m_TruthPhi );	\
    ConnectVariable( (stringTREENAME), "mc_m", m_TruthMass );	\
    ConnectVariable( (stringTREENAME), "tj6_n", m_NumTruthJets );	\
    ConnectVariable( (stringTREENAME), "tj6_pt", m_TruthJetPt );	\
    ConnectVariable( (stringTREENAME), "tj6_eta", m_TruthJetEta );	\
    ConnectVariable( (stringTREENAME), "tj6_phi", m_TruthJetPhi );	\
    ConnectVariable( (stringTREENAME), "tj6_E", m_TruthJetE );	\
    ConnectVariable( (stringTREENAME), "tj6_PullMag", m_TruthJetPullMag );	\
    ConnectVariable( (stringTREENAME), "tj6_PullPhi", m_TruthJetPullPhi );	\
  }
#endif


#if DUKHEPFILTER_TYPE == DEF_FILTER
#define DECLARE( stringTREENAME )                      \
  {    DeclareVariable( o_m_RunNumber, "RunNumber" );	\
    DeclareVariable( o_m_EventNumber, "EventNumber" );	\
    DeclareVariable( o_m_LumiBlock, "lbn" );	\
    DeclareVariable( o_m_NumElectrons, "el_n" );	\
    DeclareVariable( o_m_MCEventWeight, "mcevt_weight" );	\
    DeclareVariable( o_m_PrimaryVertexType, "vxp_type" );	\
    DeclareVariable( o_m_PrimaryVertexNumTracks, "vxp_nTracks" );	\
    DeclareVariable( o_m_ElectronAuthor, "el_author" );	\
    DeclareVariable( o_m_ElectronEta, "el_eta" );	\
    DeclareVariable( o_m_ElectronPt, "el_pt" );	\
    DeclareVariable( o_m_ElectronPhi, "el_phi" );	\
    DeclareVariable( o_m_ElectronClusterE, "el_cl_E" );	\
    DeclareVariable( o_m_ElectronClusterEta, "el_cl_eta" );	\
    DeclareVariable( o_m_ElectronClusterPhi, "el_cl_phi" );	\
    DeclareVariable( o_m_JetPt, "jet_pt" );	\
    DeclareVariable( o_m_JetEta, "jet_eta" );	\
    DeclareVariable( o_m_JetPhi, "jet_phi" );	\
    DeclareVariable( o_m_JetE, "jet_E" );	\
    DeclareVariable( o_m_JetPullMag, "jet_PullMag" );	\
    DeclareVariable( o_m_JetPullPhi, "jet_PullPhi" );	\
    DeclareVariable( o_m_JetWeightSV0, "jet_flavor_weight_SV0" );	\
    DeclareVariable( o_m_JetIsUgly, "jet_isUgly" );	\
    DeclareVariable( o_m_JetIsBad, "jet_isBadLoose" );	\
    DeclareVariable( o_m_MetForTopAna, "topMET_et" );	\
    DeclareVariable( o_m_MetForTopAnaPhi, "topMET_phi" );	\
    DeclareVariable( o_m_NumPrimaryVertices, "vxp_n" );	\
    DeclareVariable( o_m_NumJets, "jet_n" );	\
    DeclareVariable( o_m_NumMuons, "mu_n" );	\
  }
#endif


#if DUKHEPFILTER_TYPE == DEF_FILTER
#define RESETVAR                      \
  {    o_m_RunNumber = -999;\
    o_m_EventNumber = -999;\
    o_m_LumiBlock = -999;\
    o_m_NumElectrons = -999;\
    o_m_MCEventWeight = -999;\
    o_m_PrimaryVertexType.clear();\
    o_m_PrimaryVertexNumTracks.clear();\
    o_m_ElectronAuthor.clear();\
    o_m_ElectronEta.clear();\
    o_m_ElectronPt.clear();\
    o_m_ElectronPhi.clear();\
    o_m_ElectronClusterE.clear();\
    o_m_ElectronClusterEta.clear();\
    o_m_ElectronClusterPhi.clear();\
    o_m_JetPt.clear();\
    o_m_JetEta.clear();\
    o_m_JetPhi.clear();\
    o_m_JetE.clear();\
    o_m_JetPullMag.clear();\
    o_m_JetPullPhi.clear();\
    o_m_JetWeightSV0.clear();\
    o_m_JetIsUgly.clear();\
    o_m_JetIsBad.clear();\
    o_m_MetForTopAna = -999;\
    o_m_MetForTopAnaPhi = -999;\
    o_m_NumPrimaryVertices = -999;\
    o_m_NumJets = -999;\
    o_m_NumMuons = -999;\
  }
#endif


#if DUKHEPFILTER_TYPE == DEF_FILTER
#define COPYVAR                      \
  {   o_m_RunNumber = m_RunNumber;\
   o_m_EventNumber = m_EventNumber;\
   o_m_LumiBlock = m_LumiBlock;\
   o_m_NumElectrons = m_NumElectrons;\
   o_m_MCEventWeight = m_MCEventWeight;\
   o_m_PrimaryVertexType = std::vector<int>(*m_PrimaryVertexType);\
   o_m_PrimaryVertexNumTracks = std::vector<int>(*m_PrimaryVertexNumTracks);\
   o_m_ElectronAuthor = std::vector<int>(*m_ElectronAuthor);\
   o_m_ElectronEta = std::vector<float>(*m_ElectronEta);\
   o_m_ElectronPt = std::vector<float>(*m_ElectronPt);\
   o_m_ElectronPhi = std::vector<float>(*m_ElectronPhi);\
   o_m_ElectronClusterE = std::vector<float>(*m_ElectronClusterE);\
   o_m_ElectronClusterEta = std::vector<float>(*m_ElectronClusterEta);\
   o_m_ElectronClusterPhi = std::vector<float>(*m_ElectronClusterPhi);\
   o_m_JetPt = std::vector<float>(*m_JetPt);\
   o_m_JetEta = std::vector<float>(*m_JetEta);\
   o_m_JetPhi = std::vector<float>(*m_JetPhi);\
   o_m_JetE = std::vector<float>(*m_JetE);\
   o_m_JetPullMag = std::vector<float>(*m_JetPullMag);\
   o_m_JetPullPhi = std::vector<float>(*m_JetPullPhi);\
   o_m_JetWeightSV0 = std::vector<double>(*m_JetWeightSV0);\
   o_m_JetIsUgly = std::vector<int>(*m_JetIsUgly);\
   o_m_JetIsBad = std::vector<int>(*m_JetIsBad);\
   o_m_MetForTopAna = m_MetForTopAna;\
   o_m_MetForTopAnaPhi = m_MetForTopAnaPhi;\
   o_m_NumPrimaryVertices = m_NumPrimaryVertices;\
   o_m_NumJets = m_NumJets;\
   o_m_NumMuons = m_NumMuons;\
  }
#endif

//end definitions DEF_FILTER


#if DUKHEPFILTER_TYPE == ELE_FILTER
#define INIT_NULLS_CTOR		\
m_NumElectrons(0),	\
o_m_NumElectrons(0),	\
m_ElectronTrackPt(0),	\
o_m_ElectronTrackPt(0),	\
m_ElectronTrackQoverP(0),	\
o_m_ElectronTrackQoverP(0),	\
m_ElectronTrackEta(0),	\
o_m_ElectronTrackEta(0),	\
m_ElectronTrackPhi(0),	\
o_m_ElectronTrackPhi(0),	\
m_ElectronTrackNPixelHits(0),	\
m_ElectronTrackNSCTHits(0),	\
m_ElectronTrackNBLayerHits(0),	\
m_ElectronTrackNTRTHits(0),	\
m_ElectronTrackNTRTHighThresholdHits(0),	\
m_ElectronTrackD0(0),	\
o_m_ElectronTrackD0(0),	\
m_ElectronTrackZ0(0),	\
m_ElectronIsoCone20(0),	\
o_m_ElectronIsoCone20(0),	\
m_ElectronAuthor(0),	\
o_m_ElectronAuthor(0),	\
m_ElectronMedium(0),	\
o_m_ElectronMedium(0),	\
m_ElectronOQ(0),	\
o_m_ElectronOQ(0),	\
m_ElectronClusterE(0),	\
o_m_ElectronClusterE(0),	\
m_ElectronClusterEta(0),	\
o_m_ElectronClusterEta(0),	\
m_ElectronClusterPhi(0),	\
o_m_ElectronClusterPhi(0),	\
m_ElectronClusterPt(0),	\
o_m_ElectronClusterPt(0),	\
m_ElectronCharge(0),	\
o_m_ElectronCharge(0),	\
m_ElectronEFDistance(0),	\
o_m_ElectronEFDistance(0),	\
m_RunNumber(0),	\
o_m_RunNumber(0),	\
m_EventNumber(0),	\
o_m_EventNumber(0),	\
m_LumiBlock(0),	\
o_m_LumiBlock(0),	\
m_MCEventWeight(0),	\
o_m_MCEventWeight(0),	\
m_PrimaryVertexType(0),	\
o_m_PrimaryVertexType(0),	\
m_PrimaryVertexNumTracks(0),	\
o_m_PrimaryVertexNumTracks(0),	\
m_ElectronEta(0),	\
o_m_ElectronEta(0),	\
m_ElectronPt(0),	\
o_m_ElectronPt(0),	\
m_ElectronPhi(0),	\
o_m_ElectronPhi(0),	\
m_JetPt(0),	\
o_m_JetPt(0),	\
m_JetEta(0),	\
o_m_JetEta(0),	\
m_JetPhi(0),	\
o_m_JetPhi(0),	\
m_JetE(0),	\
o_m_JetE(0),	\
m_JetPullMag(0),	\
o_m_JetPullMag(0),	\
m_JetPullPhi(0),	\
o_m_JetPullPhi(0),	\
m_JetWeightSV0(0),	\
o_m_JetWeightSV0(0),	\
m_JetIsUgly(0),	\
o_m_JetIsUgly(0),	\
m_JetIsBad(0),	\
o_m_JetIsBad(0),	\
m_MetForTopAna(0),	\
o_m_MetForTopAna(0),	\
m_MetForTopAnaPhi(0),	\
o_m_MetForTopAnaPhi(0),	\
m_MuonAuthor(0),	\
m_MuonEta(0),	\
m_MuonStacoMatchChi2(0),	\
m_MuonStacoMatchDOF(0),	\
m_MuonIsoEtCone20(0),	\
m_MuonIsoPtCone30(0),	\
m_MuonPt(0),	\
m_MuonPhi(0),	\
m_NumTopElectrons(0),	\
m_NumTopMuons(0),	\
m_NumTopJets(0),	\
m_IndexTopElectron(0),	\
m_IndexTopMuon(0),	\
m_IndexTopJet(0),	\
m_UseTopJet(0),	\
m_TopEleInTrigger(0),	\
m_TopMuInTrigger(0),	\
m_OverlapEleMu(0),	\
m_NumPrimaryVertices(0),	\
o_m_NumPrimaryVertices(0),	\
m_NumJets(0),	\
o_m_NumJets(0),	\
m_NumMuons(0),	\
o_m_NumMuons(0)
#endif



#if DUKHEPFILTER_TYPE == ELE_FILTER
#define DUKEHEPHEADER_MEMBERS                          \
Int_t m_NumElectrons;	\
Int_t o_m_NumElectrons;	\
std::vector<float>* m_ElectronTrackPt;	\
std::vector<float> o_m_ElectronTrackPt;	\
std::vector<float>* m_ElectronTrackQoverP;	\
std::vector<float> o_m_ElectronTrackQoverP;	\
std::vector<float>* m_ElectronTrackEta;	\
std::vector<float> o_m_ElectronTrackEta;	\
std::vector<float>* m_ElectronTrackPhi;	\
std::vector<float> o_m_ElectronTrackPhi;	\
std::vector<int>* m_ElectronTrackNPixelHits;	\
std::vector<int>* m_ElectronTrackNSCTHits;	\
std::vector<int>* m_ElectronTrackNBLayerHits;	\
std::vector<int>* m_ElectronTrackNTRTHits;	\
std::vector<int>* m_ElectronTrackNTRTHighThresholdHits;	\
std::vector<float>* m_ElectronTrackD0;	\
std::vector<float> o_m_ElectronTrackD0;	\
std::vector<float>* m_ElectronTrackZ0;	\
std::vector<float>* m_ElectronIsoCone20;	\
std::vector<float> o_m_ElectronIsoCone20;	\
std::vector<int>* m_ElectronAuthor;	\
std::vector<int> o_m_ElectronAuthor;	\
std::vector<int>* m_ElectronMedium;	\
std::vector<int> o_m_ElectronMedium;	\
std::vector<unsigned int>* m_ElectronOQ;	\
std::vector<unsigned int> o_m_ElectronOQ;	\
std::vector<float>* m_ElectronClusterE;	\
std::vector<float> o_m_ElectronClusterE;	\
std::vector<float>* m_ElectronClusterEta;	\
std::vector<float> o_m_ElectronClusterEta;	\
std::vector<float>* m_ElectronClusterPhi;	\
std::vector<float> o_m_ElectronClusterPhi;	\
std::vector<float>* m_ElectronClusterPt;	\
std::vector<float> o_m_ElectronClusterPt;	\
std::vector<float>* m_ElectronCharge;	\
std::vector<float> o_m_ElectronCharge;	\
std::vector<float>* m_ElectronEFDistance;	\
std::vector<float> o_m_ElectronEFDistance;	\
UInt_t m_RunNumber;	\
UInt_t o_m_RunNumber;	\
UInt_t m_EventNumber;	\
UInt_t o_m_EventNumber;	\
UInt_t m_LumiBlock;	\
UInt_t o_m_LumiBlock;	\
Float_t m_MCEventWeight;	\
Float_t o_m_MCEventWeight;	\
std::vector<int>* m_PrimaryVertexType;	\
std::vector<int> o_m_PrimaryVertexType;	\
std::vector<int>* m_PrimaryVertexNumTracks;	\
std::vector<int> o_m_PrimaryVertexNumTracks;	\
std::vector<float>* m_ElectronEta;	\
std::vector<float> o_m_ElectronEta;	\
std::vector<float>* m_ElectronPt;	\
std::vector<float> o_m_ElectronPt;	\
std::vector<float>* m_ElectronPhi;	\
std::vector<float> o_m_ElectronPhi;	\
std::vector<float>* m_JetPt;	\
std::vector<float> o_m_JetPt;	\
std::vector<float>* m_JetEta;	\
std::vector<float> o_m_JetEta;	\
std::vector<float>* m_JetPhi;	\
std::vector<float> o_m_JetPhi;	\
std::vector<float>* m_JetE;	\
std::vector<float> o_m_JetE;	\
std::vector<float>* m_JetPullMag;	\
std::vector<float> o_m_JetPullMag;	\
std::vector<float>* m_JetPullPhi;	\
std::vector<float> o_m_JetPullPhi;	\
std::vector<double>* m_JetWeightSV0;	\
std::vector<double> o_m_JetWeightSV0;	\
std::vector<int>* m_JetIsUgly;	\
std::vector<int> o_m_JetIsUgly;	\
std::vector<int>* m_JetIsBad;	\
std::vector<int> o_m_JetIsBad;	\
float m_MetForTopAna;	\
float o_m_MetForTopAna;	\
float m_MetForTopAnaPhi;	\
float o_m_MetForTopAnaPhi;	\
std::vector<int>* m_MuonAuthor;	\
std::vector<float>* m_MuonEta;	\
std::vector<float>* m_MuonStacoMatchChi2;	\
std::vector<int>* m_MuonStacoMatchDOF;	\
std::vector<float>* m_MuonIsoEtCone20;	\
std::vector<float>* m_MuonIsoPtCone30;	\
std::vector<float>* m_MuonPt;	\
std::vector<float>* m_MuonPhi;	\
Int_t m_NumTopElectrons;	\
Int_t m_NumTopMuons;	\
Int_t m_NumTopJets;	\
std::vector<int>* m_IndexTopElectron;	\
std::vector<int>* m_IndexTopMuon;	\
std::vector<int>* m_IndexTopJet;	\
std::vector<int>* m_UseTopJet;	\
std::vector<int>* m_TopEleInTrigger;	\
std::vector<int>* m_TopMuInTrigger;	\
std::vector<int>* m_OverlapEleMu;	\
Int_t m_NumPrimaryVertices;	\
Int_t o_m_NumPrimaryVertices;	\
Int_t m_NumJets;	\
Int_t o_m_NumJets;	\
Int_t m_NumMuons;	\
Int_t o_m_NumMuons;
#endif



#if DUKHEPFILTER_TYPE == ELE_FILTER
#define CONNECT( stringTREENAME )                      \
  {    ConnectVariable( (stringTREENAME), "el_n", m_NumElectrons );	\
    ConnectVariable( (stringTREENAME), "el_trackpt", m_ElectronTrackPt );	\
    ConnectVariable( (stringTREENAME), "el_trackqoverp", m_ElectronTrackQoverP );	\
    ConnectVariable( (stringTREENAME), "el_tracketa", m_ElectronTrackEta );	\
    ConnectVariable( (stringTREENAME), "el_trackphi", m_ElectronTrackPhi );	\
    ConnectVariable( (stringTREENAME), "el_nPixHits", m_ElectronTrackNPixelHits );	\
    ConnectVariable( (stringTREENAME), "el_nSCTHits", m_ElectronTrackNSCTHits );	\
    ConnectVariable( (stringTREENAME), "el_nBLHits", m_ElectronTrackNBLayerHits );	\
    ConnectVariable( (stringTREENAME), "el_nTRTHits", m_ElectronTrackNTRTHits );	\
    ConnectVariable( (stringTREENAME), "el_nTRTHighTHits", m_ElectronTrackNTRTHighThresholdHits );	\
    ConnectVariable( (stringTREENAME), "el_trackd0_physics", m_ElectronTrackD0 );	\
    ConnectVariable( (stringTREENAME), "el_trackz0", m_ElectronTrackZ0 );	\
    ConnectVariable( (stringTREENAME), "el_Etcone20", m_ElectronIsoCone20 );	\
    ConnectVariable( (stringTREENAME), "el_author", m_ElectronAuthor );	\
    ConnectVariable( (stringTREENAME), "el_medium", m_ElectronMedium );	\
    ConnectVariable( (stringTREENAME), "el_OQ", m_ElectronOQ );	\
    ConnectVariable( (stringTREENAME), "el_cl_E", m_ElectronClusterE );	\
    ConnectVariable( (stringTREENAME), "el_cl_eta", m_ElectronClusterEta );	\
    ConnectVariable( (stringTREENAME), "el_cl_phi", m_ElectronClusterPhi );	\
    ConnectVariable( (stringTREENAME), "el_cl_pt", m_ElectronClusterPt );	\
    ConnectVariable( (stringTREENAME), "el_charge", m_ElectronCharge );	\
    ConnectVariable( (stringTREENAME), "el_EF_dr", m_ElectronEFDistance );	\
    ConnectVariable( (stringTREENAME), "RunNumber", m_RunNumber );	\
    ConnectVariable( (stringTREENAME), "EventNumber", m_EventNumber );	\
    ConnectVariable( (stringTREENAME), "lbn", m_LumiBlock );	\
    ConnectVariable( (stringTREENAME), "mcevt_weight", m_MCEventWeight );	\
    ConnectVariable( (stringTREENAME), "vxp_type", m_PrimaryVertexType );	\
    ConnectVariable( (stringTREENAME), "vxp_nTracks", m_PrimaryVertexNumTracks );	\
    ConnectVariable( (stringTREENAME), "el_eta", m_ElectronEta );	\
    ConnectVariable( (stringTREENAME), "el_pt", m_ElectronPt );	\
    ConnectVariable( (stringTREENAME), "el_phi", m_ElectronPhi );	\
    ConnectVariable( (stringTREENAME), "jet_pt", m_JetPt );	\
    ConnectVariable( (stringTREENAME), "jet_eta", m_JetEta );	\
    ConnectVariable( (stringTREENAME), "jet_phi", m_JetPhi );	\
    ConnectVariable( (stringTREENAME), "jet_E", m_JetE );	\
    ConnectVariable( (stringTREENAME), "jet_PullMag", m_JetPullMag );	\
    ConnectVariable( (stringTREENAME), "jet_PullPhi", m_JetPullPhi );	\
    ConnectVariable( (stringTREENAME), "jet_flavor_weight_SV0", m_JetWeightSV0 );	\
    ConnectVariable( (stringTREENAME), "jet_isUgly", m_JetIsUgly );	\
    ConnectVariable( (stringTREENAME), "jet_isBadLoose", m_JetIsBad );	\
    ConnectVariable( (stringTREENAME), "topMET_et", m_MetForTopAna );	\
    ConnectVariable( (stringTREENAME), "topMET_phi", m_MetForTopAnaPhi );	\
    ConnectVariable( (stringTREENAME), "mu_author", m_MuonAuthor );	\
    ConnectVariable( (stringTREENAME), "mu_eta", m_MuonEta );	\
    ConnectVariable( (stringTREENAME), "mu_matchchi2", m_MuonStacoMatchChi2 );	\
    ConnectVariable( (stringTREENAME), "mu_matchndof", m_MuonStacoMatchDOF );	\
    ConnectVariable( (stringTREENAME), "mu_etcone20", m_MuonIsoEtCone20 );	\
    ConnectVariable( (stringTREENAME), "mu_etcone30", m_MuonIsoPtCone30 );	\
    ConnectVariable( (stringTREENAME), "mu_pt", m_MuonPt );	\
    ConnectVariable( (stringTREENAME), "mu_phi", m_MuonPhi );	\
    ConnectVariable( (stringTREENAME), "topEl_n", m_NumTopElectrons );	\
    ConnectVariable( (stringTREENAME), "topMu_n", m_NumTopMuons );	\
    ConnectVariable( (stringTREENAME), "topJet_n", m_NumTopJets );	\
    ConnectVariable( (stringTREENAME), "topEl_index", m_IndexTopElectron );	\
    ConnectVariable( (stringTREENAME), "topMu_index", m_IndexTopMuon );	\
    ConnectVariable( (stringTREENAME), "topJet_index", m_IndexTopJet );	\
    ConnectVariable( (stringTREENAME), "topJet_use", m_UseTopJet );	\
    ConnectVariable( (stringTREENAME), "topEl_inTrigger", m_TopEleInTrigger );	\
    ConnectVariable( (stringTREENAME), "topMu_inTrigger", m_TopMuInTrigger );	\
    ConnectVariable( (stringTREENAME), "top_isEleMuOverlap", m_OverlapEleMu );	\
    ConnectVariable( (stringTREENAME), "vxp_n", m_NumPrimaryVertices );	\
    ConnectVariable( (stringTREENAME), "jet_n", m_NumJets );	\
    ConnectVariable( (stringTREENAME), "mu_n", m_NumMuons );	\
  }
#endif



#if DUKHEPFILTER_TYPE == ELE_FILTER
#define DECLARE( stringTREENAME )                      \
  {    DeclareVariable( o_m_NumElectrons, "el_n" );	\
    DeclareVariable( o_m_ElectronTrackPt, "el_trackpt" );	\
    DeclareVariable( o_m_ElectronTrackQoverP, "el_trackqoverp" );	\
    DeclareVariable( o_m_ElectronTrackEta, "el_tracketa" );	\
    DeclareVariable( o_m_ElectronTrackPhi, "el_trackphi" );	\
    DeclareVariable( o_m_ElectronTrackD0, "el_trackd0_physics" );	\
    DeclareVariable( o_m_ElectronIsoCone20, "el_Etcone20" );	\
    DeclareVariable( o_m_ElectronAuthor, "el_author" );	\
    DeclareVariable( o_m_ElectronMedium, "el_medium" );	\
    DeclareVariable( o_m_ElectronOQ, "el_OQ" );	\
    DeclareVariable( o_m_ElectronClusterE, "el_cl_E" );	\
    DeclareVariable( o_m_ElectronClusterEta, "el_cl_eta" );	\
    DeclareVariable( o_m_ElectronClusterPhi, "el_cl_phi" );	\
    DeclareVariable( o_m_ElectronClusterPt, "el_cl_pt" );	\
    DeclareVariable( o_m_ElectronCharge, "el_charge" );	\
    DeclareVariable( o_m_ElectronEFDistance, "el_EF_dr" );	\
    DeclareVariable( o_m_RunNumber, "RunNumber" );	\
    DeclareVariable( o_m_EventNumber, "EventNumber" );	\
    DeclareVariable( o_m_LumiBlock, "lbn" );	\
    DeclareVariable( o_m_MCEventWeight, "mcevt_weight" );	\
    DeclareVariable( o_m_PrimaryVertexType, "vxp_type" );	\
    DeclareVariable( o_m_PrimaryVertexNumTracks, "vxp_nTracks" );	\
    DeclareVariable( o_m_ElectronEta, "el_eta" );	\
    DeclareVariable( o_m_ElectronPt, "el_pt" );	\
    DeclareVariable( o_m_ElectronPhi, "el_phi" );	\
    DeclareVariable( o_m_JetPt, "jet_pt" );	\
    DeclareVariable( o_m_JetEta, "jet_eta" );	\
    DeclareVariable( o_m_JetPhi, "jet_phi" );	\
    DeclareVariable( o_m_JetE, "jet_E" );	\
    DeclareVariable( o_m_JetPullMag, "jet_PullMag" );	\
    DeclareVariable( o_m_JetPullPhi, "jet_PullPhi" );	\
    DeclareVariable( o_m_JetWeightSV0, "jet_flavor_weight_SV0" );	\
    DeclareVariable( o_m_JetIsUgly, "jet_isUgly" );	\
    DeclareVariable( o_m_JetIsBad, "jet_isBadLoose" );	\
    DeclareVariable( o_m_MetForTopAna, "topMET_et" );	\
    DeclareVariable( o_m_MetForTopAnaPhi, "topMET_phi" );	\
    DeclareVariable( o_m_NumPrimaryVertices, "vxp_n" );	\
    DeclareVariable( o_m_NumJets, "jet_n" );	\
    DeclareVariable( o_m_NumMuons, "mu_n" );	\
  }
#endif



#if DUKHEPFILTER_TYPE == ELE_FILTER
#define RESETVAR                      \
  {    o_m_NumElectrons = -999;\
    o_m_ElectronTrackPt.clear();\
    o_m_ElectronTrackQoverP.clear();\
    o_m_ElectronTrackEta.clear();\
    o_m_ElectronTrackPhi.clear();\
    o_m_ElectronTrackD0.clear();\
    o_m_ElectronIsoCone20.clear();\
    o_m_ElectronAuthor.clear();\
    o_m_ElectronMedium.clear();\
    o_m_ElectronOQ.clear();\
    o_m_ElectronClusterE.clear();\
    o_m_ElectronClusterEta.clear();\
    o_m_ElectronClusterPhi.clear();\
    o_m_ElectronClusterPt.clear();\
    o_m_ElectronCharge.clear();\
    o_m_ElectronEFDistance.clear();\
    o_m_RunNumber = -999;\
    o_m_EventNumber = -999;\
    o_m_LumiBlock = -999;\
    o_m_MCEventWeight = -999;\
    o_m_PrimaryVertexType.clear();\
    o_m_PrimaryVertexNumTracks.clear();\
    o_m_ElectronEta.clear();\
    o_m_ElectronPt.clear();\
    o_m_ElectronPhi.clear();\
    o_m_JetPt.clear();\
    o_m_JetEta.clear();\
    o_m_JetPhi.clear();\
    o_m_JetE.clear();\
    o_m_JetPullMag.clear();\
    o_m_JetPullPhi.clear();\
    o_m_JetWeightSV0.clear();\
    o_m_JetIsUgly.clear();\
    o_m_JetIsBad.clear();\
    o_m_MetForTopAna = -999;\
    o_m_MetForTopAnaPhi = -999;\
    o_m_NumPrimaryVertices = -999;\
    o_m_NumJets = -999;\
    o_m_NumMuons = -999;\
  }
#endif



#if DUKHEPFILTER_TYPE == ELE_FILTER
#define COPYVAR                      \
  {   o_m_NumElectrons = m_NumElectrons;\
   o_m_ElectronTrackPt = std::vector<float>(*m_ElectronTrackPt);\
   o_m_ElectronTrackQoverP = std::vector<float>(*m_ElectronTrackQoverP);\
   o_m_ElectronTrackEta = std::vector<float>(*m_ElectronTrackEta);\
   o_m_ElectronTrackPhi = std::vector<float>(*m_ElectronTrackPhi);\
   o_m_ElectronTrackD0 = std::vector<float>(*m_ElectronTrackD0);\
   o_m_ElectronIsoCone20 = std::vector<float>(*m_ElectronIsoCone20);\
   o_m_ElectronAuthor = std::vector<int>(*m_ElectronAuthor);\
   o_m_ElectronMedium = std::vector<int>(*m_ElectronMedium);\
   o_m_ElectronOQ = std::vector<unsigned int>(*m_ElectronOQ);\
   o_m_ElectronClusterE = std::vector<float>(*m_ElectronClusterE);\
   o_m_ElectronClusterEta = std::vector<float>(*m_ElectronClusterEta);\
   o_m_ElectronClusterPhi = std::vector<float>(*m_ElectronClusterPhi);\
   o_m_ElectronClusterPt = std::vector<float>(*m_ElectronClusterPt);\
   o_m_ElectronCharge = std::vector<float>(*m_ElectronCharge);\
   o_m_ElectronEFDistance = std::vector<float>(*m_ElectronEFDistance);\
   o_m_RunNumber = m_RunNumber;\
   o_m_EventNumber = m_EventNumber;\
   o_m_LumiBlock = m_LumiBlock;\
   o_m_MCEventWeight = m_MCEventWeight;\
   o_m_PrimaryVertexType = std::vector<int>(*m_PrimaryVertexType);\
   o_m_PrimaryVertexNumTracks = std::vector<int>(*m_PrimaryVertexNumTracks);\
   o_m_ElectronEta = std::vector<float>(*m_ElectronEta);\
   o_m_ElectronPt = std::vector<float>(*m_ElectronPt);\
   o_m_ElectronPhi = std::vector<float>(*m_ElectronPhi);\
   o_m_JetPt = std::vector<float>(*m_JetPt);\
   o_m_JetEta = std::vector<float>(*m_JetEta);\
   o_m_JetPhi = std::vector<float>(*m_JetPhi);\
   o_m_JetE = std::vector<float>(*m_JetE);\
   o_m_JetPullMag = std::vector<float>(*m_JetPullMag);\
   o_m_JetPullPhi = std::vector<float>(*m_JetPullPhi);\
   o_m_JetWeightSV0 = std::vector<double>(*m_JetWeightSV0);\
   o_m_JetIsUgly = std::vector<int>(*m_JetIsUgly);\
   o_m_JetIsBad = std::vector<int>(*m_JetIsBad);\
   o_m_MetForTopAna = m_MetForTopAna;\
   o_m_MetForTopAnaPhi = m_MetForTopAnaPhi;\
   o_m_NumPrimaryVertices = m_NumPrimaryVertices;\
   o_m_NumJets = m_NumJets;\
   o_m_NumMuons = m_NumMuons;\
  }
#endif


//end definitions ELE_FILTER

#if DUKHEPFILTER_TYPE == WELE_FILTER
#define INIT_NULLS_CTOR		\
m_NumElectrons(0),	\
o_m_NumElectrons(0),	\
m_ElectronTrackPt(0),	\
o_m_ElectronTrackPt(0),	\
m_ElectronTrackQoverP(0),	\
o_m_ElectronTrackQoverP(0),	\
m_ElectronTrackEta(0),	\
o_m_ElectronTrackEta(0),	\
m_ElectronTrackPhi(0),	\
o_m_ElectronTrackPhi(0),	\
m_ElectronTrackNPixelHits(0),	\
m_ElectronTrackNSCTHits(0),	\
m_ElectronTrackNBLayerHits(0),	\
m_ElectronTrackNTRTHits(0),	\
m_ElectronTrackNTRTHighThresholdHits(0),	\
m_ElectronTrackD0(0),	\
o_m_ElectronTrackD0(0),	\
m_ElectronTrackZ0(0),	\
m_ElectronIsoCone20(0),	\
o_m_ElectronIsoCone20(0),	\
m_ElectronAuthor(0),	\
o_m_ElectronAuthor(0),	\
m_ElectronMedium(0),	\
o_m_ElectronMedium(0),	\
m_ElectronOQ(0),	\
o_m_ElectronOQ(0),	\
m_ElectronClusterE(0),	\
o_m_ElectronClusterE(0),	\
m_ElectronClusterEta(0),	\
o_m_ElectronClusterEta(0),	\
m_ElectronClusterPhi(0),	\
o_m_ElectronClusterPhi(0),	\
m_ElectronClusterPt(0),	\
o_m_ElectronClusterPt(0),	\
m_ElectronCharge(0),	\
o_m_ElectronCharge(0),	\
m_ElectronEFDistance(0),	\
o_m_ElectronEFDistance(0),	\
m_RunNumber(0),	\
o_m_RunNumber(0),	\
m_EventNumber(0),	\
o_m_EventNumber(0),	\
m_LumiBlock(0),	\
o_m_LumiBlock(0),	\
m_PrimaryVertexType(0),	\
o_m_PrimaryVertexType(0),	\
m_PrimaryVertexNumTracks(0),	\
o_m_PrimaryVertexNumTracks(0),	\
m_ElectronEta(0),	\
o_m_ElectronEta(0),	\
m_ElectronPt(0),	\
o_m_ElectronPt(0),	\
m_ElectronPhi(0),	\
o_m_ElectronPhi(0),	\
m_ElectronEtHadOne(0),	\
o_m_ElectronEtHadOne(0),	\
m_ElectronF1(0),	\
o_m_ElectronF1(0),	\
m_JetPt(0),	\
m_JetEta(0),	\
m_JetPhi(0),	\
m_JetE(0),	\
m_JetWeightSV0(0),	\
m_JetIsUgly(0),	\
m_JetIsBad(0),	\
m_MetForTopAna(0),	\
m_MetForTopAnaPhi(0),	\
m_MuonAuthor(0),	\
m_MuonEta(0),	\
m_MuonStacoMatchChi2(0),	\
m_MuonStacoMatchDOF(0),	\
m_MuonIsoEtCone20(0),	\
m_MuonIsoPtCone30(0),	\
m_MuonPt(0),	\
m_MuonPhi(0),	\
m_NumPrimaryVertices(0),	\
o_m_NumPrimaryVertices(0),	\
m_NumJets(0),	\
m_NumMuons(0)
#endif



#if DUKHEPFILTER_TYPE == WELE_FILTER
#define DUKEHEPHEADER_MEMBERS                          \
Int_t m_NumElectrons;	\
Int_t o_m_NumElectrons;	\
std::vector<float>* m_ElectronTrackPt;	\
std::vector<float> o_m_ElectronTrackPt;	\
std::vector<float>* m_ElectronTrackQoverP;	\
std::vector<float> o_m_ElectronTrackQoverP;	\
std::vector<float>* m_ElectronTrackEta;	\
std::vector<float> o_m_ElectronTrackEta;	\
std::vector<float>* m_ElectronTrackPhi;	\
std::vector<float> o_m_ElectronTrackPhi;	\
std::vector<int>* m_ElectronTrackNPixelHits;	\
std::vector<int>* m_ElectronTrackNSCTHits;	\
std::vector<int>* m_ElectronTrackNBLayerHits;	\
std::vector<int>* m_ElectronTrackNTRTHits;	\
std::vector<int>* m_ElectronTrackNTRTHighThresholdHits;	\
std::vector<float>* m_ElectronTrackD0;	\
std::vector<float> o_m_ElectronTrackD0;	\
std::vector<float>* m_ElectronTrackZ0;	\
std::vector<float>* m_ElectronIsoCone20;	\
std::vector<float> o_m_ElectronIsoCone20;	\
std::vector<int>* m_ElectronAuthor;	\
std::vector<int> o_m_ElectronAuthor;	\
std::vector<int>* m_ElectronMedium;	\
std::vector<int> o_m_ElectronMedium;	\
std::vector<unsigned int>* m_ElectronOQ;	\
std::vector<unsigned int> o_m_ElectronOQ;	\
std::vector<float>* m_ElectronClusterE;	\
std::vector<float> o_m_ElectronClusterE;	\
std::vector<float>* m_ElectronClusterEta;	\
std::vector<float> o_m_ElectronClusterEta;	\
std::vector<float>* m_ElectronClusterPhi;	\
std::vector<float> o_m_ElectronClusterPhi;	\
std::vector<float>* m_ElectronClusterPt;	\
std::vector<float> o_m_ElectronClusterPt;	\
std::vector<float>* m_ElectronCharge;	\
std::vector<float> o_m_ElectronCharge;	\
std::vector<float>* m_ElectronEFDistance;	\
std::vector<float> o_m_ElectronEFDistance;	\
UInt_t m_RunNumber;	\
UInt_t o_m_RunNumber;	\
UInt_t m_EventNumber;	\
UInt_t o_m_EventNumber;	\
UInt_t m_LumiBlock;	\
UInt_t o_m_LumiBlock;	\
std::vector<int>* m_PrimaryVertexType;	\
std::vector<int> o_m_PrimaryVertexType;	\
std::vector<int>* m_PrimaryVertexNumTracks;	\
std::vector<int> o_m_PrimaryVertexNumTracks;	\
std::vector<float>* m_ElectronEta;	\
std::vector<float> o_m_ElectronEta;	\
std::vector<float>* m_ElectronPt;	\
std::vector<float> o_m_ElectronPt;	\
std::vector<float>* m_ElectronPhi;	\
std::vector<float> o_m_ElectronPhi;	\
std::vector<float>* m_ElectronEtHadOne;	\
std::vector<float> o_m_ElectronEtHadOne;	\
std::vector<float>* m_ElectronF1;	\
std::vector<float> o_m_ElectronF1;	\
std::vector<float>* m_JetPt;	\
std::vector<float>* m_JetEta;	\
std::vector<float>* m_JetPhi;	\
std::vector<float>* m_JetE;	\
std::vector<double>* m_JetWeightSV0;	\
std::vector<int>* m_JetIsUgly;	\
std::vector<int>* m_JetIsBad;	\
float m_MetForTopAna;	\
float m_MetForTopAnaPhi;	\
std::vector<int>* m_MuonAuthor;	\
std::vector<float>* m_MuonEta;	\
std::vector<float>* m_MuonStacoMatchChi2;	\
std::vector<int>* m_MuonStacoMatchDOF;	\
std::vector<float>* m_MuonIsoEtCone20;	\
std::vector<float>* m_MuonIsoPtCone30;	\
std::vector<float>* m_MuonPt;	\
std::vector<float>* m_MuonPhi;	\
Int_t m_NumPrimaryVertices;	\
Int_t o_m_NumPrimaryVertices;	\
Int_t m_NumJets;	\
Int_t m_NumMuons;
#endif



#if DUKHEPFILTER_TYPE == WELE_FILTER
#define CONNECT( stringTREENAME )                      \
  {    ConnectVariable( (stringTREENAME), "el_n", m_NumElectrons );	\
    ConnectVariable( (stringTREENAME), "el_trackpt", m_ElectronTrackPt );	\
    ConnectVariable( (stringTREENAME), "el_trackqoverp", m_ElectronTrackQoverP );	\
    ConnectVariable( (stringTREENAME), "el_tracketa", m_ElectronTrackEta );	\
    ConnectVariable( (stringTREENAME), "el_trackphi", m_ElectronTrackPhi );	\
    ConnectVariable( (stringTREENAME), "el_nPixHits", m_ElectronTrackNPixelHits );	\
    ConnectVariable( (stringTREENAME), "el_nSCTHits", m_ElectronTrackNSCTHits );	\
    ConnectVariable( (stringTREENAME), "el_nBLHits", m_ElectronTrackNBLayerHits );	\
    ConnectVariable( (stringTREENAME), "el_nTRTHits", m_ElectronTrackNTRTHits );	\
    ConnectVariable( (stringTREENAME), "el_nTRTHighTHits", m_ElectronTrackNTRTHighThresholdHits );	\
    ConnectVariable( (stringTREENAME), "el_trackd0_physics", m_ElectronTrackD0 );	\
    ConnectVariable( (stringTREENAME), "el_trackz0", m_ElectronTrackZ0 );	\
    ConnectVariable( (stringTREENAME), "el_Etcone20", m_ElectronIsoCone20 );	\
    ConnectVariable( (stringTREENAME), "el_author", m_ElectronAuthor );	\
    ConnectVariable( (stringTREENAME), "el_medium", m_ElectronMedium );	\
    ConnectVariable( (stringTREENAME), "el_OQ", m_ElectronOQ );	\
    ConnectVariable( (stringTREENAME), "el_cl_E", m_ElectronClusterE );	\
    ConnectVariable( (stringTREENAME), "el_cl_eta", m_ElectronClusterEta );	\
    ConnectVariable( (stringTREENAME), "el_cl_phi", m_ElectronClusterPhi );	\
    ConnectVariable( (stringTREENAME), "el_cl_pt", m_ElectronClusterPt );	\
    ConnectVariable( (stringTREENAME), "el_charge", m_ElectronCharge );	\
    ConnectVariable( (stringTREENAME), "el_EF_dr", m_ElectronEFDistance );	\
    ConnectVariable( (stringTREENAME), "RunNumber", m_RunNumber );	\
    ConnectVariable( (stringTREENAME), "EventNumber", m_EventNumber );	\
    ConnectVariable( (stringTREENAME), "lbn", m_LumiBlock );	\
    ConnectVariable( (stringTREENAME), "vxp_type", m_PrimaryVertexType );	\
    ConnectVariable( (stringTREENAME), "vxp_nTracks", m_PrimaryVertexNumTracks );	\
    ConnectVariable( (stringTREENAME), "el_eta", m_ElectronEta );	\
    ConnectVariable( (stringTREENAME), "el_pt", m_ElectronPt );	\
    ConnectVariable( (stringTREENAME), "el_phi", m_ElectronPhi );	\
    ConnectVariable( (stringTREENAME), "el_Ethad1", m_ElectronEtHadOne );	\
    ConnectVariable( (stringTREENAME), "el_f1", m_ElectronF1 );	\
    ConnectVariable( (stringTREENAME), "jet_akt6topoem_pt", m_JetPt );	\
    ConnectVariable( (stringTREENAME), "jet_akt6topoem_eta", m_JetEta );	\
    ConnectVariable( (stringTREENAME), "jet_akt6topoem_phi", m_JetPhi );	\
    ConnectVariable( (stringTREENAME), "jet_akt6topoem_E", m_JetE );	\
    ConnectVariable( (stringTREENAME), "jet_akt6topoem_flavor_weight_SV0", m_JetWeightSV0 );	\
    ConnectVariable( (stringTREENAME), "jet_akt6topoem_isUgly", m_JetIsUgly );	\
    ConnectVariable( (stringTREENAME), "jet_akt6topoem_isBadLoose", m_JetIsBad );	\
    ConnectVariable( (stringTREENAME), "topMET_et", m_MetForTopAna );	\
    ConnectVariable( (stringTREENAME), "topMET_phi", m_MetForTopAnaPhi );	\
    ConnectVariable( (stringTREENAME), "mu_muid_author", m_MuonAuthor );	\
    ConnectVariable( (stringTREENAME), "mu_muid_eta", m_MuonEta );	\
    ConnectVariable( (stringTREENAME), "mu_muid_matchchi2", m_MuonStacoMatchChi2 );	\
    ConnectVariable( (stringTREENAME), "mu_muid_matchndof", m_MuonStacoMatchDOF );	\
    ConnectVariable( (stringTREENAME), "mu_muid_etcone20", m_MuonIsoEtCone20 );	\
    ConnectVariable( (stringTREENAME), "mu_muid_etcone30", m_MuonIsoPtCone30 );	\
    ConnectVariable( (stringTREENAME), "mu_muid_pt", m_MuonPt );	\
    ConnectVariable( (stringTREENAME), "mu_muid_phi", m_MuonPhi );	\
    ConnectVariable( (stringTREENAME), "vxp_n", m_NumPrimaryVertices );	\
    ConnectVariable( (stringTREENAME), "jet_akt6topoem_n", m_NumJets );	\
    ConnectVariable( (stringTREENAME), "mu_muid_n", m_NumMuons );	\
  }
#endif



#if DUKHEPFILTER_TYPE == WELE_FILTER
#define DECLARE( stringTREENAME )                      \
  {    DeclareVariable( o_m_NumElectrons, "el_n" );	\
    DeclareVariable( o_m_ElectronTrackPt, "el_trackpt" );	\
    DeclareVariable( o_m_ElectronTrackQoverP, "el_trackqoverp" );	\
    DeclareVariable( o_m_ElectronTrackEta, "el_tracketa" );	\
    DeclareVariable( o_m_ElectronTrackPhi, "el_trackphi" );	\
    DeclareVariable( o_m_ElectronTrackD0, "el_trackd0_physics" );	\
    DeclareVariable( o_m_ElectronIsoCone20, "el_Etcone20" );	\
    DeclareVariable( o_m_ElectronAuthor, "el_author" );	\
    DeclareVariable( o_m_ElectronMedium, "el_medium" );	\
    DeclareVariable( o_m_ElectronOQ, "el_OQ" );	\
    DeclareVariable( o_m_ElectronClusterE, "el_cl_E" );	\
    DeclareVariable( o_m_ElectronClusterEta, "el_cl_eta" );	\
    DeclareVariable( o_m_ElectronClusterPhi, "el_cl_phi" );	\
    DeclareVariable( o_m_ElectronClusterPt, "el_cl_pt" );	\
    DeclareVariable( o_m_ElectronCharge, "el_charge" );	\
    DeclareVariable( o_m_ElectronEFDistance, "el_EF_dr" );	\
    DeclareVariable( o_m_RunNumber, "RunNumber" );	\
    DeclareVariable( o_m_EventNumber, "EventNumber" );	\
    DeclareVariable( o_m_LumiBlock, "lbn" );	\
    DeclareVariable( o_m_PrimaryVertexType, "vxp_type" );	\
    DeclareVariable( o_m_PrimaryVertexNumTracks, "vxp_nTracks" );	\
    DeclareVariable( o_m_ElectronEta, "el_eta" );	\
    DeclareVariable( o_m_ElectronPt, "el_pt" );	\
    DeclareVariable( o_m_ElectronPhi, "el_phi" );	\
    DeclareVariable( o_m_ElectronEtHadOne, "el_Ethad1" );	\
    DeclareVariable( o_m_ElectronF1, "el_f1" );	\
    DeclareVariable( o_m_NumPrimaryVertices, "vxp_n" );	\
  }
#endif



#if DUKHEPFILTER_TYPE == WELE_FILTER
#define RESETVAR                      \
  {    o_m_NumElectrons = -999;\
    o_m_ElectronTrackPt.clear();\
    o_m_ElectronTrackQoverP.clear();\
    o_m_ElectronTrackEta.clear();\
    o_m_ElectronTrackPhi.clear();\
    o_m_ElectronTrackD0.clear();\
    o_m_ElectronIsoCone20.clear();\
    o_m_ElectronAuthor.clear();\
    o_m_ElectronMedium.clear();\
    o_m_ElectronOQ.clear();\
    o_m_ElectronClusterE.clear();\
    o_m_ElectronClusterEta.clear();\
    o_m_ElectronClusterPhi.clear();\
    o_m_ElectronClusterPt.clear();\
    o_m_ElectronCharge.clear();\
    o_m_ElectronEFDistance.clear();\
    o_m_RunNumber = -999;\
    o_m_EventNumber = -999;\
    o_m_LumiBlock = -999;\
    o_m_PrimaryVertexType.clear();\
    o_m_PrimaryVertexNumTracks.clear();\
    o_m_ElectronEta.clear();\
    o_m_ElectronPt.clear();\
    o_m_ElectronPhi.clear();\
    o_m_ElectronEtHadOne.clear();\
    o_m_ElectronF1.clear();\
    o_m_NumPrimaryVertices = -999;\
  }
#endif



#if DUKHEPFILTER_TYPE == WELE_FILTER
#define COPYVAR                      \
  {   o_m_NumElectrons = m_NumElectrons;\
   o_m_ElectronTrackPt = std::vector<float>(*m_ElectronTrackPt);\
   o_m_ElectronTrackQoverP = std::vector<float>(*m_ElectronTrackQoverP);\
   o_m_ElectronTrackEta = std::vector<float>(*m_ElectronTrackEta);\
   o_m_ElectronTrackPhi = std::vector<float>(*m_ElectronTrackPhi);\
   o_m_ElectronTrackD0 = std::vector<float>(*m_ElectronTrackD0);\
   o_m_ElectronIsoCone20 = std::vector<float>(*m_ElectronIsoCone20);\
   o_m_ElectronAuthor = std::vector<int>(*m_ElectronAuthor);\
   o_m_ElectronMedium = std::vector<int>(*m_ElectronMedium);\
   o_m_ElectronOQ = std::vector<unsigned int>(*m_ElectronOQ);\
   o_m_ElectronClusterE = std::vector<float>(*m_ElectronClusterE);\
   o_m_ElectronClusterEta = std::vector<float>(*m_ElectronClusterEta);\
   o_m_ElectronClusterPhi = std::vector<float>(*m_ElectronClusterPhi);\
   o_m_ElectronClusterPt = std::vector<float>(*m_ElectronClusterPt);\
   o_m_ElectronCharge = std::vector<float>(*m_ElectronCharge);\
   o_m_ElectronEFDistance = std::vector<float>(*m_ElectronEFDistance);\
   o_m_RunNumber = m_RunNumber;\
   o_m_EventNumber = m_EventNumber;\
   o_m_LumiBlock = m_LumiBlock;\
   o_m_PrimaryVertexType = std::vector<int>(*m_PrimaryVertexType);\
   o_m_PrimaryVertexNumTracks = std::vector<int>(*m_PrimaryVertexNumTracks);\
   o_m_ElectronEta = std::vector<float>(*m_ElectronEta);\
   o_m_ElectronPt = std::vector<float>(*m_ElectronPt);\
   o_m_ElectronPhi = std::vector<float>(*m_ElectronPhi);\
   o_m_ElectronEtHadOne = std::vector<float>(*m_ElectronEtHadOne);\
   o_m_ElectronF1 = std::vector<float>(*m_ElectronF1);\
   o_m_NumPrimaryVertices = m_NumPrimaryVertices;\
  }
#endif


//end definitions WELE_FILTER
//end macro definitions
