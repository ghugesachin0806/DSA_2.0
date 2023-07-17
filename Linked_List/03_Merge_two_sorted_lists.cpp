// https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode *soln(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        else if (list2 == NULL)
            return list1;
        else
        {
            ListNode *head = NULL;
            ListNode *temp = NULL;
            if (list1->val > list2->val)
            {
                head = list2;
                temp = list2;
                list2 = list2->next;
            }
            else
            {
                head = list1;
                temp = list1;
                list1 = list1->next;
            }

            while (list1 != NULL && list2 != NULL)
            {
                if (list1->val > list2->val)
                {
                    temp->next = list2;
                    list2 = list2->next;
                    temp = temp->next;
                }
                else
                {
                    temp->next = list1;
                    list1 = list1->next;
                    temp = temp->next;
                }
            }
            if (list1 == NULL)
            {
                temp->next = list2;
            }
            else
            {
                temp->next = list1;
            }

            return head;
        }
    }
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        return soln(list1, list2);
    }
};