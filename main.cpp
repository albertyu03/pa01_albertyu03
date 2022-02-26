#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"
#include "utility.h"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;
  
  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  //******************own code starts here
  Cards alice, bob;
  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
	  int cConv = ConvStrCard(line);
    alice.insert(cConv);
  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){
    int cConv = ConvStrCard(line);
    bob.insert(cConv);
  }
  cardFile2.close();
  cout << "passed!" << endl; 
  
  return 0;
}
