// File:    GraphMain.cpp
// Project: CSIS3400 Assignment 12
// Author:  Brandon Catalano 
// History:  1.0 Nov 29th, 2022

#include "Graph.h"
int main()
{
	Graph<char> theGraph;
	theGraph.addVertex('A');
	theGraph.addVertex('B');
	theGraph.addVertex('C');//3
	theGraph.addVertex('D');
	theGraph.addVertex('E');//5
	theGraph.addVertex('F');
	theGraph.addVertex('G');
	theGraph.addVertex('H');
	theGraph.addVertex('I');
	theGraph.addEdge('A', 'B', 1); //AB
	theGraph.addEdge('B', 'A', 1); //BA
	theGraph.addEdge('A', 'C', 1); //AC
	theGraph.addEdge('C', 'A', 1); //CA
	theGraph.addEdge('A', 'D', 1); //AD
	theGraph.addEdge('D', 'A', 1); //DA
	theGraph.addEdge('A', 'E', 1); //AE
	theGraph.addEdge('E', 'A', 1); //EA
	theGraph.addEdge('B', 'F', 1); //BF
	theGraph.addEdge('F', 'B', 1); //FB
	theGraph.addEdge('D', 'G', 1); //DG
	theGraph.addEdge('G', 'D', 1); //GD
	theGraph.addEdge('F', 'H', 1); //FH
	theGraph.addEdge('H', 'F', 1); //HF
	theGraph.addEdge('G', 'I', 1); //GI
	theGraph.addEdge('I', 'G', 1); //IG

	theGraph.adjMatrixDisplay();

	cout << endl;
	cout << "Depth First Search: " << endl;
	theGraph.depthFirstSearch(0);

	cout << "Depth First Search recursion:" << endl;
	theGraph.depthFirstSearchRec_Brandon(0);


	cout << endl;
	cout << "Breadth First Search Recursion: " << endl;
	theGraph.breadthFirstSearch_Brandon(0);
	return 0;
}