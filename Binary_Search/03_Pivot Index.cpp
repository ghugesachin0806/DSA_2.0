// https://leetcode.com/problems/find-pivot-index/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {

        vector<int> vect;
        int sum = 0;

        for (auto it : nums)
        {
            sum += it;
            vect.push_back(sum);
        }

        int start = 0;
        int end = nums.size() - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            int temp = (vect[mid] - nums[mid]) - (vect[nums.size() - 1] - vect[mid]);

            if (temp == 0)
                return mid;

            if (temp > 0)
                end = mid - 1;
            else
                start = mid + 1;
        }

        return -1;
    }
};