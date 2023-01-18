//? Difficulty -> Easy

//? Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//? You may assume that each input would have exactly one solution, and you may not use the same element twice.
//? You can return the answer in any order.

//! Question Tag -> Array, Hash Table

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        unordered_map<int, int> mp; //* map to store key as number and value as its index
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.find(target - nums[i]) != mp.end()) //* find() finds a number in a map until it reaches map end
            {
                res.push_back(i);
                res.push_back(mp[target - nums[i]]);
                return res; //* as answer is unique, no need to iterate further
            }
            mp[nums[i]] = i;
        }
        return res;
    }
};