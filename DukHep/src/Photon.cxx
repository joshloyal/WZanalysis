//-----------------------------------------------------------------------------------------------
//
// #Name: Photon.cxx
// #Description: This file contains a few methods that perform calculated properties of the 
//               photons.
// 
// #Author: Joshua Loyal
// #Updated: 6/19/2011
//
//-----------------------------------------------------------------------------------------------

// STL include(s)
#include <vector>

// class include
#include "DukHep/include/Photon.h"

// egamma/photonID include(s)
#include "DukHep/include/EnergyRescaler.h"
#include "PhotonIDTool/PhotonIDTool.h"
#include "egammaAnalysisUtils/egammaAnalysisUtils/CaloIsoCorrection.h"

// using declarations
using AnalysisUtils::dR;

// static variable initialization
float Photon::ph_dpx = 0.;
float Photon::ph_dpy = 0.;

//-----Energy Correction Functions-----//

// energy rescale method
double Photon::CorrectEnergy(std::string part_type) {

    // initalize a few variables and the Energy Rescaler object
    EnergyRescaler m_eRescaler;
    m_eRescaler.useDefaultCalibConstants("2011");
    double corrE(0.);
    double photon_E_scale(1.0);
    double photon_cl_eng = eCluster/1000.0;
    double photon_cl_et  = etCluster/1000.0;

    //-----Energy Rescale (data only)-----//

    // method returns corrected energy
    corrE = (float) m_eRescaler.applyEnergyCorrection(etaCluster, phiCluster, photon_cl_eng, photon_cl_et, 0, part_type);
        
    // I don't know why these lines of code are necessary
    photon_E_scale = corrE/photon_cl_eng;
    eCluster = (photon_E_scale*photon_cl_eng)*1000.0;

    // implement the corrected et variables
    etCluster   = std::cosh(etaCluster) != 0. ? eCluster/std::cosh(etaCluster) : 0.;
    ptCluster   = etCluster;
    etShower    = std::cosh(Etas2) != 0. ? eCluster/std::cosh(Etas2) : 0.;
    
    // re-set photon 4vector
    this->SetPtEtaPhiE(etCluster, etaCluster, phiCluster, eCluster);

    return photon_E_scale;
}

// energy smearing method
double Photon::CorrectEnergy(Int_t EventNumber, bool mcWithConstantTerm) {
   
    // initialize a few variables and the EnergyRescaler object
    EnergyRescaler m_eRescaler;
    m_eRescaler.useDefaultCalibConstants("2011");
    double photon_smearcorr(1.0);
    double photon_cl_eng = eCluster/1000.0;
        
    //-----Energy Smearing (MC only)-----//
    
    // set random seed, probably to something like eventNumbe + offset
    m_eRescaler.SetRandomSeed(1771561+EventNumber+(Index*10));
        
    // calculate the smeared cluster energy
    photon_smearcorr = m_eRescaler.getSmearingCorrection(etaCluster, photon_cl_eng, 0, mcWithConstantTerm, "2011");
    eCluster = (photon_smearcorr*photon_cl_eng)*1000.0;

    // implement the corrected et variables
    etCluster   = std::cosh(etaCluster) != 0. ? eCluster/std::cosh(etaCluster) : 0.;
    ptCluster   = etCluster;
    etShower    = std::cosh(Etas2) != 0. ? eCluster/std::cosh(Etas2) : 0.;

    // re-set photon 4vector
    this->SetPtEtaPhiE(etCluster, etaCluster, phiCluster, eCluster);
    
    return photon_smearcorr;
}


bool Photon::isTight() const {
    // calculate some values used in the PhotonIDTool constructor
    //double eta2 = fabs(Etas2);
    //double et   = std::cosh(eta2) != 0. ? eCluster/std::cosh(eta2) : 0.;

    PhotonIDTool GammaSelection = PhotonIDTool( etShower,           // shower transverse energy
                                                fabs(Etas2),        // eta from the 2nd calo sampling
                                                Ethad1  ,           // energy leakage measured in the first sampling of the  Hcal
                                                Ethad   ,           // energy leakage measured in the whole Hcal
                                                E277    ,           // energy deposited in the second sampling of the electromagnetic calorimeter in a DeltaEta*DeltaPhi=7x7
                                                E237    ,           // energy deposited in the second sampling of the electromagnetic calorimeter in a DeltaEta*DeltaPhi=3x7
                                                E233    ,           // energy deposited in the second sampling of the electromagnetic calorimeter in a DeltaEta*DeltaPhi=3x3
                                                Weta2   ,           // shower lateral width in the Ecal middle
                                                F1      ,           // something...
                                                Emaxs1  ,           // energy deposited in the strip of first sampling of Ecal with the maximum energy
                                                Emax2   ,           // energy deposited in the strip with the maximum energy
                                                Emins1  ,           // energy deposited in the strip of first sampling of Ecal with the minimum energy
                                                Fside   ,           // fside = fracm : fraction of energy outside the core of the shower
                                                Wstot   ,           // width of the shower in 20 strips of first sampling
                                                Ws3     ,           // width of the shower in 3 strips of first sampling (should be ws1...)
                                                isConversion  );    // conversion flag 

    if(!GammaSelection.PhotonCutsTight(6)) return false;

    return true;
}

float Photon::getConeCorrected(const std::vector<int> *vxp_nTracks, bool isMC) const {
/*    // variable to count the number of primary verticies
    unsigned int nPV(0);

    // count the number of primary verticies in the event with at least 2 associated tracks
    for(unsigned int i = 0; i < vxp_nTracks->size(); i++) {
        if(vxp_nTracks->at(i) >= 2) nPV++;
    }
 
    float ConeCorrected = CaloIsoCorrection::GetPtNPVCorrectedIsolation( nPV            ,               // number of primary vertices with 2 associated tracks
                                                                         eCluster       ,               // cluster energy (in MeV)
                                                                         Etas2          ,               // eta from the 2nd calo sampling
                                                                         etaPointing    ,               // pointing eta (from the first and second calo sampling)
                                                                         etaCluster     ,               // cluster eta
                                                                         0.40           ,               // radius of input cone variable (dr or dr*100)
                                                                         isMC           ,               // flag for applying MC corrections
                                                                         etCone40       ,               // value of the uncorrected etconeXX variable
                                                                         isConversion   ,               // conversion flag
                                                                         CaloIsoCorrection::PHOTON );   // enum in CaloIsoCorrection namespace
    
    return ConeCorrected;
*/
return etCone40_Corrected;
}

float Photon::getConeCorrected(unsigned int nPV, bool isMC) const {
/*    // calculate cone corrected
    float ConeCorrected = CaloIsoCorrection::GetPtNPVCorrectedIsolation( nPV            ,               // number of primary vertices with 2 associated tracks
                                                                         eCluster       ,               // cluster energy (in MeV)
                                                                         Etas2          ,               // eta from the 2nd calo sampling
                                                                         etaPointing    ,               // pointing eta (from the first and second calo sampling)
                                                                         etaCluster     ,               // cluster eta
                                                                         0.4            ,               // radius of input cone variable (dr or dr*100)
                                                                         isMC           ,               // flag for applying MC corrections
                                                                         etCone40       ,               // value of the uncorrected etconeXX variable
                                                                         isConversion   ,               // conversion flag
                                                                         CaloIsoCorrection::PHOTON );   // enum in CaloIsoCorrection namespace

    return ConeCorrected;
*/
return etCone40_Corrected;
}

void Photon::checkIsolation(std::vector<Muon*>::const_iterator amuon, std::vector<Muon*>::const_iterator endmuon, float mindR) {
    // loop through the muon container
    for( /*initialized in the function*/ ; amuon != endmuon; ++amuon) {
        // check the eta-phi separation
        if( dR(*amuon, this) < mindR ) {
            IsIsolated = false;
            return;
        }
    }
    return;
}

   
