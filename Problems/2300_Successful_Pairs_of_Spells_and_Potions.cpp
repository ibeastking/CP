//* Difficulty -> Medium

//? You are given two positive integer arrays spells and potions, of length n and m respectively,
//? where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.
//? You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.
//? Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.

//! Question Tag -> Array, Greedy, Two Pointer, Sorting

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        vector<int> res;

        sort(potions.begin(), potions.end());

        for (long long spell : spells)
        {
            long long product = 0;
            int slow = 0;
            int fast = potions.size() - 1;

            while (slow <= fast)
            {
                int mid = slow + (fast - slow) / 2;
                product = spell * (long long)(potions[mid]);

                if (product >= success)
                {
                    fast = mid - 1;
                }
                else
                {
                    slow = mid + 1;
                }
            }

            res.push_back(potions.size() - slow);
        }

        return res;
    }
};