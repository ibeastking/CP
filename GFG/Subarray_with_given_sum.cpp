//? Difficulty -> Easy

//? Given an unsorted array A of size N that contains only positive integers, 
//? find a continuous sub-array that adds to a given number S and return the left and right index(1-based indexing) of that subarray.
//? In case of multiple subarrays, return the subarray indexes which come first on moving from left to right.
//? Note:- You have to return an ArrayList consisting of two elements left and right. 
//? In case no such subarray exists return an array consisting of element -1.

//! Question Tag -> Algorithms, Arrays, Data Structures, prefix-sum, Searching, sliding-window

#include<bits\stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long target)
    {
        // Your code here
        vector<int> res;
        
        if(target == 0){
            res.push_back(-1);
            return res;
        }
        
        int left = 0;
        int sum = 0;
        
        for(int right=0;right<n;right++){
            sum = sum + arr[right];
            
            while(sum>target and left<n){
                sum = sum - arr[left];
                left++;
            }
            
            if(sum == target){
                res.push_back(left+1);
                res.push_back(right+1);
                return res;
            }
        }
        
        res.push_back(-1);
        return res;
    }
};