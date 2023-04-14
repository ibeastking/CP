//? Difficulty -> Easy

//? You are given an array of strings words and a string chars.
//? A string is good if it can be formed by characters from chars (each character can only be used once).
//? Return the sum of lengths of all good strings in words.

//! Question Tag -> Array, Hash Table, String

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        vector<char> freq(26, 0);
        int count = 0;

        for (int i = 0; i < chars.size(); i++)
        {
            freq[chars[i] - 'a']++;
        }

        for (int i = 0; i < words.size(); i++)
        {
            string temp = words[i];
            int j;
            for (j = 0; j < temp.length(); j++)
            {
                if (freq[temp[j] - 'a'] == 0)
                {
                    break;
                }
                freq[temp[j] - 'a']--;
            }

            if (j == temp.length())
            {
                count += temp.length();
            }

            // restore frequency of characters in chars
            for (int k = 0; k < j; k++)
            {
                freq[temp[k] - 'a']++;
            }
        }

        return count;
    }
};