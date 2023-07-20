// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

#include <bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k)
{
    // add code here.
    stack<int> st;
    int temp = k;
    while (temp--)
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    temp = q.size() - k;

    while (temp--)
    {
        q.push(q.front());
        q.pop();
    }

    return q;
}