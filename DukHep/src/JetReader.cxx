////../bin/dukhep_create_reader.py -n JetReader JetReaderMacrosFilter.dat
#include "DukHep/include/JetReader.h"
JetReader::JetReader(SCycleBaseNTuple * ownr, const char* collname): owner(ownr), cname(collname),
JetE(0),
JetPt(0),
JetMass(0),
JetEta(0),
JetPhi(0),
JetTiming(0),
JetLArQuality(0),
JetsumPtTrk(0),
JetHECQuality(0),
JetNegativeE(0),
JetFracSamplingMax(0),
JetHecf(0),
JetEmfrac(0),
JetEmscaleE(0),
JetEmscalePt(0),
JetEmscaleEta(0),
JetEmscalePhi(0),
JetIsUgly(0),
NumberofJets(0)
{std::cout << "JetReader: Collection name is " << cname << std::endl; }

void JetReader::ConnectVariables(std::string treename){
  owner->ConnectVariable( treename.c_str(), VarName("jet_E").c_str(), JetE );
  owner->ConnectVariable( treename.c_str(), VarName("jet_pt").c_str(), JetPt );
  owner->ConnectVariable( treename.c_str(), VarName("jet_m").c_str(), JetMass );
  owner->ConnectVariable( treename.c_str(), VarName("jet_eta").c_str(), JetEta );
  owner->ConnectVariable( treename.c_str(), VarName("jet_phi").c_str(), JetPhi );
  owner->ConnectVariable( treename.c_str(), VarName("jet_Timing").c_str(), JetTiming );
  owner->ConnectVariable( treename.c_str(), VarName("jet_LArQuality").c_str(), JetLArQuality );
  owner->ConnectVariable( treename.c_str(), VarName("jet_sumPtTrk").c_str(), JetsumPtTrk );
  owner->ConnectVariable( treename.c_str(), VarName("jet_HECQuality").c_str(), JetHECQuality );
  owner->ConnectVariable( treename.c_str(), VarName("jet_NegativeE").c_str(), JetNegativeE );
  owner->ConnectVariable( treename.c_str(), VarName("jet_fracSamplingMax").c_str(), JetFracSamplingMax );
  owner->ConnectVariable( treename.c_str(), VarName("jet_hecf").c_str(), JetHecf );
  owner->ConnectVariable( treename.c_str(), VarName("jet_emfrac").c_str(), JetEmfrac );
  owner->ConnectVariable( treename.c_str(), VarName("jet_emscale_E").c_str(), JetEmscaleE );
  owner->ConnectVariable( treename.c_str(), VarName("jet_emscale_pt").c_str(), JetEmscalePt );
  owner->ConnectVariable( treename.c_str(), VarName("jet_emscale_eta").c_str(), JetEmscaleEta );
  owner->ConnectVariable( treename.c_str(), VarName("jet_emscale_phi").c_str(), JetEmscalePhi );
  owner->ConnectVariable( treename.c_str(), VarName("jet_isUgly").c_str(), JetIsUgly );
  owner->ConnectVariable( treename.c_str(), VarName("jet_n").c_str(), NumberofJets );
}

void JetReader::DeclareVariables(){
  owner->DeclareVariable( o_JetE, "jet_E" );
  owner->DeclareVariable( o_JetPt, "jet_pt" );
  owner->DeclareVariable( o_JetMass, "jet_m" );
  owner->DeclareVariable( o_JetEta, "jet_eta" );
  owner->DeclareVariable( o_JetPhi, "jet_phi" );
  owner->DeclareVariable( o_JetTiming, "jet_Timing" );
  owner->DeclareVariable( o_JetLArQuality, "jet_LArQuality" );
  owner->DeclareVariable( o_JetsumPtTrk, "jet_sumPtTrk" );
  owner->DeclareVariable( o_JetHECQuality, "jet_HECQuality" );
  owner->DeclareVariable( o_JetNegativeE, "jet_NegativeE" );
  owner->DeclareVariable( o_JetFracSamplingMax, "jet_fracSamplingMax" );
  owner->DeclareVariable( o_JetHecf, "jet_hecf" );
  owner->DeclareVariable( o_JetEmfrac, "jet_emfrac" );
  owner->DeclareVariable( o_JetEmscaleE, "jet_emscale_E" );
  owner->DeclareVariable( o_JetEmscalePt, "jet_emscale_pt" );
  owner->DeclareVariable( o_JetEmscaleEta, "jet_emscale_eta" );
  owner->DeclareVariable( o_JetEmscalePhi, "jet_emscale_phi" );
  owner->DeclareVariable( o_JetIsUgly, "jet_isUgly" );
  owner->DeclareVariable( o_NumberofJets, "jet_n" );
}

void JetReader::Reset(){
 o_JetE.clear();
 o_JetPt.clear();
 o_JetMass.clear();
 o_JetEta.clear();
 o_JetPhi.clear();
 o_JetTiming.clear();
 o_JetLArQuality.clear();
 o_JetsumPtTrk.clear();
 o_JetHECQuality.clear();
 o_JetNegativeE.clear();
 o_JetFracSamplingMax.clear();
 o_JetHecf.clear();
 o_JetEmfrac.clear();
 o_JetEmscaleE.clear();
 o_JetEmscalePt.clear();
 o_JetEmscaleEta.clear();
 o_JetEmscalePhi.clear();
 o_JetIsUgly.clear();
 o_NumberofJets=-999;
  }

void JetReader::CopyToOutput(){
 o_JetE = std::vector<float>(*JetE);
 o_JetPt = std::vector<float>(*JetPt);
 o_JetMass = std::vector<float>(*JetMass);
 o_JetEta = std::vector<float>(*JetEta);
 o_JetPhi = std::vector<float>(*JetPhi);
 o_JetTiming = std::vector<float>(*JetTiming);
 o_JetLArQuality = std::vector<float>(*JetLArQuality);
 o_JetsumPtTrk = std::vector<float>(*JetsumPtTrk);
 o_JetHECQuality = std::vector<float>(*JetHECQuality);
 o_JetNegativeE = std::vector<float>(*JetNegativeE);
 o_JetFracSamplingMax = std::vector<float>(*JetFracSamplingMax);
 o_JetHecf = std::vector<float>(*JetHecf);
 o_JetEmfrac = std::vector<float>(*JetEmfrac);
 o_JetEmscaleE = std::vector<float>(*JetEmscaleE);
 o_JetEmscalePt = std::vector<float>(*JetEmscalePt);
 o_JetEmscaleEta = std::vector<float>(*JetEmscaleEta);
 o_JetEmscalePhi = std::vector<float>(*JetEmscalePhi);
 o_JetIsUgly = std::vector<int>(*JetIsUgly);
 o_NumberofJets = NumberofJets;
  }

void JetReader::getJets(std::vector<Jet*> &jetVec) {
    // loop over all the jets and place them in the photonVec (notice the reference!)
    for( int i = 0; i < NumberofJets; i++) {

        Jet *jet = new Jet(JetPt->at(i), JetEmscaleEta->at(i), JetEmscalePhi->at(i), JetMass->at(i));


        jet->E      = JetE->at(i);
        jet->Pt     = JetPt->at(i);
        jet->Eta        = JetEta->at(i);
        jet->Phi        = JetPhi->at(i);
        jet->M      = JetMass->at(i);
        jet->eEmscale       = JetEmscaleE->at(i);
        jet->ptEmscale      = JetEmscalePt->at(i);
        jet->etaEmscale     = JetEmscaleEta->at(i);
        jet->phiEmscale     = JetEmscalePhi->at(i);
        jet->Emfrac     = JetEmfrac->at(i);
        jet->Hecf       = JetHecf->at(i);
        jet->LArQuality     = JetLArQuality->at(i);
        jet->HECQuality     = JetHECQuality->at(i);
        jet->Timing     = JetTiming->at(i);
        jet->sumPtTrk       = JetsumPtTrk->at(i);
        jet->fracSamplingMax        = JetFracSamplingMax->at(i);
        jet->NegativeE      = JetNegativeE->at(i);
        jet->IsUgly     = JetIsUgly->at(i);
        jet->Index      = i;

        jetVec.push_back(jet);
    }
    return;
}

