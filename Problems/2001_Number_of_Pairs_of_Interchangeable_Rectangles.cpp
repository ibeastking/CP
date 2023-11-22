//* Difficulty -> Medium

//? You are given n rectangles represented by a 0-indexed 2D integer array rectangles, 
//? where rectangles[i] = [widthi, heighti] denotes the width and height of the ith rectangle.
//? Two rectangles i and j (i < j) are considered interchangeable if they have the same width-to-height ratio.
//? More formally, two rectangles are interchangeable if widthi/heighti == widthj/heightj (using decimal division, not integer division).
//? Return the number of pairs of interchangeable rectangles in rectangles.

//! Question Tag -> Array, Hash Table, Math, Counting, Number Theory

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long count = 0;
        vector<double> ratio;

        for(auto itr: rectangles){
            double temp = (double)itr[0]/(double)itr[1];
            ratio.push_back(temp);
        }

        unordered_map<double,long long> mp;
        
        for(auto itr: ratio){
            count = count + mp[itr];
            mp[itr]++;
        }

        return count;
    }
};