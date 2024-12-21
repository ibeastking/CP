//* Difficulty -> Medium

//? Given a string s, partition s such that every substring of the partition is a palindrome.
//? Return all possible palindrome partitioning of s.

//! Question Tag -> String, Dynamic Programming, Backtracking

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - i - 1])
            {
                return false;
            }
        }
        return true;
    }

    void helper(string s, vector<vector<string>> &result, vector<string> &partition, int start)
    {
        if (start == s.size())
        {
            result.push_back(partition);
            return;
        }
        for (int i = start; i < s.size(); i++)
        {
            string substring = s.substr(start, i - start + 1);
            if (isPalindrome(substring))
            {
                partition.push_back(substring);
                helper(s, result, partition, i + 1);
                partition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> partition;
        helper(s, result, partition, 0);
        return result;
    }
};