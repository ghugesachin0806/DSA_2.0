// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    // Function to return the diameter of a Binary Tree.
    pair<int, int> soln(Node *root)
    {
        if (root == NULL)
        {
            return {0, 0};
        }

        pair<int, int> p1 = soln(root->left);
        pair<int, int> p2 = soln(root->right);

        int height1 = p1.first;
        int height2 = p2.first;
        int dia = max(height1 + height2 + 1, max(p1.second, p2.second));

        return {max(height1, height2) + 1, dia};
    }
    int diameter(Node *root)
    {
        // Your code here
        return soln(root).second;
    }
};