// https://practice.geeksforgeeks.org/problems/inorder-traversal/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Iterative way
class Solution
{
public:
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
                st.push(temp);
                temp = temp->left;
            }
            else
            {
                if (st.empty())
                    break;

                Node *curr = st.top();
                vect.push_back(curr->data);
                st.pop();

                temp = curr->right;
            }
        }

        return vect;
    }
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node *root)
    {
        // Your code here
        return soln(root);
    }
};