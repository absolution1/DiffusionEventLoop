#include "MCParticleFactory.h"

MCParticleFactory::MCParticleFactory::MCParticleFactory(TTree *tree){

  tree->SetBranchAddress("NMCParticles",&fNMCParticles);
  tree->SetBranchAddress("MCParticleTrackID",&fMCParticleTrackID);
  tree->SetBranchAddress("MCParticlePDG",&fMCParticlePDG);
  tree->SetBranchAddress("MCParticleNumberDaughters",&fMCParticleNumberDaughters);
  tree->SetBranchAddress("MCParticleDaughterIDs",&fMCParticleDaughterIDs);
  tree->SetBranchAddress("MCParticleStartPositionT",&fMCParticleStartPositionT);
  tree->SetBranchAddress("MCParticleStartPositionX",&fMCParticleStartPositionX);
  tree->SetBranchAddress("MCParticleStartPositionY",&fMCParticleStartPositionY);
  tree->SetBranchAddress("MCParticleStartPositionZ",&fMCParticleStartPositionZ);
  tree->SetBranchAddress("MCParticleEndPositionT",&fMCParticleEndPositionT);
  tree->SetBranchAddress("MCParticleEndPositionX",&fMCParticleEndPositionX);
  tree->SetBranchAddress("MCParticleEndPositionY",&fMCParticleEndPositionY);
  tree->SetBranchAddress("MCParticleEndPositionZ",&fMCParticleEndPositionZ);
  tree->SetBranchAddress("MCParticleStartMomentumT",&fMCParticleStartMomentumT);
  tree->SetBranchAddress("MCParticleStartMomentumX",&fMCParticleStartMomentumX);
  tree->SetBranchAddress("MCParticleStartMomentumY",&fMCParticleStartMomentumY);
  tree->SetBranchAddress("MCParticleStartMomentumZ",&fMCParticleStartMomentumZ);
  tree->SetBranchAddress("MCParticleEndMomentumT",&fMCParticleEndMomentumT);
  tree->SetBranchAddress("MCParticleEndMomentumX",&fMCParticleEndMomentumX);
  tree->SetBranchAddress("MCParticleEndMomentumY",&fMCParticleEndMomentumY);
  tree->SetBranchAddress("MCParticleEndMomentumZ",&fMCParticleEndMomentumZ);
  tree->SetBranchAddress("MCParticleStopsInTPC",&fMCParticleStopsInTPC);
  tree->SetBranchAddress("MCParticleNTPCs",&fMCParticleNTPCs);
  tree->SetBranchAddress("MCParticleTPCIDs",&fMCParticleTPCIDs);
  tree->SetBranchAddress("MCParticleNCounters",&fMCParticleNCounters);
  tree->SetBranchAddress("MCParticleCounterIDs",&fMCParticleCounterIDs);
  tree->SetBranchAddress("MCParticleUsesEastCounters",&fMCParticleUsesEastCounter);
  tree->SetBranchAddress("MCParticleUsesWestCounters",&fMCParticleUsesWestCounter);
}

std::vector<MCParticle> MCParticleFactory::GetParticleVector(){
  std::vector<MCParticle> particle_vector;
  for (UInt_t i = 0; i < fNMCParticles; i++){
    //Create an MC particle
    particle_vector.push_back(MCParticle(
      fMCParticleTrackID[i],
      fMCParticlePDG[i],
      fMCParticleNumberDaughters[i],
      fMCParticleDaughterIDs[i],
      fMCParticleStartPositionT[i],
      fMCParticleStartPositionX[i],
      fMCParticleStartPositionY[i],
      fMCParticleStartPositionZ[i],
      fMCParticleEndPositionT[i],
      fMCParticleEndPositionX[i],
      fMCParticleEndPositionY[i],
      fMCParticleEndPositionZ[i],
      fMCParticleStartMomentumT[i],
      fMCParticleStartMomentumX[i],
      fMCParticleStartMomentumY[i],
      fMCParticleStartMomentumZ[i],
      fMCParticleEndMomentumT[i],
      fMCParticleEndMomentumX[i],
      fMCParticleEndMomentumY[i],
      fMCParticleEndMomentumZ[i],
      fMCParticleStopsInTPC[i],
      fMCParticleNTPCs[i],
      fMCParticleTPCIDs[i],
      fMCParticleNCounters[i],
      fMCParticleCounterIDs[i],
      fMCParticleUsesEastCounter[i],
      fMCParticleUsesWestCounter[i]
    ));
  }
  return particle_vector;
}

void MCParticleFactory::Print(){
  for (UInt_t i = 0; i < fNMCParticles; i++){
    std::cout<<fMCParticlePDG[i] << std::endl;
  }
  return;
}
