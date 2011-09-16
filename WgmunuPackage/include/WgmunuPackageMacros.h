////../../DukHep/bin/dukhep_create_filter.py -t WGMUNU_FILTER -f Wgmunu DataMacro.dat
#undef INIT_NULLS_CTOR
#undef DUKEHEPHEADER_MEMBERS
#undef CONNECT
#undef DECLARE
#undef RESETVAR
#undef COPYVAR

#define WGMUNU_FILTER 1
#define MONTE_CARLO_FILTER 2
//begin macro definitions

#if DUKHEPFILTER_TYPE == WGMUNU_FILTER
#define INIT_NULLS_CTOR		\
m_RunNumber(0),	\
m_EventNumber(0),	\
m_lbn(0),	\
m_larError(0),	\
m_EF_mu18_MG(0),	\
m_EF_mu40_MSonly_barrel(0),	\
m_vxp_n(0),	\
m_vxp_z(0),	\
m_vxp_nTracks(0),	\
m_vxp_trk_n(0)
#endif


#if DUKHEPFILTER_TYPE == WGMUNU_FILTER
#define DUKEHEPHEADER_MEMBERS                          \
UInt_t m_RunNumber;	\
UInt_t o_m_RunNumber;	\
UInt_t m_EventNumber;	\
UInt_t o_m_EventNumber;	\
UInt_t m_lbn;	\
UInt_t o_m_lbn;	\
UInt_t m_larError;	\
UInt_t o_m_larError;	\
Bool_t m_EF_mu18_MG;	\
Bool_t o_m_EF_mu18_MG;	\
Bool_t m_EF_mu40_MSonly_barrel;	\
Bool_t o_m_EF_mu40_MSonly_barrel;	\
Int_t m_vxp_n;	\
Int_t o_m_vxp_n;	\
std::vector<float>* m_vxp_z;	\
std::vector<float> o_m_vxp_z;	\
std::vector<int>* m_vxp_nTracks;	\
std::vector<int> o_m_vxp_nTracks;	\
std::vector<int>* m_vxp_trk_n;	\
std::vector<int> o_m_vxp_trk_n;
#endif


#if DUKHEPFILTER_TYPE == WGMUNU_FILTER
#define CONNECT( stringTREENAME )                      \
  {    ConnectVariable( (stringTREENAME), "RunNumber", m_RunNumber );	\
    ConnectVariable( (stringTREENAME), "EventNumber", m_EventNumber );	\
    ConnectVariable( (stringTREENAME), "lbn", m_lbn );	\
    ConnectVariable( (stringTREENAME), "larError", m_larError );	\
    ConnectVariable( (stringTREENAME), "EF_mu18_MG", m_EF_mu18_MG );	\
    ConnectVariable( (stringTREENAME), "EF_mu40_MSonly_barrel", m_EF_mu40_MSonly_barrel );	\
    ConnectVariable( (stringTREENAME), "vxp_n", m_vxp_n );	\
    ConnectVariable( (stringTREENAME), "vxp_z", m_vxp_z );	\
    ConnectVariable( (stringTREENAME), "vxp_nTracks", m_vxp_nTracks );	\
    ConnectVariable( (stringTREENAME), "vxp_trk_n", m_vxp_trk_n );	\
  }
#endif


#if DUKHEPFILTER_TYPE == WGMUNU_FILTER
#define DECLARE( stringTREENAME )                      \
  {    DeclareVariable( o_m_RunNumber, "RunNumber" );	\
    DeclareVariable( o_m_EventNumber, "EventNumber" );	\
    DeclareVariable( o_m_lbn, "lbn" );	\
    DeclareVariable( o_m_larError, "larError" );	\
    DeclareVariable( o_m_EF_mu18_MG, "EF_mu18_MG" );	\
    DeclareVariable( o_m_EF_mu40_MSonly_barrel, "EF_mu40_MSonly_barrel" );	\
    DeclareVariable( o_m_vxp_n, "vxp_n" );	\
    DeclareVariable( o_m_vxp_z, "vxp_z" );	\
    DeclareVariable( o_m_vxp_nTracks, "vxp_nTracks" );	\
    DeclareVariable( o_m_vxp_trk_n, "vxp_trk_n" );	\
  }
#endif


#if DUKHEPFILTER_TYPE == WGMUNU_FILTER
#define RESETVAR                      \
  {    o_m_RunNumber = -999;\
    o_m_EventNumber = -999;\
    o_m_lbn = -999;\
    o_m_larError = -999;\
    o_m_EF_mu18_MG = -999;\
    o_m_EF_mu40_MSonly_barrel = -999;\
    o_m_vxp_n = -999;\
    o_m_vxp_z.clear();\
    o_m_vxp_nTracks.clear();\
    o_m_vxp_trk_n.clear();\
  }
#endif


#if DUKHEPFILTER_TYPE == WGMUNU_FILTER
#define COPYVAR                      \
  {   o_m_RunNumber = m_RunNumber;\
   o_m_EventNumber = m_EventNumber;\
   o_m_lbn = m_lbn;\
   o_m_larError = m_larError;\
   o_m_EF_mu18_MG = m_EF_mu18_MG;\
   o_m_EF_mu40_MSonly_barrel = m_EF_mu40_MSonly_barrel;\
   o_m_vxp_n = m_vxp_n;\
   o_m_vxp_z = std::vector<float>(*m_vxp_z);\
   o_m_vxp_nTracks = std::vector<int>(*m_vxp_nTracks);\
   o_m_vxp_trk_n = std::vector<int>(*m_vxp_trk_n);\
  }
#endif

//end definitions WGMUNU_FILTER


#if DUKHEPFILTER_TYPE == MONTE_CARLO_FILTER
#define INIT_NULLS_CTOR		\
m_RunNumber(0),	\
m_EventNumber(0),	\
m_lbn(0),	\
m_larError(0),	\
m_EF_mu18_MG(0),	\
m_EF_mu40_MSonly_barrel(0),	\
m_vxp_n(0),	\
m_vxp_z(0),	\
m_vxp_nTracks(0),	\
m_vxp_sumPt(0),	\
m_vxp_type(0),	\
m_vxp_trk_n(0),	\
m_mcevt_n(0),	\
m_mcevt_signal_process_id(0),	\
m_mcevt_event_number(0),	\
m_mcevt_event_scale(0),	\
m_mcevt_alphaQCD(0),	\
m_mcevt_alphaQED(0),	\
m_mcevt_pdf_id1(0),	\
m_mcevt_pdf_id2(0),	\
m_mcevt_pdf_x1(0),	\
m_mcevt_pdf_x2(0),	\
m_mcevt_pdf_scale(0),	\
m_mcevt_pdf1(0),	\
m_mcevt_pdf2(0),	\
m_mcevt_weight(0),	\
m_mcevt_nparticle(0),	\
m_mcevt_pileUpType(0),	\
m_mc_n(0),	\
m_mc_pt(0),	\
m_mc_m(0),	\
m_mc_eta(0),	\
m_mc_phi(0),	\
m_mc_status(0),	\
m_mc_barcode(0),	\
m_mc_parents(0),	\
m_mc_children(0),	\
m_mc_pdgId(0),	\
m_mc_charge(0),	\
m_mc_vx_x(0),	\
m_mc_vx_y(0),	\
m_mc_vx_z(0),	\
m_mc_child_index(0)
#endif



#if DUKHEPFILTER_TYPE == MONTE_CARLO_FILTER
#define DUKEHEPHEADER_MEMBERS                          \
UInt_t m_RunNumber;	\
UInt_t o_m_RunNumber;	\
UInt_t m_EventNumber;	\
UInt_t o_m_EventNumber;	\
UInt_t m_lbn;	\
UInt_t o_m_lbn;	\
Uint_t m_larError;	\
Uint_t o_m_larError;	\
Bool_t m_EF_mu18_MG;	\
Bool_t o_m_EF_mu18_MG;	\
Bool_t m_EF_mu40_MSonly_barrel;	\
Bool_t o_m_EF_mu40_MSonly_barrel;	\
Int_t m_vxp_n;	\
Int_t o_m_vxp_n;	\
std::vector<float>* m_vxp_z;	\
std::vector<float> o_m_vxp_z;	\
std::vector<int>* m_vxp_nTracks;	\
std::vector<int> o_m_vxp_nTracks;	\
std::vector<float>* m_vxp_sumPt;	\
std::vector<float> o_m_vxp_sumPt;	\
std::vector<int>* m_vxp_type;	\
std::vector<int> o_m_vxp_type;	\
std::vector<int>* m_vxp_trk_n;	\
std::vector<int> o_m_vxp_trk_n;	\
Int_t m_mcevt_n;	\
Int_t o_m_mcevt_n;	\
std::vector<int>* m_mcevt_signal_process_id;	\
std::vector<int> o_m_mcevt_signal_process_id;	\
std::vector<int>* m_mcevt_event_number;	\
std::vector<int> o_m_mcevt_event_number;	\
std::vector<double>* m_mcevt_event_scale;	\
std::vector<double> o_m_mcevt_event_scale;	\
std::vector<double>* m_mcevt_alphaQCD;	\
std::vector<double> o_m_mcevt_alphaQCD;	\
std::vector<double>* m_mcevt_alphaQED;	\
std::vector<double> o_m_mcevt_alphaQED;	\
std::vector<int>* m_mcevt_pdf_id1;	\
std::vector<int> o_m_mcevt_pdf_id1;	\
std::vector<int>* m_mcevt_pdf_id2;	\
std::vector<int> o_m_mcevt_pdf_id2;	\
std::vector<double>* m_mcevt_pdf_x1;	\
std::vector<double> o_m_mcevt_pdf_x1;	\
std::vector<double>* m_mcevt_pdf_x2;	\
std::vector<double> o_m_mcevt_pdf_x2;	\
std::vector<double>* m_mcevt_pdf_scale;	\
std::vector<double> o_m_mcevt_pdf_scale;	\
std::vector<double>* m_mcevt_pdf1;	\
std::vector<double> o_m_mcevt_pdf1;	\
std::vector<double>* m_mcevt_pdf2;	\
std::vector<double> o_m_mcevt_pdf2;	\
std::vector<std::vector<double> >* m_mcevt_weight;	\
std::vector<std::vector<double> > o_m_mcevt_weight;	\
std::vector<int>* m_mcevt_nparticle;	\
std::vector<int> o_m_mcevt_nparticle;	\
std::vector<short>* m_mcevt_pileUpType;	\
std::vector<short> o_m_mcevt_pileUpType;	\
Int_t m_mc_n;	\
Int_t o_m_mc_n;	\
std::vector<float>* m_mc_pt;	\
std::vector<float> o_m_mc_pt;	\
std::vector<float>* m_mc_m;	\
std::vector<float> o_m_mc_m;	\
std::vector<float>* m_mc_eta;	\
std::vector<float> o_m_mc_eta;	\
std::vector<float>* m_mc_phi;	\
std::vector<float> o_m_mc_phi;	\
std::vector<int>* m_mc_status;	\
std::vector<int> o_m_mc_status;	\
std::vector<int>* m_mc_barcode;	\
std::vector<int> o_m_mc_barcode;	\
std::vector<std::vector<int> >* m_mc_parents;	\
std::vector<std::vector<int> > o_m_mc_parents;	\
std::vector<std::vector<int> >* m_mc_children;	\
std::vector<std::vector<int> > o_m_mc_children;	\
std::vector<int>* m_mc_pdgId;	\
std::vector<int> o_m_mc_pdgId;	\
std::vector<float>* m_mc_charge;	\
std::vector<float> o_m_mc_charge;	\
std::vector<float>* m_mc_vx_x;	\
std::vector<float> o_m_mc_vx_x;	\
std::vector<float>* m_mc_vx_y;	\
std::vector<float> o_m_mc_vx_y;	\
std::vector<float>* m_mc_vx_z;	\
std::vector<float> o_m_mc_vx_z;	\
std::vector<std::vector<int> >* m_mc_child_index;	\
std::vector<std::vector<int> > o_m_mc_child_index;
#endif



#if DUKHEPFILTER_TYPE == MONTE_CARLO_FILTER
#define CONNECT( stringTREENAME )                      \
  {    ConnectVariable( (stringTREENAME), "RunNumber", m_RunNumber );	\
    ConnectVariable( (stringTREENAME), "EventNumber", m_EventNumber );	\
    ConnectVariable( (stringTREENAME), "lbn", m_lbn );	\
    ConnectVariable( (stringTREENAME), "larError", m_larError );	\
    ConnectVariable( (stringTREENAME), "EF_mu18_MG", m_EF_mu18_MG );	\
    ConnectVariable( (stringTREENAME), "EF_mu40_MSonly_barrel", m_EF_mu40_MSonly_barrel );	\
    ConnectVariable( (stringTREENAME), "vxp_n", m_vxp_n );	\
    ConnectVariable( (stringTREENAME), "vxp_z", m_vxp_z );	\
    ConnectVariable( (stringTREENAME), "vxp_nTracks", m_vxp_nTracks );	\
    ConnectVariable( (stringTREENAME), "vxp_sumPt", m_vxp_sumPt );	\
    ConnectVariable( (stringTREENAME), "vxp_type", m_vxp_type );	\
    ConnectVariable( (stringTREENAME), "vxp_trk_n", m_vxp_trk_n );	\
    ConnectVariable( (stringTREENAME), "mcevt_n", m_mcevt_n );	\
    ConnectVariable( (stringTREENAME), "mcevt_signal_process_id", m_mcevt_signal_process_id );	\
    ConnectVariable( (stringTREENAME), "mcevt_event_number", m_mcevt_event_number );	\
    ConnectVariable( (stringTREENAME), "mcevt_event_scale", m_mcevt_event_scale );	\
    ConnectVariable( (stringTREENAME), "mcevt_alphaQCD", m_mcevt_alphaQCD );	\
    ConnectVariable( (stringTREENAME), "mcevt_alphaQED", m_mcevt_alphaQED );	\
    ConnectVariable( (stringTREENAME), "mcevt_pdf_id1", m_mcevt_pdf_id1 );	\
    ConnectVariable( (stringTREENAME), "mcevt_pdf_id2", m_mcevt_pdf_id2 );	\
    ConnectVariable( (stringTREENAME), "mcevt_pdf_x1", m_mcevt_pdf_x1 );	\
    ConnectVariable( (stringTREENAME), "mcevt_pdf_x2", m_mcevt_pdf_x2 );	\
    ConnectVariable( (stringTREENAME), "mcevt_pdf_scale", m_mcevt_pdf_scale );	\
    ConnectVariable( (stringTREENAME), "mcevt_pdf1", m_mcevt_pdf1 );	\
    ConnectVariable( (stringTREENAME), "mcevt_pdf2", m_mcevt_pdf2 );	\
    ConnectVariable( (stringTREENAME), "mcevt_weight", m_mcevt_weight );	\
    ConnectVariable( (stringTREENAME), "mcevt_nparticle", m_mcevt_nparticle );	\
    ConnectVariable( (stringTREENAME), "mcevt_pileUpType", m_mcevt_pileUpType );	\
    ConnectVariable( (stringTREENAME), "mc_n", m_mc_n );	\
    ConnectVariable( (stringTREENAME), "mc_pt", m_mc_pt );	\
    ConnectVariable( (stringTREENAME), "mc_m", m_mc_m );	\
    ConnectVariable( (stringTREENAME), "mc_eta", m_mc_eta );	\
    ConnectVariable( (stringTREENAME), "mc_phi", m_mc_phi );	\
    ConnectVariable( (stringTREENAME), "mc_status", m_mc_status );	\
    ConnectVariable( (stringTREENAME), "mc_barcode", m_mc_barcode );	\
    ConnectVariable( (stringTREENAME), "mc_parents", m_mc_parents );	\
    ConnectVariable( (stringTREENAME), "mc_children", m_mc_children );	\
    ConnectVariable( (stringTREENAME), "mc_pdgId", m_mc_pdgId );	\
    ConnectVariable( (stringTREENAME), "mc_charge", m_mc_charge );	\
    ConnectVariable( (stringTREENAME), "mc_vx_x", m_mc_vx_x );	\
    ConnectVariable( (stringTREENAME), "mc_vx_y", m_mc_vx_y );	\
    ConnectVariable( (stringTREENAME), "mc_vx_z", m_mc_vx_z );	\
    ConnectVariable( (stringTREENAME), "mc_child_index", m_mc_child_index );	\
  }
#endif



#if DUKHEPFILTER_TYPE == MONTE_CARLO_FILTER
#define DECLARE( stringTREENAME )                      \
  {    DeclareVariable( o_m_RunNumber, "RunNumber" );	\
    DeclareVariable( o_m_EventNumber, "EventNumber" );	\
    DeclareVariable( o_m_lbn, "lbn" );	\
    DeclareVariable( o_m_larError, "larError" );	\
    DeclareVariable( o_m_EF_mu18_MG, "EF_mu18_MG" );	\
    DeclareVariable( o_m_EF_mu40_MSonly_barrel, "EF_mu40_MSonly_barrel" );	\
    DeclareVariable( o_m_vxp_n, "vxp_n" );	\
    DeclareVariable( o_m_vxp_z, "vxp_z" );	\
    DeclareVariable( o_m_vxp_nTracks, "vxp_nTracks" );	\
    DeclareVariable( o_m_vxp_sumPt, "vxp_sumPt" );	\
    DeclareVariable( o_m_vxp_type, "vxp_type" );	\
    DeclareVariable( o_m_vxp_trk_n, "vxp_trk_n" );	\
    DeclareVariable( o_m_mcevt_n, "mcevt_n" );	\
    DeclareVariable( o_m_mcevt_signal_process_id, "mcevt_signal_process_id" );	\
    DeclareVariable( o_m_mcevt_event_number, "mcevt_event_number" );	\
    DeclareVariable( o_m_mcevt_event_scale, "mcevt_event_scale" );	\
    DeclareVariable( o_m_mcevt_alphaQCD, "mcevt_alphaQCD" );	\
    DeclareVariable( o_m_mcevt_alphaQED, "mcevt_alphaQED" );	\
    DeclareVariable( o_m_mcevt_pdf_id1, "mcevt_pdf_id1" );	\
    DeclareVariable( o_m_mcevt_pdf_id2, "mcevt_pdf_id2" );	\
    DeclareVariable( o_m_mcevt_pdf_x1, "mcevt_pdf_x1" );	\
    DeclareVariable( o_m_mcevt_pdf_x2, "mcevt_pdf_x2" );	\
    DeclareVariable( o_m_mcevt_pdf_scale, "mcevt_pdf_scale" );	\
    DeclareVariable( o_m_mcevt_pdf1, "mcevt_pdf1" );	\
    DeclareVariable( o_m_mcevt_pdf2, "mcevt_pdf2" );	\
    DeclareVariable( o_m_mcevt_weight, "mcevt_weight" );	\
    DeclareVariable( o_m_mcevt_nparticle, "mcevt_nparticle" );	\
    DeclareVariable( o_m_mcevt_pileUpType, "mcevt_pileUpType" );	\
    DeclareVariable( o_m_mc_n, "mc_n" );	\
    DeclareVariable( o_m_mc_pt, "mc_pt" );	\
    DeclareVariable( o_m_mc_m, "mc_m" );	\
    DeclareVariable( o_m_mc_eta, "mc_eta" );	\
    DeclareVariable( o_m_mc_phi, "mc_phi" );	\
    DeclareVariable( o_m_mc_status, "mc_status" );	\
    DeclareVariable( o_m_mc_barcode, "mc_barcode" );	\
    DeclareVariable( o_m_mc_parents, "mc_parents" );	\
    DeclareVariable( o_m_mc_children, "mc_children" );	\
    DeclareVariable( o_m_mc_pdgId, "mc_pdgId" );	\
    DeclareVariable( o_m_mc_charge, "mc_charge" );	\
    DeclareVariable( o_m_mc_vx_x, "mc_vx_x" );	\
    DeclareVariable( o_m_mc_vx_y, "mc_vx_y" );	\
    DeclareVariable( o_m_mc_vx_z, "mc_vx_z" );	\
    DeclareVariable( o_m_mc_child_index, "mc_child_index" );	\
  }
#endif



#if DUKHEPFILTER_TYPE == MONTE_CARLO_FILTER
#define RESETVAR                      \
  {    o_m_RunNumber = -999;\
    o_m_EventNumber = -999;\
    o_m_lbn = -999;\
    o_m_larError = -999;\
    o_m_EF_mu18_MG = -999;\
    o_m_EF_mu40_MSonly_barrel = -999;\
    o_m_vxp_n = -999;\
    o_m_vxp_z.clear();\
    o_m_vxp_nTracks.clear();\
    o_m_vxp_sumPt.clear();\
    o_m_vxp_type.clear();\
    o_m_vxp_trk_n.clear();\
    o_m_mcevt_n = -999;\
    o_m_mcevt_signal_process_id.clear();\
    o_m_mcevt_event_number.clear();\
    o_m_mcevt_event_scale.clear();\
    o_m_mcevt_alphaQCD.clear();\
    o_m_mcevt_alphaQED.clear();\
    o_m_mcevt_pdf_id1.clear();\
    o_m_mcevt_pdf_id2.clear();\
    o_m_mcevt_pdf_x1.clear();\
    o_m_mcevt_pdf_x2.clear();\
    o_m_mcevt_pdf_scale.clear();\
    o_m_mcevt_pdf1.clear();\
    o_m_mcevt_pdf2.clear();\
    o_m_mcevt_weight.clear();\
    o_m_mcevt_nparticle.clear();\
    o_m_mcevt_pileUpType.clear();\
    o_m_mc_n = -999;\
    o_m_mc_pt.clear();\
    o_m_mc_m.clear();\
    o_m_mc_eta.clear();\
    o_m_mc_phi.clear();\
    o_m_mc_status.clear();\
    o_m_mc_barcode.clear();\
    o_m_mc_parents.clear();\
    o_m_mc_children.clear();\
    o_m_mc_pdgId.clear();\
    o_m_mc_charge.clear();\
    o_m_mc_vx_x.clear();\
    o_m_mc_vx_y.clear();\
    o_m_mc_vx_z.clear();\
    o_m_mc_child_index.clear();\
  }
#endif



#if DUKHEPFILTER_TYPE == MONTE_CARLO_FILTER
#define COPYVAR                      \
  {   o_m_RunNumber = m_RunNumber;\
   o_m_EventNumber = m_EventNumber;\
   o_m_lbn = m_lbn;\
   o_m_larError = m_larError;\
   o_m_EF_mu18_MG = m_EF_mu18_MG;\
   o_m_EF_mu40_MSonly_barrel = m_EF_mu40_MSonly_barrel;\
   o_m_vxp_n = m_vxp_n;\
   o_m_vxp_z = std::vector<float>(*m_vxp_z);\
   o_m_vxp_nTracks = std::vector<int>(*m_vxp_nTracks);\
   o_m_vxp_sumPt = std::vector<float>(*m_vxp_sumPt);\
   o_m_vxp_type = std::vector<int>(*m_vxp_type);\
   o_m_vxp_trk_n = std::vector<int>(*m_vxp_trk_n);\
   o_m_mcevt_n = m_mcevt_n;\
   o_m_mcevt_signal_process_id = std::vector<int>(*m_mcevt_signal_process_id);\
   o_m_mcevt_event_number = std::vector<int>(*m_mcevt_event_number);\
   o_m_mcevt_event_scale = std::vector<double>(*m_mcevt_event_scale);\
   o_m_mcevt_alphaQCD = std::vector<double>(*m_mcevt_alphaQCD);\
   o_m_mcevt_alphaQED = std::vector<double>(*m_mcevt_alphaQED);\
   o_m_mcevt_pdf_id1 = std::vector<int>(*m_mcevt_pdf_id1);\
   o_m_mcevt_pdf_id2 = std::vector<int>(*m_mcevt_pdf_id2);\
   o_m_mcevt_pdf_x1 = std::vector<double>(*m_mcevt_pdf_x1);\
   o_m_mcevt_pdf_x2 = std::vector<double>(*m_mcevt_pdf_x2);\
   o_m_mcevt_pdf_scale = std::vector<double>(*m_mcevt_pdf_scale);\
   o_m_mcevt_pdf1 = std::vector<double>(*m_mcevt_pdf1);\
   o_m_mcevt_pdf2 = std::vector<double>(*m_mcevt_pdf2);\
   o_m_mcevt_weight = std::vector<std::vector<double> >(*m_mcevt_weight);\
   o_m_mcevt_nparticle = std::vector<int>(*m_mcevt_nparticle);\
   o_m_mcevt_pileUpType = std::vector<short>(*m_mcevt_pileUpType);\
   o_m_mc_n = m_mc_n;\
   o_m_mc_pt = std::vector<float>(*m_mc_pt);\
   o_m_mc_m = std::vector<float>(*m_mc_m);\
   o_m_mc_eta = std::vector<float>(*m_mc_eta);\
   o_m_mc_phi = std::vector<float>(*m_mc_phi);\
   o_m_mc_status = std::vector<int>(*m_mc_status);\
   o_m_mc_barcode = std::vector<int>(*m_mc_barcode);\
   o_m_mc_parents = std::vector<std::vector<int> >(*m_mc_parents);\
   o_m_mc_children = std::vector<std::vector<int> >(*m_mc_children);\
   o_m_mc_pdgId = std::vector<int>(*m_mc_pdgId);\
   o_m_mc_charge = std::vector<float>(*m_mc_charge);\
   o_m_mc_vx_x = std::vector<float>(*m_mc_vx_x);\
   o_m_mc_vx_y = std::vector<float>(*m_mc_vx_y);\
   o_m_mc_vx_z = std::vector<float>(*m_mc_vx_z);\
   o_m_mc_child_index = std::vector<std::vector<int> >(*m_mc_child_index);\
  }
#endif


//end definitions MONTE_CARLO_FILTER
//end macro definitions
