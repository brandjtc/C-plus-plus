// File:    DoubleStackArr.cpp
// Project: CSIS3400 Assignment 6
// Author:  Brandon Catalano
// History:  1.0 Oct 7th, 2022

#ifndef DOUBLESTACKARR_CPP_
#define DOUBLESTACKARR_CPP_
#include "DoubleStackArr.h"
#include <iostream>
using namespace std;

//constructors
template <class item>
DoubleStackArr<item>::DoubleStackArr()
{
	numOfElements = 0;
	buffer = 10;
	inpArray = new item[buffer];
	cout << "Array size is set to 10." << endl;
}

template <class item>
DoubleStackArr<item>::DoubleStackArr(int bufferLength)
{
	numOfElements = 0;
	buffer = bufferLength;
	inpArray = new item[buffer];
	
	cout << "Array size set to " << bufferLength << "."<<endl;
}

//Push method that pushes two items in at once onto the array stack.
template<class item>
void DoubleStackArr<item>::push(item input1, item input2)
{
	
	item* inputAdder = new item[2];
	inputAdder[0] = input1;
	inputAdder[1] = input2;
	
	for (int i = 0; i < 2; i++)
	{
		//cout << "numOfElements: "<<numOfElements<<endl;
		//cout << "buffer: " << buffer<<endl;
	
		if (numOfElements < buffer)
		{
			//cout << "test1:"<<endl<<inputAdder[i]<<endl;
			inpArray[numOfElements] = inputAdder[i];
			//cout << "InpArray check:" << inpArray[numOfElements];
			numOfElements++;
			cout << "Succesfully added " << inputAdder[i]<< "." << endl;

		}
		//Activates when the array is full, detailing which values could not be added in specific.
		else
		{
			if (i == 1)
				cout << "Could not add element " << inputAdder[i] << ". The array is full."<<endl;
			else
			{
				cout << "Could not add elements " << inputAdder[0] << " and " << inputAdder[1] << ". The array is full"<<endl;
				break;
			}
		}
	}

}

template<class item>
void DoubleStackArr<item>::pop()
{
	
	for (int i = 0; i < 2; i++)
	{
		bool empty = isEmpty();
		//cout << "Test1"<<endl;
		if (!empty)
		{
			//cout << "Nonempty test1" << endl;
			cout << "Element "<< inpArray[numOfElements-1] <<" has been removed." << endl;
			numOfElements--;
		}
		else
		{
			cout << "The array is now empty."<<endl;

		}
	}
}

template<class item>
void DoubleStackArr<item>::top()
{
	if (!isEmpty())
		cout <<"Element "<< inpArray[numOfElements-1] << " is ontop of the stack." << endl;
	else
		cout << "The stack is empty."<<endl;
}

template<class item>
bool DoubleStackArr<item>::isEmpty()
{
	if (numOfElements > 0)
		return false;
	return true;
}


template<class item>
int DoubleStackArr<item>::getBuffer()
{
	return buffer;
}
#endif
