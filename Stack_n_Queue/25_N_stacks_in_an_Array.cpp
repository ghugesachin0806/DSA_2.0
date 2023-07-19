// https://www.codingninjas.com/studio/problems/n-stacks-in-an-array_1164271

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
class NStack
{
private:
    int freespot;
    int n;
    int size;
    int *top;
    int *arr;
    int *nxt;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
        this->n = N;
        this->size = S;
        this->freespot = 0;
        this->arr = new int[S];
        this->nxt = new int[S];
        this->top = new int[N];

        for (int i = 0; i < S; i++)
        {
            nxt[i] = i + 1;
        }
        nxt[S - 1] = -1;

        for (int i = 0; i < N; i++)
        {
            top[i] = -1;
        }
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        if (freespot == -1)
            return false;

        int temp = nxt[freespot];

        nxt[freespot] = top[m - 1];

        top[m - 1] = freespot;

        freespot = temp;

        arr[top[m - 1]] = x;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        if (top[m - 1] == -1)
            return -1;

        int ans = arr[top[m - 1]];

        int temp = top[m - 1];

        int prev = nxt[top[m - 1]];

        nxt[temp] = freespot;

        freespot = temp;

        top[m - 1] = prev;

        return ans;
    }
};