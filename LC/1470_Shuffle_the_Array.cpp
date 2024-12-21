//? Difficulty -> Easy

//? Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
//? Return the array in the form [x1,y1,x2,y2,...,xn,yn].

//! Question Tag -> Array

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> vt;

        for (int i = 0; i < n; i++)
        {
            vt.push_back(nums[i]);
            vt.push_back(nums[i + n]);
        }

        return vt;
    }
};

//! Bit Manipulation
//* We know that the number at max will only use 10 bits to store value so we shift the values by 10 bits and store the
//* new number's 10 bit in that area
//* we start iterating in reverse order so that no bits will get damaged and maintain an index j which will iterate in
//* reverse order to override the elements

class Solution2
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        for (int i = 0; i < n; i++)
        {
            nums[i] = nums[i] << 10;
            nums[i] = nums[i] | nums[i + n];
        }

        int j = 2 * n - 1;

        for (int i = n - 1; i > -1; i--)
        {
            int y = nums[i] & (int)(pow(2, 10) - 1);
            int x = nums[i] >> 10;

            nums[j] = y;
            nums[j - 1] = x;
            j = j - 2;
        }

        return nums;
    }
};
