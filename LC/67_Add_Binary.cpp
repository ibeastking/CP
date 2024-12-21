//? Difficulty -> Easy

//? Given two binary strings a and b, return their sum as a binary string.

//! Question Tag -> Math, String, Bit Manipulation, Simulation

#include<stdio.h>
#include<string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.length();
        int blen = b.length();
        int flag = 0;
        string res = "";
        string s;

        if(a.length()>b.length()){
            b = s.append(a.length()-b.length(),'0') + b;
        }else if(a.length()<b.length()){
            a = s.append(b.length()-a.length(),'0') + a;
        }

        for(int i=a.length()-1;i>-1;i--){
            int temp = (a[i] - '0') + (b[i] - '0') + flag;
            res = to_string(temp%2) + res;
            flag = temp/2;
        }

        return (flag) ? ("1" + res) : (res);
    }
};