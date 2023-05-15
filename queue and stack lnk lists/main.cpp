// File:    main.cpp
// Project: CSIS3400 Assignment 7 
// Author:  Brandon Catalano 
// History:  1.2 Oct 25th, 2022
#include "SortedRevLLStrBrandon.h"
#include "qList_Brandon.h"

#include <iostream>
using namespace std;
string ln = "\n";

int catalano_exp(int x, int e)
{
	if (e >= 0)
	{
		if (e != 1)
			return x * catalano_exp(x, e - 1);
		else

			return x;
	}
	else
	{
		return 0;
	}
	}

int main()
{
	char checker=NULL;
	if (checker!='s')
	{
		cout << "Test sorted list? y/n: ";
		cin >> checker;
		cout << ln;
	}
	if (checker == 'y')
	{
		sortedList h = sortedList();
		h.putItem("bruh");
		h.putItem("bruh2");
		h.putItem("aruh");
		h.putItem("cruh");
		h.putItem("coink");
		h.printList();
		cout << h.findWordStartWith('c') << ln;
		cout << h.findWordStartWith('b') << ln;
		cout << h.findWordStartWith('f') << ln;

		cout << "Backwards print with stack:" << endl;
		h.displayListBackwards();

		cout << "Backward print recursion: " << endl;
		h.displayListBackwardsRec();
		cout << endl;
		/*
		cout << "Removing middle node:" << endl;
		printf(h.removeMiddleNode() ? "Middle Node successfully removed" : "Middle Node could not be removed");
		cout << ln;
		*/
		cout << ln;
	}

	/*
	if (checker!='s')
	{
		cout << "Test queue linked list? y/n" << endl;
		cin >> checker;
	}
	*/
	if (checker != 's')
	{
		cout << "Test queue list? y/n: ";
		cin >> checker;
		cout << ln;
	}
	if (checker == 'y')
	{
		qList_Brandon<int> listQd;
		printf(listQd.isEmpty() ? "Queue list is Empty" : "Queue list is Not empty");
		cout <<ln;
		printf(listQd.isFull() ? "Queue list is Not Full" : "Queue list is Full");
		cout <<ln;
		listQd.addToQue(109);
		listQd.addToQue(20);
		listQd.addToQue(22);
		listQd.printQue();
		listQd + 32;
		listQd + 42;
		listQd.printQue();
		printf(listQd.findItemQue(32) ? "Item was found within the queue." : "Item was not found within the queue.");
		cout <<ln;
		printf(listQd.findItemQue(30) ? "Item was found within the queue." : "Item was not found within the queue.");
		cout <<ln;
		printf(listQd.findItemQue(12) ? "Item was found within the queue." : "Item was not found within the queue.");
		cout <<ln;
		int j = 12;
		listQd.removeFromQue(j);
		j = 32;
		listQd.removeFromQue(j);
		listQd.printQue();
		for (int i = 0; i < 7; i++)
			listQd + 42;
		listQd.printQue();
	}

	cout << "2 to the power of 5 is: " << catalano_exp(2, 5) << endl << endl;
	cout << "3 to the power of -5 is: " << catalano_exp(3, -5)<<endl;
	cout << "Note: Answer rounded to nearest whole number"<<endl<<endl;
	return 0;
}