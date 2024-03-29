
// Dear emacs, this is -*- c++ -*-
// $Id: dukheputils.py 163843 2011-05-27 18:22:01Z ayana $
#ifndef FirstCycle_H
#define FirstCycle_H

// STL include(s):
#include <vector>
#include <utility>

// Root include(s):

// SFrame include(s):
#include "../DukHep/include/DukHepFilter.h"

// particle class include(s):
#include "../DukHep/include/ParticleClasses.h"

// This line determines which branches are defined
#define DUKHEPFILTER_TYPE ZGMUMU_FILTER 
#include "ZgmumuPackage/include/ZgmumuPackageMacros.h"
#undef DUKHEPFILTER_TYPE

/**
 *  @short FirstCycle
 *  @author jdl32
 *  @version $Revision: 163843 $
 */

class FirstCycle : public DukHepFilter {

public:

// Section: Constructor/Destructor and SFrame utilities {{{1
   /// Default constructor
   FirstCycle();
   /// Default destructor
   ~FirstCycle();
   
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
double Zmass;

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

// jet members
JetReader         m_JetReader;
JetSelector       jetSelector;
std::vector<Jet*> allJets;
std::vector<Jet*> goodJets;
std::vector<Jet*> isolatedJets;

// other members
std::vector<std::pair<Int_t,Int_t> > EventVector;

// job property (set in xml file)
bool m_prop_skipgrl;

// Section: Other Stuff 
// Macro adding d3pd branch pointers
  DUKEHEPHEADER_MEMBERS
  ;

   // Macro adding the functions for dictionary generation
   ClassDef( FirstCycle, 0 );


}; // class FirstCycle

#endif // FirstCycle_H
