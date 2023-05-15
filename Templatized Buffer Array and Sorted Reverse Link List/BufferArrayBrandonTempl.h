// File:    BufferArrayBrandonTempl.h
// Project: CSIS3400 Assignment 5 
// Author:  Brandon Catalano 
// History:  1.0 Sept 29th, 2022
#ifndef BUFFERARRAYBRANDONTEMPL_H_
#define BUFFERARRAYBRANDONTEMPL_H_
#pragma once
#include <iostream>
using namespace std;
template <class item>
class BufferArrayBrandonTempl
{
private:
	int BUFFER_SIZE = 12;
	int numberOfElements;
	item* anyArray;
	int indexOf(item target);
public:
	//Constructors
	BufferArrayBrandonTempl();
	

	//Accessors
	
	


	//Operations
	bool stableRemove(int staRemInpy);
	bool insert(item insInpy);
	bool remove(item remInpy);
	bool find(item findInpy);
	void display();






};
#include "BufferArrayBrandonTempl.cpp"
#endif