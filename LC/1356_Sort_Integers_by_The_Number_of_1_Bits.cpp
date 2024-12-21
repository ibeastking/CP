//? Difficulty -> Easy

//? You are given an integer array arr.
//? Sort the integers in the array in ascending order by the number of 1's in their binary representation
//? and in case of two or more integers have the same number of 1's you have to sort them in ascending order.
//? Return the array after sorting it.

//! Question Tag -> Array, Bit Manipulation, Sorting, Counting

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        vector<int> res;
        vector<pair<int, int>> vectorMap;

        for (int i = 0; i < arr.size(); i++)
        {
            int count = 0;
            int temp = arr[i];

            while (temp)
            {
                temp = temp & (temp - 1);
                count++;
            }

            vectorMap.push_back({arr[i], count});
        }

        sort(vectorMap.begin(), vectorMap.end(), [](const auto &a, const auto &b)
             { return (a.second != b.second) ? (a.second < b.second) : (a.first < b.first); });

        for (auto itr : vectorMap)
        {
            res.push_back(itr.first);
        }

        return res;
    }
};