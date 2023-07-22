// https://leetcode.com/problems/binary-tree-right-side-view/

#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
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
    void soln(TreeNode *root, int level, vector<int> &vect)
    {
        if (root == NULL)
            return;

        if (level == vect.size())
            vect.push_back(root->val);

        soln(root->right, level + 1, vect);
        soln(root->left, level + 1, vect);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> vect;
        int level = 0;

        soln(root, level, vect);

        return vect;
    }
};