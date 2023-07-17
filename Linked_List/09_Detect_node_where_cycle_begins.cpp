// https://leetcode.com/problems/linked-list-cycle-ii/

#include <bits/stdc++.h>
using namespace std;

// Floyd's Cycle detection algorithm

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
    ListNode *soln(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (1)
        {
            if (slow && fast && fast->next)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            else
                return NULL;

            if (slow == fast)
                break;
        }
        slow = head;

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
    ListNode *detectCycle(ListNode *head)
    {
        return soln(head);
    }
};