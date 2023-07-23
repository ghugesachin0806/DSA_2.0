// https://leetcode.com/problems/delete-node-in-a-bst/

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
    TreeNode *deleteNode(TreeNode *root, int key)
    {

        if (root == NULL)
            return NULL;

        if (root->val == key)
        {
            // 0 children
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            else if (root->left && root->right)
            {
                TreeNode *temp1 = root->left;
                TreeNode *temp2 = root->left;
                TreeNode *temp3 = root->right;

                while (temp1->right)
                {
                    temp1 = temp1->right;
                }

                temp1->right = temp3;

                delete root;
                return temp2;
            }
            else if (root->left)
            {
                TreeNode *temp = root->left;

                delete root;
                return temp;
            }
            else
            {
                TreeNode *temp = root->right;

                delete root;
                return temp;
            }
        }

        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
    }
};