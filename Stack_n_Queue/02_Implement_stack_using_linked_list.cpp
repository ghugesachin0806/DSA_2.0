// https://www.codingninjas.com/studio/problems/implement-stack-with-linked-list_630475

#include <bits/stdc++.h>
using namespace std;

// Following is the class structure of the Node class:
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
    // Write your code here
    Node *top;
    int size;

public:
    Stack()
    {
        // Write your code here
        this->top = NULL;
        this->size = 0;
    }

    int getSize()
    {
        // Write your code here
        return size;
    }

    bool isEmpty()
    {
        // Write your code here
        if (top == NULL)
            return 1;
        else
            return 0;
    }

    void push(int data)
    {
        // Write your code here
        Node *temp = new Node(data);
        temp->next = top;
        top = temp;
        size++;
    }

    void pop()
    {
        // Write your code here
        if (top != NULL)
        {
            Node *temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
            size--;
        }
    }

    int getTop()
    {
        // Write your code here
        if (top != NULL)
            return top->data;
        else
            return -1;
    }
};