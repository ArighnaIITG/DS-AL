// This program is concerned with deleting of a tree.
// To delete a tree, we must traverse all the nodes, and delete them one by one.
// Therefore, we should use Postorder Traversal, because before deleting parent nodes, we should delete children nodes first.

// Time Complexity = O(n)
// Space Complexity = O(1). If we consider stack size for function calls, then it's O(n).

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
		void _deleteTree(TreeNode** treenode);
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

// This function changes root to NULL, after deleting the whole tree. This can help 
// access values using root pointer.
void TreeDeletion::_deleteTree(TreeNode** treenode)
{
	deleteTree(*treenode);
	*treenode = NULL;
}

int main()
{
	TreeDeletion tdl;
	TreeNode* root = tdl.createNode(1);
	root->left = tdl.createNode(2);
	root->right = tdl.createNode(3);
	root->left->left = tdl.createNode(4);
	root->left->right =tdl.createNode(5);

	tdl._deleteTree(&root);
	root = NULL;

	cout << "Tree Deleted." << endl;
	return 0;
}

