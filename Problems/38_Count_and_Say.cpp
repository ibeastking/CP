//* Difficulty -> Medium

//? The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
//? countAndSay(1) = "1"
//? countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
//? To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit.
//? Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.
//? For example, the saying and conversion for digit string "3322251":

//! Question Tag -> String

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string res = "1";

        for (int i = 1; i < n; i++)
        {
            string temp = "";
            int count = 1;
            for (int j = 1; j < res.size(); j++)
            {
                if (res[j] == res[j - 1])
                {
                    count++;
                }
                else
                {
                    temp.push_back(count + '0');
                    temp.push_back(res[j - 1]);
                    count = 1;
                }
            }
            temp.push_back(count + '0');
            temp.push_back(res[res.size() - 1]);
            res = temp;
        }

        return res;
    }
};