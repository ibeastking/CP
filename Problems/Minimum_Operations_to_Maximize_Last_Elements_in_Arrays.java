package Problems;

//* Difficulty -> Medium */

//? You are given two 0-indexed integer arrays, nums1 and nums2, both having length n.
//? You are allowed to perform a series of operations (possibly none).
//? In an operation, you select an index i in the range [0, n - 1] and swap the values of nums1[i] and nums2[i].
//? Your task is to find the minimum number of operations required to satisfy the following conditions:
//? nums1[n - 1] is equal to the maximum value among all elements of nums1, i.e., nums1[n - 1] = max(nums1[0], nums1[1], ..., nums1[n - 1]).
//? nums2[n - 1] is equal to the maximum value among all elements of nums2, i.e., nums2[n - 1] = max(nums2[0], nums2[1], ..., nums2[n - 1]).
//? Return an integer denoting the minimum number of operations needed to meet both conditions, or -1 if it is impossible to satisfy both conditions.

//! Question Tag -> Array, Enumeration

class Solution {
    public int solve(int[] nums1, int[] nums2) {
        int res = 0;
        int n = nums1.length;

        for(int i=0;i<nums1.length-1;i++){
            if(nums1[i] <= nums1[n-1] && nums2[i] <= nums2[n-1]) continue;
            else if(nums1[i] <= nums2[n-1] && nums2[i] <= nums1[n-1]) res++;
            else return -1;
        }

        return res;
    }

    public int minOperations(int[] nums1, int[] nums2) {
        int res = Integer.MAX_VALUE;
        int n = nums1.length;

        int temp = solve(nums1,nums2);
        if(temp != -1) res = Math.min(res,temp);

        int num = nums1[n-1];
        nums1[n-1] = nums2[n-1];
        nums2[n-1] = num;   

        temp = solve(nums1,nums2);

        if(temp != -1) res = Math.min(res,temp+1);

        return (res == Integer.MAX_VALUE) ? (-1) : (res);
    }
}

public class Minimum_Operations_to_Maximize_Last_Elements_in_Arrays {
    
}
