/*
  
   Program for implementing the various tree traversals.

   The various tree traversals are :

   1. Inorder - Left->Root->Right
   2. Preorder - Root->Left->Right
   3. Postorder - Left->Right->Root

   It will be implemented using a recursive strategy.

*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// Represents a tree node
struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;	
};

class TreeTraversal
{
	public:
		TreeNode* newTreeNode(int data);
		void printInorder(TreeNode* node);
		void printPostorder(TreeNode* node);
		void printPreorder(TreeNode* node);
};

TreeNode* TreeTraversal::newTreeNode(int data)
{
	TreeNode *newnode = new TreeNode;
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void TreeTraversal::printInorder(TreeNode* node)
{
	if(node == NULL)
		return;

	// Implemented the recurring strategy
	printInorder(node->left);
	cout << node->data << " - " ;
	printInorder(node->right);
}

void TreeTraversal::printPostorder(TreeNode* node)
{
	if(node == NULL)
		return;

	// Implemented the recurring strategy
	printInorder(node->left);
	printInorder(node->right);
	cout << node->data << " - " ;
}

void TreeTraversal::printPreorder(TreeNode* node)
{
	if(node == NULL)
		return;

	// Implemented the recurring strategy
	cout << node->data << " - " ;
	printInorder(node->left);
	printInorder(node->right);
}

int main()
{
	TreeTraversal tree;
	TreeNode *root = tree.newTreeNode(1);
	root->left = tree.newTreeNode(2);
	root->right = tree.newTreeNode(3);
	root->left->left = tree.newTreeNode(4);
	root->left->right = tree.newTreeNode(5);

	cout << "\nPreorder traversal of binary tree is \n" << endl;
    tree.printPreorder(root);
 
    cout << "\nInorder traversal of binary tree is \n" << endl;
    tree.printInorder(root);  
 
    cout << "\nPostorder traversal of binary tree is \n" << endl;
    tree.printPostorder(root);

    return 0;
}
