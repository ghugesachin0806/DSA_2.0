// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    void left_part(Node *root, vector<int> &vect)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;

        if (root->left)
        {
            vect.push_back(root->data);
            left_part(root->left, vect);
        }
        else
        {
            vect.push_back(root->data);
            left_part(root->right, vect);
        }
    }

    void leaf_node(Node *root, vector<int> &vect)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            vect.push_back(root->data);
            return;
        }

        leaf_node(root->left, vect);
        leaf_node(root->right, vect);
    }

    void right_Node(Node *root, vector<int> &vect)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;

        if (root->right)
        {
            right_Node(root->right, vect);
            vect.push_back(root->data);
        }
        else
        {
            right_Node(root->left, vect);
            vect.push_back(root->data);
        }
    }
    vector<int> boundary(Node *root)
    {
        // Your code here
        vector<int> vect;

        if (root == NULL)
            return vect;

        vect.push_back(root->data);

        // left part
        left_part(root->left, vect);

        // leaf nodes
        leaf_node(root->left, vect);
        leaf_node(root->right, vect);

        // right part
        right_Node(root->right, vect);

        return vect;
    }
};