// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> soln(TreeNode *root)
    {
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        bool flag = false;
        vector<int> vect;
        queue<TreeNode *> qt;
        stack<TreeNode *> st;

        st.push(root);

        while (!st.empty())
        {
            TreeNode *temp = st.top();
            vect.push_back(temp->val);
            st.pop();

            if (flag == true)
            {
                if (temp->right)
                    qt.push(temp->right);
                if (temp->left)
                    qt.push(temp->left);
            }
            if (flag == false)
            {
                if (temp->left)
                    qt.push(temp->left);
                if (temp->right)
                    qt.push(temp->right);
            }

            if (st.empty())
            {
                ans.push_back(vect);
                vect.clear();

                flag = !flag;
                
                while (!qt.empty())
                {
                    st.push(qt.front());
                    qt.pop();
                }
            }
        }

        return ans;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        return soln(root);
    }
};