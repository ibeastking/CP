//* Difficulty -> Medium

//? A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.
//? For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
//? Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s.
//? You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

//! Question Tag -> String, Backtracking

#include <bits\stdc++.h>
using namespace std;

class solution
{
public:
    vector<string> restoreIPAddress(string s)
    {
        vector<string> res;

        for (int i = 1; i < 4; i++)
        {
            for (int j = 1; j < 4; j++)
            {
                for (int k = 1; k < 4; k++)
                {
                    for (int l = 1; l < 4; l++)
                    {
                        if (i + j + l + k == s.length())
                        {
                            //* below conversion is done to remove all leading zeroes
                            string s1 = to_string(stoi(s.substr(0, i)));
                            string s2 = to_string(stoi(s.substr(i, j)));
                            string s3 = to_string(stoi(s.substr(i + j, k)));
                            string s4 = to_string(stoi(s.substr(i + j + k, l)));

                            //* check if all digits are below 256
                            if (stoi(s1) < 256 and stoi(s2) < 256 and stoi(s3) < 256 and stoi(s4) < 256)
                            {
                                //* after removing leading zeroes, check if the string is still equal to length of input string
                                string t = s1 + "." + s2 + "." + s3 + "." + s4;
                                if (t.length() == s.length() + 3)
                                    res.push_back(t);
                            }
                        }
                    }
                }
            }
        }

        return res;
    }
};