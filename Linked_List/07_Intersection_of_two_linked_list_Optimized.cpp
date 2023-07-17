// https://leetcode.com/problems/intersection-of-two-linked-lists/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        if (headA == NULL || headB == NULL)
            return NULL;

        int cnt = 2;
        ListNode *l1 = headA;
        ListNode *l2 = headB;

        while (l1 != l2 && cnt >= 0)
        {
            l1 = l1->next;
            l2 = l2->next;

            if (l1 == NULL)
            {
                l1 = headB;
                cnt--;
            }

            if (l2 == NULL)
            {
                l2 = headA;
                cnt--;
            }
        }

        if (cnt < 0)
            return NULL;
        else
            return l1;
    }
};