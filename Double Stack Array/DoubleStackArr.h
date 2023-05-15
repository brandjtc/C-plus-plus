// File:    DoubleStackArr.h
// Project: CSIS3400 Assignment 6
// Author:  Brandon Catalano
// History:  1.0 Oct 7th, 2022
#ifndef DOUBLESTACKARR_H_
#define DOUBLESTACKARR_H_
#pragma once

template <class item>
class DoubleStackArr
{
private:	

	//Variables
	int numOfElements;
	int buffer;
	//Template
	item* inpArray;
	
public:
	//Constructors
	DoubleStackArr();
	DoubleStackArr(int bufferLength);
	//Operations
	void push(item input1, item input2);
	void pop();
	void top();
	bool isEmpty();



private:
	//Accessors
	int getBuffer();

};
#include "doubleStackArr.cpp"
#endif