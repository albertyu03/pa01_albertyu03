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


  //the game: your turn -> iterate through cards
  //Alice --> least to greatest
  //Bob --> greatest to least
  //pick first matching card and then remove (and print card)
  //swap turns
  //print final hands
  int curTurn = 0; //0 for alice, 1 for bob
  while(alice.count() != 0 && bob.count() != 0) {
    bool found = false;
    if(curTurn == 0) { //alice's turn
      int cValue = alice.getLeast();
      
      for(int i = 0; i < alice.count(); i++) {
        if(bob.contains(cValue)) {
          found = true;
          bob.remove(cValue);
          alice.remove(cValue);
          cout << "Alice picked matching card " << ConvCardStr(cValue) << endl;
          break;
        }
        cValue = alice.getSuccessor(cValue);
      }
    } /*else {
      
    }*/
    if(found == false) { //no matches found
      //print
    }
  }
  return 0;
}
