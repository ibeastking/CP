//* Difficulty -> Medium

//? Given a string s, find the longest palindromic subsequence's length in s.
//? A subsequence is a sequence that can be derived from another sequence by deleting some
//? or no elements without changing the order of the remaining elements.

//! Question Tag -> String, Dynamic Programming

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution0
{
public:
    int solve(vector<vector<int>> &dp, string s, int start, int end)
    {
        if (start == end)
            return 1;
        if (start > end)
            return 0;
        if (dp[start][end] != 0)
            return dp[start][end];

        if (s[start] == s[end])
            return dp[start][end] = 2 + dp[start + 1][end - 1];

        int leaveleft = solve(dp, s, start + 1, end);
        int leaveright = solve(dp, s, start, end - 1);

        return dp[start][end] = max(leaveleft, leaveright);
    }

    int longestPalindromeSubseq(string s)
    {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
        int res = solve(dp, s, 0, s.length() - 1);
        return res;
    }
};

class Solution1
{
public:
    int longestPalindromeSubseq(string s)
    {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));

        for (int len = 1; len <= s.length(); len++)
        {
            for (int start = 0; start <= s.length() - len; start++)
            {
                int end = start + len - 1;

                if (len == 1)
                {
                    dp[start][end] = 1;
                    continue;
                }

                if (s[start] == s[end])
                    dp[start][end] = 2 + dp[start + 1][end - 1];
                else
                    dp[start][end] = max(dp[start + 1][end], dp[start][end - 1]);
            }
        }

        return dp[0][s.length() - 1];
    }
};