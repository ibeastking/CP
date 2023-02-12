//* Difficulty -> Medium

//! Weekly Contest 332

//? Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.
//? A pair (i, j) is fair if:
//? 0 <= i < j < n, and
//? lower <= nums[i] + nums[j] <= upper

#include <bits/stdc++.h>
using namespace std;

//! just solve the question the same way you solve normal target
//! you find number of pairs which are less than or equal to upper
//! then you find number of pairs which are less than lower
//! the final answer will be subtraction of both the number of pairs

class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {

        sort(nums.begin(), nums.end());

        int left = 0, right = nums.size() - 1;
        long long countup = 0, countlo = 0;

        while (left < right)
        {
            if (nums[left] + nums[right] <= upper)
            {
                countup = countup + right - left;
                left++;
            }
            else
            {
                right--;
            }
        }

        left = 0, right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] < lower)
            {
                countlo = countlo + right - left;
                left++;
            }
            else
            {
                right--;
            }
        }

        return countup - countlo;
    }
};