//STL
#include <iostream>
#include <algorithm>
//ROOT
#include "TChain.h"
#include "TString.h"
//CUSTOM
#include "MCParticleFactory.h"
#include "recoTrackFactory.h"
#include "selector.h"
#include "truthUtils.h"
#include "outputManager.h"

class EventLoop{
  public:
    EventLoop();
    void AddFile(TString file_name);
    void RunAndGun();

  private:
    TChain *fChain;

    void PrintEventNumber(Long64_t eventno);
};
