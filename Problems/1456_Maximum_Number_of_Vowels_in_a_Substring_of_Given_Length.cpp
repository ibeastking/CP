//* Difficulty -> Medium

//? Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
//? Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

//! Question Tag -> String, Sliding winow

#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int vcount = 0;
        int ccount = 0;
        int res = 0;

        for (int i = 0; i < k; i++)
        {
            if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u')
            {
                vcount++;
            }
            else
            {
                ccount++;
            }
        }

        res = vcount;

        for (int i = 1; i <= s.length() - k; i++)
        {
            if (s[i - 1] == 'a' or s[i - 1] == 'e' or s[i - 1] == 'i' or s[i - 1] == 'o' or s[i - 1] == 'u')
            {
                vcount--;
            }
            else
            {
                ccount--;
            }

            if (s[i + k - 1] == 'a' or s[i + k - 1] == 'e' or s[i + k - 1] == 'i' or s[i + k - 1] == 'o' or s[i + k - 1] == 'u')
            {
                vcount++;
            }
            else
            {
                ccount++;
            }

            res = max(res, vcount);
        }

        return res;
    }
};