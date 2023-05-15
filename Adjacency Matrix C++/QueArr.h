#pragma once
#ifndef _QUEARR_H
#define _QUEARR_H
#include <iostream>
using namespace std;

template <class ItemTypes>
class QueArr
{
private:
    int maxSize;
    int front;
    int rear;
    ItemTypes* items;
public:
    QueArr();
    QueArr(int size);
    ~QueArr();

    bool isEmpty();
    bool isFull();

    void enque(ItemTypes item);
    void deque();

    ItemTypes frontMan();
    ItemTypes rearMan();

    void printQue() const;
};
#include "QueArr.cpp"
#endif
