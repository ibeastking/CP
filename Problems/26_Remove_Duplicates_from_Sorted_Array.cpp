//? Difficulty -> Easy

//? Given an integer array nums sorted in non-decreasing order, 
//? remove the duplicates in-place such that each unique element appears only once. 
//? The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
//? Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
//? Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. 
//? The remaining elements of nums are not important as well as the size of nums.
//? Return k.

//! Question Tag -> Array, Two Pointers

#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // set<int>st;

        // for(auto itr:nums){
        //     st.insert(itr);
        // }
        
        // int idx = 0;
        // for(auto itr:st){
        //     nums[idx] = itr;
        //     idx++;
        // }

        // return st.size();
        int i = 0;
        for(int j=1;j<nums.size();j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }

        return i+1;
    }
};
