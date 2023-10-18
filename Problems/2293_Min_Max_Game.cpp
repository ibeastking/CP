//? Difficulty -> Easy

//? You are given a 0-indexed integer array nums whose length is a power of 2.
//? Apply the following algorithm on nums:
//? Let n be the length of nums. If n == 1, end the process. 
//? Otherwise, create a new 0-indexed integer array newNums of length n / 2.
//? For every even index i where 0 <= i < n / 2, assign the value of newNums[i] as min(nums[2 * i], nums[2 * i + 1]).
//? For every odd index i where 0 <= i < n / 2, assign the value of newNums[i] as max(nums[2 * i], nums[2 * i + 1]).
//? Replace the array nums with newNums.
//? Repeat the entire process starting from step 1.
//? Return the last number that remains in nums after applying the algorithm.

//! Question Tag -> Array, Simulation

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int minMaxGame(vector<int>& nums){
        // while(nums.size()>1){
        //     for(int i=0;i<nums.size()/2;i++){
        //         if(i%2 == 0){
        //             nums[i] = min(nums[2*i],nums[2*i+1]);
        //         }else{
        //             nums[i] = max(nums[2*i],nums[2*i+1]);
        //         }
        //     }
        //     for(int i=nums.size()/2;i<nums.size();i++){
        //         nums.pop_back();
        //     }
        // }

        // return nums[0];
        for (int n = nums.size(); n > 1; n -= n/ 2) { // O(logN)
            for (int i = 0; i < n / 2; i++) { // O(N)
                nums[i] = (i % 2 == 0) ?
                    min(nums[2 * i], nums[2 * i + 1]) :
                    max(nums[2 * i], nums[2 * i + 1]); 
            }
        }
        return nums[0];
    }
};