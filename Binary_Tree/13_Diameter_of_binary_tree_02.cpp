// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

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

class Solution
{
public:
    // Function to return the diameter of a Binary Tree.
    int soln(Node *root, int &dia)
    {
        if (root == NULL)
            return 0;

        int h1 = soln(root->left, dia);
        int h2 = soln(root->right, dia);

        dia = max(dia, h1 + h2 + 1);

        return max(h1, h2) + 1;
    }
    int diameter(Node *root)
    {
        // Your code here
        int dia = 0;

        soln(root, dia);

        return dia;
    }
};