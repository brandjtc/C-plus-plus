// File:    SortDblLnkLst.cpp
// Project: CSIS3400 Assignment 8
// Author:  Brandon Catalano 
// History:  1.0 Oct 29th, 2022
#pragma once
#ifndef SORTDBLLNKLST_CPP
#define SORTDBLLNKLST_CPP
#include "SortDblLnkLst.h"
#include <iostream>
using namespace std;
//Default constructor
template <class Brandon>
SortDblLnkLst<Brandon>::SortDblLnkLst()
{
	listData = NULL;
	incrementorNode = NULL;
}

//Copy constructor. Calls upon = operator function.
template <class Brandon>
SortDblLnkLst<Brandon>::SortDblLnkLst(const SortDblLnkLst& another)
{
	*this = another;
}

//Destructor
template <class Brandon>
SortDblLnkLst<Brandon>::~SortDblLnkLst()
{
	emptyList();
}
template <class Brandon>
void SortDblLnkLst<Brandon>::emptyList()
{
	Node<Brandon>* deleteNode;
	while (listData != NULL)
	{
		deleteNode = listData;
		listData = listData->next;
		delete deleteNode;
	}
	listData = NULL;
	resetList();
}

//Helper function that adds item into sorted linklist.
template <class Brandon>
void SortDblLnkLst<Brandon>::putItem(Brandon item)
{
	Node<Brandon>* location;
	Node<Brandon>* prevLoc;
	Node<Brandon>* newNode;

	bool moreToSearch;
	location = listData;
	prevLoc = NULL;
	moreToSearch = (location != NULL);

	//Searches for correct area to place item into sorted list.
	while (moreToSearch)
	{
		//Activates if item is less than location info
		if (item < location->info)
		{
			prevLoc = location;
			location = location->next;
			moreToSearch = (location != NULL);
		}
			//Activates if item is greater than location info
			else if (item >= location->info)
			{
				moreToSearch = false;
				break;
			}
		}

		newNode = new Node<Brandon>;
		newNode->info = item;
		//Activates if there are no prior nodes in the link list
		if (prevLoc == NULL)
		{
			newNode->next = listData;
			listData = newNode;
			listData->prev = NULL;
		}
		//Activates if node must be placed inbetween several other nodes in link list for the sort.
		else
		{
			location->prev = newNode;
			newNode->next = location;
			newNode->prev = prevLoc;
			prevLoc->next = newNode;
		}
		nodeCount++;

	}

//Helper function that gets next item in link list
template <class Brandon>
Brandon SortDblLnkLst<Brandon>::getNextItem()
{
	if (incrementorNode == NULL)
	{
		incrementorNode = listData;
		return incrementorNode->info;
	}
	else
	{
		incrementorNode = incrementorNode->next;
		return incrementorNode->info;
	}
}
//Checks if list is empty
template <class Brandon>
bool SortDblLnkLst<Brandon>::isEmpty()
{
	return (listData == NULL);
}
template <class Brandon>
void SortDblLnkLst<Brandon>::resetList()
{
	incrementorNode = NULL;
}

//Assignment operator to equate two nodes to one another.
template <class Brandon>
void SortDblLnkLst<Brandon>::operator = (const SortDblLnkLst& another)
{ 
	if (!isEmpty())
		emptyList();
	Node<Brandon>* tempNode = new Node<Brandon>;
	Node<Brandon>* anotherNode = new Node<Brandon>;
	Node<Brandon>* prevLoc = new Node<Brandon>;
	if (another.listData == NULL)
		listData = NULL;
	else
	{
		listData = new Node<Brandon>;
		listData->info = another.listData->info;
		tempNode = listData;
		anotherNode = another.listData->next;
		for (int i = 1; i < another.nodeCount; i++)
		{
			tempNode->next = new Node<Brandon>;
			prevLoc = tempNode;
			tempNode = tempNode->next;
			tempNode->prev = prevLoc;
			tempNode->info = anotherNode->info;
			anotherNode = anotherNode->next;
		}
		tempNode->next = NULL;
	}
	nodeCount = another.nodeCount;

}

//Checks if item is within a list.
template <class Brandon>
bool SortDblLnkLst<Brandon>::findItem(Brandon item)
{
	resetList();
	bool moreToSearch = (incrementorNode != NULL);

	if (isEmpty())
		return false;
	incrementorNode = listData;
	for (int i = 0; i < nodeCount; i++)
		{
			if (incrementorNode->info == item)
				return true;
			getNextItem();
		}
		return false;

	
}

//Prints link list in order.
template <class Brandon>
void SortDblLnkLst<Brandon>::printItems()
{
	if (isEmpty())
	{
		cout << "Cannot print link list as it is empty";
		return;
	}
	cout << "Printing list:" << endl;
	for (int i = 0; i<nodeCount; i++)
	{
		cout<<getNextItem()<<" ";
	}
	cout << endl << endl;
	resetList();
}

//Prints link list in reverse using prev node.
template <class Brandon>
void SortDblLnkLst<Brandon>::printItemsReverse()
{
	if (isEmpty())
	{
		cout << "Cannot print link list as it is empty";
		return;
	}
	cout << "Printing list backwards:" << endl;
	for (int i = 0; i<nodeCount; i++)
	{
		Brandon item = getNextItem();
	}
	for (int i = 0; i < nodeCount; i++)
	{
		cout << incrementorNode->info<<" ";
		incrementorNode=incrementorNode->prev;
	}
	cout << endl << endl;
	resetList();
}

//Deletes a node
 template<class Brandon>
void SortDblLnkLst<Brandon>::deleteItem(Brandon item)
{
	if (findItem(item))
	{
		Node<Brandon>* tempNode = new Node<Brandon>;
		Node<Brandon>* deleteNode = new Node<Brandon>;
		tempNode = listData;
		//Runs if the item is not found in first node of list.
		if (item != tempNode->info)
		{
			while (item != (tempNode->next->info))
				getNextItem();
			deleteNode = tempNode->next;
			tempNode->next = tempNode->next->next;
		}
		else
		{
			deleteNode = tempNode;
			listData = listData->next;
		}
		delete deleteNode;
	}
	cout << "Removed " << item << " from link list" << endl << endl;
	nodeCount--;
	resetList();

}


#endif