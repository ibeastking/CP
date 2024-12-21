package LC;

import java.util.List;

//? Difficulty -> Easy

//? You are given a 0-indexed integer array nums and an integer k.
//? Return an integer that denotes the sum of elements in nums whose corresponding indices have exactly k set bits in their binary representation.
//? The set bits in an integer are the 1's present when it is written in binary.
//? For example, the binary representation of 21 is 10101, which has 3 set bits.

//! Question Tag -> Array, Bit Manipulation

public class Sum_of_Values_at_Indices_With_K_Set_Bits {
    public int sumIndicesWithKSetBits(List<Integer> nums, int k) {
        int sum = 0;
        int n = nums.size();
        int[] array = new int[n];

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                array[i] = array[i / 2];
            else
                array[i] = array[i / 2] + 1;

            if (array[i] == k)
                sum += nums.get(i);
        }

        return sum;
    }
}
