//* Difficulty -> Medium

//? Implement pow(x,n), which calculates x raised to the power n.

//! Question Tag -> Math, Recurrsion

#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        double res = 1.0;
        long long num = n;

        //* for calculation purpose make power positive
        if (num < 0)
        {
            num = -1 * n;
        }

        while (num > 0)
        {
            //* if power is odd, just multiple one type and reduce power by 1
            if (num % 2 == 1)
            {
                res = res * x;
                num--;
            }
            //* if power is even, square the current value and reduce power by half
            else
            {
                x = x * x;
                num = num / 2;
            }
        }

        //* if n is negative that means power is negative, so we have to divide 1 by the res
        if (n < 0)
        {
            res = (double)(1.0) / (double)(res);
        }

        return res;
    }
};