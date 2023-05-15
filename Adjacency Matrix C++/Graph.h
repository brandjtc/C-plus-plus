// File:    Graph.h
// Project: CSIS3400 Assignment 12
// Author:  Brandon Catalano 
// History:  1.0 Nov 29th, 2022

#ifndef _GRAPH_H
#define _GRAPH_H
#include <iostream>
#include "StackArr.h"
#include "QueArr.h"
using namespace std;
template <class ItemType>
class Graph
{
public:
	Graph();
	Graph(int maxV);
	~Graph();
	bool isEmpty() const;
	bool isFull() const;
	void addVertex(ItemType item);
	int indexIs(ItemType* vertices, ItemType vertex);
	void addEdge(ItemType item1, ItemType item2, int wt);
	int getWeight(ItemType item1, ItemType item2);
	void markVertex(ItemType item);
	bool isMarked(ItemType item);
	void clearMarks();
	void depthFirstSearch(int startVertex);
	void breadthFirstSearch_Brandon(int startVertex);
	int getAdjUnmarkedVertex(ItemType item);
	void depthFirstSearchRec_Brandon(int recVertex);
	void depthFirstHelper(int recVertex);
	void adjMatrixDisplay();
private:
	int numVertices;
	int maxVertices = 20;
	ItemType* vertices;
	int edge[20][20];
	bool* marks;
};
#include "Graph.cpp"
#endif