// This program is concerned with deleting of a tree.

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
};

class TreeDeletion
{
	public:
		TreeNode* createNode(int data);
		void deleteTree(TreeNode* treenode);
};

TreeNode* TreeDeletion::createNode(int data)
{
	TreeNode* treenode = new TreeNode;
	treenode->data = data;
	treenode->left = NULL;
	treenode->right = NULL;
	return treenode;
}

void TreeDeletion::deleteTree(TreeNode* treenode)
{
	if(treenode == NULL)
		return;

	// Performing a Postorder Traversal in the tree.
	deleteTree(treenode->left);
	deleteTree(treenode->right);

	cout << "Deleting the node : " << treenode->data << endl;
	free(treenode);
}

int main()
{
	TreeDeletion tdl;
	TreeNode* root = tdl.createNode(1);
	root->left = tdl.createNode(2);
	root->right = tdl.createNode(3);
	root->left->left = tdl.createNode(4);
	root->left->right =tdl.createNode(5);

	tdl.deleteTree(root);
	return 0;
}