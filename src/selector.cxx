#include "selector.h"

void Selector::ApplySelection(RecoTrack reco_track){
  fCutLevel = 0;
  if (!MatchedT0(reco_track)) return;
  fCutLevel++;


  return;
}

bool Selector::MatchedT0(RecoTrack reco_track){
  if (reco_track.ValidT0) return true;

  return false;
}
