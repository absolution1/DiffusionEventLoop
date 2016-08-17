#include "FitCounterPositions.h"

FitCounterPositions::FitCounterPositions::FitCounterPositions(std::string input_file, int counter_number){
  fInputStream.open(input_file);
  fCounterNumber = counter_number;

  bool is_data = true;

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



  for (std::map<Int_t,std::pair<TVector3,std::pair<double,double> > >::iterator it = fCounterPositionsAndDimensions.begin(); it != fCounterPositionsAndDimensions.end(); it++){
    (*it).second.second.first = 2.*0.475;
    //(*it).second.second.second = 32.56;
    (*it).second.second.second = 27.06;
    if (is_data){
      Int_t id = (*it).first;
      Double_t x_correction = fEWCounterPosCorrection[id];
      (*it).second.first.SetX(x_correction);
    }
  }



}



void FitCounterPositions::AnalyzeCounter(){
  //Get the nominal center of the counters
  double x_center = fCounterPositionsAndDimensions[fCounterNumber].first.X();
  double z_center = fCounterPositionsAndDimensions[fCounterNumber].first.Z();

  double x_min = x_center-40.;
  double x_max = x_center+40.;
  int Nx_steps = 1000;
  double x_step = (x_max-x_min)/Nx_steps;
  double z_min = z_center-40.;
  double z_max = z_center+40.;
  int Nz_steps = 1000;
  double z_step = (z_max-z_min)/Nz_steps;


  int NTotal = Nx_steps*Nz_steps;
  //The output
  TH2F *hist = new TH2F("results","",Nz_steps,z_min-z_step/2.,z_max-z_step/2.,Nx_steps,x_min-x_step/2.,x_max-x_step/2.); 
  hist->GetXaxis()->SetTitle("Counter centre Z coord (cm)");
  hist->GetYaxis()->SetTitle("Counter centre X coord (cm)");
  hist->GetZaxis()->SetTitle("No. track intersections");


  int curr_counter_assessment = 0;
  std::cout<<"Number of counter positions to assess: " << NTotal << std::endl;
  for (double x = x_min; x < x_max; x+=x_step){
    for (double z = z_min; z < z_max; z+=z_step){
      if (curr_counter_assessment > 0 && curr_counter_assessment%10000==0) std::cout<<"Assessing counter " << curr_counter_assessment<<"/"<<NTotal<<std::endl;
      std::vector<TVector2> counter_coords = GetCounterBoundingBox(z,x);
      int NIntersections = 0;
      double m, c;
      while (fInputStream.good()){
        LoadLine(m,c);
        if (!fInputStream.good()) break;
        //For the ray collision algorithm, it expects there to be two points on the line so calculate these
        double z_1 = -10000.;
        double x_1 = m*z_1 + c;
        double z_2 = 10000.;
        double x_2 = m*z_2 + c;
        bool success = SegmentIntersectRectangle(counter_coords[0].X(),counter_coords[0].Y(),counter_coords[1].X(),counter_coords[1].Y(),z_1,x_1,z_2,x_2);
        if (success) NIntersections++;
      }
      //std::cout<<"z: " << z << " x: " << x << " NInt: " << NIntersections << std::endl;
      hist->Fill(z,x,NIntersections);

      fInputStream.clear();
      fInputStream.seekg(0,fInputStream.beg);

      curr_counter_assessment++;
    }
  }

  TString file_name = Form("results_for_counter_%i.root",fCounterNumber);
  TFile *file = new TFile(file_name,"RECREATE");
  hist->Write();
  file->Close();

  return;
}

void FitCounterPositions::LoadLine(double &m, double &c){
  fInputStream >> m >> c;
  return;

}

void FitCounterPositions::Run(){
  AnalyzeCounter();
  return;
}

std::vector<TVector2> FitCounterPositions::GetCounterBoundingBox(double z_center, double x_center){
  //Get counter dimensions
  double z_dim = fCounterPositionsAndDimensions[fCounterNumber].second.first;
  double x_dim = fCounterPositionsAndDimensions[fCounterNumber].second.second;

  std::vector<TVector2> coords;
  coords.push_back(TVector2(z_center-z_dim/2.,x_center-x_dim/2.));
  coords.push_back(TVector2(z_center+z_dim/2.,x_center+x_dim/2.));

  return coords;

}

bool FitCounterPositions::SegmentIntersectRectangle(double a_rectangleMinX,
                                 double a_rectangleMinY,
                                 double a_rectangleMaxX,
                                 double a_rectangleMaxY,
                                 double a_p1x,
                                 double a_p1y,
                                 double a_p2x,
                                 double a_p2y)
  {
    // Find min and max X for the segment

    double minX = a_p1x;
    double maxX = a_p2x;

    if(a_p1x > a_p2x)
    {
      minX = a_p2x;
      maxX = a_p1x;
    }

    // Find the intersection of the segment's and rectangle's x-projections

    if(maxX > a_rectangleMaxX)
    {
      maxX = a_rectangleMaxX;
    }

    if(minX < a_rectangleMinX)
    {
      minX = a_rectangleMinX;
    }

    if(minX > maxX) // If their projections do not intersect return false
    {
      return false;
    }

    // Find corresponding min and max Y for min and max X we found before

    double minY = a_p1y;
    double maxY = a_p2y;

    double dx = a_p2x - a_p1x;

    if(std::abs(dx) > 0.0000001)
    {
      double a = (a_p2y - a_p1y) / dx;
      double b = a_p1y - a * a_p1x;
      minY = a * minX + b;
      maxY = a * maxX + b;
    }

    if(minY > maxY)
    {
      double tmp = maxY;
      maxY = minY;
      minY = tmp;
    }

    // Find the intersection of the segment's and rectangle's y-projections

    if(maxY > a_rectangleMaxY)
    {
      maxY = a_rectangleMaxY;
    }

    if(minY < a_rectangleMinY)
    {
      minY = a_rectangleMinY;
    }

    if(minY > maxY) // If Y-projections do not intersect return false
    {
      return false;
    }

    return true;
  }

void FitCounterPositions::Test(){
  std::cout<<"SUCCESS"<<std::endl;
  return;
}
