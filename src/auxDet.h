#ifndef AUXDET_H_SEEN
#define AUXDET_H_SEEN

class AuxDet{
  public:
    AuxDet(Int_t AuxDetID,
        Int_t AuxDetTime)
      :
        ID(AuxDetID),
        Time(AuxDetTime) {};

    Int_t ID;
    Int_t Time;
};
#endif
