// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    void soln(TreeNode *root, queue<TreeNode *> &qt)
    {
        if (root == NULL)
            return;

        qt.push(root);
        soln(root->left, qt);
        soln(root->right, qt);
    }

    void flatten(TreeNode *root)
    {

        queue<TreeNode *> qt;
        soln(root, qt);

        if (root == NULL)
            return;

        TreeNode *temp = qt.front();
        qt.pop();

        while (!qt.empty())
        {
            temp->right = qt.front();
            temp->left = NULL;

            temp = qt.front();
            qt.pop();
        }
    }
};