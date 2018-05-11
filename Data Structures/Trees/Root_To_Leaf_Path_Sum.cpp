// This program tells us whether the root to leaf path sum in any path in a binary tree,
// is equal to a given number.

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
};

class PathSum
{
	public:
		TreeNode* createNode(int data);
		bool hasPathSum(TreeNode* treenode, int data);
};

TreeNode* PathSum::createNode(int data)
{
	TreeNode* treenode = new TreeNode;
	treenode->data = data;
	treenode->left = NULL;
	treenode->right = NULL;
	return treenode;
}

bool PathSum::hasPathSum(TreeNode* treenode, int sum)
{
	if(treenode == NULL)
		return (sum == 0);

	else
	{
		bool ans = 0;
		int subsum = sum - treenode->data;

		if(subsum == 0 && treenode->left == NULL && treenode->right == NULL)
			return 1;

		if(treenode->left)
			ans = ans || hasPathSum(treenode->left, subsum);
		if(treenode->right)
			ans = ans || hasPathSum(treenode->right, subsum);

		return ans;
	}
}

int main()
{
	int sum = 21;
	PathSum ps;
	TreeNode* treenode = ps.createNode(10);
	treenode->left = ps.createNode(8);
	treenode->left->left = ps.createNode(3);
	treenode->right = ps.createNode(7);
	treenode->left->right = ps.createNode(6);

	bool result = ps.hasPathSum(treenode, sum);

	cout << result << endl;

	if (result == 1)
		cout << "The path sum is valid." << endl;
	else
		cout << "The path sum is invalid." << endl;

	return 0;
}
