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
  bool hitTSULow = 0;
  bool hitTSUHigh = 0;

  for (UInt_t i = 0; i < particle.NCounters; i++){
    CounterDefs::Counters counter_id = static_cast<CounterDefs::Counters>(particle.CounterIDs[i]);
    if (counter_id >= CounterDefs::kBSUW0 && counter_id <= CounterDefs::kBSUW9) hitWest = true;
    else if (counter_id >= CounterDefs::kBSUE0 && counter_id <= CounterDefs::kBSUE9) hitEast = true;
    else if (counter_id >= CounterDefs::kBSUNU0 && counter_id <= CounterDefs::kBSUNU5) hitNorthUp = true;
    else if (counter_id >= CounterDefs::kBSUSD0 && counter_id <= CounterDefs::kBSUSD5) hitSouthDown = true;
    else if (counter_id >= CounterDefs::kBSUND0 && counter_id <= CounterDefs::kBSUND5) hitNorthDown = true;
    else if (counter_id >= CounterDefs::kBSUSU0 && counter_id <= CounterDefs::kBSUSU5) hitSouthUp = true;
    else if (counter_id >= CounterDefs::kTSU0 && counter_id <= CounterDefs::kTSU21) hitTSULow = true;
    else if (counter_id >= CounterDefs::kTSU22 && counter_id <= CounterDefs::kTSU47) hitTSUHigh = true;
  }

  if (hitWest && hitEast) return TriggerDefs::kBSUEW;
  if (hitNorthUp && hitSouthDown) return TriggerDefs::kBSUNUSD;
  if (hitNorthDown && hitSouthUp) return TriggerDefs::kBSUNDSU;
  if (hitTSULow && hitTSUHigh) return TriggerDefs::kTSU;

  return TriggerDefs::kNoTrigger;
}

Bool_t TruthUtils::IsSignal(const MCParticle &particle){

  TriggerDefs::Triggers trig_id = GetExternalTrigger(particle);
  if (trig_id != TriggerDefs::kBSUEW) return false;
  if (std::abs(particle.PDG) != 13) return false;

  return true;
}
