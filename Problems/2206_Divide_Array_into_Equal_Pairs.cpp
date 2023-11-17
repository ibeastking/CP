//? Difficulty -> Easy

//? You are given an integer array nums consisting of 2 * n integers.
//? You need to divide nums into n pairs such that:
//? Each element belongs to exactly one pair.
//? The elements present in a pair are equal.
//? Return true if nums can be divided into n pairs, otherwise return false.

//! Question Tag -> Array, Hash Table, Bit Manipulation, Counting

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        vector<int> mp(501, 0);

        for (auto itr : nums)
            mp[itr]++;

        for (auto itr : mp)
        {
            if (itr % 2 != 0)
                return false;
        }

        return true;
    }
};