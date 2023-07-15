//? Difficulty -> Easy

//? Given two unsorted arrays A of size N and B of size M of distinct elements, 
//? the task is to find all pairs from both arrays whose sum is equal to X.
//? Note: All pairs should be printed in increasing order of u. 
//? For eg. for two pairs (u1,v1) and (u2,v2), if u1 < u2 then (u1,v1) should be printed first else second.

#include<bits\stdc++.h>
using namespace std;

class Solution{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int x)
    {
        // Your code goes here   
        vector<pair<int,int>> res;
        sort(A,A+N);
        sort(B,B+M);
        
        for(int i=0;i<N;i++){
            int left = 0;
            int right = M-1;
            
            while(left<=right){
                int mid = left + (right-left)/2;
                if(A[i] + B[mid] == x){
                    res.push_back({A[i],B[mid]});
                    break;
                }else if(A[i] + B[mid] > x){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
        }
        
        return res;
    }
};