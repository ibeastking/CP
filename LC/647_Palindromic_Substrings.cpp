//* Difficulty -> Medium

//? Given a string s, return the number of palindromic substrings in it.
//? A string is a palindrome when it reads the same backward as forward.
//? A substring is a contiguous sequence of characters within the string.

//! Question Tag -> String, Dynamic Programming

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
        int count = 0;

        for (int diff = 0; diff < s.length(); diff++)
        {
            for (int i = 0, j = diff; j < s.length(); i++, j++)
            {
                if (diff == 0)
                {
                    dp[i][j] = 1;
                }
                else if (diff == 1)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = 1;
                    }
                }
                else
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j])
                {
                    count++;
                }
            }
        }

        return count;
    }
};