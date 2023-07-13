//? Difficulty -> Easy

//? You are given an array of N+2 integer elements. 
//? All elements of the array are in the range 1 to N.
//? Also, all elements occur once except two numbers which occur twice. Find the two repeating numbers.
//? Note: Return the numbers in their order of appearing twice. So, if X and Y are the repeating numbers,
//? and X repeats twice before Y repeating twice, then the order should be (X, Y).

#include<bits\stdc++.h>
using namespace std;

class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int N) {
        // Your code here
        vector<int> res;
        
        for(int i=0;i<N+2;i++){
            if(arr[abs(arr[i])] >= 0){
                arr[abs(arr[i])] = -arr[abs(arr[i])];
            }else{
                res.push_back(abs(arr[i]));
            }
        }
        
        return res;
    }
};