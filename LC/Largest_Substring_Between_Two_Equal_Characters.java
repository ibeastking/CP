package LC;

//? Difficulty -> Easy

//? Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. 
//? If there is no such substring return -1.
//? A substring is a contiguous sequence of characters within a string.

//! Question Tag -> Hash Table, String

class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        for (int i = s.length() - 1; i > 0; i--) {
            for (int j = 0; j + i < s.length(); j++) {
                if (s.charAt(j) == s.charAt(j + i))
                    return i - 1;
            }
        }
        return -1;
    }
}

class Largest_Substring_Between_Two_Equal_Characters {
    public static void main(String[] args) {
        new Solution().maxLengthBetweenEqualCharacters("abcbabf");
    }
}