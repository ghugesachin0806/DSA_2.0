// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
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

        if (target > nums[nums.size() - 1])
        {
            end = start - 1;
            start = 0;
        }
        else
            end = nums.size() - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }

        return -1;
    }
};