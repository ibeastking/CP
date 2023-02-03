//* Difficulty -> Medium

//? The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
//? (you may want to display this pattern in a fixed font for better legibility)

/*P   A   H   N
A P L S I I G
Y   I   R*/

//? And then read line by line: "PAHNAPLSIIGYIR"

//! Question Tag -> String

#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int n) {
        
        if(s.length()==1 || n==1){
            return s;
        }
        
        int ptr = 0;
        bool flag= true;
        string arr[n];
        
        for(int i=0;i<n;i++){
            arr[i] = "";
        }
        
        for(int i=0;i<s.length();i++){
            
            arr[ptr] =  arr[ptr] + s[i];
            
            if(ptr == 0){
                flag =  true;
            }
            
            if(ptr == n-1){
                flag = false;
            }
            
            if(flag == true){
                ptr++;
            }else{
                ptr--;
            }
        }
        
        string temp = "";
        
        for(int i=0;i<n;i++){
            temp = temp + arr[i];
        }
        
        return temp;
    }
};