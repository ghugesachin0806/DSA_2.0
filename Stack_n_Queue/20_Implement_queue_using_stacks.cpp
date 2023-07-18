// https://leetcode.com/problems/implement-queue-using-stacks/

#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
private:
    stack<int> st1;
    stack<int> st2;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        st1.push(x);
    }

    int pop()
    {
        if (st1.empty())
            return -1;
        else
        {
            int temp;
            while (!st1.empty())
            {
                temp = st1.top();
                st1.pop();
                if (!st1.empty())
                    st2.push(temp);
            }

            while (!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }

            return temp;
        }
    }

    int peek()
    {
        if (st1.empty())
            return -1;
        else
        {
            int temp;
            while (!st1.empty())
            {
                temp = st1.top();
                st1.pop();
                st2.push(temp);
            }

            while (!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }
            return temp;
        }
    }

    bool empty()
    {
        if (st1.empty())
            return true;
        else
            return false;
    }
};