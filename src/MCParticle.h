#ifndef MCPARTICLE_H_SEEN
#define MCPARTICLE_H_SEEN
//STL
//ROOT
#include "TLorentzVector.h"
//CUSTOM
#include "definitions.h"

class MCParticle{
  public:
    MCParticle(
          Int_t ParticleTrackID,
          Int_t ParticlePDG,
          UInt_t ParticleNumberDaughters,
          Int_t *ParticleDaughterIDs,
          Double_t ParticleStartPositionT,
          Double_t ParticleStartPositionX,
          Double_t ParticleStartPositionY,
          Double_t ParticleStartPositionZ,
          Double_t ParticleEndPositionT,
          Double_t ParticleEndPositionX,
          Double_t ParticleEndPositionY,
          Double_t ParticleEndPositionZ,
          Double_t ParticleStartMomentumT,
          Double_t ParticleStartMomentumX,
          Double_t ParticleStartMomentumY,
          Double_t ParticleStartMomentumZ,
          Double_t ParticleEndMomentumT,
          Double_t ParticleEndMomentumX,
          Double_t ParticleEndMomentumY,
          Double_t ParticleEndMomentumZ,
          Bool_t ParticleStopsInTPC,
          UInt_t ParticleNTPCs,
          Int_t *ParticleTPCIDs,
          UInt_t ParticleNCounters,
          Int_t *ParticleCounterIDs,
          Bool_t ParticleUsesEastCounter,
          Bool_t ParticleUsesWestCounter) :

            TrackID        (ParticleTrackID),
            PDG            (ParticlePDG),
            NumberDaughters(ParticleNumberDaughters),
            //DaughterIDs    (ParticleDaughterIDs),
            StartPosition (ParticleStartPositionX, ParticleStartPositionY, ParticleStartPositionZ,ParticleStartPositionT),
            EndPosition (ParticleEndPositionX, ParticleEndPositionY, ParticleEndPositionZ,ParticleEndPositionT),
            StartMomentum (ParticleStartMomentumX, ParticleStartMomentumY, ParticleStartMomentumZ,ParticleStartMomentumT),
            EndMomentum (ParticleEndMomentumX, ParticleEndMomentumY, ParticleEndMomentumZ,ParticleEndMomentumT),
            StopsInTPC     (ParticleStopsInTPC),
            NTPCs          (ParticleNTPCs),
            //TPCIDs         (ParticleTPCIDs),
            NCounters      (ParticleNCounters),
            //CounterIDs     (ParticleCounterIDs),
            UsesEastCounter(ParticleUsesEastCounter),
            UsesWestCounter(ParticleUsesWestCounter){
              for (UInt_t i = 0; i < NumberDaughters; i++){
                DaughterIDs[i] = ParticleDaughterIDs[i];
              }
              for (UInt_t i = 0; i < NTPCs; i++){
                TPCIDs[i] = ParticleTPCIDs[i];
              }
              for (UInt_t i = 0; i < NCounters; i++){
                CounterIDs[i] = ParticleCounterIDs[i];
              }



            };

    
 
          
    Int_t TrackID;
    Int_t PDG;
    UInt_t NumberDaughters;
    Int_t DaughterIDs[GlobalDefs::kNMaxMCParticleDaughters];
    TLorentzVector StartPosition;
    TLorentzVector EndPosition;
    TLorentzVector StartMomentum;
    TLorentzVector EndMomentum;
    Bool_t StopsInTPC;
    UInt_t NTPCs;
    Int_t TPCIDs[GlobalDefs::kNMaxMCParticleTPCs];
    UInt_t NCounters;
    Int_t CounterIDs[GlobalDefs::kNMaxMCParticleCounters];
    Bool_t UsesEastCounter;
    Bool_t UsesWestCounter;

  private:
};
#endif
