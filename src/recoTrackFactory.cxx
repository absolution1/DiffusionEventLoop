#include "recoTrackFactory.h"

RecoTrackFactory::RecoTrackFactory::RecoTrackFactory(TTree *tree){
  tree->SetBranchAddress("NRecoTracks",&fNRecoTracks);
  tree->SetBranchAddress("RecoTrackID",&fRecoTrackID);
  tree->SetBranchAddress("RecoTrackG4ID",&fRecoTrackG4ID);
  tree->SetBranchAddress("RecoTrackNumberTrajectoryPoints",&fRecoTrackNumberTrajectoryPoints);
  tree->SetBranchAddress("RecoTrackFrontPosition",&fRecoTrackFrontPosition);
  tree->SetBranchAddress("RecoTrackFrontDirection",&fRecoTrackFrontDirection);
  tree->SetBranchAddress("RecoTrackBackPosition",&fRecoTrackBackPosition);
  tree->SetBranchAddress("RecoTrackBackDirection",&fRecoTrackBackDirection);
  tree->SetBranchAddress("RecoTrackLength",&fRecoTrackLength);
  tree->SetBranchAddress("RecoTrackValidT0",&fRecoTrackValidT0);
  tree->SetBranchAddress("RecoTrackT0",&fRecoTrackT0);
  tree->SetBranchAddress("RecoTrackT0CounterIDs",&fRecoTrackT0CounterIDs);
  tree->SetBranchAddress("RecoTrackFittedPosition",&fRecoTrackFittedPosition);
  tree->SetBranchAddress("RecoTrackFittedDirection",&fRecoTrackFittedDirection);
  tree->SetBranchAddress("RecoTrackFittedMetric",&fRecoTrackFittedMetric);
  tree->SetBranchAddress("RecoTrackFittedValidT0",&fRecoTrackFittedValidT0);
  tree->SetBranchAddress("RecoTrackFittedT0",&fRecoTrackFittedT0);
  tree->SetBranchAddress("RecoTrackFittedT0CounterIDs",&fRecoTrackFittedT0CounterIDs);

  tree->SetBranchAddress("NRecoHits",&fNRecoHits);
  tree->SetBranchAddress("RecoHitTrackID",&fRecoHitTrackID);
  tree->SetBranchAddress("RecoHitStartTick",&fRecoHitStartTick);
  tree->SetBranchAddress("RecoHitEndTick",&fRecoHitEndTick);
  tree->SetBranchAddress("RecoHitPeakTime",&fRecoHitPeakTime);
  tree->SetBranchAddress("RecoHitSigmaPeakTime",&fRecoHitSigmaPeakTime);
  tree->SetBranchAddress("RecoHitRMS",&fRecoHitRMS);
  tree->SetBranchAddress("RecoHitPeakAmplitude",&fRecoHitPeakAmplitude);
  tree->SetBranchAddress("RecoHitSigmaPeakAmplitude",&fRecoHitSigmaPeakAmplitude);
  tree->SetBranchAddress("RecoHitSummedADC",&fRecoHitSummedADC);
  tree->SetBranchAddress("RecoHitIntegral",&fRecoHitIntegral);
  tree->SetBranchAddress("RecoHitSigmaIntegral",&fRecoHitSigmaIntegral);
  tree->SetBranchAddress("RecoHitMultiplicity",&fRecoHitMultiplicity);
  tree->SetBranchAddress("RecoHitLocalIndex",&fRecoHitLocalIndex);
  tree->SetBranchAddress("RecoHitGoodnessOfFit",&fRecoHitGoodnessOfFit);
  tree->SetBranchAddress("RecoHitDegreesOfFreedom",&fRecoHitDegreesOfFreedom);
  tree->SetBranchAddress("RecoHitChannel",&fRecoHitChannel);
  tree->SetBranchAddress("RecoHitView",&fRecoHitView);
  tree->SetBranchAddress("RecoHitWireID",&fRecoHitWireID);
  tree->SetBranchAddress("RecoHitPlaneID",&fRecoHitPlaneID);
  tree->SetBranchAddress("RecoHitTPCID",&fRecoHitTPCID);
  tree->SetBranchAddress("RecoHitIsValid",&fRecoHitIsValid);
  tree->SetBranchAddress("RecoHitCryostatID",&fRecoHitCryostatID);
}

std::vector<RecoTrack> RecoTrackFactory::GetRecoTrackVector(){
  std::vector<RecoTrack> reco_tracks;

  std::map<Int_t, std::vector<RecoHit> > reco_hit_map = ConstructHitMap();

  for (UInt_t i = 0; i < fNRecoTracks; i++){
    RecoTrack reco_track(
      fRecoTrackID[i],
      fRecoTrackG4ID[i],
      fRecoTrackNumberTrajectoryPoints[i],
      fRecoTrackFrontPosition[i],
      fRecoTrackFrontDirection[i],
      fRecoTrackBackPosition[i],
      fRecoTrackBackDirection[i],
      fRecoTrackLength[i],
      fRecoTrackValidT0[i],
      fRecoTrackT0[i],
      fRecoTrackT0CounterIDs[i],
      fRecoTrackFittedPosition[i],
      fRecoTrackFittedDirection[i],
      fRecoTrackFittedMetric[i],
      fRecoTrackFittedValidT0[i],
      fRecoTrackFittedT0[i],
      fRecoTrackFittedT0CounterIDs[i],
      reco_hit_map[fRecoTrackID[i]]);

    reco_tracks.push_back(reco_track);
  }

  return reco_tracks;
}

void RecoTrackFactory::Print(){
  std::cout<<"NTracks: " << fNRecoTracks << std::endl;
  for (UInt_t i = 0; i < fNRecoTracks; i++){
    std::cout<<"--track " << i << "  ID: " << fRecoTrackID[i] << std::endl;
  }
  return;
}

std::map<Int_t, std::vector<RecoHit> >& RecoTrackFactory::ConstructHitMap(){
  static std::map<Int_t, std::vector<RecoHit> > hit_map;
  hit_map.clear();
  for (UInt_t i = 0; i < fNRecoHits; i++){

    RecoHit reco_hit(fRecoHitStartTick[i],
        fRecoHitEndTick[i],
        fRecoHitPeakTime[i],
        fRecoHitSigmaPeakTime[i],
        fRecoHitRMS[i],
        fRecoHitPeakAmplitude[i],
        fRecoHitSigmaPeakAmplitude[i],
        fRecoHitSummedADC[i],
        fRecoHitIntegral[i],
        fRecoHitSigmaIntegral[i],
        fRecoHitMultiplicity[i],
        fRecoHitLocalIndex[i],
        fRecoHitGoodnessOfFit[i],
        fRecoHitDegreesOfFreedom[i],
        fRecoHitChannel[i],
        fRecoHitView[i],
        fRecoHitWireID[i],
        fRecoHitPlaneID[i],
        fRecoHitTPCID[i],
        fRecoHitIsValid[i],
        fRecoHitCryostatID[i]);

    hit_map[fRecoHitTrackID[i]].push_back(reco_hit);
  }

  return hit_map;
}
