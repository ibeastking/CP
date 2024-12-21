//? Difficulty -> Easy

//? The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence,
//? such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
//? F(0) = 0, F(1) = 1
//? F(n) = F(n - 1) + F(n - 2), for n > 1.
//? Given n, calculate F(n).

//! Question Tag -> Math, Dynamic Programming, Recursion, Memoization

#include <bits\stdc++.h>
using namespace std;

class solution
{
public:
    class Solution
    {
    public:
        int fib(int n)
        {
            if (n == 0)
                return 0;
            if (n == 1 or n == 2)
                return 1;

            vector<int> vt(n + 1);
            vt[1] = 1;
            vt[2] = 1;

            for (int i = 3; i < n + 1; i++)
            {
                vt[i] = vt[i - 1] + vt[i - 2];
            }

            return vt[n];
        }
    };
};