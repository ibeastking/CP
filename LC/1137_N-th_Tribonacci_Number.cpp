//? Difficulty -> Easy

//? The Tribonacci sequence Tn is defined as follows:
//? T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
//? Given n, return the value of Tn.

//! Question Tag -> Math, Dynamic Programming, Memotization

#include <bits\stdc++.h>
using namespace std;

class solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1 or n == 2)
            return 1;
        vector<int> vt(n + 1, 0);
        vt[1] = 1;
        vt[2] = 1;

        for (int i = 3; i < n + 1; i++)
        {
            vt[i] = vt[i - 3] + vt[i - 2] + vt[i - 1];
        }

        return vt[n];
    }
};