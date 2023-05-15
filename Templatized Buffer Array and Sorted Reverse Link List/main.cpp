// File:    SortedRevLLStrBrandon.cpp
// Project: CSIS3400 Assignment 5 
// Author:  Brandon Catalano 
// History:  1.0 Sept 30th, 2022
#include "SortedRevLLStrBrandon.h"
#include "BufferArrayBrandonTempl.h"
#include <iostream>
using namespace std;
string ln = "\n\n";
int main()
{

	//Testing that strings can be indexed like arrays. They can.
	//string test = "0123456";
	//cout << test[0];
	char yesn;
		cout << "Test Buffer Array Template first?" << ln;
		cout << "y/n: ";
		cin >> yesn;
	if (yesn == 'y') {
		cout << ln;

		BufferArrayBrandonTempl<int> anyNum;

		anyNum.insert(12);
		anyNum.insert(22);
		anyNum.insert(23);
		cout << "Is 22 in the array?" << ln;
		anyNum.find(22);
		cout << "Is 0 in the array?" << ln;
		anyNum.find(0);
		anyNum.display();
		anyNum.remove(22);
		anyNum.display();
		cout << ln;
		cout << "String test: ";
		cout << ln;
		BufferArrayBrandonTempl<string>anyStr;
		anyStr.insert("Peter picked a pickled pepper while she sold seashells by the seashore.");
		anyStr.insert("How much wood could a woodchuck chuck if a wood chuck could chuck wood?");
		anyStr.display();
		anyStr.insert("beans, brother");
		anyStr.display();
		cout << "No more seashell" << ln;
		anyStr.remove("Peter picked a pickled pepper while she sold seashells by the seashore.");
		anyStr.display();
		cout << ln << "Is \"bruh\" in the array?" << ln;

		anyStr.find("bruh");

		cout << ln << "Is \"beans, brother\" in the array?" << ln;
		anyStr.find("beans, brother");
	}

	sortedList h = sortedList();
	h.putItem("bruh");
	h.putItem("bruh2");
	h.putItem("aruh");
	h.putItem("cruh");
	h.putItem("coink");
	h.printList();
	cout<<h.findWordStartWith('c')<<ln;
	cout << h.findWordStartWith('b') << ln;
	cout << h.findWordStartWith('f') << ln;

	cout << "Removing middle node:"<<endl;
	printf(h.removeMiddleNode()? "Middle Node successfully removed": "Middle Node could not be removed");
	cout << ln;
	h.printList();

	cout << "Removing middle node:"<<endl;
	printf(h.removeMiddleNode() ? "Middle Node successfully removed" : "Middle Node could not be removed");
	cout << ln;
	h.printList();
	
	cout << endl;

	cout << "Backwards print:" << endl;
	h.displayListBackwards();

	cout << "Removing middle node:" << endl;
	printf(h.removeMiddleNode() ? "Middle Node successfully removed" : "Middle Node could not be removed");
	cout << ln;
	h.printList();
	cout << "Removing middle node:" << endl;
	printf(h.removeMiddleNode() ? "Middle Node successfully removed" : "Middle Node could not be removed");
	cout << ln;
	h.printList();
	cout << "Removing middle node:" << endl;
	printf(h.removeMiddleNode() ? "Middle Node successfully removed" : "Middle Node could not be removed");
	cout << ln;


	return 0;
}