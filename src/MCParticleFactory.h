//STL
#include <iostream>
//ROOT
#include "TTree.h"
//CUSTOM
#include "definitions.h"
#include "MCParticle.h"

class MCParticleFactory{
  public:
    MCParticleFactory(TTree *tree);
    std::vector<MCParticle> GetParticleVector();
    void Print();

  private:
    UInt_t fNMCParticles;
    Int_t fMCParticleTrackID[GlobalDefs::kNMaxMCParticles];
    Int_t fMCParticlePDG[GlobalDefs::kNMaxMCParticles];
    UInt_t fMCParticleNumberDaughters[GlobalDefs::kNMaxMCParticles];
    Int_t fMCParticleDaughterIDs[GlobalDefs::kNMaxMCParticles][GlobalDefs::kNMaxMCParticleDaughters];
    Double_t fMCParticleStartPositionT[GlobalDefs::kNMaxMCParticles];
    Double_t fMCParticleStartPositionX[GlobalDefs::kNMaxMCParticles];
    Double_t fMCParticleStartPositionY[GlobalDefs::kNMaxMCParticles];
    Double_t fMCParticleStartPositionZ[GlobalDefs::kNMaxMCParticles];
    Double_t fMCParticleEndPositionT[GlobalDefs::kNMaxMCParticles];
    Double_t fMCParticleEndPositionX[GlobalDefs::kNMaxMCParticles];
    Double_t fMCParticleEndPositionY[GlobalDefs::kNMaxMCParticles];
    Double_t fMCParticleEndPositionZ[GlobalDefs::kNMaxMCParticles];
    Double_t fMCParticleStartMomentumT[GlobalDefs::kNMaxMCParticles];
    Double_t fMCParticleStartMomentumX[GlobalDefs::kNMaxMCParticles];
    Double_t fMCParticleStartMomentumY[GlobalDefs::kNMaxMCParticles];
    Double_t fMCParticleStartMomentumZ[GlobalDefs::kNMaxMCParticles];
    Double_t fMCParticleEndMomentumT[GlobalDefs::kNMaxMCParticles];
    Double_t fMCParticleEndMomentumX[GlobalDefs::kNMaxMCParticles];
    Double_t fMCParticleEndMomentumY[GlobalDefs::kNMaxMCParticles];
    Double_t fMCParticleEndMomentumZ[GlobalDefs::kNMaxMCParticles];
    Bool_t fMCParticleStopsInTPC[GlobalDefs::kNMaxMCParticles];
    UInt_t fMCParticleNTPCs[GlobalDefs::kNMaxMCParticles];
    Int_t fMCParticleTPCIDs[GlobalDefs::kNMaxMCParticles][GlobalDefs::kNMaxMCParticleTPCs];
    UInt_t fMCParticleNCounters[GlobalDefs::kNMaxMCParticles]; 
    Int_t fMCParticleCounterIDs[GlobalDefs::kNMaxMCParticles][GlobalDefs::kNMaxMCParticleCounters];
    Bool_t fMCParticleUsesEastCounter[GlobalDefs::kNMaxMCParticles];
    Bool_t fMCParticleUsesWestCounter[GlobalDefs::kNMaxMCParticles];

};
