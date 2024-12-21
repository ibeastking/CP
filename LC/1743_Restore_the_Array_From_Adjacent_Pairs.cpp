//* Difficulty -> Medium

//? There is an integer array nums that consists of n unique elements, but you have forgotten it.
//? However, you do remember every pair of adjacent elements in nums.
//? You are given a 2D integer array adjacentPairs of size n - 1
//? where each adjacentPairs[i] = [ui, vi] indicates that the elements ui and vi are adjacent in nums.
//? It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will exist in adjacentPairs,
//? either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any order.
//? Return the original array nums. If there are multiple solutions, return any of them.

//! Question Tag -> Array, Hash Table

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> restoreArray(vector<vector<int>> &adj)
    {
        vector<int> res;
        unordered_map<int, vector<int>> mp;

        for (auto itr : adj)
        {
            mp[itr[0]].push_back(itr[1]);
            mp[itr[1]].push_back(itr[0]);
        }

        for (auto itr : mp)
        {
            if (itr.second.size() == 1)
            {
                res.push_back(itr.first);
                res.push_back(itr.second[0]);
                break;
            }
        }

        while (res.size() < mp.size())
        {
            int last = res[res.size() - 1];
            int slast = res[res.size() - 2];

            vector<int> temp = mp[last];

            if (temp[0] == slast)
            {
                res.push_back(temp[1]);
            }
            else
            {
                res.push_back(temp[0]);
            }
        }

        return res;
    }
};