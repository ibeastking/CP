//* Difficulty -> Medium

//? You are given a 0-indexed array of strings words and a 2D array of integers queries.
//? Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.
//? Return an array ans of size queries.length, where ans[i] is the answer to the ith query.
//? Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.

//! Leetcode weekly 331

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        vector<int> res;
        vector<int> vt;
        int count = 0;

        for (int i = 0; i < words.size(); i++)
        {
            string temp = words[i];
            if (temp[0] == 'a' or temp[0] == 'e' or temp[0] == 'i' or temp[0] == 'o' or temp[0] == 'u')
            {
                if (temp[temp.size() - 1] == 'a' or temp[temp.size() - 1] == 'e' or temp[temp.size() - 1] == 'i' or temp[temp.size() - 1] == 'o' or temp[temp.size() - 1] == 'u')
                {
                    count++;
                }
            }
            vt.push_back(count);
        }

        for (int i = 0; i < queries.size(); i++)
        {
            if (queries[i][0] == 0)
                res.push_back(vt[queries[i][1]]);
            else
                res.push_back(vt[queries[i][1]] - vt[queries[i][0] - 1]);
        }

        return res;
    }
};