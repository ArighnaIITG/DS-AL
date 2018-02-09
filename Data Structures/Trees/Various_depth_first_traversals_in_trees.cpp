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
	TreeNode *root = newTreeNode(1);
	root->left = newTreeNode(2);
	root->right = newTreeNode(3);
	root->left->left = newTreeNode(4);
	root->left->right = newTreeNode(5);

	cout << "\nPreorder traversal of binary tree is \n" << endl;
    printPreorder(root);
 
    cout << "\nInorder traversal of binary tree is \n" << endl;
    printInorder(root);  
 
    cout << "\nPostorder traversal of binary tree is \n" << endl;
    printPostorder(root);

    return 0;
}
