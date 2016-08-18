//STL
#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
//ROOT
#include "TH2F.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TString.h"
#include "TMatrixD.h"
#include "TF1.h"
#include "TFile.h"
#include "TTree.h"
//CUSTOM
#include "recoHit.h"
#include "auxDet.h"
#include "definitions.h"

static const int NCuts = 4;

class ReconstructCounterTracks{
  public:
    ReconstructCounterTracks();
    ~ReconstructCounterTracks();


    void AccumulateStats(const std::vector<RecoHit> &hits, const std::vector<AuxDet> &aux_dets);

  private:

    std::vector<AuxDet> ReconstructEWTrigger(const std::vector<AuxDet> &aux_dets);
    Double_t GetT0FromCounters(const std::vector<AuxDet> &aux_dets);

    UInt_t NHitsOnWire(UInt_t wire_id, const std::vector<RecoHit> &reco_hits);

    Bool_t HitWithinCounterShadow(const RecoHit &hit, const std::vector<AuxDet> &aux_dets);

    Bool_t PointInPolygon(TVector2 point, const std::vector<TVector2> &polygon_points);

    Int_t ConvertXToTicks(Double_t x);
    Double_t ConvertTicksToX(Int_t t, Bool_t is_short_vol = 0);

    Bool_t IsInShortDrift(const RecoHit &hit);

    Double_t Fit2DLine(const std::vector<TVector2> &points, Double_t &m, Double_t &c);

    void Reset();

    TApplication *fApp;

    std::map<Int_t,std::pair<TVector3,std::pair<double,double> > > fCounterPositionsAndDimensions;
    std::map<int,double> fEWCounterPosCorrection;

    std::map<Int_t,std::vector<std::pair<Double_t,Double_t> > > fCounterToLineMap;

    TFile *fFile;
    TTree *fTree;
    Int_t fNCuts;
    Int_t fNHits[NCuts];
    Double_t fResiduals[NCuts];
};

