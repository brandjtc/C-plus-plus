#ifndef _QUEARR_CPP
#define _QUEARR_CPP

#include "QueArr.h"

template <class ItemType>
QueArr<ItemType>::QueArr()
{
	maxSize = 10;
	front = maxSize - 1;
	rear = maxSize - 1;
	items = new ItemType[maxSize];
}

template <class ItemType>
QueArr<ItemType>::QueArr( int size)
{
	maxSize = size;
	front = maxSize - 1;
	rear = maxSize - 1;
	items = new ItemType[maxSize];
}

template <class ItemType>
bool QueArr<ItemType>::isEmpty() const
{
	return (rear == front);
}

template <class ItemType>
bool QueArr<ItemType>::isFull() const
{
	return ( (rear+1)%maxSize == front);
}

template <class ItemType>
void QueArr<ItemType>::enque(ItemType item)
{
	if (isFull())
		cout << "Que is Full and item cannot be added" << endl;
	else
	{
		rear = (rear + 1) % maxSize;
		items[rear] = item;
	}
}

template <class ItemType>
void QueArr<ItemType>::deque(ItemType& item)
{
	if (isEmpty())
		cout << "Que is empty and nothing to be Dequed" << endl;
	else
	{
		front = (front + 1) % maxSize;
		item = items[front];
	}
}

template <class ItemType>
void QueArr<ItemType>::printQue() const
{
	int temp = front;
	while (temp != rear)
	{
		temp = (temp + 1) % maxSize;
		cout << items[temp] << " ";
	}
	cout << endl;
}




#endif