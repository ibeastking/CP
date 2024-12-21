//! Difficulty -> Hard

//? You are given an integer array nums and two integers minK and maxK.
//? A fixed-bound subarray of nums is a subarray that satisfies the following conditions:
//? The minimum value in the subarray is equal to minK.
//? The maximum value in the subarray is equal to maxK.
//? Return the number of fixed-bound subarrays.
//? A subarray is a contiguous part of an array.

//! Question Tag -> Array, Queue, Sliding Window, Monotonic Queue

#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    long long countSubarrays(vector<int>& nums, int mink, int maxk){
        int res = 0;
        int start = 0, minstart = 0, maxstart = 0;
        bool minf = false, maxf = false;

        for(int i=0;i<nums.size();i++) {
            int temp = nums[i];

            if(temp<mink or temp>maxk) {
                minf = false;
                maxf = false;
                start = i+1;
            }

            if(temp == mink){
                minf = true;
                minstart = i;
            }

            if(temp == maxk){
                maxf = true;
                maxstart = i;
            }

            if(minf and maxf){
                res = res + min(minstart,maxstart) - start + 1;
            }
        }

        return res;
    }
};