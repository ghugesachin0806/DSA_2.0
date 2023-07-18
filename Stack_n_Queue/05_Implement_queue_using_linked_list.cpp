// https://www.codingninjas.com/studio/problems/queue-using-array-or-singly-linked-list_2099908

#include <bits/stdc++.h>
using namespace std;

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

class Queue
{
private:
    Node *head;
    Node *rear;

public:
    Queue()
    {
        // Implement the Constructor
        this->head = NULL;
        this->rear = NULL;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        // Implement the isEmpty() function
        if (head == NULL)
            return true;
        else
            return false;
    }

    void enqueue(int data)
    {
        // Implement the enqueue() function
        if (head == NULL)
        {
            head = new Node(data);
            rear = head;
        }
        else
        {
            rear->next = new Node(data);
            rear = rear->next;
        }
    }

    int dequeue()
    {
        // Implement the dequeue() function
        if (head == NULL)
            return -1;
        else
        {
            int temp = head->data;
            head = head->next;
            return temp;
        }
    }

    int front()
    {
        // Implement the head() function
        if (head == NULL)
            return -1;
        else
            return head->data;
    }
};