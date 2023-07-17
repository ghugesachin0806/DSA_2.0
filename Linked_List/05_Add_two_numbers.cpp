// https://leetcode.com/problems/add-two-numbers/

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
    ListNode *soln(ListNode *l1, ListNode *l2)
    {
        ListNode *temp = new ListNode(0);
        ListNode *head = temp;
        int sum = 0;
        int carry = 0;

        while (l1 && l2)
        {
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;

            ListNode *t = new ListNode(sum);
            temp->next = t;
            temp = temp->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1)
        {
            sum = l1->val + carry;
            carry = sum / 10;
            sum = sum % 10;

            ListNode *t = new ListNode(sum);
            temp->next = t;
            temp = temp->next;

            l1 = l1->next;
        }

        while (l2)
        {
            sum = l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;

            ListNode *t = new ListNode(sum);
            temp->next = t;
            temp = temp->next;

            l2 = l2->next;
        }

        if (carry)
        {
            ListNode *t = new ListNode(carry);
            temp->next = t;
            temp = temp->next;
        }

        return head->next;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return soln(l1, l2);
    }
};