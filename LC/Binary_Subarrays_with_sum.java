package LC;

import java.util.HashMap;

//* Difficulty -> Medium */

//? Given a binary array nums and an integer goal, 
//? return the number of non-empty subarrays with a sum goal.
//? A subarray is a contiguous part of the array.

//! Question Tag -> Array, Hash Table, Sliding Window, Prefix Sum

class Binary_Subarrays_with_sum {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int res = 0;
        int psum = 0;

        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);

        for (int num : nums) {
            psum += num;
            res += map.getOrDefault(psum - goal, 0);
            map.put(psum, map.getOrDefault(psum, 0) + 1);
        }

        return res;
    }
}