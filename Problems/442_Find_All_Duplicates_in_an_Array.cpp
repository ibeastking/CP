//* Difficulty -> Medium

//? Given an integer array nums of length n where all the integers of nums are in the range [1, n] and
//? each integer appears once or twice, return an array of all the integers that appears twice.
//? You must write an algorithm that runs in O(n) time and uses only constant extra space.

//! Question Tag -> Array, Hash Table

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> res;

        for (int itr : nums)
        {
            if (nums[abs(itr) - 1] < 0)
                res.push_back(abs(itr));
            else
                nums[abs(itr) - 1] *= (-1);
        }

        return res;
    }
};