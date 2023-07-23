// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    // Function to return the maximum sum of non-adjacent nodes.
    pair<int, int> soln(Node *root)
    {
        if (root == NULL)
            return make_pair(0, 0);

        pair<int, int> p1 = soln(root->left);
        pair<int, int> p2 = soln(root->right);

        int excl = max(p1.first, p1.second) + max(p2.first, p2.second);

        int incl = root->data + p1.first + p2.first;

        return {excl, incl};
    }
    int getMaxSum(Node *root)
    {
        // Add your code here

        pair<int, int> p1 = soln(root);

        return max(p1.first, p1.second);
    }
};