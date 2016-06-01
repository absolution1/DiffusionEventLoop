#include "auxDetFactory.h"

AuxDetFactory::AuxDetFactory::AuxDetFactory(TTree *tree){
  tree->SetBranchAddress("NCounters",&NCounters);
  tree->SetBranchAddress("CounterID",&CounterID);
  tree->SetBranchAddress("CounterTime",&CounterTime);
}

std::vector<AuxDet> AuxDetFactory::GetAuxDetVector(){
  std::vector<AuxDet> aux_dets;
  for (UInt_t i = 0; i < NCounters; i++){

    AuxDet aux_det(CounterID[i],
        CounterTime[i]);
    aux_dets.push_back(aux_det);
  }
  return aux_dets;
}
