//STL
//ROOT
//CUSTOM
#include "recoTrack.h"

class Selector{
  public:
    Selector() : fCutLevel(0) {};
    void ApplySelection(RecoTrack reco_track);
    int GetCutLevel() { return fCutLevel; };
    
  private:
    bool MatchedT0(RecoTrack reco_track);
    int fCutLevel;
};
