// File:    BufferArrayBrandonTempl.cpp
// Project: CSIS3400 Assignment 5 
// Author:  Brandon Catalano 
// History:  1.0 Sept 29th, 2022

#ifndef BUFFERARRAYBRANDONTEMPL_CPP_
#define BUFFERARRAYBRANDONTEMPL_CPP_
#include "BufferArrayBrandonTempl.h"
#include <iostream>
using namespace std;

//Used to doublespace when printing for readability



//No arg constructor using buffer size for array length.
template <class item>
BufferArrayBrandonTempl<item>::BufferArrayBrandonTempl()
{	
	anyArray = new item[BUFFER_SIZE];
	numberOfElements = 0;
}


template <class item>
int BufferArrayBrandonTempl<item>::indexOf(item target)
{
	//for loop that allows removal and find functions to find the array of a target number, if present.
	for (int i = 0; i < numberOfElements; i++)
	{
		if (anyArray[i] == target)
			//i, the index of the target value, is returned on success.
			return i;
	}
	//-1 is returned on failure.
	return -1;
}


//Insertion function for intArray
template <class item>
bool BufferArrayBrandonTempl<item>::insert(item inpy)
{
	//Adds to end of array if number of elements is less than hte maximum cap.
	if (numberOfElements < BUFFER_SIZE)
	{
		anyArray[numberOfElements] = inpy;
		numberOfElements++;
		/* Testing functionality*/
		//cout << "succesfully added item" << endl<<endl;
		//cout << anyArray[numberOfElements - 1] << endl<<endl;
	
		return true;
	}

	//cout << "did not successfully add number. Over limit" << endl<<endl;
	return false;
}


template <class item>
bool BufferArrayBrandonTempl<item>::remove(item remInpy)
{
	//Checks to see if the number exists in the array. Returns true if number exists.
	//Index integer is used to avoid running through the index of function twice.
	int index =indexOf(remInpy);
	if (index > -1) 
	{
		/*
		cout <<"num el:"<< numberOfElements<<endl<<endl;
		cout << "index: " << index<<endl<<endl;
		*/
		anyArray[index] = anyArray[numberOfElements-1];
		numberOfElements--;
		return true;
	}
	return false;
}


template <class item>
bool BufferArrayBrandonTempl<item>::stableRemove(int staRemInpy)
{
	int index = indexOf(staRemInpy);
	if (index > -1)
	{
		for (int i = index; i < numberOfElements; i++)
		{
			anyArray[i] = anyArray[i + 1];
		}
		numberOfElements--;
	}

	return false;
}


template <class item>
bool BufferArrayBrandonTempl<item>::find(item findInpy)
{
	//Returns true if number can be found inside an array.
	if (indexOf(findInpy) > -1)
	{
		cout << "Requested search term, \"" << findInpy << "\" is in the array."<<endl<<endl;
		return true;
	}
	cout << "Requested search term, \"" << findInpy << "\" could not be found."<<endl<<endl;
	return false;
}


template <class item>
void BufferArrayBrandonTempl<item>::display()
{
	/*cout << endl<<endl;
	cout << intArray[0] <<", ";
	cout << intArray[1] << ", ";
	cout << intArray[2] << ", ";
	cout << intArray[3] << ", ";
	//cout << "el num: " << numberOfElements << endl<<endl;
	*/
	//Prints out the contents of the array between two brackets.
	cout << "{ ";
	for (int i = 0; i < numberOfElements; i++)
	{
		cout << anyArray[i];
		if (i < numberOfElements - 1)
			cout << ", ";
	}
	cout << " }"<<endl<<endl;



}


#endif 