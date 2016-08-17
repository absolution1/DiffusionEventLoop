//STL
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
//ROOT
#include "TVector3.h"
#include "TVector2.h"
#include "TFile.h"
#include "TH2F.h"
#include "TString.h"
//CUSTOM

class FitCounterPositions{
  public:
    FitCounterPositions(){};
    FitCounterPositions(std::string file_name, int counter_number);

    void Run();



    void Test();
  private:

    void LoadLine(double &m, double &c);
    void AnalyzeCounter();

    bool SegmentIntersectRectangle(double a_rectangleMinX,
                                     double a_rectangleMinY,
                                     double a_rectangleMaxX,
                                     double a_rectangleMaxY,
                                     double a_p1x,
                                     double a_p1y,
                                     double a_p2x,
                                     double a_p2y);

    std::vector<TVector2> GetCounterBoundingBox(double z_center, double x_center);
    std::ifstream fInputStream;
    int fCounterNumber;

    std::map<Int_t,std::pair<TVector3,std::pair<double,double> > > fCounterPositionsAndDimensions;
    std::map<int,double> fEWCounterPosCorrection;

};
