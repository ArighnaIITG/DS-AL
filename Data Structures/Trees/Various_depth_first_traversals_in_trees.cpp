/*
  
   Program for implementing the various tree traversals.

   The various tree traversals are :

   1. Inorder - Left->Root->Right
   2. Preorder - Root->Left->Right
   3. Postorder - Left->Right->Root

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



