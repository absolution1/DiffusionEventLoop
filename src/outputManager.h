//STL
#include <iostream>
//ROOT
#include "TTree.h"
#include "TString.h"
#include "TFile.h"
//CUSTOM
#include "recoTrack.h"
#include "MCParticle.h"
#include "truthUtils.h"
#include "definitions.h"

class OutputManager{
  public:
    OutputManager(TString output_file_name);
    void StoreRecoTrack(const RecoTrack &reco_track);
    void StoreMCParticleForRecoTrack(const MCParticle &mc_particle);
    void StoreCutLevelForRecoTrack(const Int_t &cut_level);
    void FillRecoObjTree();
    void FillEvTree();
    void ResetRecoObject();
    void ResetEvTree();

    virtual ~OutputManager();
  private:
    TFile *fOutputFile;
    TTree *fSelTree;
    TTree *fEvTree;

    //sel obj tree
    Bool_t TruthIsSignal;
    Int_t TruthTrigger;
    Int_t TruthPDG;
    UInt_t TruthNCounters;
    Int_t TruthCounterIDs[GlobalDefs::kNMaxMCParticleCounters];
    Double_t TruthStartMomentumT;
    Double_t TruthStartMomentumX;
    Double_t TruthStartMomentumY;
    Double_t TruthStartMomentumZ;
    Int_t CutLevel;
    Int_t ID;
    Int_t G4ID;
    UInt_t NumberTrajectoryPoints;
    Double_t FrontPositionX;
    Double_t FrontPositionY;
    Double_t FrontPositionZ;
    Double_t FrontDirectionX;
    Double_t FrontDirectionY;
    Double_t FrontDirectionZ;
    Double_t BackPositionX;
    Double_t BackPositionY;
    Double_t BackPositionZ;
    Double_t BackDirectionX;
    Double_t BackDirectionY;
    Double_t BackDirectionZ;
    Double_t Length;
    Bool_t ValidT0;
    Double_t T0;
    UInt_t T0CounterIDs[2];
    Double_t FittedPositionX;
    Double_t FittedPositionY;
    Double_t FittedPositionZ;
    Double_t FittedDirectionX;
    Double_t FittedDirectionY;
    Double_t FittedDirectionZ;
    Double_t FittedMetric;
    Bool_t FittedValidT0;
    Double_t FittedT0;
    UInt_t FittedT0CounterIDs[2];

    UInt_t NHits;

    //Ev tree
    UInt_t NObj;
    UInt_t NSigObj;
    UInt_t NCuts;
    UInt_t NObjPerCutLevel[GlobalDefs::kNMaxCuts];
    UInt_t NSigObjPerCutLevel[GlobalDefs::kNMaxCuts];
};
