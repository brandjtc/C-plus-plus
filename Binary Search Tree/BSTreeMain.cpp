// File:    BSTreeMain.cpp
// Project: CSIS3400 Assignment 10
// Author:  Brandon Catalano 
// History:  1.0 Nov 12th, 2022
#include "BSTree.h"

#include <string>

int main()
{
	//v
	BSTree<char> charBST;
	charBST.printTree();

	charBST.addItemIter('B');
	charBST.addItemIter('F');
	charBST.printTree();

	charBST.addItemIter('A');
	charBST.addItemIter('C');
	charBST.printTree();

	charBST.addItemIter('E');
	charBST.addItemIter('G');
	charBST.printTree();
	//charBST.deleteItemIter('C');
	//charBST.printTree();
	char* j;
	j = charBST.calcRangeBrandon();
	cout << "Max: " << j[0] << endl << "Min: " << j[1] << endl;
	
	OrderType ot = Post_Order;
	
	charBST.resetTree(ot);
	bool finished = false;
	while (finished == false)
		cout << charBST.getNextItem(ot, finished) << " ";
	cout << endl;
	cout << "char BST One child node count: " << charBST.computeOneChildNodesBrandon() << endl;
	cout << "char BST non-leaf node count: " << charBST.countNonLeavesBrandon() << endl;
	charBST.deleteAllNodesBrandon();
	
	BSTree< string > sBST;
	sBST.addItem("Mat");
	sBST.addItem("Cat");
	sBST.addItem("Rat");
	sBST.addItem("Bat");
	sBST.addItem("Sat");
	sBST.addItem("Dat");
	sBST.addItem("Pat");
	cout << "sBST Nonleaf tree: " << sBST.countNonLeavesBrandon() << endl;
	sBST.printTree();

	sBST.deleteItem("Mat");

	ot = Pre_Order;
	sBST.resetTree(ot);
	bool finito = false;
	while (finito == false)
		cout << sBST.getNextItem(ot, finito) << " ";
	cout << endl;

	bool found = false;
	sBST.getItem("Rat", found);
	if (found)
		cout << "Rat is found" << endl;
	else
		cout << "Rat is not found in the tree." << endl;

	sBST.getItem("Eat", found);
	if (found)
		cout << "Eat is found" << endl;
	else
		cout << "Eat is not found in the tree." << endl;




	return 0;
}