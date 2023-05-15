// File:    DoubleStackStr.h
// Project: CSIS3400 Assignment 6
// Author:  Brandon Catalano
// History:  1.1 Oct 18th, 2022
#pragma once
#include <iostream>
using namespace std;

/*
To implement this, first I would create an array of size 21. This would be so I can have an extra reserve space
when adding values.

Said reserve value will be an integer variable, storing it's index as an integer.

They would each have their own individual number of elements variable tied to the count of their listed elements.

There would also be a constant buffer variable, set to 20 as per specs, that is compared to the sum of the lower and upper 
number of elements variables to check if there is any room inside the array for new values to be added.

Concerning how to lump strings into the correct array when uppercase/lower case is involved, e.g. putting both Lion and liar in
the lower value bracket, I would make use of the fact that all lowercase values are 32 values higher than the unicode values of their
uppercase equivalencies. I could psuedo-lowercase all of the first characters that have a value of 90 or less by adding 32 to psuedo-
lowercase all of the first characters in each string.

The pop functions would use the individual number of elements variables to differentiate between which stack is bigger for the purposes
of pop 1 and 2.
*/
 
class doubleStackStr
{
private:
	const int length=20;
	int numOfElmLow;
	int numOfElmHigh;
	string* stringArr;
public:
	doubleStackStr();
	void pop1();
	void pop2();
	void push(string input);
	void top1();
	void top2();
	void testPrint();
	//void getHighNum();
};

