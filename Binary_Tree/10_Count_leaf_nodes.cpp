// https://practice.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void soln(Node *root, int &cnt)
{
    if (root == NULL)
        return;

    soln(root->left, cnt);

    if (root->left == NULL && root->right == NULL)
        cnt++;

    soln(root->right, cnt);
}
int countLeaves(Node *root)
{
    // Your code here
    int cnt = 0;

    soln(root, cnt);

    return cnt;
}
