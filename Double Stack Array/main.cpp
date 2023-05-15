// File:    main.cpp
// Project: CSIS3400 Assignment 6
// Author:  Brandon Catalano
// History:  1.4 Oct 18th, 2022
#include "DoubleStackArr.h"
#include "DoubleStackList.h"
#include "doubleStackStrBrandon.h"
#include <iostream>
using namespace std;

int main()
{

	char decide = NULL;
	decide = 'p';
	if (decide != 'p')
	{
		cout << "Test Double Stack Array? Y/N: " << endl;
		cin >> decide;
	}
	if (decide == 'y') {
		DoubleStackArr<int> doubleArr;
		doubleArr.top();
		doubleArr.push(12, 22);
		doubleArr.top();
		doubleArr.push(12, 32);
		doubleArr.push(12, 42);
		doubleArr.push(12, 52);
		doubleArr.push(12, 62);
		doubleArr.push(12, 72);
		printf(doubleArr.isEmpty() ? "This stack list is empty" : "This stack list is not empty");
		cout << endl;

		DoubleStackArr<string> strOdd(5);
		strOdd.push("string1", "string2");
		strOdd.push("string3", "string4");
		strOdd.push("string5", "string6");
		strOdd.top();
		strOdd.pop();
		strOdd.pop();
		strOdd.pop();
		printf(strOdd.isEmpty() ? "This stack list is empty" : "This stack list is not empty");
		cout << endl;
		strOdd.top();
	}



	if (decide != 'p')
	{
		cout << endl<<"Test Double Stack List? Y/N: " << endl;
		cin >> decide;
	}
	if (decide == 'y') {
		DoubleStackList<string> stckLst(3);
		stckLst.push("string1", "string2");
		stckLst.push("string3", "string4");
		printf(stckLst.isEmpty() ? "This stack list is empty" : "This stack list is not empty");
		stckLst.top();
		stckLst.pop();
		stckLst.top();
		stckLst.pop();
		stckLst.top();

		printf(stckLst.isEmpty() ? "This stack list is empty" : "This stack		list is not empty");

	}
	if (decide != 'p')
	{
		cout << endl <<"Test Double Stack string? Y/N: " << endl;
		cin >> decide;
	}
	decide = 'y';
	if (decide == 'y') {
		doubleStackStr newby = doubleStackStr();
		newby.push("Apple");
		newby.push("bruh bruh");
		newby.push("no dude1");
		newby.push("no dude2");
		newby.push("no dude3");
		//newby.testPrint();
		newby.push("help");
		//newby.testPrint();
		newby.push("Help");
		//newby.testPrint();
		newby.push("Zebra");
		newby.push("Xenomorph");
		newby.push("This assignment was very interesting.");
		//newby.testPrint();
		newby.push("Testing");
		newby.push("Filler");
		//newby.testPrint();

		newby.top2();
	
		for (int i = 0; i < 11; i++)
		{
			newby.push("filler");
		}
		
		for (int i = 0; i < 6; i++) {
			//newby.testPrint();
			newby.pop2();
		}


		//newby.testPrint();
		newby.pop1();
		//newby.testPrint();
		//newby.getHighNum();
		newby.top2();
		newby.pop2();
		newby.testPrint();
		newby.top1();
		newby.top2();
		for (int i = 0; i < 11; i++) {
			//newby.testPrint();
			newby.pop1();
		}

		/*
		*/
		return 0;
	}
}