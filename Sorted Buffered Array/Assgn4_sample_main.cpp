// File: Assgn4_sample_main.cpp
// Project: CSIS3400 Assignment 4 
// Author:  Brandon Catalano 
// History:  1.3 Sept 27th, 2022
#include <iostream>
using namespace std;
#include "SortedBufferArrayNoDupsBrandon.h"
#include "SortedBufferArrayWithDupsBrandon.h"

int main()
{
	SortedBufferArrayNoDupsBrandon arr;

	arr.insert(2); 
	arr.insert(4);
	arr.insert(3);
	arr.insert(1);
	arr.display();
	arr.insert(3);
	arr.display();
	cout<<endl<<arr.find(1)<<endl;
	arr.stableRemove(3);
	arr.display();

	SortedBufferArrayWithDupsBrandon buf;
	buf.insert(2);
	buf.insert(4);
	buf.insert(2);
	buf.insert(3);
	buf.insert(4);
	buf.insert(1);
	buf.display();
	int fA = buf.findAll(2);
	cout <<endl<< "2 count = " << fA << endl;
	buf.stableRemoveAll(2);
	buf.display();
	cout << endl<<"4 is being removed now"<<endl;
	buf.stableRemoveAll(4);
	buf.display();
	cout << endl << "Number at end of list test. 1 and 3 have been removed."<<endl;
	buf.quickRemove(3);
	buf.quickRemove(1);
	buf.display();
	buf.insert(5);
	buf.insert(5);
	buf.insert(5);
	buf.insert(5);
	buf.insert(5);
	buf.insert(5);
	buf.insert(5);
	buf.insert(5);
	buf.insert(5);
	buf.insert(5);
	buf.insert(5);
	buf.insert(5);
	buf.insert(5);
	buf.insert(5);
	buf.stableRemoveAll(5);
	buf.display();

	return 0;
}