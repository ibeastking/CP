//* Difficulty -> Medium

//? Given an array of positive numbers, 
//? the task is to find the number of possible contiguous subarrays having product less than a given number k.

//! Question Tag -> Arrays, Mathematical, Data Structures, Algorithms

#include<bits\stdc++.h>
using namespace std;

class Solution{
  public:
    long long countSubArrayProductLessThanK(vector<int>& arr, int n, long long k) {
        
        long long res = 0;
        long long product = 1;
        
        int left = 0;
        
        for(int right = 0;right<n;right++){
            product = product * arr[right];
            
            while(product>=k and left<n){
                product = product/arr[left];
                left++;
            }
            
            if(product<k){
                res = res + right - left + 1;
            }
        }
        
        return res;
    }
};