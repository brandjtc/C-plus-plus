// File:    BufferArrayBrandon.h
// Project: CSIS3400 Assignment 2 
// Author:  Brandon Catalano 
// History:  1.2 Sept 3rd, 2022
#pragma once
#include <iostream>
using namespace std;

class BufferArrayBrandon
{
private:
	const int BUFFER_SIZE = 12;
	int numberOfElements;
	int* intArray;
	int indexOf(int target);
public:
	//Constructors
	BufferArrayBrandon();

	//Accessors
	int getBUFFER_SIZE();
	int getNumberOfElements();
	

	//Operations
	bool stableRemove(int staRemInpy);
	bool insert(int insInpy);
	bool remove(int remInpy);
	bool find(int findInpy);
	void display();






};