// File:    SortedRevLLStrBrandon.cpp
// Project: CSIS3400 Assignment 5 
// Author:  Brandon Catalano 
// History:  1.1 Oct 1st, 2022
#include "SortedRevLLStrBrandon.h"



sortedList::sortedList()
{
	length = 0;
	listData = NULL;
	currentPos = NULL;
}


void sortedList::makeEmpty()
{
	node* tempPtr;
	while (listData != NULL)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
	}
	length = 0;
}


bool sortedList::isFull()
{
	node* location;
	try
	{
		location = new node;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}


int sortedList::getLength()
{
	return length;
}


bool sortedList::findItem(string item)
{
	bool moreToSearch;
	node* location;
	location = listData;
	bool found = false;
	moreToSearch = (location != NULL);
	while (moreToSearch && !found)
		if (item == location->data)
		{
			found = true;
			break;
		}
		else if( item > location->data)
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
		else
		{
			moreToSearch = false;
			break;
		}
	return found;
}


void sortedList::putItem(string item)
{
	if (isFull())
		return;
	node* location;
	node* prevLoc;
	node* newNode;

	bool moreToSearch;
	location = listData;
	prevLoc = NULL;
	moreToSearch = (location != NULL);

	while (moreToSearch)
	{
		if (item <  location->data)
		{
			prevLoc = location;
			location = location->next;
			moreToSearch = (location != NULL);
		}
		else if (item >= location->data)
		{
			moreToSearch = false;
			break;
		}
	}
	newNode = new node;
	newNode->data = item;
	if (prevLoc == NULL)
	{
		newNode->next = listData;
		listData = newNode;
	}
	else
	{
		newNode->next = location;
		prevLoc->next = newNode;
	}

	length++;
}


void sortedList::deleteItem(string item)
{
	node* location = listData;
	node* prevLoc;
	node* tempLocation = NULL;
	location = listData;
	prevLoc = NULL;
	bool moreToSearch = (location != NULL);
	bool found = false;

	if (item == location->data)
	{
		found = true;
		tempLocation = location;
		listData = listData->next;
	}
	else
	{
		while (moreToSearch)
		{
			if (item == location->data)
			{
				
				found = true;
				moreToSearch = false;
				tempLocation = location;
				prevLoc->next = location->next;
			}
			else if (item < location->data)
			{
				prevLoc = location;
				location = location->next;
				moreToSearch = (location != NULL);
			}
			else
			{
				moreToSearch = false;
				break;
			}
		}
	}
	if (found)
	{
		cout << item << " has been deleted."<<endl;
		delete tempLocation;
		length--;
	}
	

}


void sortedList::resetList()
{
	currentPos = NULL;
}


string sortedList::getNextItem()
{
	if (currentPos == NULL)
		currentPos = listData;
	else
		currentPos = currentPos->next;
	return currentPos->data;
}
//Function that finds the first word in descending order that begins with input letter.
string sortedList::findWordStartWith(char startAlphabet)
{
	cout << "Searching for first word that begins with " << startAlphabet << "..."<<endl;
	string item;
	resetList();
	for (int i = 0; i < length; i++)
	{
		//cout << "length check:" << length<<endl;
		item= getNextItem();
		//cout <<"ItemCharOne: "<< itemCharOne << endl;
		if (item[0] == startAlphabet)
		{
			cout << "Word found: " << endl;
			return item;
		}
	}
	item ="No string in list beginning with character: ";
	item += startAlphabet;
	return item;
}
//Removes middle part of link list. In the event the length of the list is odd, the split value, splitter, is increased by one.
//If length is less than 2, the middle node cannot be removed.
bool sortedList::removeMiddleNode()
{
	string item;
	bool removeMidCheck = false;
	resetList();
	if (length > 1)
	{
		int splitter = (length / 2);
		if (length % 2 == 1)
			splitter =splitter+ 1;
		for (int i = 0; i < splitter; i++)
			item = getNextItem();
		//cout << item<<" item check"<<endl;
		
		deleteItem(item);
		return true;
	}
	return false;	
}
//Prints list in ascending order rather than descending.
void sortedList::displayListBackwards()
{

	resetList();
	string item;
	//counter variable for testin
	//int counter = 0;
	for (int j = length; j > 0; j--) 
	{
		//counter = 0;
		resetList();
		for (int i = j; i > 0; --i)
		{
		
			//counter++;
			item = getNextItem();
		}
		//cout << counter;
		cout << item << " ";
	}
	cout << endl<<endl;
}


void sortedList::printList()
{
	resetList();
	string item;
	for (int i = 0; i < length; i++)
	{
		item = getNextItem();
		cout << item<< " ";
	}
	cout << endl<<endl;
}


