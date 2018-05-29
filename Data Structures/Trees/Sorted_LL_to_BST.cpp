// This program converts a sorted Linked list to a balanced BST. (Height balanced).

#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct LLNode
{
	int data;
	struct LLNode* next;
};

struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
};

void pushNode(LLNode** head_ref, int data)
{
	LLNode* newnode = new LLNode;
	newnode->data = data;
	newnode->next = *head_ref;
	*head_ref = newnode;
}

TreeNode* newNode(int data)
{
	TreeNode* treenode = new TreeNode;
	treenode->data = data;
	treenode->left = NULL;
	treenode->right = NULL;
	return treenode;
}

int countLLNodes(LLNode* head)
{
	int count = 0;
	LLNode* temp = head;
	while(temp)
	{
		temp = temp->next;
		count++;
	}
	return count;
}

TreeNode* constructLLToBST(LLNode** head_ref, int n)
{
	if(n <= 0)
		return NULL;

	TreeNode* left = constructLLToBST(head_ref, n/2);

	TreeNode* root = newNode((*head_ref)->data);
	root->left = left;

	(*head_ref) = (*head_ref)->next;

	root->right = constructLLToBST(head_ref, n-n/2-1);
	return root;
}

TreeNode* constructBST(LLNode* head)
{
	int n = countLLNodes(head);
	return constructLLToBST(&head, n);
}

void preOrder(TreeNode* node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}
 
/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    LLNode* head = NULL;
 
    /* Let us create a sorted linked list to test the functions
     Created linked list will be 1->2->3->4->5->6->7 */
    pushNode(&head, 7);
    pushNode(&head, 6);
    pushNode(&head, 5);
    pushNode(&head, 4);
    pushNode(&head, 3);
    pushNode(&head, 2);
    pushNode(&head, 1);
 
    /* Convert List to BST */
    TreeNode *root = constructBST(head);
    printf("\n PreOrder Traversal of constructed BST ");
    preOrder(root);
 
    return 0;
}