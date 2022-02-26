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
  int curTurn = 1; //0 for alice, 1 for bob
  while(alice.count() != 0 && bob.count() != 0) {
    bool found = false;
    if(curTurn == 1) { //alice's turn
      int cValue = alice.getLeast();
      for(int i = 0; i < alice.count(); i++) { // iterate through hand count
	if(bob.contains(cValue)) {
          found = true;
          bob.remove(cValue);
          alice.remove(cValue);
          cout << "Alice picked matching card " << ConvCardStr(cValue) << endl;
          break;
        }
        cValue = alice.getSuccessor(cValue);
      }
    } else { // bob's turn
      int cValue = bob.getGreatest();

      for(int i = 0; i < bob.count(); i++) {
        if(alice.contains(cValue)) {
          found = true;
          bob.remove(cValue);
          alice.remove(cValue);
          cout << "Bob picked matching card " << ConvCardStr(cValue) << endl;
          break;
        }
        cValue = bob.getPredecessor(cValue);
      }
    }
    curTurn = curTurn * (-1); // swap turns
    if(found == false) { //no matches found --> game is over
	break;
    }
    
  }
  //game over: print both hands
  
  cout << endl << "Alice's cards:" << endl;
  alice.printInOrder();
  cout << endl << "Bob's cards:" << endl;
  bob.printInOrder();

  return 0;
}
