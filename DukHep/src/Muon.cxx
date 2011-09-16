//-----------------------------------------------------------------------------------------------
//
// #Name: Muon.cxx
// #Description: This file contains a few methods that perform calculated properties of the muons
//
// #Author: Joshua Loyal
// #Updated: 7/21/2011
//
//-----------------------------------------------------------------------------------------------

// STL include(s)
#include <iostream>

// class include
#include "DukHep/include/Muon.h"

// pt smearing tool
#include "DukHep/include/SmearingClass.h"

// static variable initializations
float Muon::mu_dpx = 0.;
float Muon::mu_dpy = 0.;

//-----Pt Smearing Functions------//

void Muon::SmearPt(Int_t EventNumber) {
    // initialize SmearingClass member
    SmearingClass *mcp_smear = new SmearingClass("muid");    // since the WW group is using staco muon, MCP suggested to the WW analysis to use "muid" in the initialization
    mcp_smear->UseScale(1);              // do muon scale correction as well, values are based on MCP Twikipage
         
    // Retrieve Eta, PtCB, PtMS and PtID from containers/ntuples
    double eta  = Eta;
    double ptcb = Pt;
    double ptms = MSExtrapolatedPt;
    double ptid = InnerPt;

    // Use the MC event number to set seed so that the random numbers are reproducible by different analyzers 
    mcp_smear->SetSeed(EventNumber, Index); 
    mcp_smear->Event(ptms,ptid,ptcb,eta); 
    
    // Get Smeared Pts 
    unCorrectedPx  = this->TLorentzVector::Px();
    unCorrectedPy  = this->TLorentzVector::Py();
    Pt                = mcp_smear->pTCB(); 
    MSExtrapolatedPt  = mcp_smear->pTMS(); 
    InnerPt           = mcp_smear->pTID(); 
    
    this->SetPtEtaPhiE(Pt, Eta, Phi, E);

    delete mcp_smear;
    mcp_smear = 0;

    return;
}

TLorentzVector Muon::getTransverseFourVector() {
    TLorentzVector tmuon;
    tmuon.SetPtEtaPhiE(Pt, 0, Phi, Pt);
    return tmuon;
}
