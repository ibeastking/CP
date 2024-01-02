package GFG;

import java.util.HashMap;

class Solution {
    public boolean canPair(int[] nums, int k) {
        // Code here
        if (nums.length % 2 != 0)
            return false;

        HashMap<Integer, Integer> map = new HashMap<>();

        for (int num : nums) {
            map.put(num % k, map.computeIfAbsent(num % k, key -> 0) + 1);
        }

        for (HashMap.Entry<Integer, Integer> entry : map.entrySet()) {
            if (entry.getKey() != 0) {
                int freq1 = entry.getValue();
                int key = k - entry.getKey();
                int freq2 = map.getOrDefault(key, 0);
                if (freq2 == 0)
                    return false;
                if ((freq1 + freq2) % 2 != 0)
                    return false;
            } else {
                if (entry.getValue() % 2 != 0)
                    return false;
            }
        }

        return true;
    }
}

public class Array_Pair_Sum_Divisibility_Problem {
    public static void main(String[] args) {
        new Solution().canPair(new int[] { 1, 2, 4, 3 }, 4);
    }
}
