// File:    qList_Brandon.CPP
// Project: CSIS3400 Assignment 7 
// Author:  Brandon Catalano 
// History:  1.1 Oct 25th, 2022

#ifndef QLIST_BRANDON_CPP
#define QLIST_BRANDON_CPP
#include <iostream>
using namespace std;
#include "qList_Brandon.h"

//No-Arg constructor
template<class Brandon>
qList_Brandon<Brandon>::qList_Brandon()
{
	nodeCount = 0;
	front=NULL;
	incrementorNode = NULL;
	rear=NULL;
}

//Checks if list is empty by trying to add new item to list
template<class Brandon>
bool qList_Brandon<Brandon>::isEmpty()
{
	if (front==NULL)
	{
		cout << "The queue link list is empty." << endl;
		return true;
	}
	return false;
}

//Checks if queue is full.
template<class Brandon>
bool qList_Brandon<Brandon>::isFull()
{
	qNode<Brandon>* location;
	try
	{
		location = new qNode<Brandon>;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}
//Adds item to the queue.
template<class Brandon>
void qList_Brandon<Brandon>::addToQue(Brandon item)
{
	//cout << "check pre if" << endl << endl;
	if (isFull())
	{
		cout << "Cannot add " << item << " as the queue is currently full." << endl << endl;
		return;
	}
	//cout<<"check post-if" << endl << endl;
	qNode<Brandon>* tempNode;
	tempNode = new qNode<Brandon>;
	tempNode->data = item;
	tempNode->next = NULL;
	//Establishes all nodes after front node.
	if (front != NULL)
	{
		rear->next = tempNode;
		rear = tempNode;
		//Points front node to correct location
		if (front->next == NULL)
			front->next = rear;
		cout << "Successfully added " << item << " to the queue." << endl << endl;
	}
	//Establishes first node in empty list
	else
	{
		front = tempNode;
		rear = tempNode;
		cout << "Successfully added " << item << " as the first item in the queue." << endl << endl;
	}
	nodeCount++;

}
//Prints out queue using for loop and getNextItem helper function.
template<class Brandon>
void qList_Brandon<Brandon>::printQue()
{

	if (isEmpty())
	{
		cout << "Cannot print the queue as the list is empty.";
		return;
	}
	incrementorNode = front;
	for (int i = 0; i < nodeCount; i++)
	{
		cout << incrementorNode->data;
		if (i < nodeCount - 1)
			cout << ", ";
		getNextItem();
	}
	cout << endl << endl;
	incrementorNode = front;
	}

//Operator that adds an item to the queue.
template<class Brandon>
void qList_Brandon<Brandon>::operator+(Brandon item)
{
	if (isFull())
	{
		cout << "The operation could not be performed as the queue is full." << endl << endl;
		return;
	}
	addToQue(item);
}

//Returns boolean for if item is found in queue.
template<class Brandon>
bool qList_Brandon<Brandon>::findItemQue(Brandon item)
{
	if (isEmpty())
		return false;
	incrementorNode = front;
	for (int i = 0; i < nodeCount; i++)
		{
			if (incrementorNode->data == item)
				return true;
			getNextItem();
		}
	return false;
}

//Removes input item from queue.
template<class Brandon>
void qList_Brandon<Brandon>::removeFromQue(Brandon& item)
{
	if (!findItemQue(item))
	{
		cout << "Could not remove " << item << " as it was not within the queue." << endl << endl;
		return;
	}
	qNode<Brandon>* location = new qNode<Brandon>;
	qNode<Brandon>* tempLocation = new qNode<Brandon>;;
	location = front;
	if (item == location->data)
	{
		tempLocation = location;
		front = front->next;
	}
	else
	{
		while (item != (location->next->data))
		{
			location = location->next;
		}
		tempLocation = location->next;
		location->next = location->next->next;
	}
	delete tempLocation;
	cout << item << " was successfully removed from queue."<<endl<<endl;
	nodeCount--;
}

//Helper function that increments the incrementorNode up one.
template<class Brandon>
void qList_Brandon<Brandon>::getNextItem()
{
	if (incrementorNode != NULL)
	{
		incrementorNode = incrementorNode->next;
		return;
		
	}
	else if (isEmpty())
		cout << "The queue is currently empty. No next item available.";	
}
#endif