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
#include "eventLoop.h"

int main (int argc, char ** argv){


  TString input_file = "input_file.root";
  int c;

  while ((c = getopt (argc, argv, "qpwi:")) != -1){
    switch (c){
      case 'i':
        input_file = optarg;
        break;
    }
  }

  EventLoop loop;

  std::string line;
  std::ifstream file(input_file);

  //std::vector<std::vector<TString> > file_names_and_labels;
  int file_count = 0;
  int threshold = 10;
  if (file.is_open()){
    while (getline(file,line)){
      std::vector<TString> tmpStrings;

      if (file_count%threshold==0 && file_count > 0) std::cout<<"Adding file " << file_count << std::endl;
      if (file_count%100==0 && file_count > 0 && file_count/threshold==threshold)threshold*=10;
      loop.RunAndGun(line);
      file_count++;
    }
  }
  std::cout<<"Finished adding " << file_count << " files"<<std::endl;

  //loop.RunAndGun();

  return 0;
}
