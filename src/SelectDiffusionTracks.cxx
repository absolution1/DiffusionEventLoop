#include "SelectDiffusionTracks.h"

SelectDiffusionTracks::SelectDiffusionTracks::SelectDiffusionTracks(){

  Bool_t is_data = true;

  fApp = new TApplication("theApp",0,0,0,0);

  if (is_data){
    fCounterPositionsAndDimensions[6].first.SetXYZ(-50, -88.2705, -106.22);
    fCounterPositionsAndDimensions[7].first.SetXYZ(-21, -88.2705, -106.22);
    fCounterPositionsAndDimensions[8].first.SetXYZ(15, -88.2705, -106.22);
    fCounterPositionsAndDimensions[9].first.SetXYZ(44, -88.2705, -106.22);
    fCounterPositionsAndDimensions[10].first.SetXYZ(74.5, -88.2705, -106.22);
    fCounterPositionsAndDimensions[11].first.SetXYZ(105.5, -88.2705, -106.22);
    fCounterPositionsAndDimensions[12].first.SetXYZ(136, -88.2705, -106.22);
    fCounterPositionsAndDimensions[13].first.SetXYZ(166.5, -88.2705, -106.22);
    fCounterPositionsAndDimensions[14].first.SetXYZ(196.5, -88.2705, -106.22);
    fCounterPositionsAndDimensions[15].first.SetXYZ(225.5, -88.2705, -106.22);

    fCounterPositionsAndDimensions[28].first.SetXYZ(-50, 121.1995, 309.32);
    fCounterPositionsAndDimensions[29].first.SetXYZ(-21, 121.1995, 309.32);
    fCounterPositionsAndDimensions[30].first.SetXYZ(15, 121.1995, 309.32);
    fCounterPositionsAndDimensions[31].first.SetXYZ(44, 121.1995, 309.32);
    fCounterPositionsAndDimensions[32].first.SetXYZ(74.5, 121.1995, 309.32);
    fCounterPositionsAndDimensions[33].first.SetXYZ(105.5, 121.1995, 309.32);
    fCounterPositionsAndDimensions[34].first.SetXYZ(136, 121.1995, 309.32);
    fCounterPositionsAndDimensions[35].first.SetXYZ(166.5, 121.1995, 309.32);
    fCounterPositionsAndDimensions[36].first.SetXYZ(196.5, 121.1995, 309.32);
    fCounterPositionsAndDimensions[37].first.SetXYZ(225.5, 121.1995, 309.32);
  }
  else{
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


  }
  /*
  fEWCounterPosCorrection[15] = 230;
  fEWCounterPosCorrection[14] = 199;
  fEWCounterPosCorrection[13] = 168;
  fEWCounterPosCorrection[12] = 137;
  fEWCounterPosCorrection[11] = 106;
  fEWCounterPosCorrection[10] = 75;
  fEWCounterPosCorrection[9] = 44;
  fEWCounterPosCorrection[8] = 13;
  fEWCounterPosCorrection[7] = -18;
  fEWCounterPosCorrection[6] = -49;

  fEWCounterPosCorrection[37] = 230;
  fEWCounterPosCorrection[36] = 199;
  fEWCounterPosCorrection[35] = 168;
  fEWCounterPosCorrection[34] = 137;
  fEWCounterPosCorrection[33] = 106;
  fEWCounterPosCorrection[32] = 75;
  fEWCounterPosCorrection[31] = 44;
  fEWCounterPosCorrection[30] = 13;
  fEWCounterPosCorrection[29] = -18;
  fEWCounterPosCorrection[28] = -49;
  */



  for (std::map<Int_t,std::pair<TVector3,std::pair<double,double> > >::iterator it = fCounterPositionsAndDimensions.begin(); it != fCounterPositionsAndDimensions.end(); it++){
    (*it).second.second.first = 2.*0.475;
    (*it).second.second.second = 32.56;
    /*
    if (is_data){
      Int_t id = (*it).first;
      Double_t x_correction = fEWCounterPosCorrection[id];
      (*it).second.first.SetX(x_correction);
    }
    */
  }


  fFile = new TFile("diff_sel_tree.root","RECREATE");
  fFile->cd();
  fTree = new TTree("diffsel","diffsel");
  fNCuts = NCuts;
  fTree->Branch("NCuts",&fNCuts);
  fTree->Branch("NHits",fNHits,"NHits[NCuts]/I");
  fTree->Branch("Residuals",fResiduals,"Residuals[NCuts]/D");
  fTree->Branch("NCounters",&fNCounters);
  fTree->Branch("CounterID",fCounterID,"CounterID[NCounters]/I");
  fTree->Branch("T0",&fT0);
  fTree->Branch("NSelRecoHits",&fNSelRecoHits);
  fTree->Branch("SelRecoHitTrackID",fSelRecoHitTrackID,"SelRecoHitTrackID[NSelRecoHits]/I");
  fTree->Branch("SelRecoHitStartTick",fSelRecoHitStartTick,"SelRecoHitStartTick[NSelRecoHits]/I");
  fTree->Branch("SelRecoHitEndTick",fSelRecoHitEndTick,"SelRecoHitEndTick[NSelRecoHits]/I");
  fTree->Branch("SelRecoHitPeakTime",fSelRecoHitPeakTime,"SelRecoHitPeakTime[NSelRecoHits]/D");
  fTree->Branch("SelRecoHitSigmaPeakTime",fSelRecoHitSigmaPeakTime,"SelRecoHitSigmaPeakTime[NSelRecoHits]/D");
  fTree->Branch("SelRecoHitRMS",fSelRecoHitRMS,"SelRecoHitRMS[NSelRecoHits]/D");
  fTree->Branch("SelRecoHitPeakAmplitude",fSelRecoHitPeakAmplitude,"SelRecoHitPeakAmplitude[NSelRecoHits]/D");
  fTree->Branch("SelRecoHitSigmaPeakAmplitude",fSelRecoHitSigmaPeakAmplitude,"SelRecoHitSigmaPeakAmplitude[NSelRecoHits]/D");
  fTree->Branch("SelRecoHitSummedADC",fSelRecoHitSummedADC,"SelRecoHitSummedADC[NSelRecoHits]/D");
  fTree->Branch("SelRecoHitIntegral",fSelRecoHitIntegral,"SelRecoHitIntegral[NSelRecoHits]/D");
  fTree->Branch("SelRecoHitSigmaIntegral",fSelRecoHitSigmaIntegral,"SelRecoHitSigmaIntegral[NSelRecoHits]/D");
  fTree->Branch("SelRecoHitMultiplicity",fSelRecoHitMultiplicity,"SelRecoHitMultiplicity[NSelRecoHits]/I");
  fTree->Branch("SelRecoHitLocalIndex",fSelRecoHitLocalIndex,"SelRecoHitLocalIndex[NSelRecoHits]/I");
  fTree->Branch("SelRecoHitGoodnessOfFit",fSelRecoHitGoodnessOfFit,"SelRecoHitGoodnessOfFit[NSelRecoHits]/D");
  fTree->Branch("SelRecoHitDegreesOfFreedom",fSelRecoHitDegreesOfFreedom,"SelRecoHitDegreesOfFreedom[NSelRecoHits]/I");
  fTree->Branch("SelRecoHitChannel",fSelRecoHitChannel,"SelRecoHitChannel[NSelRecoHits]/i");
  fTree->Branch("SelRecoHitView",fSelRecoHitView,"SelRecoHitView[NSelRecoHits]/I");
  fTree->Branch("SelRecoHitWireID",fSelRecoHitWireID,"SelRecoHitWireID[NSelRecoHits]/i");
  fTree->Branch("SelRecoHitPlaneID",fSelRecoHitPlaneID,"SelRecoHitPlaneID[NSelRecoHits]/i");
  fTree->Branch("SelRecoHitTPCID",fSelRecoHitTPCID,"SelRecoHitTPCID[NSelRecoHits]/i");
  fTree->Branch("SelRecoHitIsValid",fSelRecoHitIsValid,"SelRecoHitIsValid[NSelRecoHits]/O");
  fTree->Branch("SelRecoHitCryostatID",fSelRecoHitCryostatID,"SelRecoHitCryostatID[NSelRecoHits]/i");
  fTree->Branch("SelRecoHitWireCenterX",fSelRecoHitWireCenterX,"SelRecoHitWireCenterX[NSelRecoHits]/D");
  fTree->Branch("SelRecoHitWireCenterY",fSelRecoHitWireCenterY,"SelRecoHitWireCenterY[NSelRecoHits]/D");
  fTree->Branch("SelRecoHitWireCenterZ",fSelRecoHitWireCenterZ,"SelRecoHitWireCenterZ[NSelRecoHits]/D");


}

SelectDiffusionTracks::~SelectDiffusionTracks(){
  fFile->cd();
  fTree->Write();
  fFile->Close();
}

void SelectDiffusionTracks::AccumulateStats(const std::vector<RecoHit> &hits, const std::vector<AuxDet> &aux_dets){
  Bool_t draw = false;

  Reset();

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
    if (id >= CounterDefs::kTSUE0 && id <= CounterDefs::kTSUE9) has_east = true;
    if (id >= CounterDefs::kTSUW0 && id <= CounterDefs::kTSUW9) has_west = true;
  }
  if (!(has_east && has_west)) return;


  //Get the T0 from the trigger constituents
  Double_t T0 = GetT0FromCounters(trigger_constituents);

  /*
  //Work out histogram y values
  int time_up_0 = ConvertXToTicks(fCounterPositionsAndDimensions[trigger_constituents[0].ID].first.X()+fCounterPositionsAndDimensions[trigger_constituents[0].ID].second/2.); 
  int time_up_1 = ConvertXToTicks(fCounterPositionsAndDimensions[trigger_constituents[1].ID].first.X()+fCounterPositionsAndDimensions[trigger_constituents[1].ID].second/2.); 
  int max = std::max(time_up_0,time_up_1);
  max *= 1;
  int time_down_0 = ConvertXToTicks(fCounterPositionsAndDimensions[trigger_constituents[0].ID].first.X()-fCounterPositionsAndDimensions[trigger_constituents[0].ID].second/2.); 
  int time_down_1 = ConvertXToTicks(fCounterPositionsAndDimensions[trigger_constituents[1].ID].first.X()-fCounterPositionsAndDimensions[trigger_constituents[1].ID].second/2.); 
  int min = std::min(time_down_0,time_down_1);
  min *= 1;
  */

  double x_up_1 = fCounterPositionsAndDimensions[trigger_constituents[0].ID].first.X()+fCounterPositionsAndDimensions[trigger_constituents[0].ID].second.second/2.;
  double x_up_2 = fCounterPositionsAndDimensions[trigger_constituents[1].ID].first.X()+fCounterPositionsAndDimensions[trigger_constituents[1].ID].second.second/2.;
  int max = std::max(x_up_1,x_up_2);

  double x_down_1 = fCounterPositionsAndDimensions[trigger_constituents[0].ID].first.X()-fCounterPositionsAndDimensions[trigger_constituents[0].ID].second.second/2.;
  double x_down_2 = fCounterPositionsAndDimensions[trigger_constituents[1].ID].first.X()-fCounterPositionsAndDimensions[trigger_constituents[1].ID].second.second/2.;
  int min = std::min(x_down_1,x_down_2);




  TH2F h_Selection[NCuts];
  for (int i = 0; i < NCuts; i++){
    TString name = Form("h_%i",i);
    h_Selection[i] = TH2F(name,"",1000,0,150,max-min,min,max);
    h_Selection[i].GetXaxis()->SetTitle("z (cm)");
    h_Selection[i].GetYaxis()->SetTitle("x (cm)");
  }

  Int_t cut_number = 0;
  fNHits[cut_number] = (int)hits.size();

  std::vector<RecoHit> hits_after_cut_1;
  for (unsigned int hit_i = 0; hit_i < hits.size(); hit_i++){
    //Get the X_coordinate of the hit
    Double_t x_coord = ConvertTicksToX(hits[hit_i].PeakTime-T0,IsInShortDrift(hits[hit_i]));
    //Only look at the collection plane
    if (hits[hit_i].PlaneID != 2) continue;
    //Now Draw all of the hits
    //h_Selection[0].Fill(hits[hit_i].WireCenter.Z(),hits[hit_i].PeakTime-T0);//,hits[hit_i].Integral);
    h_Selection[0].Fill(hits[hit_i].WireCenter.Z(),x_coord);//,hits[hit_i].Integral);

    Bool_t hit_in_window = HitWithinCounterShadow(hits[hit_i],trigger_constituents);
    if (!hit_in_window) {
      continue;
    }
    //h_Selection[1].Fill(hits[hit_i].WireCenter.Z(),hits[hit_i].PeakTime-T0);//,hits[hit_i].Integral);
    h_Selection[1].Fill(hits[hit_i].WireCenter.Z(),x_coord);//,hits[hit_i].Integral);

    hits_after_cut_1.push_back(hits[hit_i]);
  }

  cut_number++;
  fNHits[cut_number] = (int)hits_after_cut_1.size();


  std::vector<RecoHit> hits_after_cut_2;
  //Now loop through the remaining hits
  for (unsigned int hit_i = 0; hit_i < hits_after_cut_1.size(); hit_i++){
    Double_t x_coord = ConvertTicksToX(hits_after_cut_1[hit_i].PeakTime-T0,IsInShortDrift(hits_after_cut_1[hit_i]));

    //Now reject hits on wires with multiple occupancy
    UInt_t nhits_on_wire = NHitsOnWire(hits_after_cut_1[hit_i].Channel,hits_after_cut_1);
    if (nhits_on_wire > 1) continue;
    //h_Selection[2].Fill(hits_after_cut_1[hit_i].WireCenter.Z(),hits_after_cut_1[hit_i].PeakTime-T0);//,hits_after_cut_1[hit_i].Integral);
    h_Selection[2].Fill(hits_after_cut_1[hit_i].WireCenter.Z(),x_coord);//,hits_after_cut_1[hit_i].Integral);

    hits_after_cut_2.push_back(hits_after_cut_1[hit_i]);
  }

  cut_number++;
  fNHits[cut_number] = (int)hits_after_cut_2.size();


  std::vector<RecoHit> hits_after_cut_3;
  //Combine two cuts into 1
  //Demand that there are enough hits to fit with
  UInt_t NRequiredHits = 20;
  if (hits_after_cut_2.size() < NRequiredHits) {
    fTree->Fill();
    return;
  }
  //Now fit a line to the hits
  std::vector<TVector2> hit_positions;
  Double_t m, c;
  //I appreciate the boiler plate but lets keep it as separate as possible
  for (unsigned int hit_i = 0; hit_i < hits_after_cut_2.size(); hit_i++){
    Double_t x_coord = ConvertTicksToX(hits_after_cut_2[hit_i].PeakTime-T0,IsInShortDrift(hits_after_cut_2[hit_i]));
    Double_t z_coord = hits_after_cut_2[hit_i].WireCenter.Z();
    hit_positions.push_back(TVector2(z_coord,x_coord));
    h_Selection[3].Fill(hits_after_cut_2[hit_i].WireCenter.Z(),x_coord);//,hits_after_cut_2[hit_i].Integral);
  }

  hits_after_cut_3 = hits_after_cut_2;
  Double_t residual = Fit2DLine(hit_positions,m,c);
  TF1 fit("traj_fit","x*[0] + [1]",0,150);
  fit.SetLineColor(1);
  fit.SetLineStyle(2);
  fit.SetLineWidth(2);
  fit.SetParameter(0,m);
  fit.SetParameter(1,c);
  fResiduals[cut_number] = residual;

  if (residual > 1.) return;

  cut_number++;
  fNHits[cut_number] = (int)hits_after_cut_3.size();
  fResiduals[cut_number] = residual;


  /*
  //Now we have made it to the end, accumulate the stats
  std::pair<Double_t,Double_t> line = std::make_pair(m,c);
  //Store the line for the two counter pairs
  int counterA_id = trigger_constituents[0].ID;
  fCounterToLineMap[counterA_id].push_back(line);
  int counterB_id = trigger_constituents[1].ID;
  fCounterToLineMap[counterB_id].push_back(line);
  */

  if (draw){
    TCanvas canvas("canvasKey");
    canvas.Divide(2,2);


    for (int i = 0; i < NCuts; i++){
      canvas.cd(i+1);
      h_Selection[i].Draw("colz");
      if (i==3) fit.Draw("same");
    }
    canvas.Update();
    canvas.WaitPrimitive();
  }

  //Fill the tree variables

  fNCounters = trigger_constituents.size();
  for (int i = 0; i < fNCounters; i++){
    fCounterID[i] = trigger_constituents[i].ID;
  }
  fNSelRecoHits = std::min((int)hits_after_cut_3.size(),kNMaxSelRecoHits);
  for (int i = 0; i < fNSelRecoHits; i++){
    fSelRecoHitStartTick[i] = hits_after_cut_3[i].StartTick;
    fSelRecoHitEndTick[i] = hits_after_cut_3[i].EndTick;
    fSelRecoHitPeakTime[i] = hits_after_cut_3[i].PeakTime;
    fSelRecoHitSigmaPeakTime[i] = hits_after_cut_3[i].SigmaPeakTime;
    fSelRecoHitRMS[i] = hits_after_cut_3[i].RMS;
    fSelRecoHitPeakAmplitude[i] = hits_after_cut_3[i].PeakAmplitude;
    fSelRecoHitSigmaPeakAmplitude[i] = hits_after_cut_3[i].SigmaPeakAmplitude;
    fSelRecoHitSummedADC[i] = hits_after_cut_3[i].SummedADC;
    fSelRecoHitIntegral[i] = hits_after_cut_3[i].Integral;
    fSelRecoHitSigmaIntegral[i] = hits_after_cut_3[i].SigmaIntegral;
    fSelRecoHitMultiplicity[i] = hits_after_cut_3[i].Multiplicity;
    fSelRecoHitLocalIndex[i] = hits_after_cut_3[i].LocalIndex;
    fSelRecoHitGoodnessOfFit[i] = hits_after_cut_3[i].GoodnessOfFit;
    fSelRecoHitDegreesOfFreedom[i] = hits_after_cut_3[i].DegreesOfFreedom;
    fSelRecoHitChannel[i] = hits_after_cut_3[i].Channel;
    fSelRecoHitView[i] = hits_after_cut_3[i].View;
    fSelRecoHitWireID[i] = hits_after_cut_3[i].WireID;
    fSelRecoHitPlaneID[i] = hits_after_cut_3[i].PlaneID;
    fSelRecoHitTPCID[i] = hits_after_cut_3[i].TPCID;
    fSelRecoHitIsValid[i] = hits_after_cut_3[i].IsValid;
    fSelRecoHitCryostatID[i] = hits_after_cut_3[i].CryostatID;
    fSelRecoHitWireCenterX[i] = hits_after_cut_3[i].WireCenter.X();
    fSelRecoHitWireCenterY[i] = hits_after_cut_3[i].WireCenter.Y();
    fSelRecoHitWireCenterZ[i] = hits_after_cut_3[i].WireCenter.Z();


  }
  fTree->Fill();
  return;
}

std::vector<AuxDet> SelectDiffusionTracks::ReconstructEWTrigger(const std::vector<AuxDet> &aux_dets){
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
    if (!((id >= CounterDefs::kTSUE0 && id <= CounterDefs::kTSUE9) || (id >= CounterDefs::kTSUW0 && id <= CounterDefs::kTSUW9))) continue;
    //Now check if the counter is within the time tolerance
    Int_t counter_time = aux_dets[i].Time;
    if (std::abs(trigger_time-counter_time) < time_tolerance){
      trigger_constituents.push_back(aux_dets[i]);
    }
    
  }

  return trigger_constituents;
}

Double_t SelectDiffusionTracks::GetT0FromCounters(const std::vector<AuxDet> &aux_dets){
  Double_t T0 = 0;
  if (aux_dets.size() == 0) return T0;

  for (unsigned int i = 0; i < aux_dets.size(); i++){
    T0 += (Double_t)aux_dets[i].Time;
  }

  T0 /= aux_dets.size();

  //double ptb_timing = 31.2;
  double ptb_timing = 15.6;

  return T0*ptb_timing/500.;
}

UInt_t SelectDiffusionTracks::NHitsOnWire(UInt_t channel_id, const std::vector<RecoHit> &reco_hits){
  Int_t NHits = 0;
  for (unsigned int i = 0; i < reco_hits.size(); i++){
    if (reco_hits[i].Channel == channel_id) NHits++;
  }

  return NHits;
}

Bool_t SelectDiffusionTracks::HitWithinCounterShadow(const RecoHit &hit, const std::vector<AuxDet> &aux_dets){

  //The coordinate system is (z,t)

  Double_t T0 = GetT0FromCounters(aux_dets);

  //Make the hit coordinate first
  //TVector2 point(hit.WireCenter.Z(),hit.PeakTime-T0);
  TVector2 point(hit.WireCenter.Z(),ConvertTicksToX(hit.PeakTime-T0,IsInShortDrift(hit)));

  //Now make the vector of points which correspond to the counter edges
  //Make a safety margin for the size of the counters
  double inflation = 1.1;
  std::vector<TVector2> counter_points;
  //assumes we have two counters here

  for (unsigned int i = 0; i < aux_dets.size(); i++){
    Int_t id = aux_dets[i].ID;
    double z = fCounterPositionsAndDimensions[id].first.Z();
    double x_up = fCounterPositionsAndDimensions[id].first.X() + (fCounterPositionsAndDimensions[id].second.second/2. * inflation);
    //TVector2 coords1(z,ConvertXToTicks(x_up));
    TVector2 coords1(z,x_up);


    double x_down = fCounterPositionsAndDimensions[id].first.X() - (fCounterPositionsAndDimensions[id].second.second/2. * inflation);
    //TVector2 coords2(z,ConvertXToTicks(x_down));
    TVector2 coords2(z,x_down);


    //Figure out the order to push them back
    if (i%2==0){
      counter_points.push_back(coords1);
      counter_points.push_back(coords2);
    }
    else {
      counter_points.push_back(coords2);
      counter_points.push_back(coords1);
    }
  }

  return PointInPolygon(point,counter_points);
}

Bool_t SelectDiffusionTracks::PointInPolygon(TVector2 point, const std::vector<TVector2> &polygon_points){

  bool c = false;

  unsigned int i, j, nvert = polygon_points.size();
  for(i = 0, j = nvert - 1; i < nvert; j = i++) {
      if( ( (polygon_points[i].Y() >= point.Y() ) != (polygon_points[j].Y() >= point.Y()) ) &&
                  (point.X() <= (polygon_points[j].X() - polygon_points[i].X()) * (point.Y() - polygon_points[i].Y()) / (polygon_points[j].Y() - polygon_points[i].Y()) + polygon_points[i].X())
                        )
        c = !c;
  }
  return c;
}

Int_t SelectDiffusionTracks::ConvertXToTicks(Double_t x){
  double drift_velocity = 0.109035;

  return (x/drift_velocity)/0.5;
}

Double_t SelectDiffusionTracks::ConvertTicksToX(Int_t t, Bool_t is_short_vol){
  Int_t plane_positions_ticks[4];
  plane_positions_ticks[0] = 0; //Z
  plane_positions_ticks[1] = 4; //V
  plane_positions_ticks[2] = 9; //U
  plane_positions_ticks[3] = 15; //G

  Double_t drift_velocity[4];
  drift_velocity[0] = 0.259/2;
  drift_velocity[1] = 0.192/2;
  drift_velocity[2] = 0.177/2;
  drift_velocity[3] = 0.109/2;

  Double_t x =0;
  if (t > plane_positions_ticks[0] && t <= plane_positions_ticks[1]){
    x = (t-plane_positions_ticks[0])*drift_velocity[0];
  }
  else if (t > plane_positions_ticks[1] && t <= plane_positions_ticks[2]){
    x = (plane_positions_ticks[1]-plane_positions_ticks[0])*drift_velocity[0] + (t-plane_positions_ticks[1])*drift_velocity[1];
  }
  else if (t > plane_positions_ticks[2] && t <= plane_positions_ticks[3]){
    x = (plane_positions_ticks[1]-plane_positions_ticks[0])*drift_velocity[0] + (plane_positions_ticks[2]-plane_positions_ticks[1])*drift_velocity[1] + (t - plane_positions_ticks[2])*drift_velocity[2];
  }
  else{
    x = (plane_positions_ticks[1] -plane_positions_ticks[0])*drift_velocity[0] + (plane_positions_ticks[2]-plane_positions_ticks[1])*drift_velocity[1] + (plane_positions_ticks[3] - plane_positions_ticks[2])*drift_velocity[2] + (t - plane_positions_ticks[3])*drift_velocity[3];
  }

  if (is_short_vol){
    x=-1.*x - 6.031; //subtract off plane gap
  }
  return x;
}

Bool_t SelectDiffusionTracks::IsInShortDrift(const RecoHit &hit){
  bool flag = false;
  Int_t tpc_id = hit.TPCID;
  if(tpc_id % 2 ==0) flag = true;

  return flag;
}

Double_t SelectDiffusionTracks::Fit2DLine(const std::vector<TVector2> &points, Double_t &m, Double_t &c){

  //Do this with ROOT's matrices
  unsigned int NPoints = points.size();
  TMatrixD X(NPoints,2);
  TMatrixD Y(NPoints,1);

  for (unsigned int i = 0; i < NPoints; i++){
    X[i][0] = points[i].X();
    X[i][1] = 1;
    Y[i][0] = points[i].Y();
  }

  //We need the transpose of X
  TMatrixD X_T(2,NPoints);
  X_T.Transpose(X);

  //We also need the inverse of X_T*X
  TMatrixD X_T_x_X_inv = X_T*X;
  X_T_x_X_inv.Invert();


  //The final equation for the params is (X^T*X)^-1 * X^T*Y
  TMatrixD params = X_T_x_X_inv * X_T * Y;

  m = params[0][0];
  c = params[1][0];

  //Now calculate what the residual is
  TMatrixD epsilon = Y - X*params;
  TMatrixD epsilon_T(1, NPoints);
  epsilon_T.Transpose(epsilon);

  Double_t residual = (epsilon_T*epsilon)[0][0]/(NPoints-2);
  return residual;
}

void SelectDiffusionTracks::Reset(){
  int kDefDouble = -999999.;
  int kDefInt = -999999;

  for (int i = 0; i < NCuts; i++){
    fResiduals[i] = kDefDouble;
    fNHits[i] = 0;
  }
  fNCounters = 0;
  for (int i = 0; i < kNMaxCounters; i++){
    fCounterID[i] = kDefInt;
  }
  fT0 = kDefDouble;

  for (int i = 0; i < kNMaxSelRecoHits; i++){
    fSelRecoHitTrackID[i] = kDefInt;
    fSelRecoHitStartTick[i] = kDefInt;
    fSelRecoHitEndTick[i] = kDefInt;
    fSelRecoHitPeakTime[i] = kDefDouble;
    fSelRecoHitSigmaPeakTime[i] = kDefDouble;
    fSelRecoHitRMS[i] = kDefDouble;
    fSelRecoHitPeakAmplitude[i] = kDefDouble;
    fSelRecoHitSigmaPeakAmplitude[i] = kDefDouble;
    fSelRecoHitSummedADC[i] = kDefDouble;
    fSelRecoHitIntegral[i] = kDefDouble;
    fSelRecoHitSigmaIntegral[i] = kDefDouble;
    fSelRecoHitMultiplicity[i] = kDefInt;
    fSelRecoHitLocalIndex[i] = kDefInt;
    fSelRecoHitGoodnessOfFit[i] = kDefDouble;
    fSelRecoHitDegreesOfFreedom[i] = kDefInt;
    fSelRecoHitChannel[i] = kDefInt;
    fSelRecoHitView[i] = kDefInt;
    fSelRecoHitWireID[i] = kDefInt;
    fSelRecoHitPlaneID[i] = kDefInt;
    fSelRecoHitTPCID[i] = kDefInt;
    fSelRecoHitIsValid[i] = 0;
    fSelRecoHitCryostatID[i] = kDefInt;
    fSelRecoHitWireCenterX[i] = kDefDouble;
    fSelRecoHitWireCenterY[i] = kDefDouble;
    fSelRecoHitWireCenterZ[i] = kDefDouble;


  }
  return;
}
