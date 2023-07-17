// https://leetcode.com/problems/reverse-nodes-in-k-group/

#include <bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
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
    ListNode *soln(ListNode *head, int k, int cnt)
    {
        if (cnt < k)
            return head;

        ListNode *headptr = head;
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *nextptr = NULL;

        int tempcnt = 0;

        while (tempcnt < k)
        {
            nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
            tempcnt++;
        }

        headptr->next = soln(nextptr, k, cnt - k);

        return prev;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int cnt = 0;
        ListNode *temp = head;

        while (temp)
        {
            cnt++;
            temp = temp->next;
        }

        return soln(head, k, cnt);
    }
};