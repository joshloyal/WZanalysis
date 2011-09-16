#ifndef __JETID__
#define __JETID__

namespace JetID
{
  typedef enum  { LooseBad, MediumBad, TightBad  } BadJetCategory;
bool isBadJet(BadJetCategory criteria,
	      double emf,
	      double hecf,
	      double larq,
	      double hecq,
	      double time,
	      double sumpttrk,
	      double eta,
	      double pt,
	      double fmax,
	      double negE
	      )  ;
}

#endif
