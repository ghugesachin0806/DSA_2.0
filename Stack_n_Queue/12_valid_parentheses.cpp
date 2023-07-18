// https://leetcode.com/problems/valid-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<int> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (st.empty() || s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else
            {
                if ((s[i] == '}' && st.top() == '{') || (s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '['))
                    st.pop();
                else
                    st.push(s[i]);
            }
        }

        if (st.empty())
            return true;
        else
            return false;
    }
};