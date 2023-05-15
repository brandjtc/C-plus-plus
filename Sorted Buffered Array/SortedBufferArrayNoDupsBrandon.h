// File:    SortedBufferArrayNoDupsBrandon.h
// Project: CSIS3400 Assignment 4 
// Author:  Brandon Catalano 
// History:  1.2 Sept 23rd, 2022#pragma once
#include <iostream>
#include "SortedBufferArrayWithDupsBrandon.h"
using namespace std;

class SortedBufferArrayNoDupsBrandon : public SortedBufferArrayWithDupsBrandon
{
public:
	//Constructors
	SortedBufferArrayNoDupsBrandon();
	SortedBufferArrayNoDupsBrandon(int buffer);



	//Accessors
	


	//Operations
	bool insert(int insInpy);
};