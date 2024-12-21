//* Difficulty -> Medium

//? Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

//! Question Tag -> Array, Backtracking

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    void fun(vector<vector<int>> &res, vector<int> temp, vector<int> &nums, unordered_map<int, int> visited)
    {
        if (temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!visited[nums[i]])
            {
                temp.push_back(nums[i]);
                visited[nums[i]] = 1;
                fun(res, temp, nums, visited);
                visited[nums[i]] = 0;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> vt;
        unordered_map<int, int> visited;

        for (auto itr : nums)
        {
            visited[itr] = 0;
        }

        fun(res, vt, nums, visited);

        return res;
    }
};