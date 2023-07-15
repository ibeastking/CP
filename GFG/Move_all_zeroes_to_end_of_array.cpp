//? Difficulty -> Easy

//? Given an array arr[] of N positive integers. 
//? Push all the zeros of the given array to the right end of the array 
//? while maintaining the order of non-zero elements.

#include<bits\stdc++.h>
using namespace std;

class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    int zeros = 0;
	    int idx = 0;
	    
	    for(int i=0;i<n;i++){
	        if(arr[i] == 0){
	            zeros++;
	        }
	    }
	    
	    for(int left=0;left<n;left++){
	        if(idx == n - zeros){
	            break;
	        }
            
	        if(arr[left] != 0){
	            arr[idx] = arr[left];
	        }else{
	            int right = left;
	            while(arr[right] == 0 and right<n){
	                right++;
	            }
	            arr[idx] = arr[right];
	            left = right;
	        }
	        idx++;
	    }
	    
	    for(int i=idx;i<n;i++){
	        arr[i] = 0;
	    }
	}
};