// https://leetcode.com/problems/rotate-list/description/

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
        if (head == NULL)
            return head;
        int it = k % cnt;
        if (it)
        {
            ListNode *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = head;

            int tempcnt = cnt - it;
            temp = head;

            int k = 1;
            while (k < tempcnt)
            {
                k++;
                temp = temp->next;
            }

            ListNode *nxt = temp->next;
            temp->next = NULL;
            return nxt;
        }
        else
            return head;
    }
    ListNode *rotateRight(ListNode *head, int k)
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