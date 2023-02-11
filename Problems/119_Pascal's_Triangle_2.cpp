//? Difficulty -> Easy

//? Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

//! Question Tag -> Array, Dynamic Programming

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {

        vector<int> ans(rowIndex + 1, 1);

        for (int i = 2; i < rowIndex + 1; i++)
        {
            for (int j = 1; j < i; j++)
            {
                ans[i - j] += ans[i - j - 1];
            }
        }

        return ans;
    }
};