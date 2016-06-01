#include "FitCounterPositions.h"

FitCounterPositions::FitCounterPositions::FitCounterPositions(){
  fApp = new TApplication("theApp",0,0,0,0);

  fCounterPositionsAndDimensions[6].first.SetXYZ(-31.6952,-88.2705,-106.22);
  fCounterPositionsAndDimensions[7].first.SetXYZ(-0.946863,-88.2705,-106.22);
  fCounterPositionsAndDimensions[8].first.SetXYZ(29.8015,-88.2705,-106.22);
  fCounterPositionsAndDimensions[9].first.SetXYZ(60.5498,-88.2705,-106.22);
  fCounterPositionsAndDimensions[10].first.SetXYZ(91.2981,-88.2705,-106.22);
  fCounterPositionsAndDimensions[11].first.SetXYZ(122.046,-88.2705,-106.22);
  fCounterPositionsAndDimensions[12].first.SetXYZ(152.795,-88.2705,-106.22);
  fCounterPositionsAndDimensions[13].first.SetXYZ(183.543,-88.2705,-106.22);
  fCounterPositionsAndDimensions[14].first.SetXYZ(214.291,-88.2705,-106.22);
  fCounterPositionsAndDimensions[15].first.SetXYZ(245.04,-88.2705,-106.22);

  fCounterPositionsAndDimensions[28].first.SetXYZ(-36.1102,121.1995,309.32);
  fCounterPositionsAndDimensions[29].first.SetXYZ(-7.22853,121.1995,309.32);
  fCounterPositionsAndDimensions[30].first.SetXYZ(21.6531,121.1995,309.32);
  fCounterPositionsAndDimensions[31].first.SetXYZ(50.5348,121.1995,309.32);
  fCounterPositionsAndDimensions[32].first.SetXYZ(79.4165,121.1995,309.32);
  fCounterPositionsAndDimensions[33].first.SetXYZ(108.298,121.1995,309.32);
  fCounterPositionsAndDimensions[34].first.SetXYZ(137.18,121.1995,309.32);
  fCounterPositionsAndDimensions[35].first.SetXYZ(166.061,121.1995,309.32);
  fCounterPositionsAndDimensions[36].first.SetXYZ(194.943,121.1995,309.32);
  fCounterPositionsAndDimensions[37].first.SetXYZ(223.825, 121.1995,309.32);

  for (std::map<Int_t,std::pair<TVector3,double> >::iterator it = fCounterPositionsAndDimensions.begin(); it != fCounterPositionsAndDimensions.end(); it++){
    (*it).second.second = 32.56;
  }

}

void FitCounterPositions::AccumulateStats(const std::vector<RecoHit> &hits, const std::vector<AuxDet> &aux_dets){
  //Firstly, reconstruct the trigger
  //Check if a trigger exists.  If not sack of this event

  bool has_trigger = false;
  for (unsigned int i = 0; i < aux_dets.size(); i++){
    if (aux_dets[i].ID == 111){
      has_trigger = true;
      break;
    }
  }
  if (!has_trigger) return;

  std::vector<AuxDet> trigger_constituents = ReconstructEWTrigger(aux_dets);
  //Only proceed if there are exactly 2 counters found
  if (trigger_constituents.size() != 2) return;

  //Check that we have one East AND one West counter
  bool has_east = false;
  bool has_west = false;
  for (unsigned int i = 0; i < trigger_constituents.size(); i++){
    CounterDefs::Counters id = static_cast<CounterDefs::Counters>(trigger_constituents[i].ID);
    if (id > CounterDefs::kTSUE0 && CounterDefs::kTSUE9) has_east = true;
    if (id > CounterDefs::kTSUW0 && CounterDefs::kTSUW9) has_west = true;
  }
  if (!(has_east && has_west)) return;


  //Get the T0 from the trigger constituents
  Double_t T0 = GetT0FromCounters(trigger_constituents);


  TH2F h_Selection[NCuts];
  for (int i = 0; i < NCuts; i++){
    TString name = Form("h_%i",i);
    h_Selection[i] = TH2F(name,"",1000,0,150,5000,0,5000);

  }
  TCanvas canvas("canvasKey");
  canvas.Divide(2,1);


  //Now loop over the hits
  for (unsigned int hit_i = 0; hit_i < hits.size(); hit_i++){
    //Only look at the collection plane
    if (hits[hit_i].PlaneID != 2) continue;
    //Now Draw all of the hits
    h_Selection[0].Fill(hits[hit_i].WireCenter.Z(),hits[hit_i].PeakTime-T0,hits[hit_i].Integral);

    //Now reject hits on wires with multiple occupancy
    UInt_t nhits_on_wire = NHitsOnWire(hits[hit_i].WireID,hits);
    if (nhits_on_wire > 80) continue;
    h_Selection[1].Fill(hits[hit_i].WireCenter.Z(),hits[hit_i].PeakTime-T0,hits[hit_i].Integral);

  }
  for (int i = 0; i < NCuts; i++){
    canvas.cd(i+1);
    h_Selection[i].Draw("colz");
  }
  canvas.Update();
  canvas.WaitPrimitive();

  return;
}

std::vector<AuxDet> FitCounterPositions::ReconstructEWTrigger(const std::vector<AuxDet> &aux_dets){
  std::vector<AuxDet> trigger_constituents;

  //Get the trigger time
  Int_t trigger_time;
  for (unsigned int i = 0; i < aux_dets.size(); i++){
    if (aux_dets[i].ID == 111) trigger_time = aux_dets[i].Time;
  }

  //Now loop over them again and find all of the counters within a time tolerance
  Int_t time_tolerance = 20;
  for (unsigned int i = 0; i < aux_dets.size(); i++){
    Int_t id = static_cast<CounterDefs::Counters>(aux_dets[i].ID);
    //Only look at EW counters
    if (!((id > CounterDefs::kTSUE0 && id < CounterDefs::kTSUE9) || (id > CounterDefs::kTSUW0 && id < CounterDefs::kTSUW9))) continue;
    //Now check if the counter is within the time tolerance
    Int_t counter_time = aux_dets[i].Time;
    if (std::abs(trigger_time-counter_time) < time_tolerance){
      trigger_constituents.push_back(aux_dets[i]);
    }
    
  }

  return trigger_constituents;
}

Double_t FitCounterPositions::GetT0FromCounters(const std::vector<AuxDet> &aux_dets){
  Double_t T0 = 0;
  if (aux_dets.size() == 0) return T0;

  for (unsigned int i = 0; i < aux_dets.size(); i++){
    T0 += (Double_t)aux_dets[i].Time;
  }

  T0 /= aux_dets.size();

  return T0;
}

UInt_t FitCounterPositions::NHitsOnWire(UInt_t wire_id, const std::vector<RecoHit> &reco_hits){
  Int_t NHits = 0;
  for (unsigned int i = 0; i < reco_hits.size(); i++){
    if (reco_hits[i].WireID == wire_id) NHits++;
  }

  return NHits;
}

Bool_t FitCounterPositions::HitWithinCounterShadow(const RecoHit &hit, const std::vector<AuxDet> &aux_dets){

  //Convert counter pos to drift time
  //form lines between counters
  //check if hit within bounds


  return false;
}
