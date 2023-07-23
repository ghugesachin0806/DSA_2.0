// https://leetcode.com/problems/path-sum-iii/description/

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
    void soln(TreeNode *root, int target, int &cnt, vector<int> vect)
    {
        if (root == NULL)
            return;

        vect.push_back(root->val);

        soln(root->left, target, cnt, vect);
        soln(root->right, target, cnt, vect);

        long long int sum = 0;
        for (int i = vect.size() - 1; i >= 0; i--)
        {
            sum += vect[i];
            if (sum == target)
                cnt++;
        }
    }
    int pathSum(TreeNode *root, int targetSum)
    {

        vector<int> vect;
        int cnt = 0;

        soln(root, targetSum, cnt, vect);

        return cnt;
    }
};