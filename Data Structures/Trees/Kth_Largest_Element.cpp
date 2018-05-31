// This program finds out the kth largest element in a Binary Saerch Tree. The opposite
// order can be followed for finding out the kth smallest element in a BST.

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
	node->left = node->right = NULL;
	return node;
}

void findElement(TreeNode* root, int k, int* c);

void findElementUtil(TreeNode* root, int k)
{
	int c = 0; // Keep count of nodes visited.
	findElement(root, k, &c); // c is passed as reference
}

void findElement(TreeNode* root, int k, int* c)
{
	if(root == NULL || *c >= k)
		return;

	// Performing reverse inorder traversal
	findElement(root->right, k, c);

	(*c)++;
	if((*c) == k)
	{
		cout << "K'th largest element is : " << root->data << endl;
		return;
	}

	findElement(root->left, k, c);
	// Perform inorder traversal for finding out the kth smallest node.
}

TreeNode* insert(TreeNode* node, int key)
{
	if(node == NULL)
		return newNode(key);

	if(key < node->data)
		node->left = insert(node->left, key);
	else if(key > node->data)
		node->right = insert(node->right, key);

	return node;
}

int main()
{
	TreeNode* root = NULL;
	root = insert(root, 50);
	insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    for(int k=1; k<=7; k++)
        findElementUtil(root, k);
 
    return 0;
}