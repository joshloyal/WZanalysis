
// Dear emacs, this is -*- c++ -*-
// $Id: dukheputils.py 163843 2011-05-27 18:22:01Z ayana $
#ifndef MCAnalysisCycle_H
#define MCAnalysisCycle_H

// STL include(s):
#include <vector>
#include <utility>

// Root include(s):

// DukHep include(s):
#include "../DukHep/include/DukHepFilter.h"

// Pileup Reweighting include(s):
#include "../PileupReweighting/PileupReweighting/TPileupReweighting.h"

// particle class include(s):
#include "../DukHep/include/ParticleClasses.h"

// This line determines which branches are defined
#define DUKHEPFILTER_TYPE MONTE_CARLO_FILTER 
#include "ZgmumuPackage/include/ZgmumuPackageMacros.h"
#undef DUKHEPFILTER_TYPE

/**
 *  @short MCAnalysisCycle
 *  @author jdl32
 *  @version $Revision: 163843 $
 */

class MCAnalysisCycle : public DukHepFilter {

public:

// Section: Constructor/Destructor and SFrame utilities {{{1
   /// Default constructor
   MCAnalysisCycle();
   /// Default destructor
   ~MCAnalysisCycle();
   
   // SFrame utilities
   /// Function called at the beginning of the cycle
   virtual void BeginCycle() throw( SError );
   /// Function called at the end of the cycle
   virtual void EndCycle() throw( SError );

   /// Function called at the beginning of a new input data
   virtual void BeginInputData( const SInputData& ) throw( SError );
   /// Function called after finishing to process an input data
   virtual void EndInputData  ( const SInputData& ) throw( SError );

   /// Function called after opening each new input file
   virtual void BeginInputFile( const SInputData& ) throw( SError );

   /// Function called for every event
   virtual void ExecuteEvent( const SInputData&, Double_t ) throw( SError );
   
   /// Function called to report cut flow
   virtual void EndMasterInputData( const SInputData& ) throw( SError );

private:

// muon members
MuonReader      m_MuonReader;

// photon members 
PhotonReader    m_PhotonReader;

// jet members
JetReader       m_JetReader;

// truth members
TruthReader     m_TruthReader;
std::vector<Muon*> TruthMuons;

// variables in the input tree
Double_t m_Zmass;
std::vector<float>* m_mu_index;
std::vector<float>* m_ph_index;

// variables put in output tree
std::vector<float> o_muonIndex;
std::vector<float> o_photonIndex;

// pileup reweighting variables
TPileupReweighting *m_tPileUp;
TString m_dataRootFileName;
TString m_dataRootHistName;
TString m_mcRootFileName;
TString m_mcRootHistName;

// job property (set in xml file)
bool m_prop_skipgrl;

// Section: Other Stuff 
// Macro adding d3pd branch pointers
  DUKEHEPHEADER_MEMBERS
  ;

   // Macro adding the functions for dictionary generation
   ClassDef( MCAnalysisCycle, 0 );


}; // class MCAnalysisCycle

#endif // MCAnalysisCycle_H
