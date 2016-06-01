#include "recoHitFactory.h"

RecoHitFactory::RecoHitFactory::RecoHitFactory(TTree *tree){
  tree->SetBranchAddress("NAllRecoHits",&fNRecoHits);
  tree->SetBranchAddress("AllRecoHitTrackID",&fRecoHitTrackID);
  tree->SetBranchAddress("AllRecoHitStartTick",&fRecoHitStartTick);
  tree->SetBranchAddress("AllRecoHitEndTick",&fRecoHitEndTick);
  tree->SetBranchAddress("AllRecoHitPeakTime",&fRecoHitPeakTime);
  tree->SetBranchAddress("AllRecoHitSigmaPeakTime",&fRecoHitSigmaPeakTime);
  tree->SetBranchAddress("AllRecoHitRMS",&fRecoHitRMS);
  tree->SetBranchAddress("AllRecoHitPeakAmplitude",&fRecoHitPeakAmplitude);
  tree->SetBranchAddress("AllRecoHitSigmaPeakAmplitude",&fRecoHitSigmaPeakAmplitude);
  tree->SetBranchAddress("AllRecoHitSummedADC",&fRecoHitSummedADC);
  tree->SetBranchAddress("AllRecoHitIntegral",&fRecoHitIntegral);
  tree->SetBranchAddress("AllRecoHitSigmaIntegral",&fRecoHitSigmaIntegral);
  tree->SetBranchAddress("AllRecoHitMultiplicity",&fRecoHitMultiplicity);
  tree->SetBranchAddress("AllRecoHitLocalIndex",&fRecoHitLocalIndex);
  tree->SetBranchAddress("AllRecoHitGoodnessOfFit",&fRecoHitGoodnessOfFit);
  tree->SetBranchAddress("AllRecoHitDegreesOfFreedom",&fRecoHitDegreesOfFreedom);
  tree->SetBranchAddress("AllRecoHitChannel",&fRecoHitChannel);
  tree->SetBranchAddress("AllRecoHitView",&fRecoHitView);
  tree->SetBranchAddress("AllRecoHitWireID",&fRecoHitWireID);
  tree->SetBranchAddress("AllRecoHitPlaneID",&fRecoHitPlaneID);
  tree->SetBranchAddress("AllRecoHitTPCID",&fRecoHitTPCID);
  tree->SetBranchAddress("AllRecoHitIsValid",&fRecoHitIsValid);
  tree->SetBranchAddress("AllRecoHitCryostatID",&fRecoHitCryostatID);
  tree->SetBranchAddress("AllRecoHitWireCenterX",&fRecoHitWireCenterX);
  tree->SetBranchAddress("AllRecoHitWireCenterY",&fRecoHitWireCenterY);
  tree->SetBranchAddress("AllRecoHitWireCenterZ",&fRecoHitWireCenterZ);



}

std::vector<RecoHit> RecoHitFactory::GetRecoHitVector(){

  std::vector<RecoHit> reco_hits;
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
        fRecoHitCryostatID[i],
        fRecoHitWireCenterX[i],
        fRecoHitWireCenterY[i],
        fRecoHitWireCenterZ[i]);

    reco_hits.push_back(reco_hit);
  }

  return reco_hits;
}
