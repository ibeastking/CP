//? Difficulty -> Easy

//? You are given two 0-indexed strings s and target.
//? You can take some letters from s and rearrange them to form new strings.
//? Return the maximum number of copies of target that can be formed by taking letters from s and rearranging them.

//! Question Tag -> String, Hash Table, Counting

#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

class Solution
{
public:
    int rearrangeCharacters(string s, string target)
    {
        vector<char> freqs(26, 0);
        vector<char> freqt(26, 0);
        int res = INT_MAX;

        for (int i = 0; i < s.length(); i++)
        {
            freqs[s[i] - 'a']++;
        }

        for (int i = 0; i < target.length(); i++)
        {
            freqt[target[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            int temp = floor(freqs[i] / freqt[i]);
            res = min(res, temp);
        }

        return res;
    }
};