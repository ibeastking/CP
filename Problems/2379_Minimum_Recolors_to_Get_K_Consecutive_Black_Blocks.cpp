//? Difficulty -> Easy

//? You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B',
//? representing the color of the ith block. The characters 'W' and 'B' denote the colors white and black, respectively.
//? You are also given an integer k, which is the desired number of consecutive black blocks.
//? In one operation, you can recolor a white block such that it becomes a black block.
//? Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.

//! Question Tag -> String, Sliding Window

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    int minimumRecolors(string s, int k)
    {
        int count = INT_MAX;

        for (int i = 0; i <= s.length() - k; i++)
        {
            int countw = 0;

            for (int j = i; j < k + i; j++)
            {
                if (s[j] == 'W')
                    countw++;
            }

            count = min(count, countw);
        }

        return count;
    }
};