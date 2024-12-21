//? Difficulty -> Easy

//? Given a string s consisting of words and spaces, return the length of the last word in the string.
//? A word is a maximal substring consisting of non-space characters only.

//! Question Tag -> String

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {

        int last = s.size() - 1;

        while (last >= 0 and s[last] == ' ')
        {
            last--;
        }

        int count = 0;
        while (last >= 0 and s[last] != ' ')
        {
            count = count + 1;
            last = last - 1;
        }

        return count;
    }
};