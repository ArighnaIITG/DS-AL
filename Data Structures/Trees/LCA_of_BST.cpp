// This program finds out the lowest common ancestor of a Binary Search Tree. For more information ,
// visit the reference :- https://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/

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

TreeNode* findLCA(TreeNode* node, int n1, int n2)
{
	if(node == NULL)
		return NULL;

	if(node->data > n1 && node->data > n2)
		return findLCA(node->left, n1, n2);

	if(node->data < n1 && node->data < n2)
		return findLCA(node->right, n1, n2);

	return node;
}

int main()
{
	TreeNode* root = NULL;
	root = newNode(20);
	root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);

    int n1 = 10, n2 = 14;
    TreeNode* node = findLCA(root, n1, n2);
    cout << "LCA of BST is :- " << node->data << endl;

    return 0;
}