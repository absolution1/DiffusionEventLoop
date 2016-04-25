//STL
#include <iostream>
#include <vector>
#include <map>
//ROOT
#include "TTree.h"
//CUSTOM
#include "definitions.h"
#include "recoTrack.h"
#include "recoHit.h"

class RecoTrackFactory{
  public:
    RecoTrackFactory(TTree *tree);
    std::vector<RecoTrack> GetRecoTrackVector();
    void Print();
  private:
    std::map<Int_t, std::vector<RecoHit> >& ConstructHitMap();

  //RecoInfo
  UInt_t fNRecoTracks;
  Int_t fRecoTrackID[GlobalDefs::kNMaxRecoTracks];
  Int_t fRecoTrackG4ID[GlobalDefs::kNMaxRecoTracks];
  UInt_t fRecoTrackNumberTrajectoryPoints[GlobalDefs::kNMaxRecoTracks];
  Double_t fRecoTrackFrontPosition[GlobalDefs::kNMaxRecoTracks][3];
  Double_t fRecoTrackFrontDirection[GlobalDefs::kNMaxRecoTracks][3];
  Double_t fRecoTrackBackPosition[GlobalDefs::kNMaxRecoTracks][3];
  Double_t fRecoTrackBackDirection[GlobalDefs::kNMaxRecoTracks][3];
  Double_t fRecoTrackLength[GlobalDefs::kNMaxRecoTracks];
  Bool_t fRecoTrackValidT0[GlobalDefs::kNMaxRecoTracks];
  Double_t fRecoTrackT0[GlobalDefs::kNMaxRecoTracks];
  UInt_t fRecoTrackT0CounterIDs[GlobalDefs::kNMaxRecoTracks][2];
  Double_t fRecoTrackFittedPosition[GlobalDefs::kNMaxRecoTracks][3];
  Double_t fRecoTrackFittedDirection[GlobalDefs::kNMaxRecoTracks][3];
  Double_t  fRecoTrackFittedMetric[GlobalDefs::kNMaxRecoTracks];
  Bool_t fRecoTrackFittedValidT0[GlobalDefs::kNMaxRecoTracks];
  Double_t fRecoTrackFittedT0[GlobalDefs::kNMaxRecoTracks];
  UInt_t fRecoTrackFittedT0CounterIDs[GlobalDefs::kNMaxRecoTracks][2];

  //Hit stuff
  UInt_t fNRecoHits;
  Int_t fRecoHitTrackID[GlobalDefs::kNMaxRecoHits];
  Int_t fRecoHitStartTick[GlobalDefs::kNMaxRecoHits];
  Int_t fRecoHitEndTick[GlobalDefs::kNMaxRecoHits];
  Double_t fRecoHitPeakTime[GlobalDefs::kNMaxRecoHits];
  Double_t fRecoHitSigmaPeakTime[GlobalDefs::kNMaxRecoHits];
  Double_t fRecoHitRMS[GlobalDefs::kNMaxRecoHits];
  Double_t fRecoHitPeakAmplitude[GlobalDefs::kNMaxRecoHits];
  Double_t fRecoHitSigmaPeakAmplitude[GlobalDefs::kNMaxRecoHits];
  Double_t fRecoHitSummedADC[GlobalDefs::kNMaxRecoHits];
  Double_t fRecoHitIntegral[GlobalDefs::kNMaxRecoHits];
  Double_t fRecoHitSigmaIntegral[GlobalDefs::kNMaxRecoHits];
  Int_t fRecoHitMultiplicity[GlobalDefs::kNMaxRecoHits];
  Int_t fRecoHitLocalIndex[GlobalDefs::kNMaxRecoHits];
  Double_t fRecoHitGoodnessOfFit[GlobalDefs::kNMaxRecoHits];
  Int_t fRecoHitDegreesOfFreedom[GlobalDefs::kNMaxRecoHits];
  UInt_t fRecoHitChannel[GlobalDefs::kNMaxRecoHits];
  Int_t fRecoHitView[GlobalDefs::kNMaxRecoHits];
  UInt_t fRecoHitWireID[GlobalDefs::kNMaxRecoHits];
  UInt_t fRecoHitPlaneID[GlobalDefs::kNMaxRecoHits];
  UInt_t fRecoHitTPCID[GlobalDefs::kNMaxRecoHits];
  Bool_t fRecoHitIsValid[GlobalDefs::kNMaxRecoHits];
  UInt_t fRecoHitCryostatID[GlobalDefs::kNMaxRecoHits];

};
