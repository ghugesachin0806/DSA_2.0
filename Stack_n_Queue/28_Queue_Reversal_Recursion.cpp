// https://practice.geeksforgeeks.org/problems/queue-reversal/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void soln(queue<int> &qt)
    {
        if (qt.empty())
            return;

        int temp = qt.front();
        qt.pop();
        soln(qt);
        qt.push(temp);
    }
    queue<int> rev(queue<int> q)
    {
        soln(q);

        return q;
    }
};