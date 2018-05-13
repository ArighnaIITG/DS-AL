// This program converts a binary tree into its mirror counterpart.
// Reference - https://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/

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

void mirrorTree(TreeNode* node)
{
	if(node == NULL)
		return;

	else
	{
		TreeNode* temp;

		mirrorTree(node->left);
		mirrorTree(node->right);

		temp = node->left;
		node->left = node->right;
		node->right = temp;
	}
}

void inorder(TreeNode* node)
{
	if(node == NULL)
		return;

	inorder(node->left);
	cout << node->data << "-";
	inorder(node->right);
}

int main()
{
	TreeNode *root = newNode(1);  
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);

	cout << "Inorder traversal of the original tree - ";
	inorder(root);
	cout << endl;

	mirrorTree(root);
	cout << "Inorder traversal of the mirror tree - ";
	inorder(root);
	cout << endl;

	return 0;
}
