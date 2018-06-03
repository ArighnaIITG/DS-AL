#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode* left, *right;
};

TreeNode* newNode(int data)
{
    TreeNode* node = new TreeNode;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void printLevel(TreeNode* );
void printLevelOrder(TreeNode* ,int , bool);
int height(TreeNode* root)
{
    if(root == NULL)
        return 0;
        
    int lh = height(root->left);
    int rh = height(root->right);
    
    if(lh > rh)
        return (lh + 1);
    else return (rh+1);
}

void printLevel(TreeNode* root)
{
    int h = height(root);
    bool ltr = false;
    int count = 0;
    for(int i=1; i<=h; i++){
        printLevelOrder(root, i, ltr);
        count++;
        if (count == 2){
            ltr = !ltr;
            count = 0;
        }
        cout << endl;
    }
}

void printLevelOrder(TreeNode* root, int level, bool ltr)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1){
        if(ltr == false){
            printLevelOrder(root->left, level-1, ltr);
            printLevelOrder(root->right, level-1, ltr);
        }
        else if (ltr == true){
            printLevelOrder(root->right, level-1, ltr);
            printLevelOrder(root->left, level-1, ltr);
        }
    }
}

int main()
{
    TreeNode* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(3);
    root->left->right->right = newNode(1);
    root->right->left->left = newNode(4);
    root->right->left->right = newNode(2);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(2);
    root->left->right->left->left = newNode(16);
    root->left->right->left->right = newNode(17);
    root->right->left->right->left = newNode(18);
    root->right->right->left->right = newNode(19);
    
    printLevel(root);
    return 0;
}