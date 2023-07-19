// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        // code here

        stack<int> st;

        for (int i = 0; i < n; i++)
            st.push(i);

        int i, j;

        while (!st.empty())
        {
            i = st.top();
            st.pop();
            if (st.empty())
                break;
            j = st.top();
            st.pop();

            if (M[i][j] == 1)
            {
                st.push(j);
            }
            else if (M[j][i] == 1)
            {
                st.push(i);
            }
        }

        // second check for the celebrity.
        for (int k = 0; k < n; k++)
        {
            // for row
            if (M[i][k] == 1)
            {
                return -1;
            }

            if (M[k][i] == 0 && k != i)
            {
                return -1;
            }
        }

        return i;
    }
};