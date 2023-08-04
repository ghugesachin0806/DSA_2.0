// https://practice.geeksforgeeks.org/problems/aggressive-cows/0

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool soln(int mid, int n, int k, vector<int> &stalls)
    {
        int last = stalls[0];
        int cnt = 1;

        for (int i = 0; i < stalls.size(); i++)
        {
            if (stalls[i] - last >= mid)
            {
                cnt++;
                if (cnt >= k)
                    return true;

                last = stalls[i];
            }
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls)
    {

        // Write your code here
        sort(stalls.begin(), stalls.end());

        int start = 0;
        int end = stalls[stalls.size() - 1];

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (soln(mid, n, k, stalls))
                start = mid + 1;
            else
                end = mid - 1;
        }
        return end;
    }
};