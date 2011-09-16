//RandomDataPeriod.h
//
//randomly provides a runnumber from the total dataset 
//based on the luminosity, to be used e.g. for trigger
//selection or detector defects modelling in MC.
//
//Usage:
//
//In header/constructor, do:
//#include "RandomDataPeriod.h"
//RandomDataPeriod mc_dataperiod;
//
//In event-loop, do:
//mc_dataperiod.SetSeed(EventNumber);
//int dataperiodformc = mc_dataperiod.GetDataPeriod();
//
//
//v00-00-00: initial version
//GRL used: data11_7TeV.periodAllYear_DetStatus-v13-pro08-02_WZjets_allchannels.xml 
//Lumi output: https://atlas-datasummary.cern.ch/lumicalc/results/35809b/result.html
//iLumiCalc.exe --lumitag=OflLumi-7TeV-001 --livetrigger=L1_EM14 --trigger=EF_mu18_MG --xml=/tmp/lumifiles/35809b/data11_7TeV.periodAllYear_DetStatus-v13-pro08-02_WZjets_allchannels.xml --plots
//
//v00-00-01: update data runs up to period F2
//GRL used: data11_7TeV.periodAllYear_DetStatus-v15-pro08-03_WZjets_allchannels.xml
//Lumi output: https://atlas-datasummary.cern.ch/lumicalc/results/d6d5bb/result.html
//iLumiCalc.exe --lumitag=OflLumi-7TeV-001 --livetrigger=L1_EM14 --trigger=EF_mu18_MG --xml=/tmp/lumifiles/d6d5bb/data11_7TeV.periodAllYear_DetStatus-v15-pro08-03_WZjets_allchannels.xml --plots
//
//v00-00-02: update data runs up to period G3
//GRL used: data11_7TeV.periodAllYear_DetStatus-v16-pro08-03_WZjets_allchannels.xml
//Lumi output: https://atlas-datasummary.cern.ch/lumicalc/results/4bad87/result.html
//iLumiCalc.exe --lumitag=OflLumi-7TeV-001 --livetrigger=L1_EM14 --trigger=EF_mu18_MG --xml=/tmp/lumifiles/4bad87/data11_7TeV.periodAllYear_DetStatus-v16-pro08-03_WZjets_allchannels.xml
//
//v00-00-03: still data runs up to period G3, but adjusting lumi for run 182886 (changed in DB after v00-00-02)
//GRL used: data11_7TeV.periodAllYear_DetStatus-v16-pro08-03_WZjets_allchannels.xml
//Lumi output: https://atlas-datasummary.cern.ch/lumicalc/results/b2a056/result.html
//iLumiCalc.exe --lumitag=OflLumi-7TeV-001 --livetrigger=L1_EM14 --trigger=EF_mu18_MG --xml=/tmp/lumifiles/b2a056/data11_7TeV.periodAllYear_DetStatus-v16-pro08-03_WZjets_allchannels.xml
//
//v00-00-04: update data runs up to period G5
//GRL used: data11_7TeV.periodAllYear_DetStatus-v17-pro08-03_WZjets_allchannels.xml
//Lumi output: https://atlas-datasummary.cern.ch/lumicalc/results/9407aa/result.html
//iLumiCalc.exe --lumitag=OflLumi-7TeV-001 --livetrigger=L1_EM14 --trigger=EF_mu18_MG --xml=/tmp/lumifiles/9407aa/data11_7TeV.periodAllYear_DetStatus-v17-pro08-03_WZjets_allchannels.xml --plots
//
//v00-00-05: Drop period B2 data; use D-G5 only
//GRL used: data11_7TeV.periodAllYear_DetStatus-v17-pro08-03_WZjets_allchannels_NOB2.xml
//Lumi output: https://atlas-datasummary.cern.ch/lumicalc/results/29ad56/result.html
//iLumiCalc.exe --lumitag=OflLumi-7TeV-001 --livetrigger=L1_EM14 --trigger=EF_mu18_MG --xml=/tmp/lumifiles/29ad56/data11_7TeV.periodAllYear_DetStatus-v17-pro08-03_WZjets_allchannels_NOB2.xml --plots
//
//v00-00-06: update data runs up to period H1
//GRL used: data11_7TeV.periodAllYear_DetStatus-v18-pro08-04_WZjets_allchannels_NOB2.xml
//Lumi output: https://atlas-datasummary.cern.ch/lumicalc/results/c56e2/result.html
//iLumiCalc.exe --lumitag=OflLumi-7TeV-001 --livetrigger=L1_EM14 --trigger=EF_mu18_MG --xml=/tmp/lumifiles/c56e2/data11_7TeV.periodAllYear_DetStatus-v18-pro08-04_WZjets_allchannels_NOB2.xml --plots
//
//v00-00-07: Adjust lumi values of runs from _previous_ iterations to current lumi DB output (v00-00-06)
//
//v00-00-08: update data runs up to period H4 (full EPS dataset!)
//GRL used: data11_7TeV.periodAllYear_DetStatus-v18-pro08-04_CoolRunQuery-00-03-98_WZjets_allchannels_NOB2.xml
//Lumi output: https://atlas-datasummary.cern.ch/lumicalc/results/4e48c1/result.html 
//iLumiCalc.exe --lumitag=OflLumi-7TeV-001 --livetrigger=L1_EM14 --trigger=EF_mu18_MG --xml=/tmp/lumifiles/4e48c1/data11_7TeV.periodAllYear_DetStatus-v18-pro08-04_CoolRunQuery-00-03-98_WZjets_allchannels_NOB2.xml --plots
//
//v00-00-09: data runs up to period H4 (full EPS dataset), using OflLumi-7TeV-002
//GRL used: data11_7TeV.periodAllYear_DetStatus-v18-pro08-04_CoolRunQuery-00-03-98_WZjets_allchannels_NOB2.xml
//Lumi output: https://atlas-datasummary.cern.ch/lumicalc/results/8ef9aa/result.html
//iLumiCalc.exe --lumitag=OflLumi-7TeV-002 --livetrigger=L1_EM14 --trigger=EF_mu18_MG --xml=/tmp/lumifiles/8ef9aa/data11_7TeV.periodAllYear_DetStatus-v18-pro08-04_CoolRunQuery-00-03-98_WZjets_allchannels_NOB2.xml --plots
//
//v00-00-10: data runs up to period H4 (full EPS dataset), using OflLumi-7TeV-002 AND new GRL based on pro08-05
//GRL used: data11_7TeV.periodAllYear_DetStatus-v18-pro08-05_CoolRunQuery-00-03-98_WZjets_allchannels_periodDtoH.xml
//Lumi output: https://atlas-datasummary.cern.ch/lumicalc/results/fb43ae/result.html
//iLumiCalc.exe --lumitag=OflLumi-7TeV-002 --livetrigger=L1_EM14 --trigger=EF_mu18_MG --xml=/tmp/lumifiles/fb43ae/data11_7TeV.periodAllYear_DetStatus-v18-pro08-05_CoolRunQuery-00-03-98_WZjets_allchannels_periodDtoH.xml --plots
//
//author: Marc-Andre Pleier (pleier@fnal.gov)


#include <TRandom3.h>
#include <map>

using namespace std;

class  RandomDataPeriod
{
 private:
  TRandom3 *random3;
  map<int,double> runvslumi;
  double totallumi;
 public:
  RandomDataPeriod()
    {
      random3 = new TRandom3(0);
      //initialize the run versus luminosity map...
      //Drop B2 data: v00-00-05
      //runvslumi[178044] = 4.74266092 	; 	
      //runvslumi[178047] = 0.0824528 	; 	
      //runvslumi[178109] = 6.56101119 	; 
      runvslumi[179710] = 4.3161489 	; 	
      runvslumi[179725] = 2.1890082 	; 	
      runvslumi[179739] = 2.9074613 	; 	
      runvslumi[179771] = 1.3043222 	; 	
      runvslumi[179804] = 7.4297323 	; 	
      runvslumi[179938] = 1.004276 	; 	
      runvslumi[179939] = 3.7024826 	; 	
      runvslumi[179940] = 0.122703 	; 	
      runvslumi[180122] = 5.65726244 	; 	
      runvslumi[180124] = 7.6549647 	; 	
      runvslumi[180139] = 7.7714978 	; 	
      runvslumi[180144] = 3.8258826 	; 	
      runvslumi[180149] = 3.5597485 	; 	
      runvslumi[180153] = 8.900373 	; 	
      runvslumi[180164] = 19.3460478 	; 	
      runvslumi[180212] = 0.125478 	; 	
      runvslumi[180225] = 17.2809273 	; 	
      runvslumi[180241] = 4.8035822 	; 	
      runvslumi[180242] = 5.3288709 	; 	
      runvslumi[180309] = 9.6575144 	; 	
      runvslumi[180400] = 14.6875097 	; 	
      runvslumi[180448] = 1.1658153 	; 	
      runvslumi[180481] = 21.3402185 	; 	
      runvslumi[180614] = 2.8782582 	; 	
      runvslumi[180636] = 24.3764427 	; 	
      runvslumi[180664] = 2.7022412 	; 	
      runvslumi[180710] = 12.1708124 	; 	
      runvslumi[180776] = 0.3045317 	; 	
      runvslumi[182013] = 0.02569579 	; 	
      runvslumi[182161] = 2.93351621 	; 	
      runvslumi[182284] = 13.9691241 	; 	
      runvslumi[182346] = 1.3988048 	; 	
      runvslumi[182372] = 12.9039944 	; 	
      runvslumi[182424] = 20.9536595 	; 	
      runvslumi[182449] = 3.3513165 	; 	
      runvslumi[182450] = 1.5062815 	; 	
      runvslumi[182454] = 7.712866 	; 	
      runvslumi[182455] = 0.495602 	; 	
      runvslumi[182456] = 19.5658658 	; 	
      runvslumi[182486] = 25.2613923 	; 	
      runvslumi[182516] = 9.1515254 	; 	
      runvslumi[182518] = 1.317099 	; 	
      runvslumi[182519] = 2.126597 	; 	
      runvslumi[182726] = 4.3504048 	; 	
      runvslumi[182747] = 26.37567022 	; 	
      runvslumi[182766] = 4.1220245 	; 	
      runvslumi[182787] = 31.1026089 	; 	
      runvslumi[182796] = 27.8164716 	; 	
      runvslumi[182879] = 4.891075 	; 	
      runvslumi[182886] = 3.985365 	; 	
      runvslumi[182997] = 3.409155 	; 	
      runvslumi[183003] = 39.45135334 	; 	
      runvslumi[183021] = 21.0495704 	; 	
      runvslumi[183038] = 1.1635 	; 	
      runvslumi[183045] = 16.0090433 	; 	
      runvslumi[183054] = 8.1191694 	; 	
      runvslumi[183078] = 1.7590964 	; 	
      runvslumi[183079] = 0.9066888 	; 	
      runvslumi[183081] = 40.7795288 	; 	
      runvslumi[183127] = 11.716888 	; 	
      runvslumi[183129] = 6.3983942 	; 	
      runvslumi[183130] = 18.3523151 	; 	
      runvslumi[183216] = 27.9919599 	; 	
      runvslumi[183272] = 12.3804543 	; 	
      runvslumi[183286] = 24.2227424 	; 	
      runvslumi[183347] = 27.6754298 	; 	
      runvslumi[183391] = 20.4267367 	; 	
      runvslumi[183407] = 10.4615599 	; 	
      runvslumi[183412] = 0.876727 	; 	
      runvslumi[183426] = 25.9066596 	; 	
      runvslumi[183462] = 42.5104686 	; 	
      runvslumi[183544] = 22.0175326 	; 	
      runvslumi[183580] = 2.879942 	; 	
      runvslumi[183581] = 22.7797949 	; 	
      runvslumi[183602] = 0.790836 	; 	
      runvslumi[183780] = 43.2627417 	;
      runvslumi[183963] = 8.7497454 	; 
      runvslumi[184022] = 38.3158984 	;
      runvslumi[184066] = 1.9327 	;  
      runvslumi[184072] = 4.429904 	;  
      runvslumi[184074] = 0.790583 	;  
      runvslumi[184088] = 6.2392247 	; 
      runvslumi[184130] = 47.2983884 	;
      runvslumi[184169] = 40.7695573 	;
      //calculate total lumi
      totallumi = 0.;
      const map< int, double >::const_iterator itend = runvslumi.end();
      for(map< int, double >::iterator it = runvslumi.begin(); it != itend; ++it)
        {
	  totallumi += it->second;
	}
      cout << "RandomDataPeriod has been initialised with a total lumi of "<< totallumi << "." << endl;
    }
  inline void SetSeed(int seed) {random3->SetSeed(seed);}
  inline int  GetSeed() {return random3->GetSeed();}
  inline double  GetTotLumi() {return totallumi;}
  int GetDataPeriod()
  {
    double lumi = totallumi * random3->Rndm();
    double lumisum = 0.;
    const map< int, double >::const_iterator itend = runvslumi.end();
    for(map< int, double >::iterator it = runvslumi.begin(); it != itend; ++it)
      {
	lumisum += it->second;
	if (lumisum >= lumi)
	  return it->first;
      }
    return 0;
  }
};
