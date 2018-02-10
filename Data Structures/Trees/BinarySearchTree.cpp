/* 
	
	BINARY SEARCH TREES (BST) :
	=========================

	Binary Search Tree, is a node-based binary tree data structure which has the following properties:

    	1. The left subtree of a node contains only nodes with keys less than the node’s key.
    	2. The right subtree of a node contains only nodes with keys greater than the node’s key.
    	3. The left and right subtree each must also be a binary search tree.
    	4. There must be no duplicate nodes.
	
	This program will implement how to search a given key and also insert a given node in a BST.
	Done by the recursive strategy.

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
		void inorder(TreeNode* root);
		TreeNode* insertBSTNode(TreeNode* root, int key);
		TreeNode* searchBSTNode(TreeNode* root, int key);
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

TreeNode* BinarySearchTree::insertBSTNode(TreeNode* root, int key)
{
	// If the tree is empty, then return a new node.
	if (root == NULL)
		return newBSTNode(key);

	// Now, recurring down the tree
	if (key < root->key)
		root->left = insertBSTNode(root->left, key);
	if (key > root->key)
		root-> right  insertBSTNode(root->right, key);

	// Return the unchanged root pointer
	return root;
}

TreeNode* BinarySearchTree::searchBSTNode(TreeNode* root, int key)
{
	if ((root == NULL) || (root->key == key))
		return root;

	// Else recur down the tree.
	if (key < root->key)
		searchBSTNode(root->left, key);
	if (key > root->key)
		searchBSTNode(root->right, key);
}

int main()
{
	BinarySearchTree bst;
	TreeNode *root = NULL;
	bst.insertBSTNode(root, 10);
	bst.insertBSTNode(root, 30);
    bst.insertBSTNode(root, 20);
    bst.insertBSTNode(root, 40);
    bst.insertBSTNode(root, 70);
    bst.insertBSTNode(root, 60);
    bst.insertBSTNode(root, 80);

    TreeNode *node = NULL;
    node = bst.searchBSTNode(root, 40);
    if (node == NULL)
    	cout << "Element not in Binary Search Tree.";
    else
    	cout << "Element is there !!";
}