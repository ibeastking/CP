//* Difficulty -> Medium

//? Given a 0-indexed string s, permute s to get a new string t such that:
//? All consonants remain in their original places.
//? More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] = s[i].
//? The vowels must be sorted in the nondecreasing order of their ASCII values.
//? More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels,
//? then t[i] must not have a higher ASCII value than t[j].
//? Return the resulting string.
//? The vowels are 'a', 'e', 'i', 'o', and 'u', and
//? they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.

//! Question Tag -> String, Sorting

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string sortVowels(string s)
    {
        vector<int> index;
        vector<char> val;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U')
            {
                index.push_back(i);
                val.push_back(s[i]);
            }
        }

        sort(val.begin(), val.end());

        for (int i = 0; i < val.size(); i++)
        {
            s[index[i]] = val[i];
        }

        return s;
    }
};