#ifndef _QUEARR_CPP
#define _QUEARR_CPP
#include "QueArr.h"

template <class ItemTypes>
QueArr<ItemTypes>::QueArr()
{
    maxSize = 100;
    front = 0;
    rear = 0;
    items = new ItemTypes[maxSize];
}

template <class ItemTypes>
QueArr<ItemTypes>::QueArr(int size)
{
    maxSize = size;
    front = 0;
    rear = 0;
    items = new ItemTypes[maxSize];
}

template<class ItemTypes>
QueArr<ItemTypes>::~QueArr()
{
    delete[] items;
}

template <class ItemTypes>
bool QueArr<ItemTypes>::isEmpty()
{
    return (rear == front);
}

template <class ItemTypes>
bool QueArr<ItemTypes>::isFull()
{
    return (maxSize == rear);
}

template <class ItemTypes>
void QueArr<ItemTypes>::enque(ItemTypes item)
{
    if (isFull())
        cout << "Que is Full and item cannot be added" << endl;
    else
    {
        items[rear] = item;
        rear++;
    }
}

template <class ItemTypes>
void QueArr<ItemTypes>::deque()
{
    if (isEmpty())
        cout << "Que is empty and nothing to be Dequed" << endl;
    else
    {
        for (int i = 0; i < rear - 1; i++)
            items[i] = items[i + 1];
        rear--;
    }
}

template<class ItemTypes>
ItemTypes QueArr<ItemTypes>::frontMan()
{
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
        return NULL;
    }
    else
    {
        return items[front];
    }
}

template<class ItemTypes>
ItemTypes QueArr<ItemTypes>::rearMan()
{
    if (isEmpty())
    {
        cout << "Que is Empty" << endl;
        return NULL;
    }
    else
    {
        return items[rear];
    }
}

template <class ItemTypes>
void QueArr<ItemTypes>::printQue() const
{
    int temp;
    if (isEmpty())
        cout << "Queue is Empty" << endl;
    for (temp = front; temp < rear; temp++)
        cout << items[temp] << " ";
}

#endif