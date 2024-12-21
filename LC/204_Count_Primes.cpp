//* Difficulty -> Medium

//? Given an integer n, return the number of prime numbers that are strictly less than n.

//! Question Tag -> Array, Math, Enumeration, Number Theory

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        vector<int> isPrime(n + 1, 1);
        int count = 0;

        for (int i = 2; i * i <= n; i++)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j <= n; j = j + i)
                {
                    isPrime[j] = 0;
                }
            }
        }

        for (int i = 2; i < n; i++)
        {
            if (isPrime[i])
                count++;
        }

        return count;
    }
};