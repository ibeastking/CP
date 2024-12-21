//* Difficulty -> Medium

//?You are given an array nums that consists of non-negative integers.
//? Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21.
//? A pair of indices (i, j) is nice if it satisfies all of the following conditions:
//? 0 <= i < j < nums.length
//? nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
//? Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.

//! Question Tag -> Array, Hash Table, Math, Counting

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define mod 1000000007

class Solution
{
public:
    int rev(int x)
    {
        int res = 0;
        while (x > 0)
        {
            res = res * 10 + x % 10;
            x = x / 10;
        }
        return res;
    }

    int countNicePairs(vector<int> &nums)
    {
        int res = 0;
        unordered_map<int, int> mp;

        for (auto itr : nums)
        {
            int temp = itr - rev(itr);
            res = (res + mp[temp]) % mod;
            mp[temp]++;
        }

        return res % mod;
    }
};