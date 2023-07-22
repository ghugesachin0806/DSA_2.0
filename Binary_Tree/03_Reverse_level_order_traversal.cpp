// https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> soln(Node *root)
{
    vector<int> vect;

    if (root == NULL)
        return vect;

    queue<Node *> qt;
    stack<int> st;

    qt.push(root);
    qt.push(NULL);

    while (!qt.empty())
    {
        Node *temp = qt.front();
        qt.pop();

        if (temp == NULL)
        {
            if (!qt.empty())
            {
                qt.push(NULL);
            }
        }
        else
        {
            st.push(temp->data);

            if (temp->right)
                qt.push(temp->right);
            if (temp->left)
                qt.push(temp->left);
        }
    }

    while (!st.empty())
    {
        vect.push_back(st.top());
        st.pop();
    }

    return vect;
}
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    return soln(root);
}