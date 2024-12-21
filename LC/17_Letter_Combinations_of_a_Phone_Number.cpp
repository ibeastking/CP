//* Difficulty -> Medium

//? Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
//? Return the answer in any order.
//? A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

//! Question Tags -> Hash Table, String, Backtracking

//! Youtube link -> https://www.youtube.com/watch?v=tWnHbSHwNmA

//* Above question is solved using backtracking method and defth first traversal

#include <bits\stdc++.h>
using namespace std;

class Solution
{
private:
    //* creating a dfs function to iterate through the tree until tree is over
    void dfs(vector<string> &vt, map<char, string> &mp, string str, int index, string res)
    {
        //* base case which checks whether the iteration are within the tree or it has gone out of tree
        //* if index goes out, then push the string in result vector and stop that tree route using return
        if (index >= str.size())
        {
            vt.push_back(res);
            return;
        }

        //* create a temporary array to store the string of pressed key
        string temp = mp[str[index]];

        //*  iterate through all the possible strings
        for (int i = 0; i < temp.size(); i++)
        {
            res.push_back(temp[i]);
            dfs(vt, mp, str, index + 1, res);
            res.pop_back();
        }
    }

public:
    //* main function
    vector<string> letterCombinations(string digits)
    {
        vector<string> vt;
        int n = digits.size();
        string res = "";

        if (n == 0)
            return vt;

        //* creating hash map to store string values
        map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        //* start defth first traversal
        //* passing resultant vector, hashmap, input string, current index and string
        dfs(vt, mp, digits, 0, res);

        return vt;
    }
};