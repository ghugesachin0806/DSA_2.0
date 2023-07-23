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
        TreeNode *temp = root;

        while (temp)
        {
            if (temp->val == val)
                return temp;
            else if (temp->val > val)
                temp = temp->left;
            else
                temp = temp->right;
        }

        return temp;
    }
    TreeNode *searchBST(TreeNode *root, int val)
    {
        return soln(root, val);
    }
};