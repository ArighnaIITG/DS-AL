/* 
	
	BINARY SEARCH TREES (BST) :
	=========================

	Binary Search Tree, is a node-based binary tree data structure which has the following properties:

    	1. The left subtree of a node contains only nodes with keys less than the node’s key.
    	2. The right subtree of a node contains only nodes with keys greater than the node’s key.
    	3. The left and right subtree each must also be a binary search tree.
    	4. There must be no duplicate nodes.
	
	This program will implement how to search a given key and also insert a given node in a BST.
	Done by the recuresive strategy.

*/

#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
};

class BinarySearchTree
{
	public:
		TreeNode* newBSTNode(int data);
		void inorder(TreeNode* node);
		TreeNode* insertBSTNode(TreeNode* node, int key);
		TreeNode* searchBSTNode(TreeNode* node, int key);
}

TreeNode* BinarySearchTree::newBSTNode(int data)
{
	TreeNode *newnode = new TreeNode;
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void BinarySearchTree::inorder(TreeNode* root)
{
	if (root == NULL)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

