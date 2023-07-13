//* Difficulty -> Medium

//? Given a matrix with n rows and m columns. 
//? Your task is to find the kth element which is obtained while traversing the matrix spirally. 
//? You need to complete the method findK which takes four arguments the first argument is the matrix A and 
//? the next two arguments will be n and m denoting the size of the matrix A and then the forth argument is an integer k. 
//? The function will return the kth element obtained while traversing the matrix spirally.

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int left = 0;
 		int right = m-1;
 		int top = 0;
 		int bottom = n-1;
 		
 		while(top<=bottom and left<=right){
 		    for(int i=left;i<=right;i++){
 		        if(k==1){
 		            return a[top][i];
 		        }
 		        k--;
 		    }
 		    top++;
 		    
 		    for(int i=top;i<=bottom;i++){
 		        if(k==1){
 		            return a[i][right];
 		        }
 		        k--;
 		    }
 		    right--;
 		    
 		    
 		    if(top<=bottom){
 		        for(int i=right;i>=left;i--){
 		            if(k==1){
 		                return a[bottom][i];
 		            }
 		            k--;
 		        }   
 		        bottom--;
 		    }
 		    
 		    
 		    if(left<=right){
 		        for(int i=bottom;i>=top;i--){
 		            if(k==1){
 		                return a[i][left];
 		            }
 		            k--;
 		        }
 		        left++;
 		    }
 		}
 		
 		return 0;
    }
};