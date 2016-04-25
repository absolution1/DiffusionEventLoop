#include "eventLoop.h"

EventLoop::EventLoop::EventLoop(){
  fChain = new TChain("diffusion/difftree");
}

void EventLoop::AddFile(TString file_name){
  fChain->Add(file_name);
  return;
}

void EventLoop::RunAndGun(){
  //Initialise the factories
  MCParticleFactory truth_factory(fChain);
  RecoTrackFactory reco_factory(fChain);

  //Create the selector
  Selector selector;

  //Create the output manager
  OutputManager output_manager("output.root");
  
  //Get the information to start the loop
  Long64_t NEvents = fChain->GetEntries();
  std::cout<<"Number of events to loop over: " << NEvents << std::endl;
  for (Long64_t eventno = 0; eventno < NEvents; eventno++){
    PrintEventNumber(eventno);
    fChain->GetEntry(eventno);
    std::vector<MCParticle> mc_particles = truth_factory.GetParticleVector();
    for (unsigned int i = 0; i < mc_particles.size(); i++){
    }
    std::vector<RecoTrack> reco_tracks = reco_factory.GetRecoTrackVector();
    for (unsigned int i = 0; i < reco_tracks.size(); i++){
      selector.ApplySelection(reco_tracks[i]);
      const MCParticle *matched_particle = TruthUtils::GetMCParticleByID(mc_particles, reco_tracks[i].G4ID);
      if (matched_particle) output_manager.StoreMCParticleForRecoTrack(*matched_particle);
      output_manager.StoreCutLevelForRecoTrack(selector.GetCutLevel());
      output_manager.StoreRecoTrack(reco_tracks[i]);
      output_manager.FillRecoObjTree();
    }

    output_manager.FillEvTree();
  }

  return;
}



void EventLoop::PrintEventNumber(Long64_t eventno){
  if (eventno<10) return;
  Long64_t holder = eventno;
  int order = 0;
  while (holder > 0){
    holder/=10;
    order++;
  }
  int mag = 1;
  for (int i = 0; i < std::min(order-1,4); i++){
    mag*=10;
  }
  if (eventno % mag == 0) std::cout<<"Loop has reached event: " << eventno << std::endl;

  return;
}
