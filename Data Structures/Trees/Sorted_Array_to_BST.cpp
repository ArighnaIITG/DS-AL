// This program converts a sorted array to a BST.

#include <bits/stdc++.h>
#include <iostream>

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

TreeNode* constructBST(int arr[], int start, int end)
{
	if(start > end)
		return NULL;

	int mid = (start + end)/2;

	TreeNode* root = NULL;
	root = newNode(arr[mid]);

	root->left = constructBST(arr, start, mid-1);
	root->right = constructBST(arr, mid+1, end);

	return root;
}

void preorder(TreeNode* node)
{
	if(node == NULL)
		return;

	cout << node->data << " ";
	preorder(node->left);
	preorder(node->right);
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int n = sizeof(arr)/sizeof(arr[0]);

	TreeNode* root = constructBST(arr, 0, n-1);

	cout << "Preorder traversal of the tree is :- " << endl;
	preorder(root);

	return 0;
}

// Worst Case Time Complexity = O(n)
/* T(n) = 2T(n/2) + C
  T(n) -->  Time taken for an array of size n
   C   -->  Constant (Finding middle of array and linking root to left 
                      and right subtrees take constant time) 
*/
