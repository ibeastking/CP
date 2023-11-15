//? Difficulty -> Easy

//? Given a string s, reverse only all the vowels in the string and return it.
//? The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

//! Question Tag -> Two Pointer, String

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool fun(char ch)
    {
        return (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U') ? (false) : (true);
    }

    string reverseVowels(string s)
    {
        int left = 0;
        int right = s.length() - 1;

        while (left < right)
        {
            while (fun(s[left]) and left < s.length())
            {
                left++;
            }

            while (fun(s[right]) and 0 < right)
            {
                right--;
            }

            if (left < right)
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};