// https://leetcode.com/problems/path-sum/

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
    bool soln(TreeNode *root, int temp, int &target)
    {
        if (root == NULL)
            return false;

        if (root->left == NULL && root->right == NULL)
        {
            if (temp + root->val == target)
                return true;
            else
                return false;
        }

        bool b1 = false;
        bool b2 = false;

        b1 = soln(root->left, temp + root->val, target);
        b2 = soln(root->right, temp + root->val, target);

        return b1 || b2;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {

        return soln(root, 0, targetSum);
    }
};