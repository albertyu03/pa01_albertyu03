#include <iostream>
#include "cards.h"
using namespace std;


int main() {
	Cards n;
	n.insert(1);
	n.insert(2);
	n.insert(4);
	n.insert(3);

	//tests
	//can't test "find" as getNodeFor is private, however have tested inside of cards.cpp previously (removed for gradescope)
	cout << "should equal 4: " << n.count() << endl; //test insert
	cout << "should equal 3: " << n.getSuccessor(2) << endl; //test success
	cout << "should equal 1: " << n.getPredecessor(2) << endl; //test predecess
	n.remove(2);
	cout << "should equal 3: " << n.count() << endl; // test remove

}
