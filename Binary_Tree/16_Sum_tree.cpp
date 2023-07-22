// https://practice.geeksforgeeks.org/problems/sum-tree/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// Should return true if tree is Sum Tree, else false
class Solution
{
public:
    pair<int, bool> soln(Node *root)
    {
        if (root == NULL)
            return {0, true};

        if (root->left == NULL && root->right == NULL)
            return {root->data, true};

        pair<int, bool> p1 = soln(root->left);
        pair<int, bool> p2 = soln(root->right);

        int sum = p1.first + p2.first;

        bool b1 = p1.second && p2.second && (sum == root->data);

        return {sum + root->data, b1};
    }
    bool isSumTree(Node *root)
    {
        // Your code here
        return soln(root).second;
    }
};