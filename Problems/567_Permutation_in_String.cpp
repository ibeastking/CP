//* Difficulty -> Medium

//? Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
//? In other words, return true if one of s1's permutations is the substring of s2.

//! Question Tag -> Two Pointer, Hash Table, String, Sliding window

#include <bits\stdc++.h>
using namespace std;

class solution
{
public:
    bool checkInclusion(string s1, string s2)
    {

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        int left = 0;
        int right = 0;

        while (right < s1.length())
        {
            freq1[s1[right] - 'a']++;
            freq2[s2[right] - 'a']++;
            right++;
        }

        right--;

        while (right < s2.length())
        {
            if (freq1 == freq2)
                return true;

            right++;
            if (right != s2.length())
                freq2[s2[right] - 'a']--;

            freq2[s2[left] - 'a']--;
            left++;
        }

        return false;
    }
};

int main()
{
    solution s;
    string s1, s2;
    cout << "Enter String 1: ";
    cin >> s1;
    cout << "Enter String 2: ";
    cin >> s2;

    cout << s.checkInclusion(s1, s2);

    return 0;
}
