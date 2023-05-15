// File:    main.cpp
// Project: CSIS3400 Assignment 9 
// Author:  Brandon Catalano 
// History:  1.1 Nov 6th, 2022
#include <iostream>
#include "StackArr.h";
#include "QueArr.h";
using namespace std;
bool palindromeTest(string test)
{
	int	length = test.length();
	int index = 0;
	StackArr<char> stack(length);
	QueArr<char>  qArr(length);
	int stackNqueueLength=0;

	for (int i = 0; i < length; i++)
	{
		char testChar = test[i];
		if (testChar <91&&testChar>64)
			testChar += 32;
		if (testChar > 96 && testChar < 123)
		{

			stack.push(testChar);
			qArr.enque(testChar); 
			stackNqueueLength++;
		}

	}
	bool retVal = true;
	for (int i = 0; i < stackNqueueLength; i++)
	{

		if (stack.topView() != qArr.first())
			retVal=false;
		stack.pop();
		qArr.deque();
	}

	return retVal;
}
int main()
{
	string test1 ="bro racecar orb";
	cout << test1 << " is palindrome?" << endl;
	printf(palindromeTest(test1) ? "Is Palindrome!\n\n" : "Is Not Palindrome!\n\n");


	string test2 = "\"I'm not a palindrome.\"";
	cout << test2<<" ";
	printf(palindromeTest(test2) ? "is a Palindrome!\n\n" : "is not a Palindrome!\n\n");

	string test3 = "\"palindrome backwards sdrawkcab Emordnilap\"";
	cout << test3 << " ";
	printf(palindromeTest(test3) ? "is a Palindrome!\n\n" : "is not a Palindrome!\n\n");
	cout << endl;

	string test4 = "\"fr this is not a plaindrome?????? why not?\"";
	cout << test4 << " ";
	printf(palindromeTest(test4) ? "is a Palindrome!\n\n" : "is not a Palindrome!\n\n");
	cout << endl;

	cout << endl;
	return 0;
}