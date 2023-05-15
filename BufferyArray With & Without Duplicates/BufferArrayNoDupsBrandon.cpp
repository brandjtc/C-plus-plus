// File:    BufferArrayNoDupsBrandon.cpp
// Project: CSIS3400 Assignment 3 
// Author:  Brandon Catalano 
// History:  1.1 Sept 10th, 2022
#include "BufferArrayNoDupsBrandon.h"
#include <iostream>
using namespace std;



//constructors

BufferArrayNoDupsBrandon::BufferArrayNoDupsBrandon()
{
	BUFFER_SIZE = 12;
	numberOfElements = 0;
	intArray = new int[BUFFER_SIZE];
}

BufferArrayNoDupsBrandon::BufferArrayNoDupsBrandon(int buffer)
{
	BUFFER_SIZE = buffer;
	numberOfElements = 0;
	intArray = new int[BUFFER_SIZE];
}
/*
int BufferArrayBrandon::indexOf(int target)
{
	//for loop that allows removal and find functions to find the array of a target number, if present.
	for (int i = 0; i < numberOfElements; i++) {
		if (intArray[i] == target)
			return i;
	}
	//-1 is returned on failure.
	return -1;
}
*/

//Accessors

//Operations
int BufferArrayNoDupsBrandon::indexOf(int target)
{
	for (int i = 0; i < numberOfElements; i++) {
		if (intArray[i] == target)
			return i;
	}
	return -1;

}

//Insertion operation that only inserts if the value is not a duplicate of existing value in IntArray and there's room in the array.
bool BufferArrayNoDupsBrandon::insert(int insInpy)
{
	if (numberOfElements < BUFFER_SIZE) {
		if (!find(insInpy)) {
			intArray[numberOfElements] = insInpy;
			//cout << "{" << intArray[numberOfElements] << "}";
			numberOfElements++;
			return true;
		}
	}
	return false;
}

bool BufferArrayNoDupsBrandon::find(int findInpy)
{
	if (indexOf(findInpy) > -1)
		return true;
	else
		return false;
}

void BufferArrayNoDupsBrandon::display()
{
	cout << "{ ";
	for (int i = 0; i < numberOfElements; i++)
	{
		cout<<intArray[i];
		if (i < numberOfElements - 1)
			cout << ", ";
	}
	cout << " }" << endl<<endl;

}

bool BufferArrayNoDupsBrandon::stableRemove(int staRemInpy)
{
	if (find(staRemInpy))
	{
		for (int i = indexOf(staRemInpy); i < numberOfElements; i++)
		{
			intArray[i] = intArray[i + 1];
		}
		
		numberOfElements--;
		return true;
	}
	else
		return false;
}

bool BufferArrayNoDupsBrandon::quickRemove(int remInpy)
{
	if (find(remInpy)) {
		intArray[indexOf(remInpy)] = intArray[numberOfElements - 1];
		numberOfElements--;
		return true;
	}
	else
		return false;
}




