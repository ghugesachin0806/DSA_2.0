// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    queue<long long> qt;
    vector<long long> vect;

    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
            qt.push(i);
    }

    if (!qt.empty())
        vect.push_back(A[qt.front()]);
    else
        vect.push_back(0);

    for (int i = K; i < N; i++)
    {
        if (A[i] < 0)
            qt.push(i);

        if (!qt.empty() && i - qt.front() >= K)
            qt.pop();

        if (!qt.empty())
            vect.push_back(A[qt.front()]);
        else
            vect.push_back(0);
    }

    return vect;
}