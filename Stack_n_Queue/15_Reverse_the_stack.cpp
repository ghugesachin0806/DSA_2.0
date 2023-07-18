// https://practice.geeksforgeeks.org/problems/reverse-a-stack/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void InsertAtBottom(stack<int> &st, int x)
    {
        if (st.empty())
        {
            st.push(x);
            return;
        }

        int temp = st.top();
        st.pop();

        InsertAtBottom(st, x);
        st.push(temp);
    }
    void Reverse(stack<int> &St)
    {

        if (St.empty())
        {
            return;
        }

        int temp = St.top();
        St.pop();

        Reverse(St);

        InsertAtBottom(St, temp);
    }
};