// This program calculates the maximum depth of a tree.

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

int maxDepth(TreeNode* node)
{
	if (node == NULL)
		return 0;

	int ldepth = maxDepth(node->left);
	int rdepth = maxDepth(node->right);

	if(ldepth >= rdepth)
		return ldepth + 1;
	else
		return rdepth + 1;
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

	cout << "Maximum depth of the tree : " << maxDepth(root) << "." << endl;
	return 0;
}
