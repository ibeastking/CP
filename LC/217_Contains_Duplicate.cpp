//? Difficulty -> Easy

//? Given an integer array nums, return true if any value appears at least twice in the array, 
//? and return false if every element is distinct.

//! Question Tag -> Array, Hash table, Sorting

#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//! space -> O(n), time O(n)
class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>st;

        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }

        return (st.size()==nums.size()) ? (false) : (true);
    }
};

//! space -> O(1), time -> n.log(n)
class Solution2{
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]) return true;
        }

        return false;
    }        
};