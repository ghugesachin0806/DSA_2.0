// https://leetcode.com/problems/sqrtx/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {

        int start = 0;
        int end = x;

        while (start <= end)
        {
            long long mid = start + (end - start) / 2;

            if (mid * mid == x)
                return mid;

            if (mid * mid < x)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return end;
    }
};