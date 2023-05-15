// File:    qList_Brandon.h
// Project: CSIS3400 Assignment 7 
// Author:  Brandon Catalano 
// History:  1.1 Oct 25th, 2022
#pragma once
#ifndef QLIST_BRANDON_H
#define QLIST_BRANDON_H
#include <iostream>
using namespace std;
template<class Brandon>
struct qNode
{
	Brandon data;
	qNode<Brandon>* next;
};
template<class Brandon>
class qList_Brandon
{
private:
	//counts the amount of items in queue.
	int nodeCount;
	qNode<Brandon>* incrementorNode;
	qNode<Brandon>* front;
	qNode<Brandon>* rear;
	//Private helper function that increments the incrementorNode.
	void getNextItem();
public:
	//noarg constructor.
	qList_Brandon();
	bool isEmpty();
	bool isFull();
	void addToQue(Brandon item);
	void printQue();
	void operator +(Brandon item);
	bool findItemQue(Brandon item);
	void removeFromQue(Brandon& item);
};

#include "qList_Brandon.cpp"
#endif