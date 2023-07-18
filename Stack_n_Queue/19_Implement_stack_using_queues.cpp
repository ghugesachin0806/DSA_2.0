// https://leetcode.com/problems/implement-stack-using-queues/description/

#include <bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    queue<int> qt1;
    queue<int> qt2;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        qt1.push(x);
    }

    int pop()
    {
        if (qt1.empty())
            return -1;
        else
        {
            int temp;
            while (!qt1.empty())
            {
                temp = qt1.front();
                qt1.pop();
                if (!qt1.empty())
                    qt2.push(temp);
            }

            while (!qt2.empty())
            {
                qt1.push(qt2.front());
                qt2.pop();
            }

            return temp;
        }
    }

    int top()
    {
        if (qt1.empty())
            return -1;
        else
        {
            int temp;
            while (!qt1.empty())
            {
                temp = qt1.front();
                qt2.push(temp);
                qt1.pop();
            }

            while (!qt2.empty())
            {
                qt1.push(qt2.front());
                qt2.pop();
            }

            return temp;
        }
    }

    bool empty()
    {

        if (qt1.empty())
            return true;
        else
            return false;
    }
};