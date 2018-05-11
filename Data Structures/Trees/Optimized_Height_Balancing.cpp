// This is the optimized version of the Height Balancing program, to check whether a tree
// is height balanced or not.

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

bool isBalanced(TreeNode* node, int* height)
{
	if(node == NULL)
	{
		*height = 0;
		return 1;
	}

	int lh = 0, rh = 0; // Height of left and right subtree, respectively.
	int l = 0, r = 0;   // l and r will check if the left and the right subtrees are balanced respectively.

	l = isBalanced(node->left, &lh);
	r = isBalanced(node->right, &rh);

	*height = ((lh > rh)? lh: rh) + 1; // Get the height of the current node.

	if(abs(lh - rh) >= 2)
		return 0;

	else
		return (l && r);
}

int main()
{
    int height = 0;

  	TreeNode *root = newNode(1);  
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->left->left->left = newNode(7);
	 
	if(isBalanced(root, &height))
	    printf("Tree is balanced.");
	else
	    printf("Tree is not balanced.");    
	 
	return 0;
}