////../bin/dukhep_create_reader.py -n TruthReader MonteCarloMacros.dat
#include "include/TruthReader.h"
#include "include/Muon.h"
#include "include/Photon.h"
#include "include/AnalysisUtils.h"
#include <cmath>
#include <iostream>

TruthReader::TruthReader(SCycleBaseNTuple * ownr, std::string mcsample): owner(ownr),
mcNumber(0),
mcPt(0),
mcM(0),
mcEta(0),
mcPhi(0),
mcStatus(0),
mcBarCode(0),
mcParents(0),
mcChildren(0),
mcPdgID(0),
mcCharge(0),
mcVx_x(0),
mcVx_y(0),
mcVx_z(0),
mcChild_index(0),
mcParent_index(0),
pythia(false),
alpgen(false),
madgraph(false),
sherpa(false)
{   
    if( mcsample == "pythia" ) pythia = true;
    if( mcsample == "alpgen" ) alpgen = true;
    if( mcsample == "madgraph" ) madgraph = true;
    if( mcsample == "sherpa" ) sherpa = true;
}
    
void TruthReader::ConnectVariables(std::string treename){
  owner->ConnectVariable( treename.c_str(), VarName("mc_n").c_str(), mcNumber );
  owner->ConnectVariable( treename.c_str(), VarName("mc_pt").c_str(), mcPt );
  owner->ConnectVariable( treename.c_str(), VarName("mc_m").c_str(), mcM );
  owner->ConnectVariable( treename.c_str(), VarName("mc_eta").c_str(), mcEta );
  owner->ConnectVariable( treename.c_str(), VarName("mc_phi").c_str(), mcPhi );
  owner->ConnectVariable( treename.c_str(), VarName("mc_status").c_str(), mcStatus );
  owner->ConnectVariable( treename.c_str(), VarName("mc_barcode").c_str(), mcBarCode );
  owner->ConnectVariable( treename.c_str(), VarName("mc_parents").c_str(), mcParents );
  owner->ConnectVariable( treename.c_str(), VarName("mc_children").c_str(), mcChildren );
  owner->ConnectVariable( treename.c_str(), VarName("mc_pdgId").c_str(), mcPdgID );
  owner->ConnectVariable( treename.c_str(), VarName("mc_charge").c_str(), mcCharge );
  owner->ConnectVariable( treename.c_str(), VarName("mc_vx_x").c_str(), mcVx_x );
  owner->ConnectVariable( treename.c_str(), VarName("mc_vx_y").c_str(), mcVx_y );
  owner->ConnectVariable( treename.c_str(), VarName("mc_vx_z").c_str(), mcVx_z );
  owner->ConnectVariable( treename.c_str(), VarName("mc_child_index").c_str(), mcChild_index );
  owner->ConnectVariable( treename.c_str(), VarName("mc_parent_index").c_str(), mcParent_index );
}
void TruthReader::DeclareVariables(){
  owner->DeclareVariable( o_mcNumber, "mc_n" );
  owner->DeclareVariable( o_mcPt, "mc_pt" );
  owner->DeclareVariable( o_mcM, "mc_m" );
  owner->DeclareVariable( o_mcEta, "mc_eta" );
  owner->DeclareVariable( o_mcPhi, "mc_phi" );
  owner->DeclareVariable( o_mcStatus, "mc_status" );
  owner->DeclareVariable( o_mcBarCode, "mc_barcode" );
  owner->DeclareVariable( o_mcParents, "mc_parents" );
  owner->DeclareVariable( o_mcChildren, "mc_children" );
  owner->DeclareVariable( o_mcPdgID, "mc_pdgId" );
  owner->DeclareVariable( o_mcCharge, "mc_charge" );
  owner->DeclareVariable( o_mcVx_x, "mc_vx_x" );
  owner->DeclareVariable( o_mcVx_y, "mc_vx_y" );
  owner->DeclareVariable( o_mcVx_z, "mc_vx_z" );
  owner->DeclareVariable( o_mcChild_index, "mc_child_index" );
  owner->DeclareVariable( o_mcParent_index, "mc_parent_index" );
}
void TruthReader::Reset(){
 o_mcNumber= -999;
 o_mcPt.clear();
 o_mcM.clear();
 o_mcEta.clear();
 o_mcPhi.clear();
 o_mcStatus.clear();
 o_mcBarCode.clear();
 o_mcParents.clear();
 o_mcChildren.clear();
 o_mcPdgID.clear();
 o_mcCharge.clear();
 o_mcVx_x.clear();
 o_mcVx_y.clear();
 o_mcVx_z.clear();
 o_mcChild_index.clear();
 o_mcParent_index.clear();
  }
void TruthReader::CopyToOutput(){
 o_mcNumber = mcNumber;
 o_mcPt = std::vector<float>(*mcPt);
 o_mcM = std::vector<float>(*mcM);
 o_mcEta = std::vector<float>(*mcEta);
 o_mcPhi = std::vector<float>(*mcPhi);
 o_mcStatus = std::vector<int>(*mcStatus);
 o_mcBarCode = std::vector<int>(*mcBarCode);
 o_mcParents = std::vector<std::vector<int> >(*mcParents);
 o_mcChildren = std::vector<std::vector<int> >(*mcChildren);
 o_mcPdgID = std::vector<int>(*mcPdgID);
 o_mcCharge = std::vector<float>(*mcCharge);
 o_mcVx_x = std::vector<float>(*mcVx_x);
 o_mcVx_y = std::vector<float>(*mcVx_y);
 o_mcVx_z = std::vector<float>(*mcVx_z);
 o_mcChild_index = std::vector<std::vector<int> >(*mcChild_index);
 o_mcParent_index = std::vector<std::vector<int> >(*mcParent_index);
}

std::vector<Muon*> TruthReader::getTruthMuons() {
    // declare some variables used in the selection
    nTruthMuCand = 0;
    const Int_t nMaxTruthCand(2);
    truthMuons.clear();

    // loop through the MC truth particles
    for(int i = 0; i < mcNumber; ++i) {

        // obtain some variables from the leafs
        Int_t nParents  = ( mcParents->at(i) ).size();
        Int_t nParentsIdx   = ( mcParent_index->at(i) ).size();
        Int_t particle_pdgId = mcPdgID->at(i);

        // particle must have a parent
        if (nParentsIdx <= 0) continue;

        // muon selection
        if( (abs(particle_pdgId) == 13) && (mcStatus->at(i) == 1) && (nTruthMuCand < nMaxTruthCand) ) { //mc_status == 1 means a final state particle (for pythia...)
                // construct the truth muon and add it to a vector
                Muon *amuon = new Muon(mcCharge->at(i));
                amuon->SetPtEtaPhiM(mcPt->at(i), mcEta->at(i), mcPhi->at(i), mcM->at(i));
                amuon->Index = i;
                truthMuons.push_back(amuon);

                ++nTruthMuCand; // add one to the truth muon counter
        }
    }

    sort(truthMuons.rbegin(), truthMuons.rend(), AnalysisUtils::ptMuonSort); // sort muons based on pt
    return truthMuons;
}

std::vector<TLorentzVector*> TruthReader::getTruthNuetrinos() {
    // declare some variables used in the selection
    nTruthNuCand = 0;
    const Int_t nMaxTruthCand(2);
    truthNuetrinos.clear();

    // loop through the MC truth particles
    for(int i = 0; i < mcNumber; ++i) {

        // obtain some variables from te leafs
        Int_t nParents = ( mcParents->at(i) ).size();
        Int_t nParentsIdx = ( mcParent_index->at(i) ).size();
        Int_t particle_pdgId = mcPdgID->at(i);

        // particles must have a parent
        if (nParentsIdx <= 0) continue;

        // nuetrino selection
        if( (abs(particle_pdgId == 14)) && (mcStatus->at(i) == 1) && (nTruthNuCand < nMaxTruthCand) ) {
            // construct the truth nuetrino and add it to the container
            TLorentzVector *nuetrino = new TLorentzVector();
            nuetrino->SetPtEtaPhiM(mcPt->at(i), mcEta->at(i), mcPhi->at(i), mcM->at(i));
            truthNuetrinos.push_back(nuetrino);

            ++nTruthNuCand; // add one to the truth nuetrino counters
        }
    }

   sort(truthNuetrinos.rbegin(), truthNuetrinos.rend(), AnalysisUtils::ptParticleSort);
   return truthNuetrinos;
}

std::vector<Photon*> TruthReader::getTruthPhotons() {
    // declare some variables used in the selection
    nTruthPhotonCand = 0;
    const Int_t nMaxTruthCand(999);
    truthPhotons.clear();

    Int_t nTruthPhotonCand_e(0);
    Int_t nTruthPhotonCand_mu(0);
    Int_t nTruthPhotonCand_tau(0);
    Int_t nTruthPhotonCand_q(0);
    Int_t nTruthPhotonCand_g(0);
    Int_t nTruthPhotonCand_W(0);

    // loop through the MC truth particles
    for (int i = 0; i < mcNumber; ++i) {

        // obtain some variables from the leafs
        Int_t nParents  = ( mcParents->at(i) ).size();
        Int_t nParentsIdx   = ( mcParent_index->at(i) ).size();
        Int_t particle_pdgId = mcPdgID->at(i);
        bool photon_status_flag(false);

        if (nParentsIdx <= 0) continue;

        // photon selection
        if( (abs(particle_pdgId) == 22) ) { 
            
            // check the status of the photon_______________________________________________________________
            if( (pythia) && (mcStatus->at(i) == 1) ) photon_status_flag = true;
            if( (alpgen) && ( (mcStatus->at(i) == 1) || (mcStatus->at(i) == 2) ) ) photon_status_flag = true;
            if( (madgraph || sherpa) && (mcStatus->at(i) > 2) ) photon_status_flag = true;

            if(photon_status_flag) {
                Int_t ipar(-1);
                
                // loop through the parent indeces
                for( int j = 0; j < nParentsIdx; ++j ) {
                    Int_t idx = (*mcParent_index)[i][j];

                    ipar = 7;
                    
                    if( abs(mcPdgID->at(idx)) == 11 ) {++nTruthPhotonCand_e;    ipar=1;} // e
                    if( abs(mcPdgID->at(idx)) == 13 ) {++nTruthPhotonCand_mu;   ipar=2;} // mu
                    if( abs(mcPdgID->at(idx)) == 15 ) {++nTruthPhotonCand_tau;  ipar=3;} // tau
                    if( abs(mcPdgID->at(idx)) == 23 ) {++nTruthPhotonCand_W;    ipar=4;}  // W, treat W,Z the same
                    if( abs(mcPdgID->at(idx)) == 24 ) {++nTruthPhotonCand_W;    ipar=4;}  // Z, treat W,Z the same
                    if( abs(mcPdgID->at(idx)) <= 6  ) {++nTruthPhotonCand_q;    ipar=5;}  // q
                    if( abs(mcPdgID->at(idx)) == 21 ) {++nTruthPhotonCand_g;    ipar=6;}  // g
                }
                
                // select the photon if it is coming from the above sources
                if( (ipar >= 1) && (ipar <= 6) ) {
                    if( nTruthPhotonCand < nMaxTruthCand) {
                        // construct the truth photon and add it to a vector
                        Photon *aphoton = new Photon(mcPt->at(i), mcEta->at(i), mcPhi->at(i), mcPt->at(i)*std::cosh(mcEta->at(i)) ); // recall p = pt*cosh(eta) 
                        aphoton->Index = i;
                        truthPhotons.push_back(aphoton);

                        ++nTruthPhotonCand; // add one to the truth photon counter
                    }
                }

            } // photon status
        } // if particle is a photon 
    } // loop through MC truth particles
    
    sort(truthPhotons.rbegin(), truthPhotons.rend(), AnalysisUtils::ptPhotonSort); // sort photons in terms of pt
    return truthPhotons;
}

bool TruthReader::hasFSRPhoton() {
    float dR_lep_pho(999.0);
    bool isISR(false), isFSR(false);

    // check to see if we have found the truth particles yet
    if ( truthMuons.empty() )   getTruthMuons();
    if ( truthPhotons.empty() ) getTruthPhotons();

    if ( nTruthPhotonCand > 0 ) {
        Photon *aphoton = truthPhotons.at(0);
        int nparidx = ( mcParent_index->at(aphoton->Index) ).size();

        //
        // Assume that the 1st leading (1st and 2nd leading) leptons are from the W (Z)
        //

        // for the case of Wg/Zg
        if ( nTruthMuCand >= 1 ) {
            Muon *muon1 = truthMuons.at(0);
            float dR = AnalysisUtils::dR(muon1, aphoton);

            if ( dR < dR_lep_pho ) { dR_lep_pho = dR; }
        }

        // for the case of the Zg (2 leptons)
        if (nTruthMuCand >= 2 ) {
            Muon *muon2 = truthMuons.at(1);
            float dR = AnalysisUtils::dR(muon2, aphoton);

            if ( dR < dR_lep_pho ) { dR_lep_pho = dR; }
        }
        
        for ( int j = 0; j < nparidx; ++j) {
            int idx = ( mcParent_index->at(aphoton->Index) ).at(j);
            int istatus = mcStatus->at(aphoton->Index);
            int par_istatus = mcStatus->at(idx);

            // if originated from a quark or gluon, we consider that as ISR
            if ( (abs(mcPdgID->at(idx)) <= 6) || (abs(mcPdgID->at(idx)) == 21) ) { isISR = true; }

            // if originated from a lepton or W/Z, we consider that as FSR
            if ( (abs(mcPdgID->at(idx)) == 11) || (abs(mcPdgID->at(idx)) == 13) || (abs(mcPdgID->at(idx)) == 15) ||
                (abs(mcPdgID->at(idx))  == 23) || (abs(mcPdgID->at(idx)) == 24) ) { isFSR = true; }
        }
        
        if (isFSR) {
            if (nTruthMuCand > 0) {
                if ( (aphoton->Photon::Pt > 10000.0) && (dR_lep_pho > 0.5) ) { // signal Sherpa and MadGraph is generated with this cut
                    return true;
                }
            }
            else {
                return true;
            }
        }
    }
    return false;
}
