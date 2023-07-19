// https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    vector<int> help_classmate(vector<int> arr, int n)
    {
        // Your code goes here
        stack<int> st;
        st.push(-1);

        vector<int> vect;

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            if (st.top() < arr[i])
            {
                vect.push_back(st.top());
                st.push(arr[i]);
            }
            else
            {
                while (st.top() >= arr[i])
                {
                    st.pop();
                }
                vect.push_back(st.top());
                st.push(arr[i]);
            }
        }

        reverse(vect.begin(), vect.end());

        return vect;
    }
};