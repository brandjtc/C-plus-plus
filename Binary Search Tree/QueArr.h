#ifndef _QUEARR_H
#define _QUEARR_H

#include <iostream>
using namespace std;

template < class ItemType >
class QueArr
{
private: 
	int maxSize;
	int front;
	int rear;
	ItemType* items;

public:
	QueArr();
	QueArr(int size);

	void makeEmpty();
	bool isEmpty() const;
	bool isFull() const;

	void enque(ItemType item);
	void deque(ItemType& item);

	void printQue() const;

};
#include "QueArr.cpp"
#endif