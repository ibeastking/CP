//* Difficulty -> Medium */

//? You are given an integer array nums. 
//? You need to create a 2D array from nums satisfying the following conditions:
//? The 2D array should contain only the elements of the array nums.
//? Each row in the 2D array contains distinct integers.
//? The number of rows in the 2D array should be minimal.
//? Return the resulting array. If there are multiple answers, return any of them.
//? Note that the 2D array can have a different number of elements on each row.

//! Question Tag -> Array, HashTable

package LeetCode;

import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;

class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {

        List<List<Integer>> list = new ArrayList<>();
        // int[] map = new int[200]; //* remember to -1
        HashMap<Integer, Integer> map = new HashMap<>();
        int max_freq = 0;

        for(int num: nums){
            map.put(num,map.computeIfAbsent(num,key->0)+1);
            max_freq = Math.max(max_freq,map.computeIfAbsent(num,key->0));
        }

        while(max_freq>0){
            list.add(new ArrayList<>());
            max_freq--;
        }

        for(HashMap.Entry<Integer, Integer> entry: map.entrySet()){
            int idx = 0;
            int key = (int)entry.getKey();
            int val = (int)entry.getValue();

            while(val>0){
                list.get(idx).add(key);
                idx++;
                val--;
            }
        }

        return list;
    }
}

public class Convert_an_Array_into_2D_Array {
    
}
