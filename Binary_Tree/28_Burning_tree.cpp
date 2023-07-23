// https://practice.geeksforgeeks.org/problems/burning-tree/1

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

class Solution
{
public:
    Node *mapped_parent(Node *root, int target, unordered_map<Node *, Node *> &parent)
    {
        Node *res = NULL;

        queue<Node *> qt;
        qt.push(root);
        parent[root] = NULL;

        while (!qt.empty())
        {
            Node *temp = qt.front();
            qt.pop();

            if (temp->data == target)
                res = temp;

            if (temp->left)
            {
                parent[temp->left] = temp;
                qt.push(temp->left);
            }
            if (temp->right)
            {
                parent[temp->right] = temp;
                qt.push(temp->right);
            }
        }

        return res;
    }
    int soln(Node *root, unordered_map<Node *, Node *> &parent)
    {
        int time = 0;
        unordered_map<Node *, bool> visited;

        queue<Node *> qt;
        qt.push(root);
        visited[root] = true;

        while (!qt.empty())
        {
            int size = qt.size();

            for (int i = 0; i < size; i++)
            {
                Node *temp = qt.front();
                qt.pop();

                if (temp->left && !visited[temp->left])
                {
                    qt.push(temp->left);
                    visited[temp->left] = true;
                }

                if (temp->right && !visited[temp->right])
                {
                    qt.push(temp->right);
                    visited[temp->right] = true;
                }

                if (parent[temp] && !visited[parent[temp]])
                {
                    qt.push(parent[temp]);
                    visited[parent[temp]] = true;
                }
            }

            if (!qt.empty())
            {
                time++;
            }
        }

        return time;
    }
    int minTime(Node *root, int target)
    {
        // Your code goes here
        unordered_map<Node *, Node *> parent;

        Node *tar = mapped_parent(root, target, parent);

        return soln(tar, parent);
    }
};