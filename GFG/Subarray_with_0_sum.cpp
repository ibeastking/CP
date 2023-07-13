//? Difficulty -> Easy

//? Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

#include<bits\stdc++.h>
using namespace std;

class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        unordered_set<int>st;
        int sum = 0;
        
        for(int i=0;i<n;i++){
            sum = sum + arr[i];
            
            if(sum == 0) return true;
            if(st.find(sum) != st.end()) return true;
            
            st.insert(sum);
        }
        
        return false;
    }
};