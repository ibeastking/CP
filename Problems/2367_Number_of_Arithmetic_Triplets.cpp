//? Difficulty -> Easy

//? You are given a 0-indexed, strictly increasing integer array nums and a positive integer diff. A triplet (i, j, k) is an arithmetic triplet if the following conditions are met:
//? i < j < k,
//? nums[j] - nums[i] == diff, and
//? nums[k] - nums[j] == diff.
//? Return the number of unique arithmetic triplets.

//! Question Tag -> Array, Hash Table, Two Pointers, Enumeration

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int arithmeticTriplets(vector<int> &nums, int diff)
    {
        int count = 0;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                if (nums[j] - nums[i] == diff)
                {
                    for (int k = j + 1; k < nums.size(); k++)
                    {
                        if (nums[j] - nums[i] == diff and nums[k] - nums[j] == diff)
                        {
                            count++;
                        }
                    }
                }
            }
        }

        return count;
    }
};
