//? Difficulty -> Easy

//? You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer.
//? The digits are ordered from most significant to least significant in left-to-right order.
//? The large integer does not contain any leading 0's.
//? Increment the large integer by one and return the resulting array of digits.

//! Question Tag -> Array, Math

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        bool carry = false;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] == 9)
            {
                carry = true;
                digits[i] = 0;
            }
            else
            {
                digits[i] = ++digits[i];
                carry = false;
                break;
            }
        }

        if (carry)
        {
            digits[0] = 1;
            digits.push_back(0);
        }

        return digits;
    }
};