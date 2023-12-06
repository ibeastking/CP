//* Difficulty -> Medium

//? There are 3n piles of coins of varying size, you and your friends will take piles of coins as follows:
//? In each step, you will choose any 3 piles of coins (not necessarily consecutive).
//? Of your choice, Alice will pick the pile with the maximum number of coins.
//? You will pick the next pile with the maximum number of coins.
//? Your friend Bob will pick the last pile.
//? Repeat until there are no more piles of coins.
//? Given an array of integers piles where piles[i] is the number of coins in the ith pile.
//? Return the maximum number of coins that you can have.

//! Question Tag -> Array, Math, Greedy, Sorting, Game Theory

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        int res = 0;
        sort(piles.begin(), piles.end());

        int idx = piles.size() - 2;
        for (int i = 0; i < piles.size() / 3; i++)
        {
            res = res + piles[idx];
            idx = idx - 2;
        }

        return res;
    }
};