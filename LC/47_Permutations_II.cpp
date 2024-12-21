//* Difficulty -> Medium

//? Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

//! Question Tag -> Array, Backtracking

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    void explore(vector<int> &nums, set<vector<int>> &result, int depth)
    {
        if (depth == nums.size())
        {
            result.insert(nums);
            return;
        }

        for (int i = depth; i < nums.size(); i++)
        {
            swap(nums[i], nums[depth]);
            explore(nums, result, depth + 1);
            swap(nums[depth], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        set<vector<int>> result;
        explore(nums, result, 0);
        return vector<vector<int>>(result.begin(), result.end());
    }
};