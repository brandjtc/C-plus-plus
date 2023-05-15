// File:    rows.cpp
// Project: CSIS3400 Assignment 1
// Author:  Brandon Catalano 
// History: Version 1.0 Aug 27,2022
using namespace std;
#include <iostream>

void printAsterisk(int n)
{
	//integer astCount is used to determine how many dots should be replaced by asterisks on any given line
	int astCount;
	for (int i = 0; i < n; i++)
	{
		//astCount is set to the value of the incrementing i integer, plus one to make it equal numerically to the row it's on
		astCount = i+1;
		//nested loop using integer J starting at the row count numerically and counting downwards.
		for (int j = n; j>0;j--)
		{
			//if and else statements using astCount to determine whether to print out an "*" or a "."
			if (j <= astCount) 
			{
				cout << "*";
			}
			else
			{
				cout << ".";
			}
		}
		cout << endl;
	}
	
}
int main() {
	int n;
	cout << "Input the number of rows numerically: ";
	//Userinput for row count.
	cin >> n;


	printAsterisk(n);
	return 0;

}