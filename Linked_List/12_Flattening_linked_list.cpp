// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

#include <bits/stdc++.h>
using namespace std;

// Node structure  used in the program

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *flatten(Node *root)
{
    // Your code here
    Node *list1 = root;
    Node *list2 = root->next;
    Node *nxtptr = NULL;
    Node *head = NULL;

    while (list2)
    {
        list1->next = NULL;
        nxtptr = list2->next;
        Node *temp = NULL;
        if (list1->data < list2->data)
        {
            head = list1;
            temp = list1;
            list1 = list1->bottom;
        }
        else
        {
            head = list2;
            temp = list2;
            list2 = list2->bottom;
        }

        while (list1 && list2)
        {
            if (list1->data < list2->data)
            {
                temp->bottom = list1;
                list1 = list1->bottom;
                temp = temp->bottom;
            }
            else
            {
                temp->bottom = list2;
                list2 = list2->bottom;
                temp = temp->bottom;
            }
        }

        if (list1)
            temp->bottom = list1;
        else
            temp->bottom = list2;

        list1 = head;
        list2 = nxtptr;
    }

    return list1;
}