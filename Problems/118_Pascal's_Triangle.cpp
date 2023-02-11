//? Difficulty -> Easy

//? Given an integer numRows, return the first numRows of Pascal's triangle.

//! Question Tag -> Array, Dynamic Programming

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int n)
    {
        vector<vector<int>> vt;

        for (int i = 0; i < n; i++)
        {
            vector<int> nums(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                nums[j] = (vt[i - 1][j - 1] + vt[i - 1][j]);
            }
            vt.push_back(nums);
        }

        return vt;
    }
};