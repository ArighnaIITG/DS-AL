// This program prints out all the root-to-leaf paths in the tree, in any order.

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

void printArray(int arr[], int pathlen)
{
	for(int i=0; i < pathlen; i++)
		cout << arr[i] << " - ";
	cout << endl;
}

void printPathsRecur(TreeNode* node, int path[], int pathlen)
{
	if(node == NULL)
		return;

	path[pathlen] = node->data;
	pathlen++;

	if(node->left == NULL && node->right == NULL)
		printArray(path, pathlen);

	else
	{
		printPathsRecur(node->left, path, pathlen);
		printPathsRecur(node->right, path, pathlen);
	}
}

void printPaths(TreeNode* node)
{
	int path[1000];
	int pathlen = 0;
	printPathsRecur(node, path, pathlen);
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

	printPaths(root);
	return 0;
}
