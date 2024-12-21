//* Difficulty -> Medium

//? You are given a 0-indexed array nums comprising of n non-negative integers.
//? In one operation, you must:
//? Choose an integer i such that 1 <= i < n and nums[i] > 0.
//? Decrease nums[i] by 1.
//? Increase nums[i - 1] by 1.
//? Return the minimum possible value of the maximum integer of nums after performing any number of operations.

//! Question Tag -> Array, Binary Search, Dynamic Programming, Greedy, Prefix Sum

#include <vector>
#include <algorithm>
using namespace std;

//* ceil(num1/num2) = (num1+num2-2)/num2

class Solution
{
public:
    int minimizeArrayValue(vector<int> &nums)
    {
        long long sum = 0;
        long long res = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
            res = max(res, (sum + i) / (i + 1));
        }

        return res;
    }
};