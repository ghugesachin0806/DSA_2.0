// https://leetcode.com/problems/linked-list-cycle/

// Floyd's Cycle detection algorithm

#include <bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool soln(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (slow && fast)
        {
            slow = slow->next;
            if (fast->next)
                fast = fast->next->next;
            else
                return false;

            if (fast == slow)
                return true;
        }

        return false;
    }
    bool hasCycle(ListNode *head)
    {
        return soln(head);
    }
};