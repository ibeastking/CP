//* Difficulty -> Medium

//? The frequency of an element is the number of times it occurs in an array.
//? You are given an integer array nums and an integer k.
//? In one operation, you can choose an index of nums and increment the element at that index by 1.
//? Return the maximum possible frequency of an element after performing at most k operations.

//! Question Tag -> Array, Binary Search, Greedy, Sliding Window, Sorting, Prefix Sum

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        long long int res = 0, l = 0, r = 0, total = 0, n = nums.size();

        for (r = 0; r < n; r++)
        {
            total = total + nums[r];

            while (l + 1 <= r and (nums[r] * (r - l + 1)) > total + k)
            {
                total = total - nums[l];
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};