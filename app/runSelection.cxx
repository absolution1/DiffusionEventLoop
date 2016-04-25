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
  if (file.is_open()){
    while (getline(file,line)){
      std::vector<TString> tmpStrings;

      loop.AddFile(line);
      /*
      std::stringstream strstr(line);
      std::string word;

      std::vector<TString> file_name_and_label;
      while (getline(strstr,word,',')){
        file_name_and_label.push_back(word);
      }
      file_names_and_labels.push_back(file_name_and_label);
      */
    }
  }

  loop.RunAndGun();

  return 0;
}
