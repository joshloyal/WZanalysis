#include "IsEMPlusPlusDefs.h"

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
   Author: John Alison <johnda@sas.upenn.edu>
           Chris Lester <clester@sas.upenn.edu>
	   
   Includes:
           Medium++ Optimization for  > 20 GeV electrons (MC corrected from Z T and P)
	   Loose++  Optimization for  > 20 GeV electrons (MC corrected from Z T and P)
	   Medium++ Optimization for 10-20 GeV electrons (MC corrected from Tight Ele )
	   Loose++ Optimization for 10-20 GeV electrons (MC corrected from Tight Ele )
	   
   Usage:
     The isMediumPlusPlus, and isLoosePlusPlus methods take input PiD Variables,
     and returns true if the electron satisfies the loose++ or medium++ requriements.
     It returns false otherwise.

     Additional output will be givedn if debug is set, (false by default).
     
     The trigger bit emulates the online selction of e20_medium1.

     An example of using the macro with the details of the input variables can be found 
       in offline/Reconstruction/egamma/egammaAnalysis/egammaAnalysisUtils

   Created:
      May 2011

*/

//----------------------------------------------------------------------------------------
bool isLoosePlusPlus(double eta, double eT,
		     double rHad, double rHad1, double Reta, double w2, 
		     double f1, double wstot, double DEmaxs1, double deltaEta, int nSi, 
		     bool debug, bool isTrigger
		     ){
		      

  if(eT < 10*1000){
    std::cout << " Loose++ is not yet defined below 10 GeV...false." << std::endl;
    return false;
  }

  if(eta > 2.47){
    if(debug)
      std::cout << "Failed, eta range. " << std::endl;
    return false;
  }

  unsigned int eTBin = getEtBin(eT);
  // The e20_loose++ trigger uses the 20-30 GeV bin cuts for all electrons. 
  if(isTrigger){
    eTBin = getEtBin(21*1000);

    if(eT < 20*1000){
      std::cout << " Failed, e20 Et threshold" << std::endl;
      return false;
    }
  }

  unsigned int etaBin = getEtaBin(eta);

  // RHad
  if(!passRHad_loose(rHad,rHad1,eTBin,etaBin)){
    if(debug)
      std::cout << "Failed RHad " << rHad << " " << eT << " " << eta << " " << std::endl;
    return false;
  }

  // Reta 
  if(!passReta_loose(Reta,eTBin,etaBin)){
    if(debug)
      std::cout << "Failed Reta " << Reta << " " << eT << " " << eta << " " << std::endl;
    return false;
  }

  // w2
  if(!passW2_loose(w2,eTBin,etaBin)){
    if(debug)
      std::cout << "Failed w2 " << w2 << " " << eT << " " << eta << " " << std::endl;
    return false;
  }

  // Check the energy in the strips before cutting on it
  if(f1 > 0.005){

    // wstot
    if(!passWstot_loose(wstot,eTBin,etaBin)){
      if(debug)
	std::cout << "Failed wstot " << wstot << " " << eT << " " << eta << " " << std::endl;
      return false;
    }

    // Eratio
    if(!passEratio_loose(DEmaxs1,eTBin,etaBin)){
      if(debug)
	std::cout << "Failed DEmaxs1 " << DEmaxs1 << " " << eT << " " << eta << " " << std::endl;
      return false;
    }
  }
  
  // Delta Eta
  if(!passDeltaEta_loose(deltaEta)){
    if(debug)
      std::cout << "Failed dEta " << deltaEta << " " << eT << " " << eta << " " << std::endl;
    return false;
  }

  // Si
  if(nSi < 5){
    if(debug)
      std::cout << "Failed nSi " << nSi << " " << eT << " " << eta << " " << std::endl;
    return false;
    }

  return true;
}

//-------------------------------------------------------------------------------------------------------
bool isMediumPlusPlus(double eta, double eT,
			double rHad, double rHad1, double Reta, double w2, 
			double f1, double wstot, double DEmaxs1, double deltaEta, double d0,
			double TRratio, int nTRT, int nTRTOutliers,
			int nSi, int nPix, int nPixOutliers, 
			int nBlayer, int nBlayerOutliers, bool expectBlayer, 
			bool debug, bool isTrigger ){
		      

  if(eT < 10*1000){
    std::cout << " Medium++ is not yet defined below 10 GeV ... returning false" << std::endl;
    return false;
  }

  if(eta > 2.47){
    if(debug)
      std::cout << "Failed, eta range. " << std::endl;
    return false;
  }

  unsigned int eTBin = getEtBin(eT);
  // The e20_medium1 trigger uses the 20-30 GeV bin cuts for all electrons. 
  if(isTrigger){
    eTBin = getEtBin(21*1000);
    
    if(eT < 20*1000){
      std::cout << " Failed, e20 Et threshold" << std::endl;
      return false;
    }

  }

  unsigned int etaBin = getEtaBin(eta);

  // RHad
  if(!passRHad_med(rHad,rHad1,eTBin,etaBin)){
    if(debug)
      std::cout << "Failed RHad " << rHad << " " << eT << " " << eta << " " << std::endl;
    return false;
  }

  // Reta 
  if(!passReta_med(Reta,eTBin,etaBin)){
    if(debug)
      std::cout << "Failed Reta " << Reta << " " << eT << " " << eta << " " << std::endl;
    return false;
  }
  

  // w2
  if(!passW2_med(w2,eTBin,etaBin)){
    if(debug)
      std::cout << "Failed w2 " << w2 << " " << eT << " " << eta << " " << std::endl;
    return false;
  }

  // Check the energy in the strips before cutting on it
  if(f1 > 0.005){

    // wstot
    if(!passWstot_med(wstot,eTBin,etaBin)){
      if(debug)
	std::cout << "Failed wstot " << wstot << " " << eT << " " << eta << " " << std::endl;
      return false;
    }


    // Eratio
    if(!passEratio_med(DEmaxs1,eTBin,etaBin)){
      if(debug)
	std::cout << "Failed DEmaxs1 " << DEmaxs1 << " " << eT << " " << eta << " " << std::endl;
      return false;
    }
  }
  
  // Delta Eta
  if(!passDeltaEta_med(deltaEta)){
    if(debug)
      std::cout << "Failed dEta " << deltaEta << " " << eT << " " << eta << " " << std::endl;
    return false;
  }


  // TR
  if(!passTR_med(TRratio,eta,nTRT+nTRTOutliers)){
    if(debug)
      std::cout << "Failed TR " << TRratio << " " << eT << " " << eta << " " << std::endl;
    return false;
  }


  // Si
  if(nSi < 7){
    if(debug)
      std::cout << "Failed nSi " << nSi << " " << eT << " " << eta << " " << std::endl;
    return false;
    }


  // Pix 
  if(fabs(eta) > 2.01){
    // For eta above 2 we want use pixel outliers for the additional Npix >= 2 requirement,
    //  but, *NOT* for the old medium Npix >= 1 requirement for backwards compatibility  
    if(nPix < 1){
      if(debug)
	std::cout << "Failed (old) nPix " << nPix << " " << eT << " " << eta << " " << std::endl;
      return false;
    }    

    if(!passNPix_med(nPix+nPixOutliers,etaBin)){
      if(debug)
	std::cout << "Failed nPix " << nPix << " " << eT << " " << eta << " " << std::endl;
      return false;
    }

  }else{
    if(!passNPix_med(nPix,etaBin)){
      if(debug)
	std::cout << "Failed nPix " << nPix << " " << eT << " " << eta << " " << std::endl;
      return false;
    }
  }

  // Blayer
  if(expectBlayer && !passNBlayer_med(nBlayer+nBlayerOutliers,etaBin)){
    if(debug)
      std::cout << "Failed Bl " << nBlayer << " " << eT << " " << eta << " " << std::endl;
    return false;
  }

  // d0
  if(fabs(d0) > 5){
    if(debug)
      std::cout << "Failed d0 " << d0 << " " << eT << " " << eta << " " << std::endl;
      return false;
  }

  return true;
}

//---------------------------------------------------------------------------------------
// Gets the Eta bin [0-9] given the eta
unsigned int getEtaBin(double eta){
  const unsigned int nEtaBins = 10;
  const double etaBins[nEtaBins] = {0.1,0.6,0.8,1.15,1.37,1.52,1.81,2.01,2.37,2.47};
  
  for(unsigned int etaBin = 0; etaBin < nEtaBins; ++etaBin){
    if(fabs(eta) < etaBins[etaBin])
      return etaBin;
  }
  
  return 9;
}

//---------------------------------------------------------------------------------------
// Gets the Et bin [0-10] given the et (MeV)
unsigned int getEtBin(double eT){
  const unsigned int nEtBins = 11;
  const double GeV = 1000;
  const double eTBins[nEtBins] = {5*GeV,10*GeV,15*GeV,20*GeV,30*GeV,40*GeV,50*GeV,60*GeV,70*GeV,80*GeV};
  
  for(unsigned int eTBin = 0; eTBin < nEtBins; ++eTBin){
    if(eT < eTBins[eTBin])
      return eTBin;
  }
  
  return 10;
}

//----------------------------------------------------------------------------------------
bool passRHad_med(double rHad, double rHad1,unsigned int eTBin,unsigned int etaBin){
  
  // New values cut on rHad (rows are eT bins, columns are eta bins)
  //                               0.0   0.1    0.6    0.8   1.15   1.37   1.52   1.81   2.01  2.37    2.47
  const double cutRHad[11][10]  = {{ 0.031, 0.031, 0.021, 0.021, 0.019, 0.028, 0.065, 0.065, 0.046, 0.034}// < 5
				   ,{0.018, 0.018, 0.016, 0.015, 0.016, 0.028, 0.053, 0.038, 0.028, 0.025} // 5-10 
				   ,{0.015 ,0.015 ,0.014 ,0.015 ,0.013 ,0.033 ,0.030 ,0.028 ,0.021 ,0.020} //10-15
				   ,{0.013 ,0.013 ,0.013 ,0.014 ,0.012 ,0.029 ,0.029 ,0.020 ,0.017 ,0.016} //15-20
				   ,{0.010, 0.010, 0.010, 0.010, 0.010, 0.010, 0.020, 0.015, 0.008, 0.008}// 20-30 
				   ,{0.008, 0.008, 0.008, 0.008, 0.008, 0.010, 0.014, 0.015, 0.008, 0.008}// 30-40 
				   ,{0.008, 0.008, 0.008, 0.008, 0.008, 0.010, 0.015, 0.015, 0.008, 0.008}// 40-50
				   ,{0.008, 0.008, 0.008, 0.008, 0.008, 0.010, 0.015, 0.015, 0.008, 0.008}// 50-60 
				   ,{0.008, 0.008, 0.008, 0.008, 0.008, 0.010, 0.015, 0.015, 0.008, 0.008}// 60-70 
				   ,{0.008, 0.008, 0.008, 0.008, 0.008, 0.010, 0.015, 0.015, 0.008, 0.008}// 70-80 
				   ,{0.008, 0.008, 0.008, 0.008, 0.008, 0.010, 0.015, 0.015, 0.008, 0.008}};// 80< 


  if(etaBin == 3 || etaBin == 4){
    if (rHad > cutRHad[eTBin][etaBin])
      return false;
  } else{
    if(rHad1 > cutRHad[eTBin][etaBin])
      return false;
  }

  return true;
}

//----------------------------------------------------------------------------------------
bool passRHad_loose(double rHad, double rHad1,unsigned int eTBin,unsigned int etaBin){




  // New values cut on rHad (rows are eT bins, columns are eta bins)
  //                               0.0   0.1    0.6    0.8   1.15   1.37   1.52   1.81   2.01  2.37    2.47
  const double cutRHad[11][10]  = {{ 0.031, 0.031, 0.021, 0.021, 0.019, 0.028, 0.065, 0.065, 0.046, 0.034}// < 5
				   ,{0.018, 0.018, 0.016, 0.015, 0.016, 0.028, 0.053, 0.038, 0.028, 0.025} // 5-10 
				   ,{0.018, 0.018, 0.018, 0.020, 0.015, 0.033, 0.035, 0.033, 0.024, 0.025} //10-15
				   ,{0.015, 0.015, 0.015, 0.016, 0.013, 0.029, 0.033, 0.022, 0.019, 0.018} //15-20
				   ,{0.012, 0.012, 0.012, 0.012, 0.012, 0.015, 0.030, 0.022, 0.016, 0.016} //20-30
				   ,{0.011, 0.011, 0.011, 0.011, 0.011, 0.011, 0.021, 0.021, 0.015, 0.015} //30-40
				   ,{0.011, 0.011, 0.011, 0.011, 0.011, 0.011, 0.015, 0.015, 0.010, 0.010} //40-50
				   ,{0.011, 0.011, 0.011, 0.011, 0.011, 0.011, 0.015, 0.015, 0.010, 0.015}// 50-60 
				   ,{0.011, 0.011, 0.011, 0.011, 0.011, 0.011, 0.015, 0.015, 0.010, 0.015}// 60-70 
				   ,{0.011, 0.011, 0.011, 0.011, 0.011, 0.011, 0.015, 0.015, 0.010, 0.015}// 70-80 
				   ,{0.011, 0.011, 0.011, 0.011, 0.011, 0.011, 0.015, 0.015, 0.010, 0.015}};// > 80

  
  //if 0.8 < event.el_cl_eta and event.el_cl_eta < 1.37:
  //               self.rHad = event.el_Ethad/event.el_cl_Et

  if(etaBin == 3 || etaBin == 4){
    if (rHad > cutRHad[eTBin][etaBin])
      return false;
  } else{
    if(rHad1 > cutRHad[eTBin][etaBin])
      return false;
  }

  return true;
}

//----------------------------------------------------------------------------------------
bool passReta_med(double rEta, unsigned int eTBin, unsigned int etaBin){
  // New values cut on ratio e237/e277 (rows are eT bins, columns are eta bins)
  //                               0.0   0.1      0.6    0.8   1.15   1.37   1.52   1.81    2.01   2.37   2.47
  const double cutReta37[11][10] = {{ 0.700, 0.700, 0.700, 0.700, 0.700, 0.690, 0.848, 0.876, 0.870, 0.888}  // < 5
				    ,{0.700, 0.700, 0.700, 0.700, 0.700, 0.715, 0.860, 0.880, 0.880, 0.880} // 5-10
				    ,{0.895 ,0.895 ,0.885 ,0.885 ,0.885 ,0.740 ,0.870 ,0.885 ,0.880 ,0.880} //10-15
				    ,{0.910 ,0.910 ,0.905 ,0.905 ,0.900 ,0.740 ,0.890 ,0.900 ,0.890 ,0.890} //15-20
				    ,{0.930, 0.930, 0.930, 0.925, 0.925, 0.750, 0.915, 0.915, 0.910, 0.910}// 20-30
				    ,{0.930, 0.930, 0.930, 0.925, 0.925, 0.790, 0.915, 0.920, 0.910, 0.910}// 30-40
				    ,{0.930, 0.930, 0.930, 0.925, 0.925, 0.790, 0.915, 0.920, 0.910, 0.910}// 40-50
				    ,{0.930, 0.930, 0.930, 0.930, 0.925, 0.790, 0.915, 0.920, 0.910, 0.910}// 50-60
				    ,{0.930, 0.930, 0.930, 0.930, 0.925, 0.790, 0.915, 0.920, 0.910, 0.910}// 60-70
				    ,{0.930, 0.930, 0.930, 0.930, 0.925, 0.790, 0.915, 0.920, 0.910, 0.910}// 70-80
				    ,{0.930, 0.930, 0.930, 0.930, 0.925, 0.790, 0.915, 0.920, 0.910, 0.910}};// 80<

  if(rEta < cutReta37[eTBin][etaBin])
    return false;

  return true;
}

//----------------------------------------------------------------------------------------
bool passReta_loose(double rEta, unsigned int eTBin, unsigned int etaBin){
  // New values cut on ratio e237/e277 (rows are eT bins, columns are eta bins)
  //                               0.0   0.1    0.6    0.8   1.15   1.37   1.52   1.81    2.01   2.37   2.47
  const double cutReta37[11][10] = {{ 0.700, 0.700, 0.700, 0.700, 0.700, 0.690, 0.848, 0.876, 0.870, 0.888}  // < 5
				    ,{0.700, 0.700, 0.700, 0.700, 0.700, 0.715, 0.860, 0.880, 0.880, 0.880}  // 5-10
				    ,{0.875 ,0.875 ,0.875 ,0.875 ,0.875 ,0.740 ,0.860 ,0.875 ,0.870 ,0.870}  //10-15
				    ,{0.900 ,0.900 ,0.895 ,0.895 ,0.890 ,0.740 ,0.880 ,0.900 ,0.880 ,0.880}  //15-20
				    ,{0.910 ,0.910 ,0.910 ,0.910 ,0.910 ,0.750 ,0.890 ,0.900 ,0.890 ,0.890}  //20-30
				    ,{0.920 ,0.920 ,0.920 ,0.915 ,0.915 ,0.790 ,0.895 ,0.915 ,0.895 ,0.890}  //30-40
				    ,{0.920 ,0.920 ,0.920 ,0.915 ,0.915 ,0.790 ,0.895 ,0.915 ,0.895 ,0.890}  //40-50
				    ,{0.920 ,0.920 ,0.920 ,0.915 ,0.915 ,0.790 ,0.915 ,0.915 ,0.895 ,0.890}  // 50-60
				    ,{0.920 ,0.920 ,0.920 ,0.915 ,0.915 ,0.790 ,0.915 ,0.915 ,0.895 ,0.890}  // 60-70 
				    ,{0.920 ,0.920 ,0.920 ,0.915 ,0.915 ,0.790 ,0.915 ,0.915 ,0.895 ,0.890}  // 70-80 
				    ,{0.920 ,0.920 ,0.920 ,0.915 ,0.915 ,0.790 ,0.915 ,0.915 ,0.895 ,0.890}};// 80<   

  if(rEta < cutReta37[eTBin][etaBin])
    return false;

  return true;
}

//----------------------------------------------------------------------------------------
bool passW2_med(double w2, unsigned int eTBin, unsigned int etaBin){
  
  //New values for cut on shower width in 2nd sampling (rows are eT bins, columns are eta bins)
  //                               0.0   0.1    0.6    0.8   1.15   1.37   1.52   1.81    2.01   2.37   2.47
  const double cutWeta2[11][10] = {{ 0.014, 0.014, 0.014, 0.014, 0.014, 0.028, 0.017, 0.014, 0.014, 0.014} // < 5 
				   ,{0.013, 0.013, 0.014, 0.014, 0.014, 0.026, 0.017, 0.014, 0.014, 0.014} // 5-10
				   ,{0.012 ,0.012 ,0.0125 ,0.0125 ,0.0125 ,0.025 ,0.0140 ,0.013 ,0.013 ,0.013} //10-15
				   ,{0.012 ,0.012 ,0.0125 ,0.0125 ,0.013 ,0.025 ,0.0140 ,0.013 ,0.013 ,0.013 } //15-20
				   ,{0.011, 0.011, 0.012, 0.012, 0.013, 0.025, 0.014, 0.013, 0.0125, 0.0125} // 20-30
				   ,{0.011, 0.011, 0.012, 0.012, 0.012, 0.025, 0.013, 0.013, 0.0125, 0.0125} // 30-40
				   ,{0.011, 0.011, 0.012, 0.012, 0.012, 0.025, 0.013, 0.013, 0.0125, 0.0125} // 40-50
				   ,{0.011, 0.011, 0.012, 0.012, 0.012, 0.025, 0.013, 0.012, 0.0125, 0.0125} // 50-60
				   ,{0.011, 0.011, 0.012, 0.012, 0.012, 0.025, 0.013, 0.012, 0.0125, 0.0125} // 60-70
				   ,{0.011, 0.011, 0.012, 0.012, 0.012, 0.025, 0.013, 0.012, 0.0125, 0.0125} // 70-80
				   ,{0.011, 0.011, 0.012, 0.012, 0.012, 0.025, 0.013, 0.012, 0.0125, 0.0125}}; // 80<  

  if(w2 > cutWeta2[eTBin][etaBin])
    return false;
    
  return  true;
}

//----------------------------------------------------------------------------------------
bool passW2_loose(double w2, unsigned int eTBin, unsigned int etaBin){
  
  //New values for cut on shower width in 2nd sampling (rows are eT bins, columns are eta bins)
  //                               0.0   0.1    0.6    0.8   1.15   1.37   1.52   1.81    2.01   2.37   2.47
  const double cutWeta2[11][10] = {{ 0.014, 0.014, 0.014, 0.014, 0.014, 0.028, 0.017, 0.014, 0.014, 0.014}   // < 5 
				   ,{0.013, 0.013, 0.014, 0.014, 0.014, 0.026, 0.017, 0.014, 0.014, 0.014}  // 5-10
				   ,{0.013 ,0.013 ,0.014 ,0.015 ,0.015 ,0.025 ,0.016 ,0.015 ,0.015 ,0.0145} //10-15
				   ,{0.013 ,0.013 ,0.014 ,0.015 ,0.015 ,0.025 ,0.016 ,0.015 ,0.015 ,0.0145} //15-20
				   ,{0.013 ,0.013 ,0.014 ,0.015 ,0.015 ,0.025 ,0.016 ,0.015 ,0.015 ,0.014 } //20-30
				   ,{0.012 ,0.012 ,0.013 ,0.013 ,0.013 ,0.025 ,0.015 ,0.014 ,0.014 ,0.013 } //30-40
				   ,{0.011 ,0.011 ,0.012 ,0.013 ,0.013 ,0.025 ,0.015 ,0.014 ,0.014 ,0.013 } //40-50
				   ,{0.011 ,0.011 ,0.012 ,0.013 ,0.013 ,0.025 ,0.015 ,0.014 ,0.014 ,0.013}// 50-60
				   ,{0.011 ,0.011 ,0.012 ,0.013 ,0.013 ,0.025 ,0.015 ,0.014 ,0.014 ,0.013}// 60-70 
				   ,{0.011 ,0.011 ,0.012 ,0.013 ,0.013 ,0.025 ,0.015 ,0.014 ,0.014 ,0.013}// 70-80 
				   ,{0.011 ,0.011 ,0.012 ,0.013 ,0.013 ,0.025 ,0.015 ,0.014 ,0.014 ,0.013}};// 80<   

  if(w2 > cutWeta2[eTBin][etaBin])
    return false;
    
  return  true;
}

//----------------------------------------------------------------------------------------
bool passWstot_med(double wstot, unsigned int eTBin, unsigned int etaBin){
  
  //New values for cut on shower width in 2nd sampling (rows are eT bins, columns are eta bins)
  //                               0.0   0.1    0.6    0.8   1.15   1.37   1.52   1.81    2.01   2.37   2.47
  const double cutWstot[11][10]  = {{3.48, 3.48, 3.78, 3.96, 4.20, 9999., 4.02, 2.70, 1.86,  9999.} // < 5    GeV
				    ,{3.18, 3.18, 3.54, 3.90, 4.02, 9999., 3.96, 2.70, 1.80,  9999.} // 5-10   
				    ,{2.76 ,2.76 ,3.00 ,3.40 ,3.50 ,9999. ,3.65 ,2.36 ,1.72 ,9999}  //10-15
				    ,{2.76 ,2.76 ,2.92 ,3.30 ,3.45 ,9999. ,3.67 ,2.35 ,1.72 ,9999}  //15-20
				    ,{2.50, 2.50, 2.70, 3.14, 3.23, 9999., 3.58, 2.32, 1.59,  9999.} // 20-30  
				    ,{2.45, 2.45, 2.70, 2.98, 3.17, 9999., 3.52, 2.25, 1.58,  9999.} // 30-40  
				    ,{2.27, 2.27, 2.61, 2.90, 3.17, 9999., 3.36, 2.25, 1.55,  9999.} // 40-50  
				    ,{2.27, 2.27, 2.61, 2.90, 3.17, 9999., 3.36, 2.25, 1.55,  9999.} // 50-60  
				    ,{2.27, 2.27, 2.61, 2.90, 3.17, 9999., 3.36, 2.25, 1.55,  9999.} // 60-70  
				    ,{2.27, 2.27, 2.61, 2.90, 3.17, 9999., 3.36, 2.25, 1.55,  9999.} // 70-80  
				    ,{2.27, 2.27, 2.61, 2.90, 3.17, 9999., 3.36, 2.25, 1.55,  9999.}};  // 80<    
  

  if(wstot > cutWstot[eTBin][etaBin])
    return false;
    
  return  true;
}

//----------------------------------------------------------------------------------------
bool passWstot_loose(double wstot, unsigned int eTBin, unsigned int etaBin){
  
  //New values for cut on shower width in 2nd sampling (rows are eT bins, columns are eta bins)
  //                               0.0   0.1    0.6    0.8   1.15   1.37   1.52   1.81    2.01   2.37   2.47
  const double cutWstot[11][10]  = {{3.48, 3.48, 3.78, 3.96, 4.20, 9999., 4.02, 2.70, 1.86,  9999.} // < 5    GeV
				    ,{3.18, 3.18, 3.54, 3.90, 4.02, 9999., 3.96, 2.70, 1.80,  9999.} // 5-10   
				    ,{2.90, 2.90, 3.10, 3.55, 3.55, 9999., 3.80, 3.000, 2.00, 9999} //10-15
				    ,{2.90, 2.90, 3.05, 3.50, 3.50, 9999., 3.80, 3.000, 2.00, 9999} //15-20
				    ,{2.90, 2.90, 2.90, 3.50, 3.50, 9999., 3.80, 3.000, 2.00, 9999} //20-30
				    ,{2.80, 2.80, 2.80, 3.30, 3.40, 9999., 3.70, 3.000, 1.70, 9999} //30-40
				    ,{2.80, 2.80, 2.80, 3.20, 3.40, 9999., 3.70, 2.900, 1.60, 9999} //40-50
				    ,{2.80 ,2.80 ,2.80 ,3.20 ,3.40, 9999 ,3.70 ,2.900 ,1.60 ,9999}  // 50-60  
				    ,{2.80 ,2.80 ,2.80 ,3.20 ,3.40, 9999 ,3.70 ,2.900 ,1.60 ,9999}  // 60-70   
				    ,{2.80 ,2.80 ,2.80 ,3.20 ,3.40, 9999 ,3.70 ,2.900 ,1.60 ,9999}  // 70-80   
				    ,{2.80 ,2.80 ,2.80 ,3.20 ,3.40, 9999 ,3.70 ,2.900 ,1.60 ,9999}};   // 80<    


  if(wstot > cutWstot[eTBin][etaBin])
    return false;
    
  return  true;
}


//----------------------------------------------------------------------------------------
bool passEratio_med(double DEmaxs1, unsigned int eTBin, unsigned int etaBin){
  
  
  //cut on (Emax - Emax2)/(Emax + Emax2) in 1st sampling 
  //                               0.0   0.1    0.6    0.8   1.15   1.37   1.52   1.81    2.01   2.37   2.47
  const double cutDEmaxs1[11][10] = {{0.39,   0.39,  0.20,  0.07, 0.06,  -9999.,  0.07,  0.43,   0.75, -9999.} // < 5  
				     ,{0.61,  0.61,  0.32,  0.11, 0.13,  -9999.,  0.12,  0.51,   0.62, -9999.} // 5-10
				     ,{0.830 ,0.830 ,0.750 ,0.660 ,0.650, -9999 ,0.650 ,0.860 ,0.830, -9999.} //10-15
				     ,{0.830 ,0.830 ,0.825 ,0.730 ,0.670, -9999 ,0.750 ,0.900 ,0.890, -9999.} //15-20
				     ,{0.835, 0.835, 0.835, 0.73,  0.70,  -9999., 0.8,   0.9 ,  0.91,  -9999.} // 20-30 
				     ,{0.835, 0.835, 0.835, 0.73,  0.70,  -9999., 0.8,   0.9 ,  0.91,  -9999.} // 30-40
				     ,{0.835, 0.835, 0.835, 0.73,  0.70,  -9999., 0.8,   0.9 ,  0.91,  -9999.} // 40-50
				     ,{0.835, 0.835, 0.835, 0.73,  0.70,  -9999., 0.8,   0.9 ,  0.91,  -9999.} // 50-60 
				     ,{0.835, 0.835, 0.835, 0.73,  0.70,  -9999., 0.8,   0.9 ,  0.91,  -9999.} // 60-70
				     ,{0.835, 0.835, 0.835, 0.73,  0.70,  -9999., 0.8,   0.9 ,  0.91,  -9999.} // 70-80
				     ,{0.835, 0.835, 0.835, 0.73,  0.70,  -9999., 0.8,   0.9 ,  0.91,  -9999.}}; // 80<


  if(DEmaxs1 < cutDEmaxs1[eTBin][etaBin])
    return false;
    
  return  true;
}

//----------------------------------------------------------------------------------------
bool passEratio_loose(double DEmaxs1, unsigned int eTBin, unsigned int etaBin){
  
  
  //cut on (Emax - Emax2)/(Emax + Emax2) in 1st sampling 
  //                               0.0   0.1    0.6    0.8   1.15   1.37   1.52   1.81    2.01   2.37   2.47
  const double cutDEmaxs1[11][10] = {{0.39,  0.39,  0.20,  0.07, 0.06,  -9999.,  0.07,  0.43,   0.75,  -9999.}    // < 5  
				     ,{0.61,  0.61,  0.32,  0.11, 0.13,  -9999.,  0.12,  0.51,   0.62,  -9999.}	 // 5-10  
				     ,{0.800 ,0.800 ,0.800 ,0.600 ,0.600, -9999 ,0.600 ,0.790 ,0.840, -9999.} //10-15
				     ,{0.800 ,0.800 ,0.800 ,0.700 ,0.640, -9999 ,0.700 ,0.790 ,0.850, -9999.} //15-20
				     ,{0.800 ,0.800 ,0.820 ,0.720 ,0.650, -9999 ,0.780 ,0.790 ,0.850, -9999 } //20-30
				     ,{0.800 ,0.800 ,0.825 ,0.720 ,0.690, -9999 ,0.780 ,0.810 ,0.880, -9999 } //30-40
				     ,{0.800 ,0.800 ,0.825 ,0.730 ,0.690, -9999 ,0.790 ,0.810 ,0.880, -9999 } //40-50
				     ,{0.800 ,0.800 ,0.825 ,0.730 ,0.690 ,-9999. ,0.790 ,0.810 ,0.880 ,-9999.}// 50-60  
				     ,{0.800 ,0.800 ,0.825 ,0.730 ,0.690 ,-9999. ,0.790 ,0.810 ,0.880 ,-9999.}// 60-70
				     ,{0.800 ,0.800 ,0.825 ,0.730 ,0.690 ,-9999. ,0.790 ,0.810 ,0.880 ,-9999.}// 70-80
				     ,{0.800 ,0.800 ,0.825 ,0.730 ,0.690 ,-9999. ,0.790 ,0.810 ,0.880 ,-9999.}};// 80<  

  if(DEmaxs1 < cutDEmaxs1[eTBin][etaBin])
    return false;
    
  return  true;
}


//----------------------------------------------------------------------------------------
bool passDeltaEta_med(double deltaEta ){
  
  const double cutDeltaEta = 0.005;
  
  if(fabs(deltaEta) > cutDeltaEta)
    return false;
    
  return  true;
}

//----------------------------------------------------------------------------------------
bool passDeltaEta_loose(double deltaEta){
  
  const double cutDeltaEta = 0.015;

  if(fabs(deltaEta) > cutDeltaEta)
    return false;
    
  return  true;
}

//----------------------------------------------------------------------------------------
bool passNPix_med(int nPix, unsigned int etaBin){
  
  //New values for cut on nPixHits (when nblayer cut is dropped at high eta)
  //                          0.0   0.1    0.6    0.8   1.15   1.37   1.52   1.81    2.01   2.37   2.47
  const double cutNPix[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 2, 2};   
				    
  if(nPix < cutNPix[etaBin])
    return false;
    
  return  true;
}

//----------------------------------------------------------------------------------------
bool passNBlayer_med(int nBlayer, unsigned int etaBin){
  
  //New values for cut on nPixHits (when nblayer cut is dropped at high eta)
  //                          0.0   0.1    0.6    0.8   1.15   1.37   1.52   1.81    2.01   2.37   2.47
  const double cutNBlayer[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 0, 0};   
				    
  if(nBlayer < cutNBlayer[etaBin])
    return false;
    
  return  true;
}


//----------------------------------------------------------------------------------------
bool passTR_med(double TRratio, double eta, unsigned int nTRT){

  if(nTRT == 0)
    return true;

  double feta = fabs(eta);

  if(feta < 0.1){
    if(TRratio < 0.05)
      return false;

  }else if(feta < 0.625){
    if(TRratio < 0.05)
      return false;

  }else if(feta < 1.07){
    if(TRratio < 0.05)
      return false;

  }else if(feta < 1.304){
    if(TRratio < 0.06)
      return false;

  }else if(feta < 1.752){
    if(TRratio < 0.08)
      return false;

  }else if(feta < 2.0){
    if(TRratio < 0.08)
      return false;
  }

  return true;
}






