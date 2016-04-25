//STL
#include <iostream>
#include <algorithm>
//ROOT
//CUSTOM
#include "MCParticle.h"
#include "definitions.h"

namespace TruthUtils{
  const MCParticle* GetMCParticleByID(const std::vector<MCParticle> &particles, Int_t id);
  std::vector<CounterDefs::Counters> GetCounters(const MCParticle &particle);
  TriggerDefs::Triggers GetExternalTrigger(const MCParticle &particle);
  Bool_t IsSignal(const MCParticle &particle);
};
