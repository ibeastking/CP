//? Difficulty -> Easy

//? Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

#include<bits\stdc++.h>
using namespace std;

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        // Your code here
        unordered_map<int,int>mp;
        int sum = 0;
        int res = 0;
        
        for(int right=0;right<n;right++){
            sum = sum + arr[right];
            
            if(sum == 0){
                res = right+1;
            }
            
            if(mp.find(sum) != mp.end()){
                res = max(res, right - mp[sum]);
            }else{
                mp[sum] = right;
            }
        }
        
        return res;
    }
};