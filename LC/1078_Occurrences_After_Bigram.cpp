//? Difficulty -> Easy

//? Given two strings first and second, consider occurrences in some text of the form "first second third",
//? where second comes immediately after first, and third comes immediately after second.
//? Return an array of all the words third for each occurrence of "first second third".

//! Question Tag -> String

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> findOcurrences(string text, string first, string second)
    {
        vector<string> vt;
        vector<string> res;
        string temp = "";

        for (int i = 0; i < text.size(); i++)
        {
            if (text[i] == ' ')
            {
                vt.push_back(temp);
                temp = "";
            }
            else
            {
                temp = temp + text[i];
            }
        }

        vt.push_back(temp);

        for (int i = 2; i < vt.size(); i++)
        {
            if (vt[i - 2] == first and vt[i - 1] == second)
            {
                res.push_back(vt[i]);
            }
        }

        return res;
    }
};