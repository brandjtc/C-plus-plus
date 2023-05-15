// File:    DoubleStackStr.cpp
// Project: CSIS3400 Assignment 6
// Author:  Brandon Catalano
// History:  1.4 Oct 18th, 2022
#include "doubleStackStrBrandon.h"
#include <iostream>

/*
	The push operation has a Big O notation of O(1) since it requires no for loops to push any values into either stack.
	Both pop 1 and pop 2 have a Big O notation O(1) since both require 0 for loops and have a constant computation time.
*/

using namespace std;
//constructor
doubleStackStr::doubleStackStr()
{
	length;
	stringArr = new string [20];	
	numOfElmLow=0;
	numOfElmHigh=0;

}
//Pops off top of the lower than M values stack/small stack.
void doubleStackStr::pop1()
{
	if (numOfElmLow > 0)
	{
		cout << "Successfully removed string \"" << stringArr[numOfElmLow - 1] << "\" from the small stack" << endl << endl;
		numOfElmLow--;
	}

	else
		cout << "There are no more strings in the small stack." << endl << endl;
}
//Pops off top of the higher than M values stack/large stack.
void doubleStackStr::pop2()
{
	if (numOfElmHigh >= 1)
	{

		cout << "Successfully removed string \"" << stringArr[length -numOfElmHigh] << "\" from the large stack"<<endl<<endl;
		numOfElmHigh--;
	}
	else
		cout << "There are no more strings in the large stack."<<endl<<endl;
}

//Pushes input strings into the double stack array.
void doubleStackStr::push(string input)
{
	//Checking if the maximum number limit was reached
	if (numOfElmLow + numOfElmHigh == 20)
	{
		cout << "Could not add \""<<input<<"\" to the double stack, as it has reached it's maximum capacity of 20 values."<<endl<<endl;
		return;
	}
	char testChar = input[0];
	//Makes all characters lowercase.
	if (testChar <= 90)
		testChar += 32;
	//Push for big stack
	if (testChar >= 109)
	{
	//cout << input << " is a big boy"<<endl<<endl;
		numOfElmHigh++;
		stringArr[length-numOfElmHigh] = input;
		cout << "Successfully added string \"" << input << "\" to the large stack"<<endl<<endl;
	}
	//
	else if (testChar < 109)
	{
		//cout << input << " is a little guy" << endl<<endl;
		stringArr[numOfElmLow] = input;
		cout << "Successfully added string \"" << input << "\" to the small stack" << endl<<endl;
		numOfElmLow++;

	}
}
//Displays the top of the lower than M values stack.
void doubleStackStr::top1()
{
	if (numOfElmLow != 0)
		cout << "Top of small stack: " << stringArr[numOfElmLow - 1] << endl << endl;
	else
		cout << "The small stack is empty.";
}
//Displays the top of the larger than or equal to M values stack.
void doubleStackStr::top2()
{
	if (numOfElmHigh != 0)
		cout << "Top of large stack: " << stringArr[length-numOfElmHigh] << endl<<endl;
	else
		cout << "The large stack is empty.";
}
//Test print function to ensure functionality of push and pop easily.

void doubleStackStr::testPrint()
{
	//cout << "reserve check: " << reserve << endl<<endl;
	for (int i = 0; i < numOfElmHigh+numOfElmLow; i++)
	{
			cout << "i counter: " << i<<" ";
			cout << stringArr[i]<<endl<<endl;
		}
	
	cout << endl<<"split"<<endl<<endl<<endl;
}

/*
void doubleStackStr::getHighNum()
{
	cout << "work ? ? ?";
	cout << "high num:" << numOfElmHigh << endl<<endl;
	cout <<"notice me:"<< stringArr[20-6]<<endl<<endl;
}
*/

