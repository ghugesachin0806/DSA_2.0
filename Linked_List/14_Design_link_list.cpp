// https://leetcode.com/problems/design-linked-list/description/

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

class MyLinkedList
{
private:
    Node *head;
    int size;

public:
    MyLinkedList()
    {
        this->head = NULL;
        this->size = 0;
    }

    int get(int index)
    {

        if (index < size)
        {
            Node *temp = head;
            while (index)
            {
                index--;
                temp = temp->next;
            }
            return temp->data;
        }
        else
            return -1;
    }

    void addAtHead(int val)
    {

        Node *temp = head;
        head = new Node(val);
        head->next = temp;
        size++;
    }

    void addAtTail(int val)
    {

        if (head == NULL)
        {
            head = new Node(val);
            size++;
            return;
        }

        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new Node(val);
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index <= size)
        {
            if (index == 0)
            {
                Node *temp = head;
                head = new Node(val);
                head->next = temp;
            }
            else
            {
                Node *temp = head;

                while (--index)
                {
                    temp = temp->next;
                }

                Node *nxt = temp->next;
                temp->next = new Node(val);
                temp->next->next = nxt;
            }

            size++;
        }
    }

    void deleteAtIndex(int index)
    {

        if (index < size)
        {
            if (index == 0)
            {
                Node *temp = head;
                head = head->next;
                temp->next = NULL;
                delete temp;
                size--;
            }
            else
            {
                Node *temp = head;

                while (--index)
                {
                    temp = temp->next;
                }
                temp->next = temp->next->next;
                size--;
            }
        }
    }
};