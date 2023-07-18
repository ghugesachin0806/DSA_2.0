
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int prec(char ch)
    {
        if (ch == '^')
            return 3;
        else if (ch == '*' || ch == '/')
            return 2;
        else if (ch == '+' || ch == '-')
            return 1;
        else if (ch == '(' || ch == ')')
            return 0;
        else // for all ASCII characters and numbers
            return -1;
    }
    string infixToPostfix(string s)
    {
        // Your code here

        string str;

        // reverse the string
        reverse(s.begin(), s.end());

        // convert '('->')' and ')'->'('
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                s[i] = ')';
            else if (s[i] == ')')
                s[i] = '(';
        }

        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (prec(s[i]) == -1) // (a->z, A->Z,-infinity -> +infinity)
                str.push_back(s[i]);
            else if (s[i] == '(')
                st.push(s[i]);
            else if (s[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    str.push_back(st.top());
                    st.pop();
                }

                if (!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                while (!st.empty() && (prec(st.top()) >= prec(s[i])))
                {
                    str.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
        }

        while (!st.empty())
        {
            str.push_back(st.top());
            st.pop();
        }

        // reverse the final output string
        reverse(str.begin(), str.end());

        return str;
    }
};
