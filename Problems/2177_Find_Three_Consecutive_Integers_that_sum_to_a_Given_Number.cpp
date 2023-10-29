//* Difficulty -> Medium

//? Given an integer num,
//? return three consecutive integers (as a sorted array) that sum to num.
//? If num cannot be expressed as the sum of three consecutive integers,
//? return an empty array.

//! Question Tag -> Math, Simulation

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<long long> sumOfThree(long long num)
    {
        vector<long long> res;

        if (num % 3 == 0)
        {
            res.push_back(num / 3 - 1);
            res.push_back(num / 3);
            res.push_back(num / 3 + 1);
        }

        return res;
    }
};