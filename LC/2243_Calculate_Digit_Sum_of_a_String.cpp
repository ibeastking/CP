//? Difficulty -> Easy

//? You are given a string s consisting of digits and an integer k.

//? A round can be completed if the length of s is greater than k. In one round, do the following:
//? Divide s into consecutive groups of size k such that the first k characters are in the first group, the next k characters are in the second group, and so on.
//? Note that the size of the last group can be smaller than k.
//? Replace each group of s with a string representing the sum of all its digits. For example, "346" is replaced with "13" because 3 + 4 + 6 = 13.
//? Merge consecutive groups together to form a new string. If the length of the string is greater than k, repeat from step 1.
//? Return s after all rounds have been completed.

//! Question Tag -> String, Simulation

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string digitSum(string s, int k)
    {
        while (s.length() > k)
        {
            string str = "";

            for (int i = 0; i < s.length(); i++)
            {
                int curr = 0;
                for (int j = i; j < i + k and j < s.length(); j++)
                {
                    curr = curr + (s[j] - '0');
                }
                i = i + k - 1;
                str = str + to_string(curr);
            }
            s = str;
        }

        return s;
    }
};