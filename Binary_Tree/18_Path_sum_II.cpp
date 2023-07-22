// https://leetcode.com/problems/path-sum-ii/

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
    void soln(TreeNode *root, int &target, int temp, vector<int> vect, vector<vector<int>> &ans)
    {
        if (root == NULL)
            return;

        temp = temp + root->val;
        vect.push_back(root->val);

        if (root->left == NULL && root->right == NULL)
        {
            if (temp == target)
                ans.push_back(vect);
            return;
        }

        soln(root->left, target, temp, vect, ans);
        soln(root->right, target, temp, vect, ans);
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {

        vector<vector<int>> ans;

        soln(root, targetSum, 0, vector<int>(), ans);

        return ans;
    }
};