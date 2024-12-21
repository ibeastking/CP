//* Difficulty -> Medium

//? You are given a 0-indexed integer array nums.
//? A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].
//? Return the total number of bad pairs in nums.

//! Question Tag -> Array, Hash Table

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        long long count = 0;
        long long total = ((nums.size()) * (nums.size() - 1)) / 2;

        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = i - nums[i];
        }

        unordered_map<int, long long> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            count = count + mp[nums[i]];
            mp[nums[i]]++;
        }

        return total - count;
    }
};