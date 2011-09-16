//-----------------------------------------------------------------------------------------------
//
// #Name: AnalysisUtils.h
// #Description: This is the header file for the AnalysisUtils namespace. I am placing all the
//               functions that are not within a class, but are useful for a generic physics 
//               analysis in this namespace. The point here is to prevent name clashes in 
//               future analysis programs.
// 
// #Author: Joshua Loyal
// #Updated: 6/20/2011
// 
//-----------------------------------------------------------------------------------------------

// STL include(s)
#include <vector>
#include <cmath>

// Root include(s)
#include "TLorentzVector.h"

// user defined classes
class Muon;
class Photon;
class Jet;

namespace AnalysisUtils {
  
   //------calculation functions-----//
  
   // adds two numbers in quadriture
   inline float aquad(float a, float b); 

   // finds the dR separation int eta-phi space of two particles  
   float dR(Muon* amuon, Photon* aphoton); 
   float dR(Jet* ajet, Photon* aphoton);
   float dR(Jet* ajet, Muon* amuon);
   
   //------predecate functions------//
   
   // used to sort a vector of Photons in descending order in terms of cluster pt
   bool ptPhotonSort(const Photon *lhsPhoton, const Photon *rhsPhoton);

   // used to sort a vector of Muons in descending order in terms of pt
   bool ptMuonSort(const Muon *lhsMuon, const Muon *rhsMuon);

   // note: find out how to overload these functions....
   
   //-----transformation functions-----//
   void cmTransformation(std::vector<TLorentzVector*>::iterator fourvector, std::vector<TLorentzVector*>::iterator end4Vec, TLorentzVector &boostVector);
   void cmTransformation(TLorentzVector &particle, TLorentzVector &boostVector);
   void cmRotation(TLorentzVector &particle, TLorentzVector &boostVector);
   void cmBoost(TLorentzVector &particle, TLorentzVector &boostVector);
}   
