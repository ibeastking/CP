//? Difficulty -> Easy

//? Given an array nums of n integers where nums[i] is in the range [1, n],
//? return an array of all the integers in the range [1, n] that do not appear in nums.

//! Question Tag -> Array, Hash Table

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> freq(nums.size(), 0);
        vector<int> res;

        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i] - 1]++;
        }

        for (int i = 0; i < freq.size(); i++)
        {
            if (freq[i] == 0)
                res.push_back(i + 1);
        }

        return res;
    }
};