//? Difficulty -> Easy

//? Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
//? You must implement a solution with a linear runtime complexity and use only constant extra space.

//! Question Tag -> Array, Bit Manipulation

#include<stdio.h>
#include<vector>
using namespace std;

//! This is an important property of xor operator. When we XOR two equal values they will give 
//! output as zero as they cancel each other out.
//! In below question, only the single value will be left and all other values will get cancelled out.

class Solution{
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];

        for(int i=1;i<nums.size();i++) {
            res = res ^ nums[i];
        }

        return res;
    }
};