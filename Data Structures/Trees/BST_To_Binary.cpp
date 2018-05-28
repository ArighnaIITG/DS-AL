// This program converts a Binary Search Tree to a Binary Tree, where every original key is changed to key plus
// sum of all keys greater in BST.
// Use Reverse inorder traversal, and maintain a sum pointer.

// Reference :- https://www.geeksforgeeks.org/convert-bst-to-a-binary-tree/

#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
};

TreeNode* newNode(int data)
{
	TreeNode* node = new TreeNode;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void bstToBinary(TreeNode* node, int* sum_ptr)
{
	if(node == NULL)
		return;

	bstToBinary(node->right, sum_ptr);

	*sum_ptr = *sum_ptr + node->data;
	node->data = *sum_ptr;

	bstToBinary(node->left, sum_ptr);
}

void constructUtil(TreeNode* node)
{
	int sum_ptr = 0;
	bstToBinary(node, &sum_ptr);
}

void printInorder(TreeNode* node)
{
	if(node == NULL)
		return;

	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);
}

int main()
{
	TreeNode* root = NULL;
	root = newNode(5);
	root->left = newNode(2);
	root->right = newNode(13);

	constructUtil(root);

	cout << "Inorder traversal of the modified tree is : - " << endl;
	printInorder(root);

	return 0;
}