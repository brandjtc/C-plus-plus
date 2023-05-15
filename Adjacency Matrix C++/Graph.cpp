// File:    Graph.cpp
// Project: CSIS3400 Assignment 12
// Author:  Brandon Catalano 
// History:  1.0 Nov 29th, 2022

#ifndef _GRAPH_CPP
#define _GRAPH_CPP
#include "Graph.h"
template<class ItemType>
Graph<ItemType>::Graph()
{
	numVertices = 0;
	maxVertices = 20;
	vertices = new ItemType[20];
	marks = new bool[20];
}
template<class ItemType>
Graph<ItemType>::Graph(int maxV)
{
	numVertices = 0;
	maxVertices = maxV;
	vertices = new ItemType[maxV];
	marks = new bool[maxV];
}
template<class ItemType>
Graph<ItemType>::~Graph()
{
	delete[] vertices;
	delete[] marks;
}
template<class ItemType>
bool Graph<ItemType>::isEmpty() const
{
	return numVertices == 0;
}
template<class ItemType>
bool Graph<ItemType>::isFull() const
{
	return numVertices == maxVertices;
}
template<class ItemType>
void Graph<ItemType>::addVertex(ItemType item)
{
	vertices[numVertices] = item;
	for (int i = 0; i < numVertices; i++)
	{
		edge[numVertices][i] = 0;
		edge[i][numVertices] = 0;
	}
	numVertices++;
}
template<class ItemType>
int Graph<ItemType>::indexIs(ItemType* vertices, ItemType vertex)
{
	int index = 0;
	while (!(vertex == vertices[index]))
		index++;
	return index;
}
template<class ItemType>
void Graph<ItemType>::addEdge(ItemType fromVertex, ItemType
	toVertex, int wt)
{
	int row;
	int col;
	row = indexIs(vertices, fromVertex);
	col = indexIs(vertices, toVertex);
	edge[row][col] = wt;
}
template<class ItemType>
int Graph<ItemType>::getWeight(ItemType fromVertex, ItemType toVertex)
{
	int row;
	int col;
	row = indexIs(vertices, fromVertex);
	col = indexIs(vertices, toVertex);
	return edge[row][col];
}
template<class ItemType>
void Graph<ItemType>::markVertex(ItemType item)
{
	for (int index = 0; index < numVertices; index++)
	{
		if (vertices[index] == item)
		{
			marks[index] = true;
			return;
		}
	}
}
template<class ItemType>
bool Graph<ItemType>::isMarked(ItemType item)
{
	for (int index = 0; index < numVertices; index++)
	{
		if (vertices[index] == item)
		{
			return marks[index];
		}
	}
}
template<class ItemType>
void Graph<ItemType>::clearMarks()
{
	for (int index = 0; index < numVertices; index++)
	{
		marks[index] = false;
	}
}
template<class ItemType>
void Graph<ItemType>::adjMatrixDisplay()
{
	int x, y;
	cout << "  "; //display column heads
	for (x = 0; x < numVertices; x++)
		cout << vertices[x] << " ";
	cout << endl;
	for (x = 0; x < numVertices; x++)
		cout << "==";
	cout << "=";
	cout << endl;
	for (y = 0; y < numVertices; y++)
	{
		cout << vertices[y] << " ";
		for (x = 0; x < numVertices; x++)
			cout << edge[x][y] << " ";
		cout << endl;
	}
}
template<class ItemType>
void Graph<ItemType>::depthFirstSearch(int startVertex)
{
	StackArr<ItemType> theStack(10);
	ItemType vertex = vertices[startVertex];
	ItemType item;
	clearMarks();
	markVertex(vertex);
	cout << vertex << " ";
	theStack.push(vertex);
	while (!theStack.isEmpty())
	{
		int v = getAdjUnmarkedVertex(theStack.topView());
		if (v == -1)
			theStack.pop();
		else
		{
			item = vertices[v];
			markVertex(item);
			cout << item << " ";
			theStack.push(item);
		}
	}
	cout << endl;
}

//Breadth first search
template<class ItemType>
void Graph<ItemType>::breadthFirstSearch_Brandon(int startVertex)
{
	QueArr<ItemType> queue(10);
	ItemType vertex = vertices[startVertex];
	ItemType item;
	clearMarks();
	markVertex(vertex);
	cout << vertex << " ";
	queue.enque(vertex);
	while (!queue.isEmpty())
	{
		int q = getAdjUnmarkedVertex(queue.frontMan());
	
		if (q == -1)
			queue.deque();
		else
		{
			item = vertices[q];
			markVertex(item);
			cout << item << " ";
			queue.enque(item);
		}
	}
}

template<class ItemType>
int Graph<ItemType>::getAdjUnmarkedVertex(ItemType item)
{
	int v = -1;
	for (int index = 0; index < numVertices; index++)
	{
		if (vertices[index] == item)
			v = index;
	}
	if (v == -1)
		return v;
	for (int j = 0; j < numVertices; j++)
	{
		if (edge[j][v] == 1)
		{
			if (isMarked(vertices[j]) == false)
				return j;
		}
	}
	return -1;
}

//Recursion based depth-first, calls recursive helper function
template<class ItemType>
void Graph<ItemType>::depthFirstSearchRec_Brandon(int recVertex)
{
	clearMarks();
	ItemType vertex = vertices[recVertex];
	markVertex(vertex);
	cout << vertex << " ";
	depthFirstHelper(recVertex);
}

//Recursive Helper function for DFS.
template<class ItemType>
void Graph<ItemType>::depthFirstHelper(int recVertex)
{
	ItemType item;
	ItemType vertex = vertices[recVertex];

	while (getAdjUnmarkedVertex(vertex)!=-1)
	{
		int r = getAdjUnmarkedVertex(vertex);
		item = vertices[r];
		markVertex(item);
		cout << item << " ";
		depthFirstHelper(r);
	}

}
#endif