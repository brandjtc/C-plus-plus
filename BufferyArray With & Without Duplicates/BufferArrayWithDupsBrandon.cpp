// File:    BufferArrayWithDupsBrandon.cpp
// Project: CSIS3400 Assignment 3 
// Author:  Brandon Catalano 
// History:  1.1 Sept 10th, 2022
#include "BufferArrayWithDupsBrandon.h"
#include <iostream>
using namespace std;


//Constructors
//No arg constructor using buffer size of 12 for array length.
BufferArrayWithDupsBrandon::BufferArrayWithDupsBrandon()
{
	BUFFER_SIZE = 12;
	intArray = new int[BUFFER_SIZE];
	numberOfElements = 0;
}

//Arg Constructor using user input for array length.
BufferArrayWithDupsBrandon::BufferArrayWithDupsBrandon(int buff)
{
	BUFFER_SIZE = buff;
	intArray = new int[BUFFER_SIZE];
	numberOfElements=0;
}

//Accessors
int BufferArrayWithDupsBrandon::getBUFFER_SIZE()
{
	return BUFFER_SIZE;
}

int BufferArrayWithDupsBrandon::getNumberOfElements()
{
	return numberOfElements;
}


//Operations
int BufferArrayWithDupsBrandon::indexOf(int target)
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

//Insertion function for intArray
bool BufferArrayWithDupsBrandon::insert(int inpy)
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

bool BufferArrayWithDupsBrandon::quickRemove(int remInpy)
{
	//Checks to see if the number exists in the array. Returns true if number exists.
	//Index integer is used to avoid running through the index of function twice.
	int index = indexOf(remInpy);
	if (index > -1)
	{
		/*
		cout <<"num el:"<< numberOfElements<<ln;
		cout << "index: " << index<<ln;
		*/
		intArray[index] = intArray[numberOfElements - 1];
		numberOfElements--;
		return true;
	}
	return false;
}

bool BufferArrayWithDupsBrandon::stableRemove(int staRemInpy)
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

bool BufferArrayWithDupsBrandon::find(int findInpy)
{
	//Returns true if number can be found inside an array.
	if (indexOf(findInpy) > -1)
		return true;
	return false;
}

int BufferArrayWithDupsBrandon::findAll(int target)
{
	int dupliCount = 0;
	for (int i = 0; i < numberOfElements; i++)
	{
		if (intArray[i] == target)
			dupliCount++;
	}
	return dupliCount;
}
//Removes all occurences of a value, replacing it with the last value in the array. Also double checks that the new value isn't the target
int BufferArrayWithDupsBrandon::quickRemoveAll(int target)
{
	int remCount = 0;
	if (findAll(target) > 0) 
	{
		for (int i = 0; i < numberOfElements; i++)
		{
			if (intArray[i] == target)
			{
				intArray[i] = intArray[numberOfElements - 1];
				numberOfElements--;
				i--;
				remCount++;
			}
		}
	}

	return remCount;
}
//Removes all occurences of a value, and then moves all remaining elements downwards to fill the freshly emptied slots. Also checks new value isn't 
//Target value
int BufferArrayWithDupsBrandon::stableRemoveAll(int target)
{
	int remCount = 0;
	if (findAll(target) > 0)
	{
		for (int i = 0; i < numberOfElements; i++)
		{
			if (intArray[i] == target)
			{
				intArray[i] = intArray[i + 1];
				i--;
				numberOfElements--;
				remCount++;
			}
		}
	}
	return remCount;
}
void BufferArrayWithDupsBrandon::display()
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
	cout << " }" << endl << endl;



}


