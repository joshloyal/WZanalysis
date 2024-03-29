// Dear emacs, this is -*- c++ -*-
// $Id: DukHepFilter.h 170656 2011-06-17 04:23:41Z ayana $
#ifndef DukHepFilter_H
#define DukHepFilter_H

// SFrame include(s):
#import "core/include/SCycleBase.h" //import?
#include "plug-ins/include/SSummedVar.h"

#include "GoodRunsLists/TGoodRunsListReader.h"
#include "GoodRunsLists/TGoodRunsList.h"
#include "PileupReweighting/TPileupReweighting.h"
using namespace Root;
#include "TH1.h"
#include "TH2.h"
#include <iostream>

class DukHepFilter : 
  public SCycleBase {
public:
  /// Default constructor
  DukHepFilter();
  /// Default destructor
  virtual ~DukHepFilter() {};
  virtual void BeginCycle() throw( SError ) {};
  virtual void EndCycle() throw( SError ) {};
  virtual void BeginInputData( const SInputData& ) throw( SError ) {};
  virtual void EndInputData  ( const SInputData& ) throw( SError ) {};
  virtual void BeginInputFile( const SInputData& ) throw( SError ) {};
  virtual void ExecuteEvent( const SInputData&, Double_t ) throw( SError ) {};
  virtual void BeginMasterInputData( const SInputData& ) throw( SError ) {};
  virtual void EndMasterInputData( const SInputData& ) throw( SError ) {};
  void setupGRL() throw (SError);
  void setupPileupWeights() throw (SError);
  virtual void IncrementCutFlow(bool externalcut, double w=1.) throw ( SError );

protected:
  /// Cutflow
  SSummedVar< std::vector<Int_t> > m_cutflow; //!
  TH1F * h_p, *h_n;
  unsigned int icutflow; 
  /// GRL
  TGoodRunsListReader m_grl_reader;
  TGoodRunsList m_grl;
  std::string m_jo_grl;
  /// Pileup
  TPileupReweighting m_PileUpTool;
  std::string m_jo_mudata, m_jo_mumc; 
  //common utilities for Duke analysis
public:  
  static float aquad(float a, float b); 
  static float binErr(float n, float d);
  static float deltaREtaPhi(float de, float dp); 
  static float safeRatio(float n, float d) {return (d != 0) ? n/d : 0.; };
  bool testGRL(int r,int l) {return m_grl.HasRunLumiBlock(r,l);};
  //int egammaOQ(bool isElectron, double myEta, double myPhi);
  //GetPtCorrectedIsolation(el_cl_E,  el_etas2, el_etap, el_cl_eta, 20, true, data, el_EtCone20, false, CaloIsoCorrection::ELECTRON);  
private:

  ClassDef( DukHepFilter, 0 );
  
}; // class DukHepFilter

#endif // DukHepFilter_H

