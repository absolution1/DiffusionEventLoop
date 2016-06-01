//STL
#include <iostream>
#include <map>
#include <algorithm>
//ROOT
#include "TH2F.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TString.h"
//CUSTOM
#include "recoHit.h"
#include "auxDet.h"
#include "definitions.h"

static const int NCuts = 2;

class FitCounterPositions{
  public:
    FitCounterPositions();

    void AccumulateStats(const std::vector<RecoHit> &hits, const std::vector<AuxDet> &aux_dets);

  private:

    std::map<Int_t, std::pair<TVector3,TVector3> > fCountersToLines;
    std::vector<AuxDet> ReconstructEWTrigger(const std::vector<AuxDet> &aux_dets);
    Double_t GetT0FromCounters(const std::vector<AuxDet> &aux_dets);

    UInt_t NHitsOnWire(UInt_t wire_id, const std::vector<RecoHit> &reco_hits);

    Bool_t HitWithinCounterShadow(const RecoHit &hit, const std::vector<AuxDet> &aux_dets);

    TApplication *fApp;

    std::map<Int_t,std::pair<TVector3,double> > fCounterPositionsAndDimensions;
};

