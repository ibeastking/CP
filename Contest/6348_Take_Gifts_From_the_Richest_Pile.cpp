//? Difficulty -> Easy

//? You are given an integer array gifts denoting the number of gifts in various piles.
//? Every second, you do the following:
//? Choose the pile with the maximum number of gifts.
//? If there is more than one pile with the maximum number of gifts, choose any.
//? Leave behind the floor of the square root of the number of gifts in the pile. Take the rest of the gifts.
//? Return the number of gifts remaining after k seconds.

//! Leetcode weekly 331

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        while (k--)
        {
            int max_gift = 0, max_index = -1;
            for (int i = 0; i < gifts.size(); i++)
            {
                if (gifts[i] > max_gift)
                {
                    max_gift = gifts[i];
                    max_index = i;
                }
            }
            gifts[max_index] = (int)sqrt(gifts[max_index]);
        }

        long long remaining = 0;
        for (int i = 0; i < gifts.size(); i++)
        {
            remaining += gifts[i];
        }
        return remaining;
    }
};