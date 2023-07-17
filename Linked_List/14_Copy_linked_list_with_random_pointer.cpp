// https://leetcode.com/problems/copy-list-with-random-pointer/description/

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
            return NULL;

        Node *list1 = head->next;
        Node *list2 = new Node(head->val);
        Node *head2 = list2;

        while (list1)
        {
            list2->next = new Node(list1->val);
            list2 = list2->next;
            list1 = list1->next;
        }

        list1 = head;
        list2 = head2;

        while (list1)
        {
            Node *temp = list1->next;
            list1->next = list2;
            list2->random = temp;
            list2 = list2->next;
            list1 = temp;
        }

        list1 = head;
        list2 = head2;

        queue<Node *> qt;

        while (list1)
        {
            Node *temp = list1->next->random;

            if (list1->random)
                list1->next->random = list1->random->next;
            else
                list1->next->random = NULL;
            qt.push(temp);
            list1 = temp;
        }

        list1 = head;
        while (!qt.empty())
        {
            list1->next = qt.front();
            list1 = list1->next;
            qt.pop();
        }

        return head2;
    }
};