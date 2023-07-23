// https://leetcode.com/problems/insert-into-a-binary-search-tree/

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
    void soln(TreeNode *root, int val)
    {
        if (root->val > val)
        {
            if (root->left)
                soln(root->left, val);
            else
                root->left = new TreeNode(val);
        }
        else
        {
            if (root->right)
                soln(root->right, val);
            else
                root->right = new TreeNode(val);
        }
    }
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {

        if (root == NULL)
            return new TreeNode(val);

        soln(root, val);
        return root;
    }
};