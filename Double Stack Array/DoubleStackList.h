// File:    DoubleStackList.h
// Project: CSIS3400 Assignment 6
// Author:  Brandon Catalano
// History:  1.0 Oct 7th, 2022
#pragma once
#ifndef DOUBLESTACKLIST_H_
#define DOUBLESTACKLIST_H_


template <class item>
class node
{
public:
	node* nextNode;
	item nodeData;
};

template <class item>
class DoubleStackList
{
private:
	void nodeBgone();
	//Nodes for linked list.
	node<item>* nodeList;
	node<item>* position;

	//Variables
	int numOfElements;
	int buffer;

public:
	//Constructors
	DoubleStackList();
	DoubleStackList(int);
	
	//Operations
	void push(item input1, item input2);
	void pop();
	void top();
	bool isEmpty();



};
#include "DoubleStackList.cpp"

#endif

