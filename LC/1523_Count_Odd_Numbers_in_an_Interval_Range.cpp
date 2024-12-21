//? Difficulty -> Easy

//? Given two non-negative integers low and high. 
//? Return the count of odd numbers between low and high (inclusive).

//! Question Tag -> Math

#include<stdio.h>
using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        return (low%2 == 1 or high%2 == 1) ? (((high - low)/2) + 1) : (((high - low)/2));
    }
};