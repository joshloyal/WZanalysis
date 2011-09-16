#ifndef ISEMPLUSPLUSDEFS_H
#define ISEMPLUSPLUSDEFS_H

//----------------------------------------------------------------------------------------

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

//-------------------------------------------------------------------------------------------------------
bool isLoosePlusPlus(double eta, double eT,
		     double rHad, double rHad1, double Reta, double w2,
		     double f1, double wstot, double DEmaxs1, double deltaEta, int nSi, 
		     bool debug = false,bool isTrigger = false );
  
//-------------------------------------------------------------------------------------------------------
bool isMediumPlusPlus(double eta, double eT,
		      double rHad, double rHad1, double Reta, double w2, 
		      double f1, double wstot, double DEmaxs1, double deltaEta, double d0,
		      double TRratio, int nTRT, int nTRTOutliers,
		      int nSi, int nPix, int nPixOutliers, 
		      int nBlayer, int nBlayerOutliers, bool expectBlayer, 
		      bool debug = false, bool isTrigger = false );

// Loose++ Helper Functions 
bool passRHad_loose(double rHad, double rHad1, unsigned int eTBin, unsigned int etaBin);
bool passReta_loose(double rEta, unsigned int eTBin, unsigned int etaBin);
bool passW2_loose(double w2, unsigned int eTBin, unsigned int etaBin);
bool passWstot_loose(double wstot, unsigned int eTBin, unsigned int etaBin);
bool passEratio_loose(double DEmaxs1, unsigned int eTBin, unsigned int etaBin);
bool passDeltaEta_loose(double deltaEta);

// Medium++ Helper Functions 
bool passRHad_med(double rHad, double rHad1, unsigned int eTBin, unsigned int etaBin);
bool passReta_med(double rEta, unsigned int eTBin, unsigned int etaBin);
bool passW2_med(double w2, unsigned int eTBin, unsigned int etaBin);
bool passWstot_med(double wstot, unsigned int eTBin, unsigned int etaBin);
bool passEratio_med(double DEmaxs1, unsigned int eTBin, unsigned int etaBin);
bool passDeltaEta_med(double deltaEta);
bool passTR_med(double TRratio, double eta, unsigned int nTRT);
bool passNPix_med(int nPix, unsigned int etaBin);
bool passNBlayer_med(int nBlayer, unsigned int etaBin); 

// Helper Fuctions
unsigned int getEtaBin(double eta);
unsigned int getEtBin(double eT);

//----------------------------------------------------------------------------------------
#endif
