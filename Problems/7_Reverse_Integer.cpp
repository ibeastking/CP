//? Difficulty -> Medium

//? Given a signed 32-bit integer x, return x with its digits reversed.
//? If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
//? Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

//! Question Tag -> Math

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        signed int n = abs(x);
        signed int num = 0;

        while (n > 0)
        {

            if (num > INT_MAX / 10 or num == INT_MAX / 10 and n % 10 > 7)
            {
                return 0;
            }

            if (num < INT_MIN / 10 or num == INT_MIN / 10 and n % 10 < -8)
            {
                return 0;
            }

            cout << "num: " << num << ",n: " << n << endl;

            num = (num * 10) + (n % 10);
            n = n / 10;
        }

        if (x >= 0)
        {
            return num;
        }
        else
        {
            num = 0 - num;
            return num;
        }
    }
};