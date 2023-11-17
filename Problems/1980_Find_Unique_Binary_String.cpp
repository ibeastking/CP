//* Difficulty -> Medium

//? Given an array of strings nums containing n unique binary strings each of length n,
//? return a binary string of length n that does not appear in nums.
//? If there are multiple answers, you may return any of them.

//! Question Tag -> Array, String, Backtracking

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        string res = "";

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i][i] == '0')
                res.push_back('1');
            else
                res.push_back('0');
        }

        return res;
    }
};