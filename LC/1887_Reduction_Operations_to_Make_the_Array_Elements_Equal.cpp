//* Difficulty -> Medium

//? Given an integer array nums, your goal is to make all elements in nums equal. To complete one operation,
//? follow these steps:
//? Find the largest value in nums. Let its index be i (0-indexed) and its value be largest.
//? If there are multiple elements with the largest value, pick the smallest i.
//? Find the next largest value in nums strictly smaller than largest. Let its value be nextLargest.
//? Reduce nums[i] to nextLargest.
//? Return the number of operations to make all elements in nums equal.

//! Question Tag -> Array, Sorting

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {
        int res = 0, mini = INT_MAX, step = 1;
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            mini = min(mini, nums[i]);
            mp[nums[i]]++;
        }

        for (auto itr : mp)
        {
            if (itr.first != mini)
            {
                res = res + itr.second * step;
                step++;
            }
        }

        return res;
    }
};