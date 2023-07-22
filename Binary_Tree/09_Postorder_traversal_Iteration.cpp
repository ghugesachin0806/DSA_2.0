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
vector<int> soln(Node *root)
{
    vector<int> vect;
    if (root == NULL)
        return vect;

    stack<Node *> st1;
    stack<Node *> st2;

    st1.push(root);

    while (!st1.empty())
    {
        Node *temp = st1.top();
        st2.push(temp);
        st1.pop();

        if (temp->left)
            st1.push(temp->left);
        if (temp->right)
            st1.push(temp->right);
    }

    while (!st2.empty())
    {
        vect.push_back(st2.top()->data);
        st2.pop();
    }

    return vect;
}
vector<int> postOrder(Node *root)
{
    // Your code here
    return soln(root);
}