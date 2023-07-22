// https://practice.geeksforgeeks.org/problems/postorder-traversal/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to return a list containing the postorder traversal of the tree.
void soln(Node *root, vector<int> &vect)
{
    if (root == NULL)
        return;

    soln(root->left, vect);
    soln(root->right, vect);

    vect.push_back(root->data);
}
vector<int> postOrder(Node *root)
{
    // Your code here
    vector<int> vect;

    soln(root, vect);

    return vect;
}