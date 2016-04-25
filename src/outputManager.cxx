#include "outputManager.h"

OutputManager::OutputManager::OutputManager(TString output_file_name){
  fOutputFile = new TFile(output_file_name,"RECREATE");
  fSelTree = new TTree("SelObj","SelObj");
  fSelTree->Branch("TruthIsSignal",&TruthIsSignal);
  fSelTree->Branch("TruthTrigger",&TruthTrigger);
  fSelTree->Branch("TruthPDG",&TruthPDG);
  fSelTree->Branch("TruthNCounters",&TruthNCounters);
  fSelTree->Branch("TruthCounterIDs",TruthCounterIDs,"TruthCounterIDs[TruthNCounters]/I");
  fSelTree->Branch("TruthStartMomentumT",&TruthStartMomentumT);
  fSelTree->Branch("TruthStartMomentumX",&TruthStartMomentumX);
  fSelTree->Branch("TruthStartMomentumY",&TruthStartMomentumY);
  fSelTree->Branch("TruthStartMomentumZ",&TruthStartMomentumZ);
  fSelTree->Branch("CutLevel",&CutLevel);
  fSelTree->Branch("ID",&ID);
  fSelTree->Branch("G4ID",&G4ID);
  fSelTree->Branch("NumberTrajectoryPoints",&NumberTrajectoryPoints);
  fSelTree->Branch("FrontPositionX",&FrontPositionX);
  fSelTree->Branch("FrontPositionY",&FrontPositionY);
  fSelTree->Branch("FrontPositionZ",&FrontPositionZ);
  fSelTree->Branch("FrontDirectionX",&FrontDirectionX);
  fSelTree->Branch("FrontDirectionY",&FrontDirectionY);
  fSelTree->Branch("FrontDirectionZ",&FrontDirectionZ);
  fSelTree->Branch("BackPositionX",&BackPositionX);
  fSelTree->Branch("BackPositionY",&BackPositionY);
  fSelTree->Branch("BackPositionZ",&BackPositionZ);
  fSelTree->Branch("BackDirectionX",&BackDirectionX);
  fSelTree->Branch("BackDirectionY",&BackDirectionY);
  fSelTree->Branch("BackDirectionZ",&BackDirectionZ);
  fSelTree->Branch("Length",&Length);
  fSelTree->Branch("ValidT0",&ValidT0);
  fSelTree->Branch("T0",&T0);
  fSelTree->Branch("T0CounterIDs",&T0CounterIDs,"T0CounterIDs[2]/i");
  fSelTree->Branch("FittedPositionX",&FittedPositionX);
  fSelTree->Branch("FittedPositionY",&FittedPositionY);
  fSelTree->Branch("FittedPositionZ",&FittedPositionZ);
  fSelTree->Branch("FittedDirectionX",&FittedDirectionX);
  fSelTree->Branch("FittedDirectionY",&FittedDirectionY);
  fSelTree->Branch("FittedDirectionZ",&FittedDirectionZ);
  fSelTree->Branch("FittedMetric",&FittedMetric);
  fSelTree->Branch("FittedValidT0",&FittedValidT0);
  fSelTree->Branch("FittedT0",&FittedT0);
  fSelTree->Branch("FittedT0CounterIDs",&FittedT0CounterIDs,"FittedT0CounterIDs[2]/i");

  fSelTree->Branch("NHits",&NHits);

  fEvTree = new TTree("Ev","Ev");
  fEvTree->Branch("NCuts",&NCuts);
  NCuts = GlobalDefs::kNMaxCuts;
  fEvTree->Branch("NObj",&NObj);
  fEvTree->Branch("NSigObj",&NSigObj);
  fEvTree->Branch("NObjPerCutLevel",NObjPerCutLevel,"NObjPerCutLevel[NCuts]/i");
  fEvTree->Branch("NSigObjPerCutLevel",NSigObjPerCutLevel,"NSigObjPerCutLevel[NCuts]/i");
}

void OutputManager::StoreRecoTrack(const RecoTrack &reco_track){


  /*
  if (true_particle){
    TruthTrigger          = TruthUtils::GetExternalTrigger(*true_particle);
    TruthPDG              = true_particle->PDG;
    TruthStartMomentumT         = true_particle->StartMomentum.T();
    TruthStartMomentumX         = true_particle->StartMomentum.X();
    TruthStartMomentumY         = true_particle->StartMomentum.Y();
    TruthStartMomentumZ         = true_particle->StartMomentum.Z();
  }
  else {
    TruthTrigger                = TriggerDefs::kNoTrigger; 
    TruthPDG                    = -99999;
    TruthStartMomentumT         = -99999.;
    TruthStartMomentumX         = -99999.;
    TruthStartMomentumY         = -99999.;
    TruthStartMomentumZ         = -99999.;
  }

  CutLevel              = cut_level;
  */
  ID                    = reco_track.ID;             
  G4ID                  = reco_track.G4ID;                  
  NumberTrajectoryPoints= reco_track.NumberTrajectoryPoints;
  FrontPositionX         = reco_track.FrontPosition.X();
  FrontPositionY         = reco_track.FrontPosition.Y();
  FrontPositionZ         = reco_track.FrontPosition.Z();
  FrontDirectionX         = reco_track.FrontDirection.X();
  FrontDirectionY         = reco_track.FrontDirection.Y();
  FrontDirectionZ         = reco_track.FrontDirection.Z();
  BackPositionX         = reco_track.BackPosition.X();
  BackPositionY         = reco_track.BackPosition.Y();
  BackPositionZ         = reco_track.BackPosition.Z();
  BackDirectionX         = reco_track.BackDirection.X();
  BackDirectionY         = reco_track.BackDirection.Y();
  BackDirectionZ         = reco_track.BackDirection.Z();
  Length                = reco_track.Length;        
  ValidT0               = reco_track.ValidT0;               
  T0                    = reco_track.T0;              
  T0CounterIDs[0]       = reco_track.T0CounterIDs[0];
  T0CounterIDs[1]       = reco_track.T0CounterIDs[1];
  FittedPositionX         = reco_track.FittedPosition.X();
  FittedPositionY         = reco_track.FittedPosition.Y();
  FittedPositionZ         = reco_track.FittedPosition.Z();
  FittedDirectionX         = reco_track.FittedDirection.X();
  FittedDirectionY         = reco_track.FittedDirection.Y();
  FittedDirectionZ         = reco_track.FittedDirection.Z();
  FittedMetric          = reco_track.FittedMetric;      
  FittedValidT0               = reco_track.FittedValidT0;               
  FittedT0                    = reco_track.FittedT0;              
  FittedT0CounterIDs[0]       = reco_track.FittedT0CounterIDs[0];
  FittedT0CounterIDs[1]       = reco_track.FittedT0CounterIDs[1];

  NHits                 = reco_track.Hits.size();

  NObj++;
  if (CutLevel > -99999) NObjPerCutLevel[CutLevel]++;
  if (TruthIsSignal) {
    NSigObj++;
    if (CutLevel > -99999) NSigObjPerCutLevel[CutLevel]++;
  }
  return;
}

void OutputManager::StoreMCParticleForRecoTrack(const MCParticle &mc_particle){
  TruthIsSignal = TruthUtils::IsSignal(mc_particle);
  TruthTrigger          = TruthUtils::GetExternalTrigger(mc_particle);
  TruthPDG              = mc_particle.PDG;
  std::vector<CounterDefs::Counters> hit_counters = TruthUtils::GetCounters(mc_particle);
  TruthNCounters = hit_counters.size();
  for (UInt_t i = 0; i < TruthNCounters; i++){
    TruthCounterIDs[i] = (Int_t)(hit_counters[i]);
  }
  TruthStartMomentumT         = mc_particle.StartMomentum.T();
  TruthStartMomentumX         = mc_particle.StartMomentum.X();
  TruthStartMomentumY         = mc_particle.StartMomentum.Y();
  TruthStartMomentumZ         = mc_particle.StartMomentum.Z();

  return;
}

void OutputManager::StoreCutLevelForRecoTrack(const Int_t &cut_level){
  CutLevel = cut_level;
  return;
}

void OutputManager::FillRecoObjTree(){
  fOutputFile->cd();
  fSelTree->Fill();
  ResetRecoObject();
  return;
}

void OutputManager::FillEvTree(){
  fOutputFile->cd();
  fEvTree->Fill();
  ResetEvTree();
  return;
}

void OutputManager::ResetRecoObject(){
  TruthTrigger                = TriggerDefs::kNoTrigger; 
  TruthPDG                    = -99999;
  for (UInt_t i = 0; i < TruthNCounters; i++) TruthCounterIDs[i] = -99999;
  TruthNCounters              = 0;
  TruthStartMomentumT         = -99999.;
  TruthStartMomentumX         = -99999.;
  TruthStartMomentumY         = -99999.;
  TruthStartMomentumZ         = -99999.;
  CutLevel              = -99999;
  ID                    = -99999; 
  G4ID                  = -99999;
  NumberTrajectoryPoints= 0; 
  FrontPositionX         = -99999.;
  FrontPositionY         = -99999.;
  FrontPositionZ         = -99999.;
  FrontDirectionX         = -99999.;
  FrontDirectionY         = -99999.;
  FrontDirectionZ         = -99999.;
  BackPositionX         = -99999.;
  BackPositionY         = -99999.;
  BackPositionZ         = -99999.;
  BackDirectionX         = -99999.;
  BackDirectionY         = -99999.;
  BackDirectionZ         = -99999.;
  Length                = -99999.;
  ValidT0               = 0; 
  T0                    = -99999.;
  T0CounterIDs[0]       = 99999; 
  T0CounterIDs[1]       = 99999;
  FittedPositionX         = -99999.;
  FittedPositionY         = -99999.;
  FittedPositionZ         = -99999.;
  FittedDirectionX         = -99999.;
  FittedDirectionY         = -99999.;
  FittedDirectionZ         = -99999.;
  FittedMetric          = -99999.;
  NHits = 0;
  return;
}

void OutputManager::ResetEvTree(){
  NObj = 0;
  NSigObj = 0;
  for (unsigned int i = 0; i < NCuts; i++){
    NObjPerCutLevel[i] = 0;
    NSigObjPerCutLevel[i] = 0;
  }
  return;
}



OutputManager::~OutputManager(){

  fOutputFile->cd();
  if (fSelTree->GetEntries() > 0) fSelTree->Write();
  if (fEvTree->GetEntries() > 0) fEvTree->Write();
  delete fSelTree;
  delete fEvTree;
  //delete fOutputFile;
}
