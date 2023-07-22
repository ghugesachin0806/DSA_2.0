// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;

        map<int, vector<int>> mt;
        queue<pair<TreeNode *, int>> qt;
        qt.push({root, 0});

        while (!qt.empty())
        {
            pair<TreeNode *, int> p = qt.front();
            mt[p.second].push_back(p.first->val);
            qt.pop();

            if (p.first->left)
                qt.push({p.first->left, p.second - 1});

            if (p.first->right)
                qt.push({p.first->right, p.second + 1});
        }

        for (auto it : mt)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};