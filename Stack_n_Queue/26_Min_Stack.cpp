// https://leetcode.com/problems/min-stack/description/

#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
    stack<pair<int, int>> st;
    int mini;

public:
    MinStack()
    {
        this->mini = INT_MAX;
    }

    void push(int val)
    {
        if (mini > val)
        {
            mini = val;
            st.push({val, mini});
        }
        else
        {
            st.push({val, mini});
        }
    }

    void pop()
    {
        if (!st.empty())
            st.pop();
        if (!st.empty())
            mini = st.top().second;
        else
            mini = INT_MAX;
    }

    int top()
    {
        if (!st.empty())
            return st.top().first;
        else
            return -1;
    }

    int getMin()
    {
        return mini;
    }
};