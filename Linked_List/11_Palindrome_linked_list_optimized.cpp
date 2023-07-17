// https://leetcode.com/problems/palindrome-linked-list/

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
    ListNode *reverse(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *nextptr = NULL;

        while (curr)
        {
            nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
        }

        return prev;
    }
    bool soln(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (1)
        {
            if (fast->next && fast->next->next)
                fast = fast->next->next;
            else
                break;
            slow = slow->next;
        }

        ListNode *temp = slow->next;

        slow->next = reverse(temp);

        fast = head;
        slow = slow->next;

        while (slow && fast)
        {
            if (slow->val != fast->val)
                return false;

            slow = slow->next;
            fast = fast->next;
        }

        return true;
    }
    bool isPalindrome(ListNode *head)
    {

        return soln(head);
    }
};