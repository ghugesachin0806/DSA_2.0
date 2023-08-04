// https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool soln(long long mid, int n, int k, int arr[])
    {
        long long temp = 0;
        long long cnt = 1;

        for (int i = 0; i < n; i++)
        {
            if (temp + arr[i] <= mid)
            {
                temp += arr[i];
            }
            else
            {
                cnt++;
                if (cnt > k || arr[i] > mid)
                    return false;

                temp = arr[i];
            }
        }

        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];

        long long start = 0;
        long long end = sum;

        while (start <= end)
        {
            long long mid = start + (end - start) / 2;

            if (soln(mid, n, k, arr))
                end = mid - 1;
            else
                start = mid + 1;
        }

        return start;
    }
};