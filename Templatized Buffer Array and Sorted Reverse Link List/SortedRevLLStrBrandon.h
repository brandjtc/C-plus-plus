// File:    SortedRevLLStrBrandon.h
// Project: CSIS3400 Assignment 5 
// Author:  Brandon Catalano 
// History:  1.0 Sept 30th, 2022

#include <iostream>
using namespace std;


class node
{
public:
	string data;
	node* next;
};


class sortedList
{
private:
	node* listData;
	int length;
	node* currentPos;

public:
	sortedList(); //No arg constructor
	void makeEmpty();
	bool isFull();
	int getLength();

	bool findItem(string item);
	void putItem(string item);
	void deleteItem(string item);
	void resetList();
	string getNextItem();
	string findWordStartWith(char startAlphabet);
	bool removeMiddleNode();
	void displayListBackwards();

	void printList();
};


