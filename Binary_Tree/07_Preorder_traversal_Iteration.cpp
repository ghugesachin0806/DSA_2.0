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

vector<int> soln(Node *root)
{
    vector<int> vect;
    if (root == NULL)
        return vect;

    stack<Node *> st;
    Node *temp = root;

    while (true)
    {
        if (temp)
        {
            vect.push_back(temp->data);
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            if (st.empty())
                break;

            Node *curr = st.top();
            st.pop();

            temp = curr->right;
        }
    }

    return vect;
}

vector<int> preorder(Node *root)
{
    // Your code here
    return soln(root);
}