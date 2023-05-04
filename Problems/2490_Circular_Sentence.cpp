//? Difficulty -> Easy

//? A sentence is a list of words that are separated by a single space with no leading or trailing spaces.
//? For example, "Hello World", "HELLO", "hello world hello world" are all sentences.
//? Words consist of only uppercase and lowercase English letters. Uppercase and lowercase English letters are considered different
//? A sentence is circular if:
//? The last character of a word is equal to the first character of the next word.
//? The last character of the last word is equal to the first character of the first word.
//? For example, "leetcode exercises sound delightful", "eetcode", "leetcode eats soul" are all circular sentences.
//? However, "Leetcode is cool", "happy Leetcode", "Leetcode" and "I like Leetcode" are not circular sentences.
//? Given a string sentence, return true if it is circular. Otherwise, return false.

//! Question Tag -> String

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    bool isCircularSentence(string s)
    {
        vector<string> vt;
        string temp = "";
        bool flag = true;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                vt.push_back(temp);
                temp = "";
            }
            else
            {
                temp = temp + s[i];
            }
        }

        vt.push_back(temp);

        if (vt.size() == 1)
        {
            string temp = vt[0];
            return temp[0] == temp[temp.length() - 1];
        }

        for (int i = 0; i < vt.size(); i++)
        {
            if (i == vt.size() - 1)
            {
                string s1 = vt[0];
                string s2 = vt[vt.size() - 1];
                if (s1[0] != s2[s2.length() - 1])
                {
                    return false;
                }
            }
            else
            {
                string s1 = vt[i];
                string s2 = vt[i + 1];
                if (s1[s1.length() - 1] != s2[0])
                {
                    return false;
                }
            }
        }

        return flag;
    }
};