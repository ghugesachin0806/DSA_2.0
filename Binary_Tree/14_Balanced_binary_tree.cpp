// https://leetcode.com/problems/balanced-binary-tree/

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
    pair<int, bool> soln(TreeNode *root)
    {
        if (root == NULL)
            return {0, true};

        pair<int, bool> p1 = soln(root->left);
        pair<int, bool> p2 = soln(root->right);

        int h = max(p1.first, p2.first) + 1;

        bool b = false;
        if (abs(p1.first - p2.first) <= 1)
            b = true;

        b = b && p1.second && p2.second;

        return {h, b};
    }
    bool isBalanced(TreeNode *root)
    {

        return soln(root).second;
    }
};