// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode *soln(ListNode *head, int n)
    {
        if (n == 1)
            return head->next;

        ListNode *temp = head;
        ListNode *prev = NULL;

        int cnt = 1;

        while (temp)
        {
            if (cnt == n)
            {
                prev->next = temp->next;
                temp->next = NULL;

                return head;
            }
            prev = temp;
            temp = temp->next;
            cnt++;
        }

        return head;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int totalNode = 0;
        ListNode *temp = head;

        while (temp)
        {
            totalNode++;
            temp = temp->next;
        }

        int position = totalNode + 1 - n;

        return soln(head, position);
    }
};