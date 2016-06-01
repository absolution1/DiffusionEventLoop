#ifndef DEFINITIONS_H_SEEN
#define DEFINITIONS_H_SEEN
namespace GlobalDefs{
  const unsigned int kNMaxCounters = 200;
  const unsigned int kNMaxMCParticles = 4500;
  const unsigned int kNMaxMCParticleDaughters = 100;
  const unsigned int kNMaxMCParticleTPCs = 20;
  const unsigned int kNMaxMCParticleCounters = 20;
  const unsigned int kNMaxRecoTracks = 2000;
  //const unsigned int kNMaxRecoHits = 200000;
  const unsigned int kNMaxRecoHits = 20000;
  const unsigned int kNMaxCuts = 2;
};

namespace TriggerDefs{
  enum Triggers{
    kTSUEW = 0,
    kTSUNUSD,
    kTSUNDSU,
    kBSU,
    kNoTrigger
  };
};

namespace CounterDefs{
  enum Counters{
    kTSUSD0 = 0,
    kTSUSD1,
    kTSUSD2,
    kTSUSD3,
    kTSUSD4,
    kTSUSD5,
    kTSUE0,
    kTSUE1,
    kTSUE2,
    kTSUE3,
    kTSUE4,
    kTSUE5,
    kTSUE6,
    kTSUE7,
    kTSUE8,
    kTSUE9,
    kTSUND0,
    kTSUND1,
    kTSUND2,
    kTSUND3,
    kTSUND4,
    kTSUND5,
    kTSUNU0,
    kTSUNU1,
    kTSUNU2,
    kTSUNU3,
    kTSUNU4,
    kTSUNU5,
    kTSUW0,
    kTSUW1,
    kTSUW2,
    kTSUW3,
    kTSUW4,
    kTSUW5,
    kTSUW6,
    kTSUW7,
    kTSUW8,
    kTSUW9,
    kTSUSU0,
    kTSUSU1,
    kTSUSU2,
    kTSUSU3,
    kTSUSU4,
    kTSUSU5,
    kBSU0,
    kBSU1,
    kBSU2,
    kBSU3,
    kBSU4,
    kBSU5,
    kBSU6,
    kBSU7,
    kBSU8,
    kBSU9,
    kBSU10,
    kBSU11,
    kBSU12,
    kBSU13,
    kBSU14,
    kBSU15,
    kBSU16,
    kBSU17,
    kBSU18,
    kBSU19,
    kBSU20,
    kBSU21,
    kBSU22,
    kBSU23,
    kBSU24,
    kBSU25,
    kBSU26,
    kBSU27,
    kBSU28,
    kBSU29,
    kBSU30,
    kBSU31,
    kBSU32,
    kBSU33,
    kBSU34,
    kBSU35,
    kBSU36,
    kBSU37,
    kBSU38,
    kBSU39,
    kBSU40,
    kBSU41,
    kBSU42,
    kBSU43,
    kBSU44,
    kBSU45,
    kBSU46,
    kBSU47,
    kNoCounter
  };
}
#endif
