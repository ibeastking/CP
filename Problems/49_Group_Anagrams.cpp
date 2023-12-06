//* Difficulty -> Medium

//? Given an array of strings strs, group the anagrams together. You can return the answer in any order.
//? An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
//? typically using all the original letters exactly once.

//! Question Tag -> Array, Hash Table, String, Sorting

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]);
        }

        for (auto itr : mp)
        {
            res.push_back(itr.second);
        }

        return res;
    }
};