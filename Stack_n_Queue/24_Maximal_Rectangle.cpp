// https://leetcode.com/problems/maximal-rectangle/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nxtsmall(vector<int> &base)
    {
        vector<int> vect(base.size(), 0);
        stack<pair<int, int>> st;
        st.push({-1, base.size()});

        for (int i = base.size() - 1; i >= 0; i--)
        {
            if (st.top().first < base[i])
            {
                vect[i] = st.top().second;
                st.push({base[i], i});
            }
            else
            {
                while (st.top().first >= base[i])
                {
                    st.pop();
                }
                vect[i] = st.top().second;
                st.push({base[i], i});
            }
        }

        return vect;
    }
    vector<int> prevsmall(vector<int> &base)
    {
        vector<int> vect(base.size(), 0);
        stack<pair<int, int>> st;
        st.push({-1, -1});

        for (int i = 0; i < base.size(); i++)
        {
            if (st.top().first < base[i])
            {
                vect[i] = st.top().second;
                st.push({base[i], i});
            }
            else
            {
                while (st.top().first >= base[i])
                {
                    st.pop();
                }
                vect[i] = st.top().second;
                st.push({base[i], i});
            }
        }

        return vect;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        vector<int> base(matrix[0].size(), 0);

        int temp = INT_MIN;

        for (int i = matrix.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == '1')
                    base[j]++;
                else
                    base[j] = 0;
            }

            vector<int> nxt = nxtsmall(base);
            vector<int> prev = prevsmall(base);

            for (int j = 0; j < matrix[0].size(); j++)
            {
                int length = base[j];
                int breadth = nxt[j] - prev[j] - 1;

                if (temp < length * breadth)
                    temp = length * breadth;
            }
        }

        return temp;
    }
};