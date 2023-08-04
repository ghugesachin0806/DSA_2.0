// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {

        int start = 0;
        int end = nums.size() - 1;

        while (start < end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] > nums[nums.size() - 1])
                start = mid + 1;
            else
                end = mid;
        }
        return nums[end];
    }
};