//? Difficulty -> Easy

//! Weekly Contest 332

//? You are given a 0-indexed integer array nums.
//? The concatenation of two numbers is the number formed by concatenating their numerals.
//? For example, the concatenation of 15, 49 is 1549.
//? The concatenation value of nums is initially equal to 0. Perform this operation until nums becomes empty:
//? If there exists more than one number in nums, pick the first element and last element in nums respectively and
//? add the value of their concatenation to the concatenation value of nums, then delete the first and last element from nums.
//? If one element exists, add its value to the concatenation value of nums, then delete it.
//? Return the concatenation value of the nums.

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    long long concatenate(int num1, int num2)
    {
        string str1 = to_string(num1);
        string str2 = to_string(num2);
        string result = str1 + str2;
        return stoll(result);
    }

    long long findTheArrayConcVal(vector<int> &nums)
    {
        long long result = 0;
        while (!nums.empty())
        {
            if (nums.size() == 1)
            {
                result += nums[0];
                nums.erase(nums.begin());
            }
            else
            {
                int first = nums[0];
                int last = nums[nums.size() - 1];
                result += concatenate(first, last);
                nums.erase(nums.begin());
                nums.erase(nums.end() - 1);
            }
        }
        return result;
    }
};