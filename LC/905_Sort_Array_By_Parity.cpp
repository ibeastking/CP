//? Difficulty -> Easy

//? Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
//? Return any array that satisfies this condition.

//! Question Tag -> Array, Two Pointer, Sorting

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            while (left < right and nums[left] % 2 == 0)
                left++;
            while (left < right and nums[left] % 2 == 1)
                right--;

            swap(nums[left], nums[right]);
        }

        return nums;
    }
};