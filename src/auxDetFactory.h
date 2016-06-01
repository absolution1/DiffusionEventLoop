//STL
#include <iostream>
#include <vector>
#include <map>
//ROOT
#include "TTree.h"
//CUSTOM
#include "definitions.h"
#include "auxDet.h"

class AuxDetFactory{
  public:
    AuxDetFactory(TTree *tree);
    std::vector<AuxDet> GetAuxDetVector();

  private:
    UInt_t NCounters;
    Int_t CounterID[GlobalDefs::kNMaxCounters];
    Int_t CounterTime[GlobalDefs::kNMaxCounters];
};


