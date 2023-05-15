#ifndef _STACKARR_CPP
#define _STACKARR_CPP
#include "StackArr.h"
template<class ItemType>
StackArr<ItemType>::StackArr()
{
    maxStack = 20;
    top = -1;
    items = new ItemType[maxStack];
    length = 0;
}
template<class ItemType>
StackArr<ItemType>::StackArr(int max)
{
    maxStack = max;
    top = -1;
    items = new ItemType[maxStack];
    length = 0;
}
template<class ItemType>
inline bool StackArr<ItemType>::isEmpty()
{
    return(top == -1);
}
template<class ItemType>
inline bool StackArr<ItemType>::isFull()
{
    return (top == (maxStack - 1));
}
template<class ItemType>
void StackArr<ItemType>::push(ItemType item)
{
    if (isFull())
        cout << "Stack is full and no more items can be added" << endl;
    else
    {
        top++;
        items[top] = item;
        length++;
    }
}
template<class ItemType>
void StackArr<ItemType>::pop()
{
    if (isEmpty())
        cout << "Stack is Empty and item cannot be popped" << endl;
    else
    {
        top--;
        length--;
    }
}
template<class ItemType>
ItemType StackArr<ItemType>::topView()
{
    if (isEmpty())
    {
        cout << "Stack is Empty and nothing at the top" << endl;
        return NULL;
    }
    else
    {
        return items[top];
    }
}
template<class ItemType>
void StackArr<ItemType>::printStack() const
{
    if (length == 0)
        cout << "Stack is empty" << endl;
    else
    {
        for (int i = 0; i < length; i++)
            cout << items[i] << " ";
        cout << endl;
    }
}
#endif