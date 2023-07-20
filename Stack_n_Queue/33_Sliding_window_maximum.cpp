// https://leetcode.com/problems/sliding-window-maximum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> qt;
        vector<int> ans;

        for (int i = 0; i < k; i++)
        {
            while (!qt.empty() && nums[qt.back()] < nums[i])
            {
                qt.pop_back();
            }
            qt.push_back(i);
        }

        ans.push_back(nums[qt.front()]);

        for (int i = k; i < nums.size(); i++)
        {
            while (!qt.empty() && nums[qt.back()] < nums[i])
            {
                qt.pop_back();
            }
            qt.push_back(i);

            if (i - qt.front() >= k)
                qt.pop_front();

            ans.push_back(nums[qt.front()]);
        }

        return ans;
    }
};