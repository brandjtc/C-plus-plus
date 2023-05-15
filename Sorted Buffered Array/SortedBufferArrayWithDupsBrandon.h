// File:    SortedBufferArrayWithDupsBrandon.h
// Project: CSIS3400 Assignment 4 
// Author:  Brandon Catalano 
// History:  1.2 Sept 23rd, 2022
#pragma once
#include <iostream>
using namespace std;

class SortedBufferArrayWithDupsBrandon
{
protected:
	int BUFFER_SIZE;
	int numberOfElements;
	int* intArray;
	int indexOf(int target);
	void swap(int& swapInp1, int& swapInp2);
	bool quietBubbleSort();
	bool quietCheckSort();
public:
	//Constructors
	SortedBufferArrayWithDupsBrandon();
	SortedBufferArrayWithDupsBrandon(int buff);

	//Accessors
	int getBUFFER_SIZE();
	int getNumberOfElements();


	//Operations
	bool stableRemove(int staRemInpy);
	bool insert(int insInpy);
	bool quickRemove(int remInpy);
	bool find(int findInpy);
	void display();
	int findAll(int target);
	int quickRemoveAll(int target);
	int stableRemoveAll(int target);






};
