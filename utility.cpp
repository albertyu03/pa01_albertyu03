#include <iostream>
#include <map>
#include <string>
#include "cards.h"
#include "utility.h"
using namespace std;


int ConvStrCard(string str) {
  char a = str.at(0); //suit
  char b = str.at(2); //value
  if(str.length() == 4) {
    b = 'z'; //placeholder to signify 10
  }

  int cValue = 0;
  map<char, int> suits{ {'c', 1}, {'d', 2}, {'s', 3}, {'h', 4} };
  map<char, int>::iterator i;
  for(i = suits.begin(); i != suits.end(); i++) {
    if(a == i->first) {
      cValue = i->second * 100;
    }
  }
  map<char, int> values{ {'a', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'j', 11}, {'q', 12}, {'k', 13} };
  bool found = false;
  for(i = values.begin(); i != values.end(); i++) {
    if(b == i->first) {
      cValue += i->second;
      found = true;
    }
  }
  if(!found) {
    cValue += 10;
  }
  return cValue;
}


string ConvCardStr(int value) {
  int suit = value / 100;
  int num = value % 100;
  string resultCard = "";
  map<char, int> suits{ {'c', 1}, {'d', 2}, {'s', 3}, {'h', 4} };
  map<char, int>::iterator i;
  for(i = suits.begin(); i != suits.end(); i++) {
    if(suit == i->second) {
      resultCard += i->first;
    }
  }
  map<string, int> values{ {"a", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10}, {"j", 11}, {"q", 12}, {"k", 13} };
  map<string, int>::iterator j;
  for(j = values.begin(); j != values.end(); j++) {
    if(num == j->second) {
      resultCard += " " + j->first;
    }
  }

  return resultCard;
}
