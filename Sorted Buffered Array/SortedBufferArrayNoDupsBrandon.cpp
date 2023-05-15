// File:    SortedBufferArrayNoDupsBrandon.cpp
// Project: CSIS3400 Assignment 4 
// Author:  Brandon Catalano 
// History:  1.3 Sept 27th, 2022
#include "SortedBufferArrayNoDupsBrandon.h"
#include <iostream>
using namespace std;



//constructors

SortedBufferArrayNoDupsBrandon::SortedBufferArrayNoDupsBrandon()
{
	BUFFER_SIZE = 12;
	numberOfElements = 0;
	intArray = new int[BUFFER_SIZE];
}

SortedBufferArrayNoDupsBrandon::SortedBufferArrayNoDupsBrandon(int buffer)
{
	BUFFER_SIZE = buffer;
	numberOfElements = 0;
	intArray = new int[BUFFER_SIZE];
}

//Insertion operation that only inserts if the value is not a duplicate of existing value in IntArray and there's room in the array.
bool SortedBufferArrayNoDupsBrandon::insert(int insInpy)
{
	if (numberOfElements < BUFFER_SIZE) {
		if (!find(insInpy)) {
			intArray[numberOfElements] = insInpy;
			numberOfElements++;
			//cout << "Quiet bubble sort running: ";

			//Checks if list is sorted. If not, this function then starts a bubble sort.
			quietCheckSort();
			return true;
			
		}
		else
		{
			cout << endl << "Cannot input number : " << insInpy << ". Number is a duplicate."<<endl;
			return false;
		}
	}
	cout << endl << "Cannot input number: " << insInpy << ". List is full" << endl;
	return false;
}





