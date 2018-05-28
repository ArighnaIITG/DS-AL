// This program converts a binary tree into a binary search tree.
// The 3 step solution has been given in https://www.geeksforgeeks.org/binary-tree-to-binary-search-tree-conversion/

#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <limits.h>

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

// A helper function that stores the inorder traversal of a tree.
void storeInorder(TreeNode* node, int inorder[], int* index_ptr)
{
	if(node == NULL)
		return;

	storeInorder(node->left, inorder, index_ptr);

	inorder[*index_ptr] = node->data;
	*index_ptr = *index_ptr + 1;

	storeInorder(node->right, inorder, index_ptr);
}

int countNodes(TreeNode* root)
{
	if(root == NULL)
		return 0;

	return (countNodes(root->left) + countNodes(root->right) + 1);
}

// Needed for quick sort
int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

void arrayToBST(TreeNode* node, int arr[], int *index_ptr)
{
	if(node == NULL)
		return;

	arrayToBST(node->left, arr, index_ptr);

	node->data = arr[*index_ptr];
	(*index_ptr)++;

	arrayToBST(node->right, arr, index_ptr);
}

void binaryToBST(TreeNode* root)
{
	if(root == NULL)
		return;

	int n = countNodes(root);

	int *arr = new int[n];
	int i = 0;
	storeInorder(root, arr, &i);

	// Sort the array. Quick Sort is used here. T.C. - O(nlogn)
	qsort(arr, n, sizeof(arr[0]), compare);

	i = 0;
	arrayToBST(root, arr, &i);

	// delete dynamically allocated array to avoid memory leak
	delete [] arr;
}

void printInorder(TreeNode* root)
{
	if(root == NULL)
		return;

	printInorder(root->left);
	cout << root->data << " ";
	printInorder(root->right);
}

int main()
{
	TreeNode* root = NULL;
	root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);
 	
 	binaryToBST(root);

 	cout << "Following is the inorder traversal of the BST : --" << endl;
 	printInorder(root);

 	return 0;
}