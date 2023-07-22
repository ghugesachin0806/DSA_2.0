// https://practice.geeksforgeeks.org/problems/preorder-traversal/1

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

// Function to return a list containing the preorder traversal of the tree.
void soln(Node *root, vector<int> &vect)
{
    if (root == NULL)
        return;

    vect.push_back(root->data);

    if (root->left)
        soln(root->left, vect);
    if (root->right)
        soln(root->right, vect);
}
vector<int> preorder(Node *root)
{
    // Your code here
    vector<int> vect;
    soln(root, vect);

    return vect;
}