//? Difficulty -> Easy

//? Given a non-negative integer x, return the square root of x rounded down to the nearest integer.
//? The returned integer should be non-negative as well.
//? You must not use any built-in exponent function or operator.

//! Question Tag -> Math, Binary Search

#include <iostream>
#include <math.h>
using namespace std;

//! Binary Search
class Solution1
{
public:
    int mySqrt(int x)
    {

        if (x < 2)
            return x;

        int left = 1, right = x / 2;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            long long temp = pow(mid, 2);

            if (temp <= x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left - 1;
    }
};

//! Math
class Solution2
{
public:
    int mySqrt(int x)
    {
        double y = log10(x);
        y = y / 2;
        return (pow(10, y));
    }
};