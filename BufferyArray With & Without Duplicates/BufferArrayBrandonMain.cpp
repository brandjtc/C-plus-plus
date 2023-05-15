// File:    BufferArrayBrandonMain.cpp
// Project: CSIS3400 Assignment 2 
// Author:  Brandon Catalano 
// History:  1.4 Sept 10th, 2022
#include "BufferArrayBrandon.h"
#include "BufferArrayNoDupsBrandon.h"
#include "BufferArrayWithDupsBrandon.h"
#include <iostream>
using namespace std;


int main()
{
	BufferArrayBrandon arr;
	arr.display();
	arr.insert(2);
	arr.display();
	arr.insert(4);
	arr.insert(3);
	arr.insert(1);
	arr.insert(422);
	arr.insert(322);
	arr.insert(122);
	arr.display();
	arr.insert(6);
	arr.display();
	arr.insert(601);
	arr.display();
	arr.find(1);
	arr.find(100);
	arr.remove(3);
	cout << "After removing 3" << endl;
	arr.display();
	arr.remove(100);
	cout << "After removing 100" << endl;
	arr.display();
	arr.remove(2);
	cout << "After removing 2" << endl;
	arr.display();
	arr.insert(3);
	arr.display();

	arr.stableRemove(4);
	cout << "After stable removing 4" << endl;
	arr.display();

	arr.stableRemove(3);
	cout << "After stable removing 3" << endl;
	arr.display();
	//Test Case for stable remove

	BufferArrayBrandon stableTest = BufferArrayBrandon();
	for (int i = 0; i < 12; i++)
		stableTest.insert(i);
	stableTest.display();

	stableTest.stableRemove(4);

	stableTest.display();

	stableTest.stableRemove(7);

	stableTest.display();
	
	stableTest.stableRemove(2);

	stableTest.display();
	

	//Other tests
	string ln = "\n\n";
	BufferArrayBrandon bufferTest = BufferArrayBrandon();
	bufferTest.insert(220);
	bufferTest.insert(24);
	bufferTest.insert(43.5);
	bufferTest.insert(-24);
	int i = 0;
	while (i < 10)
		//intentionally goes over buffer value of 12
	{
		bufferTest.insert(10);
		i++;
	}

	bufferTest.display();
	cout << ln;
	cout << bufferTest.find(3) << ln;
	cout<< bufferTest.find(220)<<ln;
	cout<< bufferTest.find(10)<<ln;

	bufferTest.remove(3);
	bufferTest.remove(43.5);
	bufferTest.display();

	
	cout << endl << "No dups" << endl;

	BufferArrayNoDupsBrandon buffBro = BufferArrayNoDupsBrandon(13);
	//No dups test for insertion
	buffBro.insert(22);
	buffBro.display();
	buffBro.insert(22);
	buffBro.display();
	buffBro.insert(22.5);
	buffBro.display();
	//Doublechecking re-used functions still work.
	for (int i = 0; i < 14; ++i)
	{
		buffBro.insert(i);
	}
	buffBro.display();
	buffBro.quickRemove(2);
	buffBro.display();
	buffBro.stableRemove(10);
	buffBro.display();

	cout <<endl<< "With dups" << endl;

	BufferArrayWithDupsBrandon dupeBro = BufferArrayWithDupsBrandon(19);
	dupeBro.insert(12);
	dupeBro.insert(8);
	dupeBro.insert(1);
	dupeBro.insert(43);
	dupeBro.insert(42);
	dupeBro.insert(1);
	dupeBro.insert(40);
	dupeBro.insert(12);
	dupeBro.insert(12);
	dupeBro.insert(99);
	dupeBro.insert(2);
	dupeBro.display();
	dupeBro.quickRemoveAll(12);
	dupeBro.display();

	cout << endl << "Default constructor with dups:" << endl;
	BufferArrayWithDupsBrandon dupeBroSequel = BufferArrayWithDupsBrandon();
	for (int i = 0; i<5;i++)
	{
		dupeBroSequel.insert(i);
	}
	dupeBroSequel.insert(28);
	dupeBroSequel.insert(3);
	dupeBroSequel.insert(13);

	for (int i = 0; i < 10; i++)
	{
		dupeBroSequel.insert(i);
	}

	dupeBroSequel.display();
	dupeBroSequel.stableRemoveAll(1);
	dupeBroSequel.display();
	dupeBroSequel.stableRemoveAll(3);
	dupeBroSequel.display();

	cout << "Zero test" << endl;

	BufferArrayNoDupsBrandon noDupCero = BufferArrayNoDupsBrandon(0);
	noDupCero.insert(1);
	noDupCero.remove(0);
	noDupCero.display();
	noDupCero.stableRemove(0);

	BufferArrayWithDupsBrandon yesDupCero = BufferArrayWithDupsBrandon(0);
	yesDupCero.insert(1);
	yesDupCero.quickRemove(0);
	yesDupCero.stableRemove(0);
	yesDupCero.quickRemoveAll(0);
	yesDupCero.stableRemoveAll(0);
	noDupCero.display();

	cout << "Testing BufferArrayNoDupsBrandon" << endl;
	BufferArrayNoDupsBrandon rosterNoDups; //creates an "instance" of a class
	rosterNoDups.insert(3);
	rosterNoDups.insert(2);
	rosterNoDups.insert(3);
	rosterNoDups.insert(3);
	rosterNoDups.insert(4);
	rosterNoDups.display();
	cout << rosterNoDups.find(3) << endl;
	rosterNoDups.quickRemove(2);
	rosterNoDups.display();
	rosterNoDups.stableRemove(3);
	rosterNoDups.display();
	cout << "Testing BufferArrayWithDupsBrandon" << endl;
	BufferArrayWithDupsBrandon rosterWithDups; //creates an "instance" of a class
	rosterWithDups.insert(1);
	rosterWithDups.insert(2);
	rosterWithDups.insert(4);
	rosterWithDups.insert(3);
	rosterWithDups.insert(3);
	rosterWithDups.insert(4);
	rosterWithDups.display();
	cout << rosterWithDups.find(3) << endl;
	rosterWithDups.quickRemove(2);
	rosterWithDups.display();
	rosterWithDups.quickRemoveAll(4);
	rosterWithDups.display();
	rosterWithDups.stableRemove(1);
	rosterWithDups.display();

	return 0;
}