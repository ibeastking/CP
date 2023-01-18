//* Difficulty -> Medium

//? A binary string is monotone increasing if it consists of some number of 0's (possibly none),
//? followed by some number of 1's (also possibly none).
//? You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.
//? Return the minimum number of flips to make s monotone increasing.

//! Question Tag -> String, Dynamic Programming

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int countFlip = 0;
        int countOne = 0;

        for (auto itr : s)
        {
            if (itr == '1')
            {
                countOne++;
            }
            else
            {
                countFlip++;
                countFlip = min(countFlip, countOne);
            }
        }
        return countFlip;
    }
};