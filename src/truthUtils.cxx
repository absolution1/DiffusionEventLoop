#include "truthUtils.h"

const MCParticle* TruthUtils::GetMCParticleByID(const std::vector<MCParticle> &particles, Int_t id){
  for (unsigned int i = 0; i < particles.size(); i++){
    if (id == particles[i].TrackID) {
      const MCParticle *particle = &(particles[i]);
      return particle;
    }
  }
  MCParticle *empty_particle = NULL;
  return empty_particle;
}

std::vector<CounterDefs::Counters> TruthUtils::GetCounters(const MCParticle &particle){
  std::vector<CounterDefs::Counters> hit_counters;
  for (UInt_t i = 0; i < particle.NCounters; i++){
    CounterDefs::Counters counter_id = static_cast<CounterDefs::Counters>(particle.CounterIDs[i]);
    hit_counters.push_back(counter_id);
  }

  return hit_counters;
}

TriggerDefs::Triggers TruthUtils::GetExternalTrigger(const MCParticle &particle){
  bool hitWest = 0;
  bool hitEast = 0;
  bool hitNorthUp = 0;
  bool hitSouthDown = 0;
  bool hitNorthDown = 0;
  bool hitSouthUp = 0;
  bool hitBSULow = 0;
  bool hitBSUHigh = 0;

  for (UInt_t i = 0; i < particle.NCounters; i++){
    CounterDefs::Counters counter_id = static_cast<CounterDefs::Counters>(particle.CounterIDs[i]);
    if (counter_id >= CounterDefs::kTSUW0 && counter_id <= CounterDefs::kTSUW9) hitWest = true;
    else if (counter_id >= CounterDefs::kTSUE0 && counter_id <= CounterDefs::kTSUE9) hitEast = true;
    else if (counter_id >= CounterDefs::kTSUNU0 && counter_id <= CounterDefs::kTSUNU5) hitNorthUp = true;
    else if (counter_id >= CounterDefs::kTSUSD0 && counter_id <= CounterDefs::kTSUSD5) hitSouthDown = true;
    else if (counter_id >= CounterDefs::kTSUND0 && counter_id <= CounterDefs::kTSUND5) hitNorthDown = true;
    else if (counter_id >= CounterDefs::kTSUSU0 && counter_id <= CounterDefs::kTSUSU5) hitSouthUp = true;
    else if (counter_id >= CounterDefs::kBSU0 && counter_id <= CounterDefs::kBSU21) hitBSULow = true;
    else if (counter_id >= CounterDefs::kBSU22 && counter_id <= CounterDefs::kBSU47) hitBSUHigh = true;
  }

  if (hitWest && hitEast) return TriggerDefs::kTSUEW;
  if (hitNorthUp && hitSouthDown) return TriggerDefs::kTSUNUSD;
  if (hitNorthDown && hitSouthUp) return TriggerDefs::kTSUNDSU;
  if (hitBSULow && hitBSUHigh) return TriggerDefs::kBSU;

  return TriggerDefs::kNoTrigger;
}

Bool_t TruthUtils::IsSignal(const MCParticle &particle){

  TriggerDefs::Triggers trig_id = GetExternalTrigger(particle);
  if (trig_id != TriggerDefs::kTSUEW) return false;
  if (std::abs(particle.PDG) != 13) return false;

  return true;
}
