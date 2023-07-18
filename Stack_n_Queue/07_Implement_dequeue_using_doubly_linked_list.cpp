// https://leetcode.com/problems/design-circular-deque/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class MyCircularDeque
{
private:
    Node *head;
    Node *rear;
    int cnt;
    int size;

public:
    MyCircularDeque(int k)
    {

        this->head = NULL;
        this->rear = NULL;
        this->cnt = 0;
        this->size = k;
    };

    bool insertFront(int value)
    {

        if (cnt == size)
            return false;

        if (head == NULL)
        {
            head = new Node(value);
            rear = head;
        }
        else
        {
            Node *temp = new Node(value);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        cnt++;
        return true;
    }

    bool insertLast(int value)
    {
        if (cnt == size)
            return false;

        if (rear == NULL)
        {
            head = new Node(value);
            rear = head;
        }
        else
        {
            Node *temp = new Node(value);
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
        cnt++;
        return true;
    }

    bool deleteFront()
    {

        if (head == NULL)
            return false;

        if (cnt == 1)
        {
            head = NULL;
            rear = NULL;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            head->prev = NULL;
            temp->next = NULL;

            delete temp;
        }
        cnt--;
        return true;
    }

    bool deleteLast()
    {

        if (rear == NULL)
            return false;

        if (cnt == 1)
        {
            head = NULL;
            rear = NULL;
        }
        else
        {
            Node *temp = rear;
            rear = rear->prev;
            rear->next = NULL;
            temp->prev = NULL;

            delete temp;
        }
        cnt--;
        return true;
    }

    int getFront()
    {

        if (head == NULL)
            return -1;
        else
        {
            return head->data;
        }
    }

    int getRear()
    {
        if (rear == NULL)
            return -1;
        else
            return rear->data;
    }

    bool isEmpty()
    {
        if (cnt == 0)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (cnt == size)
            return true;
        else
            return false;
    }
};