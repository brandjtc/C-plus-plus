// File:    BufferArrayNoDupsBrandon.h
// Project: CSIS3400 Assignment 3 
// Author:  Brandon Catalano 
// History:  1.1 Sept 10th, 2022
#pragma once
#include <iostream>
#include "BufferArrayBrandon.h"
using namespace std;

class BufferArrayNoDupsBrandon: public BufferArrayBrandon
{
private:
	int BUFFER_SIZE;
	int numberOfElements;
	int* intArray;
	int indexOf(int target);
public:
	//Constructors
	BufferArrayNoDupsBrandon();
	BufferArrayNoDupsBrandon(int buffer);



	//Accessors
	


	//Operations
	bool insert(int insInpy);
	void display();
	bool stableRemove(int staRemInpy);
	bool quickRemove(int remInpy);
	bool find(int findInpy);
};