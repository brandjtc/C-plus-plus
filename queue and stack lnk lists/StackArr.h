#ifndef _STACKARR_H
#define _STACKARR_H

#include <iostream>

using namespace std;

template <class ItemType>
class StackArr
{
private:
	int top;
	int maxStack;
	ItemType* items;
	int length;

public:
	StackArr();
	StackArr(int max);

	bool isEmpty();
	bool isFull();

	void push(ItemType item);
	void pop();

	ItemType topView();
	void printStack() const;
};
#include "StackArr.cpp"

#endif

