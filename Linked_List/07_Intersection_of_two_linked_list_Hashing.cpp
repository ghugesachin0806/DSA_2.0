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
        unordered_map<ListNode *, bool> mt;

        ListNode *temp = headA;
        while (temp)
        {
            mt[temp] = true;
            temp = temp->next;
        }

        temp = headB;

        while (temp)
        {
            if (mt[temp] == true)
                return temp;
            else
                temp = temp->next;
        }

        return NULL;
    }
};