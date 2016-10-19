//STL
#include <iostream>
#include <algorithm>
//ROOT
#include "TChain.h"
#include "TString.h"
//CUSTOM
#include "MCParticleFactory.h"
#include "recoTrackFactory.h"
#include "recoHitFactory.h"
#include "auxDetFactory.h"
#include "selector.h"
#include "SelectDiffusionTracks.h"
#include "truthUtils.h"
#include "outputManager.h"

class EventLoop{
  public:
    EventLoop();
    ~EventLoop();
    void AddFile(TString file_name);
    void RunAndGun(TString file_name);

  private:
    TChain *fChain;

    Int_t fRun;
    Int_t fSubRun;
    Int_t fEvent;

    void PrintEventNumber();
    Long64_t fGlobalEventNo;
    SelectDiffusionTracks *fSelectDiffusionTracks;
};
