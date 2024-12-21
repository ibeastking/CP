//* Difficulty -> Medium

//? Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
//? In other words, return true if one of s1's permutations is the substring of s2.

//! Question Tag -> Two Pointer, Hash Table, String, Sliding window

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        //! if length of s1 is greater then there is not permutation
        if (s1.length() > s2.length())
            return false;

        int left = 0;  //* stores the character whose address needs to be decremented
        int right = 0; //* stores the character whose address needs to be added

        while (right < s1.length())
        {
            freq1[s1[right] - 'a']++;
            freq2[s2[right] - 'a']++;
            right++;
        }

        //! right exceeds length of length of s1 so we should we decrement it by 1
        right--;

        while (right < s2.length())
        {
            if (freq1 == freq2)
                return true; //* if both frequency match, it means s1 is permutation of s2

            //* if we reach here then current substring is not a permutation
            //* so we move right to next location
            right++;
            if (right != s2.length())
            {
                freq2[s2[right] - 'a']++; //* increment the frequency of current character in right
            }

            freq2[s2[left] - 'a']--; //* decrement the frequency of leftmost character
            left++;
        }

        return false;
    }
};
