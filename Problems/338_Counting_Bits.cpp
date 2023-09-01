//? Difficulty -> Easy

//? Given an integer n,
//? return an array ans of length n + 1 such that for each i (0 <= i <= n),
//? ans[i] is the number of 1's in the binary representation of i.

//! Question Tag -> Dynamic Programming, Bit Manipulation

#include <bits\stdc++.h>
using namespace std;

//* below solution will have time complexity of n*log(n)
class Solution_brute_force
{
public:
    vector<int> countBits(int n)
    {
        vector<int> res(n + 1, 0);

        for (int i = 0; i <= n; i++)
        {
            int count = 0;
            int num = i;
            while (num > 0)
            {
                count = count + num % 2;
                num = num / 2;
            }
            res[i] = num;
        }

        return res;
    }
};

//* below solution will have time complexity of log(n)
//* in this code, the value of any number is left shift of its half if it is even
//* if number is odd, the value of number is left shift of its half + 1
class Solution_optimal
{
public:
    vector<int> countBits(int n)
    {
        vector<int> res(n + 1, 0);

        for (int i = 0; i < n + 1; i++)
        {
            if (i % 2 == 0)
            {
                res[i] = res[i / 2];
            }
            else
            {
                res[i] = res[i / 2] + 1;
            }
        }

        return res;
    }
};