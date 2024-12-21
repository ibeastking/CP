//? Difficulty -> Easy

//? You are given two strings word1 and word2.
//? Merge the strings by adding letters in alternating order, starting with word1.
//? If a string is longer than the other, append the additional letters onto the end of the merged string.
//? Return the merged string.

//! Question Tag -> Two Pointer, String

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string res;
        int idx1 = 0;
        int idx2 = 0;
        bool flag = true;

        while (idx1 < word1.length() and idx2 < word2.length())
        {
            if (flag)
            {
                res.push_back(word1[idx1]);
                idx1++;
                flag = false;
            }
            else
            {
                res.push_back(word2[idx2]);
                idx2++;
                flag = true;
            }
        }

        while (idx1 < word1.length())
        {
            res.push_back(word1[idx1]);
            idx1++;
        }

        while (idx2 < word2.length())
        {
            res.push_back(word2[idx2]);
            idx2++;
        }

        return res;
    }
};