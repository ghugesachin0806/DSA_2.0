// https://www.codingninjas.com/studio/problems/stack-implementation-using-array_3210209

#include <bits/stdc++.h>
using namespace std;

// Stack class.
class Stack
{
    int ptr;
    int size;
    int *arr;

public:
    Stack(int capacity)
    {
        // Write your code here.
        this->ptr = -1;
        this->size = capacity;
        this->arr = new int[capacity];
    }

    void push(int num)
    {
        // Write your code here.
        if (size - ptr > 1)
        {
            arr[++ptr] = num;
        }
    }

    int pop()
    {
        // Write your code here.
        if (ptr != -1)
            return arr[ptr--];
        else
            return -1;
    }

    int top()
    {
        // Write your code here.
        if (ptr != -1)
            return arr[ptr];
        else
            return -1;
    }

    int isEmpty()
    {
        // Write your code here.
        if (ptr == -1)
            return 1;
        else
            return 0;
    }

    int isFull()
    {
        // Write your code here.
        if (size - ptr == 1)
            return 1;
        else
            return 0;
    }
};
