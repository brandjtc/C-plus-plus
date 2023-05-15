// File:    SortDblLnkLst.h
// Project: CSIS3400 Assignment 8
// Author:  Brandon Catalano 
// History:  1.0 Oct 29th, 2022
#pragma once
#ifndef SORTDBLLNKLST_H
#define SORTDBLLNKLST_H
#include <iostream>
using namespace std;

template<class Brandon>
class Node
{
public:
    Brandon info;
    Node<Brandon>* next;
    Node<Brandon>* prev;
};

template<class Brandon>
class SortDblLnkLst
{
private:
    Node<Brandon>* listData;
    Node<Brandon>* incrementorNode;
    void resetList();
    bool isEmpty();
    Brandon getNextItem();
    int nodeCount;
    bool findItem(Brandon item);
public:
    SortDblLnkLst();
    ~SortDblLnkLst();
    void emptyList();
    SortDblLnkLst(const SortDblLnkLst& another);
    void operator = (const SortDblLnkLst& another);
    void putItem(Brandon item);
    void deleteItem(Brandon item);
    void printItems();
    void printItemsReverse();

};

#include "SortDblLnkLst.cpp"

#endif


