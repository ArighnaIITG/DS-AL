// This program finds out whether a tree is height balanced or not.(Logic used in AVL trees)..

/* Algorithm :

   An empty tree is height-balanced. A non-empty binary tree T is balanced if:

		1) Left subtree of T is balanced
		2) Right subtree of T is balanced
		3) The difference between heights of left subtree and right subtree is not more than 1. 
*/

// This is not optimized, since its Worst-Case Running Time Complexity is O(n^2), in case of skewed trees.

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

class HeightBalancing
{
	public:
		TreeNode* createNode(int data);
		int height(TreeNode* node);
		bool isBalanced(TreeNode* node);
		int max(int a, int b);
};

TreeNode* HeightBalancing::createNode(int data)
{
	TreeNode* node = new TreeNode;
	node->data =  data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

bool HeightBalancing::isBalanced(TreeNode* node)
{
	// If tree is empty
	if(node == NULL)
		return 1;

	int lh = height(node->left);   // Height of left subtree
	int rh = height(node->right);  // Height of right subtree

	if(abs(lh-rh)<=1 && isBalanced(node->left) && isBalanced(node->right))
		return 1;

	return 0;
}

int HeightBalancing::height(TreeNode* node)
{
	if(node == NULL)
		return 0;

	return (1 + max(height(node->left), height(node->right)));
}

int HeightBalancing::max(int a, int b)
{
	return (a >= b)? a :b;
}

int main()
{
	HeightBalancing hb;

	TreeNode* root = hb.createNode(1);
	root->left = hb.createNode(2);
    root->right = hb.createNode(3);
    root->left->left = hb.createNode(4);
    root->left->right = hb.createNode(5);
    root->left->left->left = hb.createNode(8);

    if(hb.isBalanced(root))
    	cout << "The tree is balanced." << endl;
    else
    	cout << "The tree is not balanced." << endl;

    return 0;
}
