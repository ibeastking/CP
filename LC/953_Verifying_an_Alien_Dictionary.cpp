//? Difficulty -> Easy

//? In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order.
//? The order of the alphabet is some permutation of lowercase letters.
//? Given a sequence of words written in the alien language, and the order of the alphabet,
//? return true if and only if the given words are sorted lexicographically in this alien language.

//! Question Tag -> Array, Hash Table, String

#include <bits\stdc++.h>
using namespace std;

class solution
{
public:
    class Solution
    {
    public:
        bool isvalid(string a, string b, unordered_map<char, int> vt)
        {
            for (int i = 0; i < min(a.length(), b.length()); i++)
            {
                if (vt[b[i]] > vt[a[i]])
                    return true;
                else if (vt[b[i]] < vt[a[i]])
                    return false;
            }
            return (a.length() > b.length()) ? (false) : (true);
        }

        bool isAlienSorted(vector<string> &wordsords, string order)
        {
            unordered_map<char, int> mp;

            for (int i = 0; i < order.length(); i++)
                mp[order[i]] = i;

            for (int i = 0; i < wordsords.size() - 1; i++)
            {
                if (!(isvalid(wordsords[i], wordsords[i + 1], mp)))
                {
                    return false;
                }
            }

            return true;
        }
    };
};

class solution2
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        int n = words.size();
        vector<int> ref(26, -1);

        for (int i = 0; i < order.size(); i++)
        {
            ref[order[i] - 'a'] = i;
        }

        for (int i = 0; i < (n - 1); i++)
        {
            int a = words[i].size(), b = words[i + 1].size();
            int k = 0, j = 0, flg = 0;

            while (k < a and j < b)
            {
                if (ref[words[i][k] - 'a'] > ref[words[i + 1][j] - 'a'])
                    return false;
                if (ref[words[i][k] - 'a'] < ref[words[i + 1][j] - 'a'])
                {
                    flg = 1;
                    break;
                }
                k++;
                j++;
            }

            if (flg)
                continue;
            else
            {
                if (a > b)
                    return false;
            }
        }
        return true;
    }
};
