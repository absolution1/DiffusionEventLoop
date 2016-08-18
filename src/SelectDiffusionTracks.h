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
static const int kNMaxCounters = 20;
static const int kNMaxSelRecoHits = 1000;

class SelectDiffusionTracks{
  public:
    SelectDiffusionTracks();
    ~SelectDiffusionTracks();


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
    //Output as a function of the cuts
    Int_t fNHits[NCuts];
    Double_t fResiduals[NCuts];
    //output after all cuts applied
    Int_t fNCounters;
    Int_t fCounterID[kNMaxCounters];
    Double_t fT0;
    Int_t fNSelRecoHits;
    Int_t fSelRecoHitTrackID[kNMaxSelRecoHits];
    Int_t fSelRecoHitStartTick[kNMaxSelRecoHits];
    Int_t fSelRecoHitEndTick[kNMaxSelRecoHits];
    Double_t fSelRecoHitPeakTime[kNMaxSelRecoHits];
    Double_t fSelRecoHitSigmaPeakTime[kNMaxSelRecoHits];
    Double_t fSelRecoHitRMS[kNMaxSelRecoHits];
    Double_t fSelRecoHitPeakAmplitude[kNMaxSelRecoHits];
    Double_t fSelRecoHitSigmaPeakAmplitude[kNMaxSelRecoHits];
    Double_t fSelRecoHitSummedADC[kNMaxSelRecoHits];
    Double_t fSelRecoHitIntegral[kNMaxSelRecoHits];
    Double_t fSelRecoHitSigmaIntegral[kNMaxSelRecoHits];
    Int_t fSelRecoHitMultiplicity[kNMaxSelRecoHits];
    Int_t fSelRecoHitLocalIndex[kNMaxSelRecoHits];
    Double_t fSelRecoHitGoodnessOfFit[kNMaxSelRecoHits];
    Int_t fSelRecoHitDegreesOfFreedom[kNMaxSelRecoHits];
    Int_t fSelRecoHitChannel[kNMaxSelRecoHits];
    Int_t fSelRecoHitView[kNMaxSelRecoHits];
    Int_t fSelRecoHitWireID[kNMaxSelRecoHits];
    Int_t fSelRecoHitPlaneID[kNMaxSelRecoHits];
    Int_t fSelRecoHitTPCID[kNMaxSelRecoHits];
    Bool_t fSelRecoHitIsValid[kNMaxSelRecoHits];
    Int_t fSelRecoHitCryostatID[kNMaxSelRecoHits];
    Double_t fSelRecoHitWireCenterX[kNMaxSelRecoHits];
    Double_t fSelRecoHitWireCenterY[kNMaxSelRecoHits];
    Double_t fSelRecoHitWireCenterZ[kNMaxSelRecoHits];
    Double_t fSelRecoHitX[kNMaxSelRecoHits];


};

