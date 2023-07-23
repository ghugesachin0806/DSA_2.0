// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
public:
    void predecessor(Node *root, Node *&pre, int key)
    {
        if (root == NULL)
            return;

        if (root->key < key)
        {
            pre = root;
            predecessor(root->right, pre, key);
        }
        else
        {
            predecessor(root->left, pre, key);
        }
    }
    void successor(Node *root, Node *&suc, int key)
    {
        if (root == NULL)
            return;
        if (root->key > key)
        {
            suc = root;
            successor(root->left, suc, key);
        }
        else
        {
            successor(root->right, suc, key);
        }
    }
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        // Your code goes here
        predecessor(root, pre, key);
        successor(root, suc, key);
    }
};