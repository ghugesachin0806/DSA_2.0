// https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to delete middle element of a stack.
    void soln(stack<int> &st, int &middle)
    {
        if (middle == 1)
        {
            st.pop();
            return;
        }

        middle--;

        int temp = st.top();
        st.pop();
        soln(st, middle);
        st.push(temp);
    }

    void deleteMid(stack<int> &s, int sizeOfStack)
    {
        // code here..
        int middle = (sizeOfStack + 2) / 2;

        soln(s, middle);
    }
};