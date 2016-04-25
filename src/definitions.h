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
    kBSUEW = 0,
    kBSUNUSD,
    kBSUNDSU,
    kTSU,
    kNoTrigger
  };
};

namespace CounterDefs{
  enum Counters{
    kBSUSD0 = 0,
    kBSUSD1,
    kBSUSD2,
    kBSUSD3,
    kBSUSD4,
    kBSUSD5,
    kBSUE0,
    kBSUE1,
    kBSUE2,
    kBSUE3,
    kBSUE4,
    kBSUE5,
    kBSUE6,
    kBSUE7,
    kBSUE8,
    kBSUE9,
    kBSUND0,
    kBSUND1,
    kBSUND2,
    kBSUND3,
    kBSUND4,
    kBSUND5,
    kBSUNU0,
    kBSUNU1,
    kBSUNU2,
    kBSUNU3,
    kBSUNU4,
    kBSUNU5,
    kBSUW0,
    kBSUW1,
    kBSUW2,
    kBSUW3,
    kBSUW4,
    kBSUW5,
    kBSUW6,
    kBSUW7,
    kBSUW8,
    kBSUW9,
    kBSUSU0,
    kBSUSU1,
    kBSUSU2,
    kBSUSU3,
    kBSUSU4,
    kBSUSU5,
    kTSU0,
    kTSU1,
    kTSU2,
    kTSU3,
    kTSU4,
    kTSU5,
    kTSU6,
    kTSU7,
    kTSU8,
    kTSU9,
    kTSU10,
    kTSU11,
    kTSU12,
    kTSU13,
    kTSU14,
    kTSU15,
    kTSU16,
    kTSU17,
    kTSU18,
    kTSU19,
    kTSU20,
    kTSU21,
    kTSU22,
    kTSU23,
    kTSU24,
    kTSU25,
    kTSU26,
    kTSU27,
    kTSU28,
    kTSU29,
    kTSU30,
    kTSU31,
    kTSU32,
    kTSU33,
    kTSU34,
    kTSU35,
    kTSU36,
    kTSU37,
    kTSU38,
    kTSU39,
    kTSU40,
    kTSU41,
    kTSU42,
    kTSU43,
    kTSU44,
    kTSU45,
    kTSU46,
    kTSU47,
    kNoCounter
  };
}
#endif
