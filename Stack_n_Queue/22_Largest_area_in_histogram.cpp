// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nxtsmall(vector<int> &heights)
    {
        vector<int> vect;
        stack<pair<int, int>> st;
        st.push({-1, heights.size()});

        for (int i = heights.size() - 1; i >= 0; i--)
        {
            if (st.top().first < heights[i])
            {
                vect.push_back(st.top().second);
                st.push({heights[i], i});
            }
            else
            {
                while (st.top().first >= heights[i])
                {
                    st.pop();
                }
                vect.push_back(st.top().second);
                st.push({heights[i], i});
            }
        }

        reverse(vect.begin(), vect.end());

        return vect;
    }
    vector<int> prevsmall(vector<int> &heights)
    {
        vector<int> vect;
        stack<pair<int, int>> st;
        st.push({-1, -1});

        for (int i = 0; i < heights.size(); i++)
        {
            if (st.top().first < heights[i])
            {
                vect.push_back(st.top().second);
                st.push({heights[i], i});
            }
            else
            {
                while (st.top().first >= heights[i])
                {
                    st.pop();
                }
                vect.push_back(st.top().second);
                st.push({heights[i], i});
            }
        }

        return vect;
    }
    int largestRectangleArea(vector<int> &heights)
    {

        vector<int> nxt = nxtsmall(heights);
        vector<int> prev = prevsmall(heights);

        int temp = INT_MIN;

        for (int i = 0; i < heights.size(); i++)
        {
            int length = heights[i];
            int breadth = nxt[i] - prev[i] - 1;

            if (temp < length * breadth)
                temp = length * breadth;
        }

        return temp;
    }
};