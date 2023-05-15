// File:    DoubleStackList.cpp
// Project: CSIS3400 Assignment 6
// Author:  Brandon Catalano
// History:  1.0 Oct 7th, 2022
#ifndef DOUBLESTACKLIST_CPP_
#define DOUBLESTACKLIST_CPP_
#include <iostream>
#include "DoubleStackList.h"
using namespace std;

//constructors
template <class item>
DoubleStackList<item>::DoubleStackList()
{
	nodeList=NULL;
	position=NULL;
	numOfElements = 0;
	buffer = 10;

}

template <class item>
DoubleStackList<item>::DoubleStackList(int buff)
{
	nodeList = NULL;
	position = NULL;
	buffer = buff;
	numOfElements = 0;

}

//operations
template<class item>
void DoubleStackList<item>::nodeBgone()
{
	node<item>* tempNode;
	tempNode = nodeList;
	nodeList = nodeList->nextNode;
	cout << tempNode->nodeData << " has been removed from the stack." << endl;
	delete tempNode;
	numOfElements--;
}
template<class item>
void DoubleStackList<item>::push(item input1, item input2)
{
	node<item>* tempNode = new node<item>;
	node<item>* tempNode2= new node<item>;
	
	//ensures items only get added when the total amount of things in the "stack" dont exceed the buffer value.
	if (numOfElements < buffer) {
		tempNode->nodeData = input1;
		tempNode->nextNode = nodeList;

		//Activates only when number of items in the stack list are one less than the maxiumum buffer value. Only adds 1 item.
		if (numOfElements == buffer - 1)
		{
			nodeList = tempNode;
			cout << "Successfully added element " << input1 << " to the stack." << endl;
			cout << "Could not add element " << input2 << ". Stack is full." << endl << endl;
			numOfElements++;
			//cout << "Numofele:" << numOfElements << endl << "buffer: " << buffer << endl;	
		}

		//Activates when there is room for 2 or more items in the stack list.
		else
		{
			tempNode2->nodeData = input2;
			tempNode2->nextNode = tempNode;
			nodeList = tempNode2;
			cout << "Successfully added elements " << input1 << " and " << input2 << " to the stack." << endl << endl;
			numOfElements += 2;

		}
	}

	//Activates in the event the stack list is completely full. 
	else
		cout << "Could not add elements " << input1 << " and " << input2 << " to the stack. The stack is currently full." << endl << endl;

	 //cout << tempNode2->nextNode->nodeData;
}

//Prints item stored in nodeData template stored inside the nodeList node. 
template<class item>
void DoubleStackList<item>::top()
{
	if (nodeList != NULL)
		cout << nodeList->nodeData << endl<<endl;
	else
		cout << "The Stack List is empty."<<endl<<endl;
}

//Pops the top two items off of the stack.
template<class item>
void DoubleStackList<item>::pop()
{
	//Activates if there is at least two items in the stack list.
	if (numOfElements > 1)
	{
		for (int i = 0; i < 2; i++)
		{
			//Function that removes a node.
			nodeBgone();
		}
	}
	//Activates in the event there is one item in the stack list.
	else if (numOfElements==1)
	{
		nodeBgone();
		cout << "The stack list is now empty." << endl << endl;
	}
	//Activates when stack list is empty;
	else
		cout<<"The Stack List is empty."<<endl<<endl;
}

//Checks if stack is empty.
template <class item>
bool DoubleStackList<item>::isEmpty()
{
	bool emptChk = (nodeList == NULL);
	return emptChk;
}



#endif
