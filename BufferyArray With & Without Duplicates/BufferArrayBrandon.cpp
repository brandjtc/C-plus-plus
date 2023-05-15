// File:    BufferArrayBrandon.cpp
// Project: CSIS3400 Assignment 2 
// Author:  Brandon Catalano 
// History:  1.1 Sept 3rd, 2022

#include "BufferArrayBrandon.h"
#include <iostream>

using namespace std;
//Used to doublespace when printing for readability
string ln = "\n\n";

int BufferArrayBrandon::indexOf(int target)
{
	//for loop that allows removal and find functions to find the array of a target number, if present.
	for (int i = 0; i < numberOfElements; i++)
	{
		if (intArray[i] == target)
			//i, the index of the target value, is returned on success.
			return i;
	}
	//-1 is returned on failure.
	return -1;
}
//No arg constructor using buffer size for array length.
BufferArrayBrandon::BufferArrayBrandon()
{
	intArray = new int[BUFFER_SIZE];
	numberOfElements = 0;
}

int BufferArrayBrandon::getBUFFER_SIZE()
{
	return BUFFER_SIZE;
}

int BufferArrayBrandon::getNumberOfElements()
{
	return numberOfElements;
}


//Insertion function for intArray
bool BufferArrayBrandon::insert(int inpy)
{
	//Adds to end of array if number of elements is less than hte maximum cap.
	if (numberOfElements < BUFFER_SIZE)
	{
		intArray[numberOfElements] = inpy;
		numberOfElements++;
		/* Testing functionality
		cout << "succesfully added number" << ln;
		cout << intArray[numberOfElements - 1] << ln;
		*/
		return true;
	}

	//cout << "did not successfully add number. Over limit" << ln;
	return false;
}

bool BufferArrayBrandon::remove(int remInpy)
{
	//Checks to see if the number exists in the array. Returns true if number exists.
	//Index integer is used to avoid running through the index of function twice.
	int index =indexOf(remInpy);
	if (index > -1) 
	{
		/*
		cout <<"num el:"<< numberOfElements<<ln;
		cout << "index: " << index<<ln;
		*/
		intArray[index] = intArray[numberOfElements-1];
		numberOfElements--;
		return true;
	}
	return false;
}

bool BufferArrayBrandon::stableRemove(int staRemInpy)
{
	int index = indexOf(staRemInpy);
	if (index > -1)
	{
		for (int i = index; i < numberOfElements; i++)
		{
			intArray[i] = intArray[i + 1];
		}
		numberOfElements--;
	}

	return false;
}

bool BufferArrayBrandon::find(int findInpy)
{
	//Returns true if number can be found inside an array.
	if (indexOf(findInpy) > -1)
		return true;
	return false;
}
 
void BufferArrayBrandon::display()
{
	/*cout << ln;
	cout << intArray[0] <<", ";
	cout << intArray[1] << ", ";
	cout << intArray[2] << ", ";
	cout << intArray[3] << ", ";
	//cout << "el num: " << numberOfElements << ln;
	*/
	//Prints out the contents of the array between two brackets.
	cout << "{ ";
	for (int i = 0; i < numberOfElements; i++)
	{
		cout << intArray[i];
		if (i < numberOfElements - 1)
			cout << ", ";
	}
	cout << " }"<<ln;



}



