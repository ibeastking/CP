//? Difficulty -> Easy

//? Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.
//? If there are fewer than k characters left, reverse all of them.
//? If there are less than 2k but greater than or equal to k characters,
//? then reverse the first k characters and leave the other as original.

//! Question Tag -> Two Pointer, String

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseStr(string s, int k)
    {

        for (int left = 0; left < s.size(); left += 2 * k)
        {
            for (int i = left, j = (left + k - 1 < s.length() - 1) ? (left + k - 1) : (s.length() - 1); i < j; i++, j--)
            {
                swap(s[i], s[j]);
            }
        }
        return s;
    }
};