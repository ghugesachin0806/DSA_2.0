// https://www.codingninjas.com/studio/problems/sort-a-stack_985275

#include <bits/stdc++.h>
using namespace std;

void sort_stack(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }

    int temp = st.top();

    if (temp > x)
    {
        st.pop();
        sort_stack(st, x);
        st.push(temp);
    }
    else
    {
        st.push(x);
        return;
    }
}
void soln(stack<int> &st)
{
    if (st.empty())
        return;

    int temp = st.top();
    st.pop();

    soln(st);

    sort_stack(st, temp);
}

void sortStack(stack<int> &stack)
{
    // Write your code here
    soln(stack);
}