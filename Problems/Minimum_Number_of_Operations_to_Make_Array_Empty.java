//* Difficulty -> Medium

//? You are given a 0-indexed array nums consisting of positive integers.
//? There are two types of operations that you can apply on the array any number of times:
//? Choose two elements with equal values and delete them from the array.
//? Choose three elements with equal values and delete them from the array.
//? Return the minimum number of operations required to make the array empty, or -1 if it is not possible.

//! Question Tag -> Array, HashTable, Greedy, Counting

package Problems;

import java.util.Arrays;
import java.util.HashMap;

class Solution_Sorting {
    public int minOperations(int[] nums) {
        Arrays.sort(nums);

        int res = 0;
        int left = 0;

        while(left < nums.length){
            int right = left;
            
            while(right < nums.length && nums[right] == nums[left]) {
                right++;
            }

            int count = right - left;
            if(count == 1) return -1;

            res += count/3;

            if(count%3 != 0) res++;
            left = right;
        }
        
        return res; 
    }
}

class Solution_HashMap {
    public int minOperations(int[] nums) {
        int res = 0;
        HashMap<Integer, Integer> map = new HashMap<>();

        for(int num: nums){
            map.put(num, map.getOrDefault(num,0)+1);
        }

        for(HashMap.Entry<Integer, Integer> entry: map.entrySet()){
            int value = entry.getValue();
            if(value == 1) return -1;
            
            res = res + value/3;
            if(value%3 != 0) res++;
        }

        return res;
    }
}