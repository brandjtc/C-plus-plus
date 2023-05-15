#ifndef _QUEARR_CPP
#define _QUEARR_CPP

#include "QueArr.h"

template <class ItemType>
QueArr<ItemType>::QueArr()
{
	maxSize = 10;
	front = 0;
	rear = 0;
	items = new ItemType[maxSize];
}

template <class ItemType>
QueArr<ItemType>::QueArr( int size)
{
	maxSize = size;
	front = 0;
	rear = 0;
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
	return ( rear==maxSize);
}

template <class ItemType>
void QueArr<ItemType>::enque(ItemType item)
{
	if (isFull())
		cout << "";
		//cout << "Que is Full and item cannot be added" << endl;
	else
	{
		items[rear] = item;
		rear++;

	}
}

template <class ItemType>
void QueArr<ItemType>::deque()
{
	if (isEmpty())
		cout << "";
		// cout << "Que is empty and nothing to be Dequed" << endl;
	else
	{
		front++;
	}
}

template <class ItemType>
ItemType QueArr<ItemType>::first()
{
	return items[front];

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