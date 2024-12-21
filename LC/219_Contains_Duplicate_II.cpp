//? Difficulty -> Easy

//? Given an integer array nums and an integer k, 
//? return true if there are two distinct indices i and j in the array 
//? such that nums[i] == nums[j] and abs(i - j) <= k.

//! Question Tag -> Array, Hash Table, Sliding window

#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

class Solution{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        //! map holds integer from nums as key
        //! and its position as value
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++) {
            if(mp.count(nums[i])) {
                if(abs(i - mp[nums[i]]) <= k) {
                    return true;
                }
            }

            mp[nums[i]] = i;
        }

        return false;
    }
};