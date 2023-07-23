// https://leetcode.com/problems/validate-binary-search-tree/

#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
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
    bool soln(TreeNode *root, long long max, long long min)
    {
        if (root == NULL)
            return true;

        if (root->val > min && root->val < max)
        {
            bool b1 = soln(root->left, root->val, min);
            bool b2 = soln(root->right, max, root->val);

            return b1 && b2;
        }
        else
            return false;
    }
    bool isValidBST(TreeNode *root)
    {

        return soln(root, LONG_LONG_MAX, LONG_LONG_MIN);
    }
};