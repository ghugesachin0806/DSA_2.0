// https://practice.geeksforgeeks.org/problems/inorder-traversal/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Recursive way
class Solution
{
public:
    // Function to return a list containing the inorder traversal of the tree.
    void soln(vector<int> &vect, Node *root)
    {
        if (root == NULL)
            return;

        if (root->left)
            soln(vect, root->left);

        vect.push_back(root->data);

        if (root->right)
            soln(vect, root->right);
    }
    vector<int> inOrder(Node *root)
    {
        // Your code here
        vector<int> vect;
        soln(vect, root);

        return vect;
    }
};