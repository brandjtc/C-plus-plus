// File:    SortedBufferArrayWithDupsBrandon.cpp
// Project: CSIS3400 Assignment 4 
// Author:  Brandon Catalano 
// History:  1.4 Sept 27th, 2022
#include "SortedBufferArrayWithDupsBrandon.h"
#include <iostream>
using namespace std;


//Constructors
//No arg constructor using buffer size of 12 for array length.
SortedBufferArrayWithDupsBrandon::SortedBufferArrayWithDupsBrandon()
{
	BUFFER_SIZE = 12;
	intArray = new int[BUFFER_SIZE];
	numberOfElements = 0;
}

//Arg Constructor using user input for array length.
SortedBufferArrayWithDupsBrandon::SortedBufferArrayWithDupsBrandon(int buff)
{
	BUFFER_SIZE = buff;
	intArray = new int[BUFFER_SIZE];
	numberOfElements=0;
}

//Accessors
int SortedBufferArrayWithDupsBrandon::getBUFFER_SIZE()
{
	return BUFFER_SIZE;
}

int SortedBufferArrayWithDupsBrandon::getNumberOfElements()
{
	return numberOfElements;
}


//Operations

bool SortedBufferArrayWithDupsBrandon::quietBubbleSort()
{
	bool sorted = false;
	for (int i = 0; i < numberOfElements - 1; i++)
	{


		if (intArray[i] > intArray[i + 1])
		{
			swap(intArray[i], intArray[i + 1]);
			sorted = false;
		}
		else
			sorted = true;
	}
	return sorted;
}

void SortedBufferArrayWithDupsBrandon::swap(int& swapInp1, int& swapInp2)
{
	int storage = swapInp1;
	swapInp1 = swapInp2;
	swapInp2 = storage;

}

bool SortedBufferArrayWithDupsBrandon::quietCheckSort()
{
	bool sorted = false;
	if (numberOfElements > 1)
	{
		for (int i = 0; i < numberOfElements; i++) {
			bool sorted = false;

			while (sorted == false)
			{
				sorted = quietBubbleSort();
			}

		}
	}
	//printf("Sorted is: %s\n", sorted ? "True" : "False");
	return sorted;
}
int SortedBufferArrayWithDupsBrandon::indexOf(int target)
{
	for (int i = 0; i < numberOfElements; i++) {
		//Loop ends early with a return if the current index of intArray passes the target value;
		if (intArray[i] > target) {
			//cout << "we went past: " << target << " gotta go back.";
			return -1;
		}
		else if (intArray[i] == target)
			return i;
	}
	return -1;

}

//Insertion function for intArray
bool SortedBufferArrayWithDupsBrandon::insert(int insInpy)
{
	if (numberOfElements < BUFFER_SIZE) {
		intArray[numberOfElements] = insInpy;
		numberOfElements++;
		//cout << "Quiet bubble sort running: ";
		//Checks if list is sorted. If not, this function then starts a bubble sort.
		quietCheckSort();
		return true;

	}
	cout << endl << "Cannot input number: " << insInpy << ". List is full" << endl;
	return false;
}

//Edited to sort after as to not unsort the array.
bool SortedBufferArrayWithDupsBrandon::quickRemove(int remInpy)
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
		quietBubbleSort();
		return true;
	}
	return false;
}

bool SortedBufferArrayWithDupsBrandon::stableRemove(int staRemInpy)
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

//Checks if findInpy input is in the sorted list.
//If the current index of i is a number greater than findInpy, the for loop breaks instantly
bool SortedBufferArrayWithDupsBrandon::find(int findInpy)
{
	for (int i = 0; i < numberOfElements; i++)
	{
		if (intArray[i] == findInpy)
			return true;
		else if (intArray[i] > findInpy)
			break;
	}
	return false;
}
//Altered to find all of a given integer in the array, but stop iteration if the current index value is greater than the target value.
int SortedBufferArrayWithDupsBrandon::findAll(int target)
{
	int dupliCount = 0;
	for (int i = 0; i < numberOfElements; i++)
	{
		if (intArray[i] == target)
			dupliCount++;
		if (intArray[i] > target)
			return dupliCount;
	}
	return dupliCount;
}
//Removes all occurences of a value, replacing it with the last value in the array. Also double checks that the new value isn't the target
int SortedBufferArrayWithDupsBrandon::quickRemoveAll(int target)
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

int SortedBufferArrayWithDupsBrandon::stableRemoveAll(int target)
{
	int remCount = 0;
	int targetTotal = findAll(target);
	int index = indexOf(target);

	cout<<endl << "Starting Stable Remove"<<endl;
	display();

	for (int i = index; i + targetTotal < numberOfElements; i++)
	{
		intArray[i] = intArray[i + targetTotal];
	}

	numberOfElements -= targetTotal;


	return remCount;
}
void SortedBufferArrayWithDupsBrandon::display()
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


