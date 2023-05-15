// File:    BufferArrayWithDupsBrandon.h
// Project: CSIS3400 Assignment 3 
// Author:  Brandon Catalano 
// History:  1.0 Sept 10th, 2022
#pragma once
#include <iostream>
#include "BufferArrayBrandon.h"
using namespace std;

class BufferArrayWithDupsBrandon : public BufferArrayBrandon
{
private:
	int BUFFER_SIZE;
	int numberOfElements;
	int* intArray;
	int indexOf(int target);
public:
	//Constructors
	BufferArrayWithDupsBrandon();
	BufferArrayWithDupsBrandon(int buff);

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
