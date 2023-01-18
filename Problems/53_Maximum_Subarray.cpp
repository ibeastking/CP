//* Difficulty -> Medium

//? Given an integer array nums, find the subarray with the largest sum, and return its sum.

//! Question Tags -> Array, Divide and Conquer, Dynamic Programming

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int cursum = nums[0];
        int maxsum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            cursum = cursum + nums[i];

            maxsum = max(maxsum, cursum);

            if (cursum < 0)
                cursum = 0;
        }

        return maxsum;
    }
};