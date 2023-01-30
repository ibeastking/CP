//? Difficulty -> Easy

//? You are climbing a staircase. It takes n steps to reach the top.
//? Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

//! Question Tag -> Math, Dynamic Programming, Memoization

#include <bits\stdc++.h>
using namespace std;

class solution
{
public:
    class Solution
    {
    public:
        int climbStairs(int n)
        {
            if (n <= 2)
                return n;

            vector<int> vt(n + 1);
            vt[0] = 0;
            vt[1] = 1;
            vt[2] = 2;

            for (int i = 3; i < n + 1; ++i)
            {
                vt[i] = vt[i - 2] + vt[i - 1];
            }

            return vt[n];
        }
    };
};