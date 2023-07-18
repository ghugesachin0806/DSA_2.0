// https://practice.geeksforgeeks.org/problems/e015cb4d3f354b035d9665e7c8a54a7aefb1901b/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int soln(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (st.top() == '(')
                    return 1;
                else
                {
                    while (st.top() != '(')
                    {
                        st.pop();
                    }
                    st.pop();
                }
            }
        }

        return 0;
    }
    int checkRedundancy(string s)
    {
        // code here

        return soln(s);
    }
};