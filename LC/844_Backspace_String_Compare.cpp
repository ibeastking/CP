//? Difficulty -> Easy

//? Given two strings s and t,
//? return true if they are equal when both are typed into empty text editors.
//? '#' means a backspace character.
//? Note that after backspacing an empty text, the text will continue empty.

//! Question Tag -> Two Pointers, String, Stack, Simulation

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> st1, st2;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '#' and !st1.empty())
            {
                st1.pop();
            }
            else
            {
                if (s[i] != '#')
                {
                    st1.push(s[i]);
                }
            }
        }

        for (int i = 0; i < t.length(); i++)
        {
            if (t[i] == '#' and !st2.empty())
            {
                st2.pop();
            }
            else
            {
                if (t[i] != '#')
                {
                    st2.push(t[i]);
                }
            }
        }

        while (!st1.empty() and !st2.empty())
        {
            if (st1.top() != st2.top())
                return false;

            st1.pop();
            st2.pop();
        }

        return (st1.empty() and st2.empty()) ? (true) : (false);
    }
};