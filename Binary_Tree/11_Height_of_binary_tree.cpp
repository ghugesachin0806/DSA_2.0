// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

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
    int soln(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int temp1 = soln(root->left) + 1;
        int temp2 = soln(root->right) + 1;

        return max(temp1, temp2);
    }
    int maxDepth(TreeNode *root)
    {
        return soln(root);
    }
};