//-----------------------------------------------------------------------------------------------
//
// #Name: AnalysisUtils.cxx
// #Description: The source file for the AnalysisUtils namespace.
//
// #Creator: Joshua Loyal
// #Updated: 6/20/2011
//
//-----------------------------------------------------------------------------------------------
#include "DukHep/include/AnalysisUtils.h"

// STL include(s)
#include <iostream>

// Root include(s)
#include "TVector3.h"
#include "TRotation.h"
#include "TLorentzRotation.h"

// class include(s)
#include "DukHep/include/Muon.h"
#include "DukHep/include/Photon.h"
#include "DukHep/include/Jet.h"

namespace AnalysisUtils {
    
    //------dR functions-----//

    float aquad(float a, float b) 
    {
        return std::sqrt( a*a + b*b );
    }
    
    // overloaded dR functions
    float dR(Muon* amuon, Photon* aphoton) {
        return amuon->DeltaR(*aphoton);
    }

    float dR(Jet* ajet, Photon* aphoton) {
        return ajet->DeltaR(*aphoton);
    }

    float dR(Jet* ajet, Muon* amuon) {
        return ajet->DeltaR(*amuon);
    }

    
    //------predecate functions------//

    bool ptPhotonSort(const Photon *lhsPhoton, const Photon *rhsPhoton)
    {
        return lhsPhoton->TLorentzVector::Pt() < rhsPhoton->TLorentzVector::Pt();
    }

    bool ptMuonSort(const Muon *lhsMuon, const Muon *rhsMuon)
    {
        return lhsMuon->Pt < rhsMuon->Pt;
    }

    bool ptParticleSort(const TLorentzVector *lhsParticle, const TLorentzVector *rhsParticle)
    {
        return lhsParticle->Pt() < rhsParticle->Pt();
    }

    //-----coordinate transformation functions-----//

    void cmTransformation(std::vector<TLorentzVector*>::iterator fourvector, std::vector<TLorentzVector*>::iterator end4Vec, TLorentzVector &boost4Vector) {
        //------calculate the rotation matrix------//
        //
        //----------------------------------------------------------------------------------------------------------------------------------
        // note: The TRotation class describes so called active rotations, i.e. rotations of objects inside a static system of coordinates.
        //       In the case you want to rotate the frame and want to know the coordiantes of objects in the rotated coordinate system then
        //       you should apply the inverse rotation to the objects.
        //----------------------------------------------------------------------------------------------------------------------------------

        // variable initialization
        TRotation R;
        TLorentzRotation L;
        TVector3 xAxis(1,0,0);
        Double_t beta = boost4Vector.Beta();        // get the magnitude of beta from our boosting 4vector
        TVector3 boostVector = boost4Vector.Vect(); // the z-axis is in the direction of the vector component of the boost (p = gmv).

        // calculate the axes of the new coordinate system
        
        TVector3 newZ = boostVector.Unit();                // z-axis points along the direction of motion of the cm particle
        TVector3 newY = (boostVector.Cross(xAxis)).Unit(); // y-axis perpendicular to the z-axis (now we have a plane)
        TVector3 newX = (newY.Cross(newZ)).Unit();  // x-axis is perpendicular to the plane defined above (newY and newZ already unit vectors).
        
        // calculate the rotation matrix
        //
        //-----------------------------------------------------------------------------------------------------------------------------------
        // TRotation::RotateAxes()
        // note: Suppose there is a 3D object and its local axes a(1,0,0), b(0,1,0), c(0,0,1) originally coincide with the global axes.
        //       If it is known the position of local axes a'(ax',ay',az'), b'(bx',by',bz'), c'(cx',cy',cz') after the rotation then matrix
        //       which describes the rotation looks as follows:
        //       R = [ax' bx' cx']
        //           |ay' by' cy'|
        //           [az' bz' cz']
        //----------------------------------------------------------------------------------------------------------------------------------

        R.RotateAxes(newX, newY, newZ);
        R.Invert();                     // as mentioned above, we need the inverse rotation.

        //------calculate the Lorentz Transformation Matrix------//
        //
        //----------------------------------------------------------------------------------------------------------------------------------
        // TLorentzRotation:
        // note: The matrix described by this object is the following:
        //       Lambda = [xx xy xz xt]
        //                |yx yy yz yt|
        //                |zx zy zz zt|
        //                [tx ty tz tt].
        //       Recall that Root uses the weird convention for four vectors: a = (ax, ay, az, at).
        //----------------------------------------------------------------------------------------------------------------------------------
        //
        //----------------------------------------------------------------------------------------------------------------------------------
        // TLorentzRotation::boost():
        // note: the matrix that results from an arbitrary boost b = (bx, by, bz) is as follows:
        //       Boost  = [1+g'bx^2     g'bxby      g'bxbz      gbx]
        //                |g'bybz       1+g'by^2    g'bybz      gby|
        //                |g'bzbx       g'bzby      1+g'bz^2    gbz|
        //                [gbx          gby         gbz         g  ].
        //      where g' = (g-1)/b^2.
        //
        //       We need the inverse matrix, which for an arbitrary Lorentz Transformation is given by the following:
        //       Lambda^-1 = [xx  xy  xz -tx]
        //                   |yx  yy  yz -ty|
        //                   |zx  zy  zz -tz|
        //                   [-xt -yt -zt tt].
        //-----------------------------------------------------------------------------------------------------------------------------------

        L.Boost(0, 0, beta);      // since we have already performed the rotation, we only need to boost along the desired direction
        L.Invert();                     // as mentioned above, we need the inverse rotation.

        //------apply the transformation to the cm frame-------//
        
        //Loop over the vector containing the 4vectors
        for( /*initialized in the function*/ ; fourvector != end4Vec; ++fourvector) { 
            // (L*R*fourvector)
            (*fourvector)->Transform(R);     // apply the rotation.
            (*fourvector)->Transform(L);     // apply the boost 
        }
        return;    
    }

    void cmTransformation(TLorentzVector &particle, TLorentzVector &boost4Vector) {
        //------calculate the rotation matrix------//
        //
        //----------------------------------------------------------------------------------------------------------------------------------
        // note: The TRotation class describes so called active rotations, i.e. rotations of objects inside a static system of coordinates.
        //       In the case you want to rotate the frame and want to know the coordiantes of objects in the rotated coordinate system then
        //       you should apply the inverse rotation to the objects.
        //----------------------------------------------------------------------------------------------------------------------------------

        // variable initialization
        TRotation R;
        TLorentzRotation L;
        TVector3 xAxis(1,0,0);
        Double_t beta = boost4Vector.Beta();        // get the magnitude of beta from our boosting 4vector
        TVector3 boostVector = boost4Vector.Vect(); // the z-axis is in the direction of the vector component of the boost (p = gmv).

        // calculate the axes of the new coordinate system
        
        TVector3 newZ = boostVector.Unit();                // z-axis points along the direction of motion of the cm particle
        TVector3 newY = (boostVector.Cross(xAxis)).Unit(); // y-axis perpendicular to the z-axis (now we have a plane)
        TVector3 newX = (newY.Cross(newZ)).Unit();  // x-axis is perpendicular to the plane defined above (newY and newZ already unit vectors).
        
        // calculate the rotation matrix
        //
        //-----------------------------------------------------------------------------------------------------------------------------------
        // TRotation::RotateAxes()
        // note: Suppose there is a 3D object and its local axes a(1,0,0), b(0,1,0), c(0,0,1) originally coincide with the global axes.
        //       If it is known the position of local axes a'(ax',ay',az'), b'(bx',by',bz'), c'(cx',cy',cz') after the rotation then matrix
        //       which describes the rotation looks as follows:
        //       R = [ax' bx' cx']
        //           |ay' by' cy'|
        //           [az' bz' cz']
        //----------------------------------------------------------------------------------------------------------------------------------

        R.RotateAxes(newX, newY, newZ);
        R.Invert();                     // as mentioned above, we need the inverse rotation.

        //------calculate the Lorentz Transformation Matrix------//
        //
        //----------------------------------------------------------------------------------------------------------------------------------
        // TLorentzRotation:
        // note: The matrix described by this object is the following:
        //       Lambda = [xx xy xz xt]
        //                |yx yy yz yt|
        //                |zx zy zz zt|
        //                [tx ty tz tt].
        //       Recall that Root uses the weird convention for four vectors: a = (ax, ay, az, at).
        //----------------------------------------------------------------------------------------------------------------------------------
        //
        //----------------------------------------------------------------------------------------------------------------------------------
        // TLorentzRotation::boost():
        // note: the matrix that results from an arbitrary boost b = (bx, by, bz) is as follows:
        //       Boost  = [1+g'bx^2     g'bxby      g'bxbz      gbx]
        //                |g'bybz       1+g'by^2    g'bybz      gby|
        //                |g'bzbx       g'bzby      1+g'bz^2    gbz|
        //                [gbx          gby         gbz         g  ].
        //      where g' = (g-1)/b^2.
        //
        //       We need the inverse matrix, which for an arbitrary Lorentz Transformation is given by the following:
        //       Lambda^-1 = [xx  xy  xz -tx]
        //                   |yx  yy  yz -ty|
        //                   |zx  zy  zz -tz|
        //                   [-xt -yt -zt tt].
        //-----------------------------------------------------------------------------------------------------------------------------------

        L.Boost(0, 0, beta);      // since we have already performed the rotation, we only need to boost along the desired direction
        L.Invert();                     // as mentioned above, we need the inverse rotation.

        //------apply the transformation to the cm frame-------//
        // (L*R*particle)
        particle.Transform(R);  // apply the rotation
        particle.Transform(L);  // apply the boost
        return;    
    }

    void cmRotation(TLorentzVector &particle, TLorentzVector &boost4Vector) {
        //------calculate the rotation matrix------//
        //
        //----------------------------------------------------------------------------------------------------------------------------------
        // note: The TRotation class describes so called active rotations, i.e. rotations of objects inside a static system of coordinates.
        //       In the case you want to rotate the frame and want to know the coordiantes of objects in the rotated coordinate system then
        //       you should apply the inverse rotation to the objects.
        //----------------------------------------------------------------------------------------------------------------------------------

        // variable initialization
        TRotation R;
        TVector3 xAxis(1,0,0);
        Double_t beta = boost4Vector.Beta();        // get the magnitude of beta from our boosting 4vector
        TVector3 boostVector = boost4Vector.Vect(); // the z-axis is in the direction of the vector component of the boost (p = gmv).

        // calculate the axes of the new coordinate system
        
        TVector3 newZ = boostVector.Unit();                // z-axis points along the direction of motion of the cm particle
        TVector3 newY = (boostVector.Cross(xAxis)).Unit(); // y-axis perpendicular to the z-axis (now we have a plane)
        TVector3 newX = (newY.Cross(newZ)).Unit();  // x-axis is perpendicular to the plane defined above (newY and newZ already unit vectors).
        
        // calculate the rotation matrix
        //
        //-----------------------------------------------------------------------------------------------------------------------------------
        // TRotation::RotateAxes()
        // note: Suppose there is a 3D object and its local axes a(1,0,0), b(0,1,0), c(0,0,1) originally coincide with the global axes.
        //       If it is known the position of local axes a'(ax',ay',az'), b'(bx',by',bz'), c'(cx',cy',cz') after the rotation then matrix
        //       which describes the rotation looks as follows:
        //       R = [ax' bx' cx']
        //           |ay' by' cy'|
        //           [az' bz' cz']
        //----------------------------------------------------------------------------------------------------------------------------------

        R.RotateAxes(newX, newY, newZ);
        R.Invert();                     // as mentioned above, we need the inverse rotation. 
        
        //------apply the transformation to the cm frame-------//
        // (R*particle)
        particle.Transform(R);  // apply the rotation

        return;
    }

    void cmBoost(TLorentzVector &particle, TLorentzVector &boost4Vector) { 
        //------calculate the Lorentz Transformation Matrix------//
        //
        //----------------------------------------------------------------------------------------------------------------------------------
        // TLorentzRotation:
        // note: The matrix described by this object is the following:
        //       Lambda = [xx xy xz xt]
        //                |yx yy yz yt|
        //                |zx zy zz zt|
        //                [tx ty tz tt].
        //       Recall that Root uses the weird convention for four vectors: a = (ax, ay, az, at).
        //----------------------------------------------------------------------------------------------------------------------------------
        //
        //----------------------------------------------------------------------------------------------------------------------------------
        // TLorentzRotation::boost():
        // note: the matrix that results from an arbitrary boost b = (bx, by, bz) is as follows:
        //       Boost  = [1+g'bx^2     g'bxby      g'bxbz      gbx]
        //                |g'bybz       1+g'by^2    g'bybz      gby|
        //                |g'bzbx       g'bzby      1+g'bz^2    gbz|
        //                [gbx          gby         gbz         g  ].
        //      where g' = (g-1)/b^2.
        //
        //       We need the inverse matrix, which for an arbitrary Lorentz Transformation is given by the following:
        //       Lambda^-1 = [xx  xy  xz -tx]
        //                   |yx  yy  yz -ty|
        //                   |zx  zy  zz -tz|
        //                   [-xt -yt -zt tt].
        //-----------------------------------------------------------------------------------------------------------------------------------

        TLorentzRotation L;
        Double_t beta = boost4Vector.Beta();        // get the magnitude of beta from our boosting 4vector
        L.Boost(0, 0, beta);                        // since we have already performed the rotation, we only need to boost along the desired direction
        L.Invert();                                 // as mentioned above, we need the inverse rotation.

        //------apply the transformation to the cm frame-------//
        // (L*particle)
        particle.Transform(L);  // apply the boost
    
        return; 
    }

}
