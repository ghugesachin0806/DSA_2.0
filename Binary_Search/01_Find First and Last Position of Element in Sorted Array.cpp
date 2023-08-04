// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {

        vector<int> vect = {-1, -1};

        int start = 0;
        int end = nums.size() - 1;

        int temp = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target || nums[mid] > target)
            {
                if (nums[mid] == target)
                    temp = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        vect[0] = temp;

        start = 0;
        end = nums.size() - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target || nums[mid] < target)
            {
                if (nums[mid] == target)
                    temp = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        vect[1] = temp;

        return vect;
    }
};