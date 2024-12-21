package LC;

class Solution {
    public int minOperations(String s) {
        char[] array = s.toCharArray();
        char ch = (array[0] == '0') ? ('1') : ('0');

        int count = 0;

        for (int i = 1; i < s.length(); i++) {
            if (ch != array[i])
                count++;

            ch = (ch == '0') ? ('1') : ('0');
        }

        return Math.min(count, s.length() - count);
    }
}

public class Minimum_Changes_to_Make_Alternating_Binary_String {
    public static void main(String[] args) {
        System.out.println(new Solution().minOperations("0100"));
    }
}
