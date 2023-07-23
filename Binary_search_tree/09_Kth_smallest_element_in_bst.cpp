

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

class Solution {
public:
void soln(TreeNode *root,queue<TreeNode*> &qt)
{
    if(root==NULL)
    return ;

    soln(root->left,qt);
    qt.push(root);
    soln(root->right,qt);

}
    int kthSmallest(TreeNode* root, int k) {
        
        queue<TreeNode *> qt;
        soln(root,qt);

        while(--k)
        {
            qt.pop();
        }

        return qt.front()->val;
    }
};

// for largest use stack data structure.

// class Solution
// {
// public:
//     int solve(TreeNode *root, int k, int &i)
//     {
//         if (root == NULL)
//             return -1;

//         // L
//         int temp = solve(root->left, k, i);

//         if (temp != -1)
//             return temp;

//         // N
//         i++;

//         if (k == i)
//             return root->val;

//         // R
//         return solve(root->right, k, i);
//     }

//     int kthSmallest(TreeNode *root, int k)
//     {
//         int i = 0;
//         return solve(root, k, i);
//     }
// };

