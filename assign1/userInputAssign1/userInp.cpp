// File:    userInp.cpp
// Project: CSIS3400 Assignment 1
// Author:  Brandon Catalano 
// History: Version 1.0 Aug 27,2022

using namespace std;
#include <iostream>


int printSmallest(int uno, int dos, int tres)
{
	int smallestnum = uno;
	//if statements that compare integer uno to the other two numbers 
	if (smallestnum > dos)
	{
		//If integer uno is bigger than integer dos, integer smallestnum becomes dos
		smallestnum = dos;
	}
	if (smallestnum > tres) 
	{
		smallestnum = tres;
	}
	return smallestnum;
}
int main()
{
	//String used for double-linespaces
	string spacing = "\n\n";
	//Variable declaration for integer inputs.
	int uno;
	int dos;
	int tres;
	cout << "User will be expected to input 3 integers"<<spacing;
	cout << "Input the first integer: ";
	cin >> uno;
	cout << endl << "Input the second integer: ";
	cin >> dos;
	cout << endl << "Input the third integer: ";
	cin >> tres;
	cout << spacing << "Smallest number of the three is: " << printSmallest(uno, dos, tres);
}
