
// Dear emacs, this is -*- c++ -*-
// $Id: dukheputils.py 163843 2011-05-27 18:22:01Z ayana $
#ifndef WgmunuCycle_H
#define WgmunuCycle_H

// STL include(s):
#include <vector>
#include <utility>

// Root include(s):

// DukHep include(s):
#include "../DukHep/include/DukHepFilter.h"
#include "../DukHep/include/RandomDataPeriod.h"

// particle class include(s):
#include "../DukHep/include/ParticleClasses.h"

// This line determines which branches are defined
#define DUKHEPFILTER_TYPE WGMUNU_FILTER 
#include "WgmunuPackage/include/WgmunuPackageMacros.h"
#undef DUKHEPFILTER_TYPE

/**
 *  @short WgmunuCycle
 *  @author jdl32
 *  @version $Revision: 163843 $
 */

class WgmunuCycle : public DukHepFilter {

public:

// Section: Constructor/Destructor and SFrame utilities {{{1
   /// Default constructor
   WgmunuCycle();
   /// Default destructor
   ~WgmunuCycle();
   
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

// event flags
bool vertex;
double Wtransmass;

// cut flow members
CutFlow eventCutFlow;

// muon members
MuonReader         m_MuonReader;
MuonSelector       muSelector;
std::vector<Muon*> allMuons;
std::vector<Muon*> goodMuons;

// photon members 
PhotonReader         m_PhotonReader;
PhotonSelector       photonSelector;
std::vector<Photon*> allPhotons;
std::vector<Photon*> goodPhotons;
std::vector<Photon*> tightPhotons;
std::vector<Photon*> isolatedPhotons;

// jet members
JetReader         m_JetReader;
JetSelector       jetSelector;
std::vector<Jet*> allJets;
std::vector<Jet*> goodJets;

// MET members
METReader   m_METReader;

// other members
RandomDataPeriod mc_dataperiod;
int RunNumber;
bool isMC;

// variables put in output tree
Double_t o_Wtransmass;
std::vector<float> o_muonIndex;
std::vector<float> o_photonIndex;
Float_t o_MET;
Float_t o_METphi;

// job property (set in xml file)
bool m_prop_skipgrl;

// Section: Other Stuff 
// Macro adding d3pd branch pointers
  DUKEHEPHEADER_MEMBERS
  ;

   // Macro adding the functions for dictionary generation
   ClassDef( WgmunuCycle, 0 );


}; // class WgmunuCycle

#endif // WgmunuCycle_H
