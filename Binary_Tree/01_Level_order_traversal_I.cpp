// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    void soln(TreeNode *root, vector<vector<int>> &ans)
    {
        if (root == NULL)
            return;

        queue<TreeNode *> qt;
        vector<int> vect;
        qt.push(root);
        qt.push(NULL);

        while (!qt.empty())
        {
            TreeNode *temp = qt.front();
            qt.pop();

            if (temp == NULL)
            {
                ans.push_back(vect);
                if (!qt.empty())
                {
                    vect.clear();
                    qt.push(NULL);
                }
            }
            else
            {
                vect.push_back(temp->val);

                if (temp->left)
                    qt.push(temp->left);
                if (temp->right)
                    qt.push(temp->right);
            }
        }
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> vect;
        soln(root, vect);
        return vect;
    }
};