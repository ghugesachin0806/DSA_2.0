// https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

Node *soln(Node *root, int &k, int &node, int &ans)
{
    if (root == NULL || root->data == node)
        return root;

    Node *temp1 = soln(root->left, k, node, ans);
    Node *temp2 = soln(root->right, k, node, ans);

    if ((k > 0) && (temp1 || temp2))
    {
        k--;
        if (k == 0)
            ans = root->data;
    }

    if (temp1)
        return temp1;
    else
        return temp2;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    int ans = -1;
    soln(root, k, node, ans);

    return ans;
}