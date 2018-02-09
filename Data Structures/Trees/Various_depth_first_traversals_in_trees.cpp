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

void printInorder(TreeNode* node)
{
	if(node == NULL)
		return;

	// Implemented the recurring strategy
	printInorder(node->left);
	cout << node->data << " - " ;
	printInorder(node->right);
}

void printPostorder(TreeNode* node)
{
	if(node == NULL)
		return;

	// Implemented the recurring strategy
	printInorder(node->left);
	printInorder(node->right);
	cout << node->data << " - " ;
}

void printPreorder(TreeNode* node)
{
	if(node == NULL)
		return;

	// Implemented the recurring strategy
	cout << node->data << " - " ;
	printInorder(node->left);
	printInorder(node->right);
}

