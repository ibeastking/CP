//? Difficulty -> Easy

//? You are given an integer array nums.
//? We consider an array good if it is a permutation of an array base[n].
//? base[n] = [1, 2, ..., n - 1, n, n]
//? (in other words, it is an array of length n + 1 which contains 1 to n - 1 exactly once, plus two occurrences of n).
//? For example, base[1] = [1, 1] and base[3] = [1, 2, 3, 3].
//? Return true if the given array is good, otherwise return false.
//? Note: A permutation of integers represents an arrangement of these numbers.

//! Question Tag -> Array, Hash Table, Sorting

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isGood(vector<int> &nums)
    {
        int base = nums.size() - 1;
        bool flag = false;

        unordered_map<int, int> mp;
        for (auto itr : nums)
        {
            mp[itr]++;
        }

        for (auto itr : mp)
        {
            if (itr.second >= 2 and itr.second != base)
                return false;
            else if (itr.second == 2 and itr.second == base)
                flag = true;
        }

        return flag;
    }
};