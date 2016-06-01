#ifndef RECOHIT_H_SEEN
#define RECOHIT_H_SEEN
//STL
//ROOT
#include "TVector3.h"
//CUSTOM

class RecoHit{
  public:
    RecoHit(Int_t RecoHitStartTick,
        Int_t RecoHitEndTick,
        Double_t RecoHitPeakTime,
        Double_t RecoHitSigmaPeakTime,
        Double_t RecoHitRMS,
        Double_t RecoHitPeakAmplitude,
        Double_t RecoHitSigmaPeakAmplitude,
        Double_t RecoHitSummedADC,
        Double_t RecoHitIntegral,
        Double_t RecoHitSigmaIntegral,
        Int_t RecoHitMultiplicity,
        Int_t RecoHitLocalIndex,
        Double_t RecoHitGoodnessOfFit,
        Int_t RecoHitDegreesOfFreedom,
        UInt_t RecoHitChannel,
        Int_t RecoHitView,
        UInt_t RecoHitWireID,
        UInt_t RecoHitPlaneID,
        UInt_t RecoHitTPCID,
        Bool_t RecoHitIsValid,
        UInt_t RecoHitCryostatID,
        Double_t RecoHitWireCenterX,
        Double_t RecoHitWireCenterY,
        Double_t RecoHitWireCenterZ) 
          :
            StartTick(RecoHitStartTick),
            EndTick(RecoHitEndTick),
            PeakTime(RecoHitPeakTime),
            SigmaPeakTime(RecoHitSigmaPeakTime),
            RMS(RecoHitRMS),
            PeakAmplitude(RecoHitPeakAmplitude),
            SigmaPeakAmplitude(RecoHitSigmaPeakAmplitude),
            SummedADC(RecoHitSummedADC),
            Integral(RecoHitIntegral),
            SigmaIntegral(RecoHitSigmaIntegral),
            Multiplicity(RecoHitMultiplicity),
            LocalIndex(RecoHitLocalIndex),
            GoodnessOfFit(RecoHitGoodnessOfFit),
            DegreesOfFreedom(RecoHitDegreesOfFreedom),
            Channel(RecoHitChannel),
            View(RecoHitView),
            WireID(RecoHitWireID),
            PlaneID(RecoHitPlaneID),
            TPCID(RecoHitTPCID),
            IsValid(RecoHitIsValid),
            CryostatID(RecoHitCryostatID),
            WireCenter(RecoHitWireCenterX,RecoHitWireCenterY,RecoHitWireCenterZ){};

    Int_t StartTick;
    Int_t EndTick;
    Double_t PeakTime;
    Double_t SigmaPeakTime;
    Double_t RMS;
    Double_t PeakAmplitude;
    Double_t SigmaPeakAmplitude;
    Double_t SummedADC;
    Double_t Integral;
    Double_t SigmaIntegral;
    Int_t Multiplicity;
    Int_t LocalIndex;
    Double_t GoodnessOfFit;
    Int_t DegreesOfFreedom;
    UInt_t Channel;
    Int_t View;
    UInt_t WireID;
    UInt_t PlaneID;
    UInt_t TPCID;
    Bool_t IsValid;
    UInt_t CryostatID;
    TVector3 WireCenter;

  private:

};
#endif
