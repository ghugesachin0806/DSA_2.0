// https://leetcode.com/problems/search-in-a-binary-search-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *soln(TreeNode *root, int val)
    {
        if (root == NULL || root->val == val)
            return root;

        if (root->val > val)
            return soln(root->left, val);
        else
            return soln(root->right, val);
    }
    TreeNode *searchBST(TreeNode *root, int val)
    {
        return soln(root, val);
    }
};