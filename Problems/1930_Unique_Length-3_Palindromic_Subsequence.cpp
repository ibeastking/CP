//* Difficulty -> Medium

//? Given a string s, return the number of unique palindromes of length three that are a subsequence of s.
//? Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.
//? A palindrome is a string that reads the same forwards and backwards.
//? A subsequence of a string is a new string generated from the original string with some characters (can be none)
//? deleted without changing the relative order of the remaining characters.
//? For example, "ace" is a subsequence of "abcde".

//! Question Tag -> Hash Table, String, Prefix Sum

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        unordered_map<int, vector<int>> mp;
        int count = 0;

        for (int i = 0; i < s.length(); i++)
        {
            mp[s[i]].push_back(i);
        }

        for (auto itr : mp)
        {
            vector<int> temp = itr.second;
            if (temp.size() > 1)
            {
                int left = temp[0];
                int right = temp[temp.size() - 1];

                set<char> st;
                for (int i = left + 1; i < right; i++)
                {
                    st.insert(s[i]);
                }

                count = count + st.size();
            }
        }

        return count;
    }
};