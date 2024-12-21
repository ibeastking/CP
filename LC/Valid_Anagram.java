//? Difficulty -> Easy

package LeetCode;

import java.util.Scanner;

class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length())
            return false;

        int[] sfreq = new int[26];
        int[] tfreq = new int[26];

        for (int i = 0; i < s.length(); i++) {
            sfreq[s.charAt(i) - 'a']++;
            tfreq[t.charAt(i) - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (sfreq[i] != tfreq[i])
                return false;
        }

        return true;
    }
}

public class Valid_Anagram {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.nextLine();
        String s2 = sc.nextLine();

        boolean res = new Solution().isAnagram(s1, s2);
        System.out.println(res);

        sc.close();
    }
}
