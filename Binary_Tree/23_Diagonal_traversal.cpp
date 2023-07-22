// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

vector<int> diagonal(Node *root)
{
    // your code here
    vector<int> vect;

    queue<Node *> qt;
    qt.push(root);

    while (!qt.empty())
    {
        Node *temp = qt.front();
        qt.pop();

        while (temp)
        {
            if (temp->left)
                qt.push(temp->left);

            vect.push_back(temp->data);

            temp = temp->right;
        }
    }

    return vect;
}