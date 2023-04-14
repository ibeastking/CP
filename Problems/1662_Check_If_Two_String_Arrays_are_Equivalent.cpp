//? Difficulty -> Easy

//? Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
//? A string is represented by an array if the array elements concatenated in order forms the string.

//! Question Tag -> Array, String

#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

class Solution0
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        int idx1 = 0, idx2 = 0;
        int i = 0, j = 0;

        while (i < word1.size() and j < word2.size())
        {
            if (word1[i][idx1++] != word2[j][idx2++])
                return false;
            if (idx1 == word1[i].size())
                i++, idx1 = 0;
            if (idx2 == word2[j].size())
                j++, idx2 = 0;
        }

        return i == word1.size() and j == word2.size();
    }
};

class Solution1
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string s1 = "";
        string s2 = "";

        s1 = accumulate(word1.begin(), word1.end(), s1);
        s2 = accumulate(word2.begin(), word2.end(), s2);

        return (!s1.compare(s2));
    }
};