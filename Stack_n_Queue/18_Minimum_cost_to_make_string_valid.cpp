// https://www.codingninjas.com/studio/problems/minimum-cost-to-make-string-valid_1115770

#include <bits/stdc++.h>
using namespace std;

int soln(string &str)
{
    stack<char> st;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '}' && (!st.empty() && st.top() == '{'))
            st.pop();
        else
            st.push(str[i]);
    }

    int a = 0;
    int b = 0;

    while (!st.empty())
    {
        if (st.top() == '{')
            a++;
        else
            b++;

        st.pop();
    }
    if ((a + b) % 2 == 1)
        return -1;

    return ((a + 1) / 2) + ((b + 1) / 2);
}

int findMinimumCost(string str)
{
    // Write your code here
    return soln(str);
}