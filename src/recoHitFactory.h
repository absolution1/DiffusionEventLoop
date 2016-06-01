//STL
#include <iostream>
#include <vector>
#include <map>
//ROOT
#include "TTree.h"
//CUSTOM
#include "definitions.h"
#include "recoHit.h"

class RecoHitFactory{
  public:
    RecoHitFactory(TTree *tree);
    std::vector<RecoHit> GetRecoHitVector();

  private:
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
    Double_t fRecoHitWireCenterX[GlobalDefs::kNMaxRecoHits];
    Double_t fRecoHitWireCenterY[GlobalDefs::kNMaxRecoHits];
    Double_t fRecoHitWireCenterZ[GlobalDefs::kNMaxRecoHits];



};
