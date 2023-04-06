//? Difficulty -> Easy

//? Given an integer array nums sorted in non-decreasing order,
//? return an array of the squares of each number sorted in non-decreasing order.

//! Question Tag -> Array, Two Pointer, Sorting

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> res(nums.size());

        int idx = nums.size() - 1;
        int start = 0, end = nums.size() - 1;

        while (start <= end)
        {
            long long x = (long long)nums[start] * (long long)nums[start];
            long long y = (long long)nums[end] * (long long)nums[end];

            if (x > y)
            {
                res[idx] = x;
                start++;
            }
            else
            {
                res[idx] = y;
                end--;
            }
        }

        return res;
    }
};