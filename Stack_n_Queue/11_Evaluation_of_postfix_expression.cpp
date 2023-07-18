// https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool operatr(char ch)
    {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
            return true;
        else
            return false;
    }
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;

        // Traverse from Right to Left for prefix expression
        for (int i = 0; i < S.size(); i++)
        {
            if (operatr(S[i]))
            {

                int operand1 = 0;
                int operand2 = 0;

                // first stack top will be operand2
                if (!st.empty())
                {
                    operand2 = st.top();
                    st.pop();
                }
                // second stack top will be operand1
                if (!st.empty())
                {
                    operand1 = st.top();
                    st.pop();
                }

                if (S[i] == '+')
                    st.push(operand1 + operand2);
                else if (S[i] == '-')
                    st.push(operand1 - operand2);
                else if (S[i] == '*')
                    st.push(operand1 * operand2);
                else if (S[i] == '/')
                    st.push(operand1 / operand2);
                else
                    st.push(operand1 ^ operand2);
            }
            else
            {
                st.push(S[i] - 48);
            }
        }

        return st.top();
    }
};