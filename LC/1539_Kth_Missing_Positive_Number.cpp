//? Difficulty -> Easy

//? Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
//? Return the kth positive integer that is missing from this array.

//! Question Tag -> Array, Binary Search

#include<iostream>
#include<vector>

class Solution{
public:
    int findKthPositive(std::vector<int>& arr, int k){
        int idx = 0; //* to store index of arr vector
        int val = 1; //* to store which is current value
        int res = 1;

        while(k>0){
            if(idx<arr.size()){
                if(arr[idx] == val){
                    idx++;
                }else{
                    res = val;
                    k--;
                }
            }else{
                res = val;
                k--;
            }
            val++;
        }

        return res;
    }
};