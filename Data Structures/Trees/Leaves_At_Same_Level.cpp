// This program checks whether all the leaves are at the same level or not.
// Reference - https://www.geeksforgeeks.org/check-leaves-level/

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

bool checkUtil(TreeNode* node, int level, int leaflevel)
{
	if(node == NULL)
		return false;

	if(node->left == NULL && node->right == NULL)
	{
		if(leaflevel == 0)
		{
			leaflevel = level;
			return true;
		}
		return (level == leaflevel);
	}

	else
	{
		return checkUtil(node->left, level+1, leaflevel) && checkUtil(node->right, level+1, leaflevel);
	}
}

bool check(TreeNode* node)
{
	int level = 0;
	int leaflevel = 0;
	return checkUtil(node, level, leaflevel);
}

int main()
{
  	TreeNode *root = newNode(1);  
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);

	if(check(root))
		cout << "Leaves are at the same level." << endl;
	else
		cout << "Leaves are not at the same level." << endl;

	return 0;
}
