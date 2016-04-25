#ifndef RECOTRACK_H_SEEN
#define RECOTRACK_H_SEEN
//STL
//ROOT
#include "TVector3.h"
//CUSTOM
#include "recoHit.h"

class RecoTrack{
  public:
    RecoTrack(
        Int_t RecoTrackID,
        Int_t RecoTrackG4ID,
        UInt_t RecoTrackNumberTrajectoryPoints,
        Double_t *RecoTrackFrontPosition,
        Double_t *RecoTrackFrontDirection,
        Double_t *RecoTrackBackPosition,
        Double_t *RecoTrackBackDirection,
        Double_t RecoTrackLength,
        Bool_t RecoTrackValidT0,
        Double_t RecoTrackT0,
        UInt_t *RecoTrackT0CounterIDs,
        Double_t *RecoTrackFittedPosition,
        Double_t *RecoTrackFittedDirection,
        Double_t RecoTrackFittedMetric,
        Bool_t RecoTrackFittedValidT0,
        Double_t RecoTrackFittedT0,
        UInt_t *RecoTrackFittedT0CounterIDs,
        std::vector<RecoHit> &RecoHits)
      :
        ID(RecoTrackID),
        G4ID(RecoTrackG4ID),
        NumberTrajectoryPoints(RecoTrackNumberTrajectoryPoints),
        FrontPosition(RecoTrackFrontPosition[0], RecoTrackFrontPosition[1], RecoTrackFrontPosition[2]),
        FrontDirection(RecoTrackFrontDirection[0], RecoTrackFrontDirection[1], RecoTrackFrontDirection[2]),
        BackPosition(RecoTrackBackPosition[0], RecoTrackBackPosition[1], RecoTrackBackPosition[2]),
        BackDirection(RecoTrackBackDirection[0], RecoTrackBackDirection[1], RecoTrackBackDirection[2]),
        Length(RecoTrackLength),
        ValidT0(RecoTrackValidT0),
        T0(RecoTrackT0),
        FittedPosition(RecoTrackFittedPosition[0], RecoTrackFittedPosition[1], RecoTrackFittedPosition[2]),
        FittedDirection(RecoTrackFittedDirection[0], RecoTrackFittedDirection[1], RecoTrackFittedDirection[2]),
        FittedMetric(RecoTrackFittedMetric),
        FittedValidT0(RecoTrackFittedValidT0),
        FittedT0(RecoTrackFittedT0),
        Hits(RecoHits)
    {
      T0CounterIDs[0] = RecoTrackT0CounterIDs[0];
      T0CounterIDs[1] = RecoTrackT0CounterIDs[1];
      FittedT0CounterIDs[0] = RecoTrackFittedT0CounterIDs[0];
      FittedT0CounterIDs[1] = RecoTrackFittedT0CounterIDs[1];

    };

    Int_t ID;
    Int_t G4ID;
    UInt_t NumberTrajectoryPoints;
    TVector3 FrontPosition;
    TVector3 FrontDirection;
    TVector3 BackPosition;
    TVector3 BackDirection;
    Double_t Length;
    Bool_t ValidT0;
    Double_t T0;
    UInt_t T0CounterIDs[2];
    TVector3 FittedPosition;
    TVector3 FittedDirection;
    Double_t FittedMetric;
    Bool_t FittedValidT0;
    Double_t FittedT0;
    UInt_t FittedT0CounterIDs[2];

    std::vector<RecoHit> Hits;

  private:

};
#endif
