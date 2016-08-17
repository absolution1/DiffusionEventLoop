//STL
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
//ROOT
#include "TString.h"
#include "TObjArray.h"
#include "TObjString.h"
#include "TPRegexp.h"
//CUSTOM
#include "FitCounterPositions.h"

int main (int argc, char ** argv){


  std::string input_file = "input_file.root";
  int c;
  int n;

  while ((c = getopt (argc, argv, "i:n:")) != -1){
    switch (c){
      case 'i':
        input_file = optarg;
        break;
      case 'n':
        n = atoi(optarg);
    }
  }
  /*

  EventLoop loop;

  std::string line;
  std::ifstream file(input_file);

  if (file.is_open()){
    while (getline(file,line)){
      std::vector<TString> tmpStrings;

      loop.AddFile(line);
    }
  }

  loop.RunAndGun();
  */

  FitCounterPositions fitter(input_file,n);
  fitter.Run();
  return 0;
}
