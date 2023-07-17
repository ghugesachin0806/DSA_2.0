// https://leetcode.com/problems/reverse-linked-list/

#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *soln(ListNode *&head, ListNode *&temp)
    {
        if (head == NULL || head->next == NULL)
        {
            temp = head;
            return head;
        }

        ListNode *headtemp = soln(head->next, temp);
        headtemp->next = head;
        head->next = NULL;

        return head;
    }
    ListNode *reverseList(ListNode *head)
    {

        ListNode *temp = NULL;
        soln(head, temp);
        return temp;
    }
};