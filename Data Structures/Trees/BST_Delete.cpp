#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
};

TreeNode* newNode(int data)
{
	TreeNode* treenode = new TreeNode;
	treenode->data = data;
	treenode->left = NULL;
	treenode->right = NULL;
	return treenode;
}

void inorder(TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

TreeNode* minValueNode(TreeNode* root)
{
	TreeNode* current = root;

	while(current->left != NULL)
		current = current->left;

	return current;
}

TreeNode* deleteNode(TreeNode* root, int data)
{
	if(root == NULL)
		return root;

	if(root->data > data)
		root->left = deleteNode(root->left, data);
	else if(root->data < data)
		root->right = deleteNode(root->right, data);

	else
	{
		if(root->left == NULL)
		{
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}

		else if(root->right == NULL)
		{
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}

		TreeNode* temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key)
	}
	return root;
}

int main()
{
    TreeNode *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the given tree \n");
    inorder(root);

    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    return 0;
}