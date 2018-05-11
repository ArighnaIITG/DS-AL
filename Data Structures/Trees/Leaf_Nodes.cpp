// This program calculates the no. of leaf nodes in a tree.

#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
};

TreeNode* newNode(int data)
{
	TreeNode* treenode = new TreeNode;
	treenode->data = data;
	treenode->left = NULL;
	treenode->right = NULL;
	return treenode;
}

int noOfNodes(TreeNode* node)
{
	if(node == NULL)
		return 0;

	if(node->left == NULL && node->right == NULL)
		return 1;

	else
		return (noOfNodes(node->left) + noOfNodes(node->right));
}

int main()
{
  	TreeNode *root = newNode(1);  
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->left->left->left = newNode(7);
	 
	int number = noOfNodes(root);
	cout << "The number of leaf nodes are : " << number << "." << endl;  
	 
	return 0;
}