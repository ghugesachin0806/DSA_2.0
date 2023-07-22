// https://leetcode.com/problems/same-tree/

#include<bits/stdc++.h>
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
    bool soln(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL && root2 == NULL)
            return true;
        if (root1 == NULL || root2 == NULL)
            return false;

        bool b1 = soln(root1->left, root2->left);
        bool b2 = soln(root1->right, root2->right);

        bool b3 = false;
        if (root1->val == root2->val)
            b3 = true;

        return b1 && b2 && b3;
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {

        return soln(p, q);
    }
};