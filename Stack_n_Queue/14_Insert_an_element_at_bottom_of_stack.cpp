// https://practice.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void soln(stack<int> &st, int &x)
    {
        if (st.empty())
        {
            st.push(x);
            return;
        }

        int temp = st.top();
        st.pop();

        soln(st, x);
        st.push(temp);
    }
    stack<int> insertAtBottom(stack<int> St, int X)
    {

        soln(St, X);
        return St;
    }
};