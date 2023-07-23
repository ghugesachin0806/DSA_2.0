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
        while (root)
        {
            if (root->key < key)
            {
                pre = root;
                root = root->right;
            }
            else
                root = root->left;
        }
    }
    void successor(Node *root, Node *&suc, int key)
    {
        while(root)
        {
            if(root->key >key)
            {
                suc = root;
                root= root->left;
            }
            else
            root = root->right;
        }
    }
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        // Your code goes here
        predecessor(root, pre, key);
        successor(root, suc, key);
    }
};