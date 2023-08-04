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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {

        if (root == NULL)
            return new TreeNode(val);

        TreeNode *temp = root;

        while (temp)
        {
            if (temp->val > val)
            {
                if (temp->left)
                    temp = temp->left;
                else
                {
                    temp->left = new TreeNode(val);
                    break;
                }
            }
            else
            {
                if (temp->right)
                    temp = temp->right;
                else
                {
                    temp->right = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};