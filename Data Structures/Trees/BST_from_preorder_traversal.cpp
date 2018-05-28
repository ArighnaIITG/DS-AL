#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}

TreeNode* newNode(int data)
{
	TreeNode* treenode = new TreeNode;
	treenode->data = data;
	treenode->left = NULL;
	treenode->right = NULL;
	return treenode;
}

// This function gives O(n^2) time complexity.
TreeNode* constructTreeFromUtil(int pre[], int* preindex, int low, int high, int size)
{
	// Base Case
	if(*preindex >= size || low > high)
		return NULL;

	TreeNode* root = newNode(pre[*preindex]);
	*preindex = *preindex + 1;

	// If the tree has only one element, no need to recur.
	if(low == high)
		return root;

	for(int i=low; i<=high; ++i)
	{
		if(pre[i] > root->data)
			break;
	}

	root->left = constructTreeFromUtil(pre, preindex, *preindex, i-1, size);
	root->right = constructTreeFromUtil(pre, preindex, i, high, size);

	return root;
}

TreeNode* constructTree(int pre[], int size)
{
	int preindex = 0;
	return constructTreeFromUtil(pre, &preindex, 0, size-1, size);
}

/* 
	The following snippet will provide another way to construct a BST from its preorder traversal,
	in O(n) time complexity.
	The idea is to use a range for each node of the tree. Range - (INT_MIN, INT_MAX)
	The first element is the root node. To construct the left subtree, set the range as (INT_MIN, root->data).
	To construct the right subtree, set the range as (root->data, INT_MAX).


TreeNode* constructTreeFromUtil(int pre[], int* preindex, int key, int min, int max, int size)
{
	if(*preindex >= size)
		return;

	TreeNode* root = NULL;

	if(key > min && key < max)
	{
		root = newNode(key);
		*preindex = *preindex + 1;

		if(*preindex < size)
		{
			root->left = constructTreeFromUtil(pre, *preindex, pre[*preindex], min, key, size);
			root->right = constructTreeFromUtil(pre, *preindex, pre[*preindex], key, max, size);
		}
	}
	return root;
}

TreeNode* constructTree(int pre[], int size)
{
	int *preindex = 0;
	return constructTreeFromUtil(pre, *preindex, pre[0], INT_MIN, INT_MAX, size);
}

*/
void printInorder (TreeNode* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}
 
// Driver program to test above functions
int main ()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );
 
    TreeNode *root = constructTree(pre, size);
 
    printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);
 
    return 0;
}