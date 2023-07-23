// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *soln(TreeNode *root, TreeNode *n1, TreeNode *n2)
    {
        if (root == NULL)
            return NULL;

        if (root == n1 || root == n2)
            return root;

        TreeNode *temp1 = soln(root->left, n1, n2);
        TreeNode *temp2 = soln(root->right, n1, n2);

        if (temp1 && temp2)
            return root;
        else if (temp1)
            return temp1;
        else
            return temp2;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return soln(root, p, q);
    }
};