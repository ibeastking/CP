//? Difficulty -> Easy

//? You are given a 0-indexed integer array nums.
//? Rearrange the values of nums according to the following rules:
//? Sort the values at odd indices of nums in non-increasing order.
//? For example, if nums = [4,1,2,3] before this step, it becomes [4,3,2,1] after.
//? The values at odd indices 1 and 3 are sorted in non-increasing order.
//? Sort the values at even indices of nums in non-decreasing order.
//? For example, if nums = [4,1,2,3] before this step, it becomes [2,1,4,3] after.
//? The values at even indices 0 and 2 are sorted in non-decreasing order.
//? Return the array formed after rearranging the values of nums.

//! Question Tag -> Array, Sorting

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortEvenOdd(vector<int> &nums)
    {
        priority_queue<int> odd;
        priority_queue<int, vector<int>, greater<int>> even;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 0)
                even.push(nums[i]);
            if (i % 2 == 1)
                odd.push(nums[i]);
        }

        bool flag = false;
        for (int i = 0; i < nums.size(); i++)
        {
            if (flag)
            {
                nums[i] = odd.top();
                odd.pop();
                flag = false;
            }
            else
            {
                nums[i] = even.top();
                even.pop();
                flag = true;
            }
        }

        return nums;
    }
};