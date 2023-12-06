//* Difficulty -> Medium

//? You are given an integer array nums sorted in non-decreasing order.
//? Build and return an integer array result with the same length as nums such that result[i] is equal to the summation of absolute differences between nums[i]
//? and all the other elements in the array.
//? In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).

//! Question Tag -> Array, Math, Prefix Sum

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        int left_sum = 0;
        int total_sum = 0;

        for (auto itr : nums)
            total_sum = total_sum + itr;

        for (int i = 0; i < nums.size(); i++)
        {
            int temp = nums[i];
            nums[i] = ((nums[i] * i) - left_sum) + (total_sum - left_sum - (nums[i] * (nums.size() - i)));
            left_sum = left_sum + temp;
        }

        return nums;
    }
};