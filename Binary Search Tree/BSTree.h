// File:    BSTree.H
// Project: CSIS3400 Assignment 10
// Author:  Brandon Catalano 
// History:  1.1 Nov 15th, 2022
#ifndef _BSTREE_H_
#define _BSTREE_H

#include "QueArr.h"
#include <iostream>

using namespace std;

enum OrderType { Pre_Order, Post_Order, In_Order };

template <class ItemType>
class TreeNode
{
public:
	ItemType data;
	TreeNode* left;
	TreeNode* right;
};

template <class ItemType>
class BSTree
{
public:
	//Counts the amount of non-leaf nodes in the tree.
	int countNonLeavesBrandon();


	//Checks if given node exists within the binary tree and returns true if found.
	bool findNodeBrandon(TreeNode<ItemType>* tree,
		ItemType item,
		TreeNode<ItemType>*& nodePtr,
		TreeNode<ItemType>*& parentPtr);

	BSTree(); //No arg constructor
	~BSTree(); //Destructor

	//Function that deletes all nodes recursively using the destroy helper function.
	void deleteAllNodesBrandon();

	BSTree(const BSTree& origTree); //Copy constructor

	void operator = (const BSTree& origTree); //Assign operator

	void makeEmpty();
	inline bool isEmpty() const;
	bool isFull() const;
	inline int getLength() const;

	ItemType getItem(ItemType item, bool& found);

	//Returns array of largest & smallest nums
	ItemType* calcRangeBrandon();

	//Calculates amount of nodes with one child.
	int computeOneChildNodesBrandon();

	//Iterative add and delete
	void addItemIter(ItemType item);
	void deleteItemIter(ItemType item);

	void printTree();
	void resetTree(OrderType order);

	//Recursive add and delete
	void addItem(ItemType item);
	void deleteItem(ItemType item);

	ItemType getNextItem(OrderType order, bool& finished);

private:
	TreeNode<ItemType>* root;
	QueArr<ItemType> preQue;
	QueArr<ItemType> postQue;
	QueArr<ItemType> inQue;

	//Helper functions
	int oneChildCounter(TreeNode<ItemType>*& tree);
	int leafCounter(TreeNode<ItemType>*& tree);

	void destroy(TreeNode<ItemType>*& tree);
	void insert(TreeNode<ItemType>*& tree, ItemType& Item);


	int countNodes(TreeNode<ItemType>*& tree);
	void copyTree(TreeNode<ItemType>*& copy, TreeNode<ItemType>*& const origTree);

	void retrieve(TreeNode<ItemType>*& tree, ItemType& item, bool& found);
	void del(TreeNode<ItemType>*& tree, ItemType& item);

	void printNode(TreeNode<ItemType>*& tree);
	void deleteNode(TreeNode<ItemType>*& tree);

	void getPredecessor(TreeNode<ItemType>* tree, ItemType& item);

	void preOrder(TreeNode<ItemType>* tree, QueArr<ItemType>& q);
	void postOrder(TreeNode<ItemType>* tree, QueArr<ItemType>& q);
	void inOrder(TreeNode<ItemType>* tree, QueArr<ItemType>& q);

};

//#include "BSTree.cpp"
#endif

template <class ItemType>
BSTree<ItemType>::BSTree()
{
	root = NULL;
}

template <class ItemType>
BSTree<ItemType>::~BSTree()
{
	destroy(root);
}

template <class ItemType>
void BSTree<ItemType>::destroy(TreeNode<ItemType>*& tree)
{
	if (tree != NULL)
	{
		destroy(tree->left);
		destroy(tree->right);
		delete tree;
	}
}

template<class ItemType>
void BSTree<ItemType>::insert(TreeNode<ItemType>*& tree,
	ItemType& item)
{
	if (tree == NULL)
	{
		tree = new TreeNode<ItemType>;
		tree->data = item;
		tree->right = NULL;
		tree->left = NULL;
	}
	else if (item < tree->data)
		insert(tree->left, item);
	else
		insert(tree->right, item);

}

template<class ItemType>
int BSTree<ItemType>::countNodes(TreeNode<ItemType>*& tree)
{
	if (tree == NULL)
		return 0;
	else
		return(countNodes(tree->left) + countNodes(tree->right) + 1);
}

template<class ItemType>
void BSTree<ItemType>::copyTree(TreeNode<ItemType>*& copy, TreeNode<ItemType>*& const origTree)
{
	if (origTree == NULL)
		copy = NULL;
	else
	{
		copy = new TreeNode<ItemType>;
		copy->data = origTree->data;

		copyTree(copy->left, origTree->left);
		copyTree(copy->right, origTree->right);
	}
}

template<class ItemType>
void BSTree<ItemType>::retrieve(TreeNode<ItemType>*& tree,
	ItemType& item, bool& found)
{
	if (tree == NULL)
		found = false;
	else if (item < tree->data)
		retrieve(tree->left, item, found);
	else if (item > tree->data)
		retrieve(tree->right, item, found);
	else
	{
		item = tree->data;
		found = true;
	}

}

template<class ItemType>
void BSTree<ItemType>::del(TreeNode<ItemType>*& tree,
	ItemType& item)
{
	if (item < tree->data)
		del(tree->left, item);
	else if (item > tree->data)
		del(tree->right, item);
	else
		deleteNode(tree);

}

template<class ItemType>
void BSTree<ItemType>::printNode(TreeNode<ItemType>*& tree)
{
	if (tree == root)
		cout << "Roots data: " << root->data << endl;
	if (tree != NULL)
	{
		printNode(tree->left);
		cout << tree->data << " ";
		printNode(tree->right);
	}
}

template<class ItemType>
void BSTree<ItemType>::deleteNode(TreeNode<ItemType>*& tree)
{
	ItemType item;
	TreeNode<ItemType>* tempPtr;
	tempPtr = tree;

	if (tree->left == NULL)
	{
		tree = tree->right;
		delete tempPtr;
	}
	else if (tree->right == NULL)
	{
		tree = tree->left;
		delete tempPtr;
	}
	else
	{
		getPredecessor(tree->left, item);
		tree->data = item;
		del(tree->left, item);
	}
}

template<class ItemType>
void BSTree<ItemType>::getPredecessor(TreeNode<ItemType>* tree, ItemType& item)
{
	while (tree->right != NULL)
		tree = tree->right;
	item = tree->data;
}

//Function that deletes all nodes recursively using the destroy helper function.
template<class ItemType>
void BSTree<ItemType>::deleteAllNodesBrandon()
{
	destroy(root);
	root = NULL;
}

//Counts the number of one-child nodes nodes in the tree.
template<class ItemType>
int BSTree<ItemType>::computeOneChildNodesBrandon()
{
	int leafCount = 0;
	if (root != NULL)
	{
		leafCount = oneChildCounter(root);
	}

	return leafCount;
}
//Helper function for computeOneChildNodesBrandon
template<class ItemType>
int BSTree<ItemType>::oneChildCounter(TreeNode<ItemType>*& tree)
{
	if (tree == NULL)
		return 0;
	else if (tree->right == NULL && tree->left != NULL)
		return (oneChildCounter(tree->left) + 1);
	else if (tree->left == NULL && tree->right != NULL)
		return (oneChildCounter(tree->right) + 1);
	else
		return(oneChildCounter(tree->left) + oneChildCounter(tree->right) + 0);

}




//Counts the number of non-leaf nodes in the tree.
template<class ItemType>
int BSTree<ItemType>::countNonLeavesBrandon()
{
	int leafCount = 0;
	if (root != NULL)
	{
		leafCount = leafCounter(root);
	}

	return leafCount;
}
//Helper function for countNonLeavesBrandon
template<class ItemType>
int BSTree<ItemType>::leafCounter(TreeNode<ItemType>*& tree)
{

	//cout << "Data: " << tree->data << endl;

	if (tree == NULL)
	{
		//cout << "treenull" << endl;
		return 0;
	}
	else if ((tree->right == NULL) && (tree->left != NULL))
	{
		//cout << "tree right null" << endl;
		return (leafCounter(tree->left) + 1);
	}
	else if ((tree->left == NULL) && (tree->right != NULL))
	{
		//cout << "tree left null" << endl;
		return (leafCounter(tree->right) + 1);
	}
	else if (tree->left == NULL && tree->right == NULL)
	{
		//cout << "Tree left and right null" << endl;
		return 0;
	}
	else
	{
		//cout << "both left and right"<<endl;
		return(leafCounter(tree->left) + leafCounter(tree->right) + 1);
	}
}
//*/
template<class ItemType>
bool BSTree<ItemType>::findNodeBrandon(TreeNode<ItemType>* tree,
	ItemType item,
	TreeNode<ItemType>*& nodePtr,
	TreeNode<ItemType>*& parentPtr)
{
	nodePtr = tree;
	parentPtr = NULL;
	bool found = false;
	while (nodePtr != NULL && !found)
	{
		if (item < nodePtr->data)
		{
			parentPtr = nodePtr;
			nodePtr = nodePtr->left;
		}
		else if (item > nodePtr->data)
		{
			parentPtr = nodePtr;
			nodePtr = nodePtr->right;
		}
		else
			found = true;
	}
	return found;
}

template<class ItemType>
void BSTree<ItemType>::preOrder(TreeNode<ItemType>* tree, QueArr<ItemType>& q)
{
	if (tree != NULL)
	{
		preQue.enque(tree->data);
		preOrder(tree->left, preQue);
		preOrder(tree->right, preQue);
	}
}

template<class ItemType>
void BSTree<ItemType>::postOrder(TreeNode<ItemType>* tree, QueArr<ItemType>& q)
{
	if (tree != NULL)
	{
		postOrder(tree->left, postQue);
		postOrder(tree->right, postQue);
		postQue.enque(tree->data);
	}
}

template<class ItemType>
void BSTree<ItemType>::inOrder(TreeNode<ItemType>* tree, QueArr<ItemType>& q)
{

	if (tree != NULL)
	{
		inOrder(tree->left, inQue);
		inQue.enque(tree->data);
		inOrder(tree->right, inQue);
	}

}

template <class ItemType>
BSTree<ItemType>::BSTree(const BSTree& origTree)
{
	copyTree(root, origTree);
}

template <class ItemType>
void BSTree<ItemType>::operator=(const BSTree& origTree)
{
	if (&origTree == this)
		return;
	destroy(root);
	copyTree(root, origTree.root);
}

template<class ItemType>
void BSTree<ItemType>::makeEmpty()
{
	destroy(root);
	root = NULL;
}

template<class ItemType>
inline bool BSTree<ItemType>::isEmpty() const
{
	return root == NULL;
}

template<class ItemType>
bool BSTree<ItemType>::isFull() const
{
	TreeNode<ItemType>* location;
	try
	{
		location = new TreeNode<ItemType>;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}

template<class ItemType>
inline int BSTree<ItemType>::getLength() const
{
	return countNodes(root);
}

template<class ItemType>
ItemType BSTree<ItemType>::getItem(ItemType item, bool& found)
{
	retrieve(root, item, found);
	return item;
}

//Returns itemType array containing maximum and minimum value.
template<class ItemType>
ItemType* BSTree<ItemType>::calcRangeBrandon()
{
	TreeNode<ItemType>* temp = root;
	//declaration of return array
	static ItemType rangeArr[2];

	//Goes down left side of tree until leftmost and smallest node is found.
	while (temp->left != NULL)
		temp=temp->left;

	rangeArr[0] = temp->data;
	temp = root;

	//Goes down right side of tree until rightmost and greatest node is found.
	while (temp->right != NULL)
		temp = temp->right;

	rangeArr[1]=temp->data;


	return rangeArr;
}

template<class ItemType>
void BSTree<ItemType>::addItemIter(ItemType item)
{
	TreeNode<ItemType>* newNode;
	TreeNode<ItemType>* nodePtr;
	TreeNode<ItemType>* parentPtr;

	newNode = new TreeNode<ItemType>;
	newNode->data = item;
	newNode->left = NULL;
	newNode->right = NULL;

	findNodeBrandon(root, item, nodePtr, parentPtr);
	if (parentPtr == NULL)
		root = newNode;
	else if (item < parentPtr->data)
		parentPtr->left = newNode;
	else
		parentPtr->right = newNode;

}

template<class ItemType>
void BSTree<ItemType>::deleteItemIter(ItemType item)
{
	TreeNode<ItemType>* nodePtr;
	TreeNode<ItemType>* parentPtr;

	findNodeBrandon(root, item, nodePtr, parentPtr);

	if (nodePtr == root)
		deleteNode(root);
	else
	{
		if (parentPtr->left = nodePtr)
			deleteNode(parentPtr->left);
		else
			deleteNode(parentPtr->right);
	}
}

template<class ItemType>
void BSTree<ItemType>::printTree()
{
	if (root == NULL)
	{
		cout << "No nodes in the tree" << endl;
		return;
	}
	printNode(root);
	cout << endl;
}

template<class ItemType>
void BSTree<ItemType>::resetTree(OrderType order)
{
	switch (order)
	{
	case Pre_Order:
		preOrder(root, preQue);
		break;
	case Post_Order:
		postOrder(root, postQue);
		break;
	case In_Order:
		inOrder(root, inQue);
		break;


	}
}

template<class ItemType>
void BSTree<ItemType>::addItem(ItemType item)
{
	insert(root, item);
}

template<class ItemType>
void BSTree<ItemType>::deleteItem(ItemType item)
{
	del(root, item);
}

template<class ItemType>
ItemType BSTree<ItemType>::getNextItem(OrderType order, bool& finished)
{
	if (root != NULL)
	{
		ItemType item;
		finished = false;
		switch (order)
		{
		case Pre_Order:
			preQue.deque(item);
			if (preQue.isEmpty())
				finished = true;
			break;
		case Post_Order:
			postQue.deque(item);
			if (postQue.isEmpty())
				finished = true;
			break;
		case In_Order:
			inQue.deque(item);
			if (inQue.isEmpty())
				finished = true;
			break;

		}
		return item;
	}
	cout << "Tree is empty" << endl;
	return NULL;
}
