//* Difficulty -> Medium

//? Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

//! Question Tags -> String, Backtracking, Dynamic Programming

//! Youtube link -> https://www.youtube.com/watch?v=WW1rYrR3tTI

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    void recur(int balance, int open, int close, string &str, vector<string> &vt)
    {
        if (balance < 0) //* if number of close bracket exceeds number of open bracket, then stop that branch and return
            return;

        //* if the number of open and close parenthesis is equal and number of close parenthesis are zero
        if (balance == 0 and close == 0)
        {
            vt.push_back(str);
            return;
        }

        if (open)
        {
            str.push_back('(');
            recur(balance + 1, open - 1, close, str, vt);
            str.pop_back();
        }
        if (close)
        {
            str.push_back(')');
            recur(balance - 1, open, close - 1, str, vt);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> vt;
        string str;

        //* recurrsive function contains 5 arguments
        //* balance is the difference between open and close parenthesis
        //* open is number of remaining open brackets to use and close is number of remaining close brackets
        //* string to store the parenthesis and vector to return as result
        recur(0, n, n, str, vt);
        return vt;
    }
};