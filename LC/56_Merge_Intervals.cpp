//* Difficulty -> Medium

//? Given an array of intervals where intervals[i] = [starti, endi],
//? merge all overlapping intervals,
//? and return an array of the non-overlapping intervals that cover all the intervals in the input.

//! Question Tag -> Array, Sorting

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](auto a, auto b)
             {
            if(a[0] == b[0]){
                return a[1]<b[1];
            }else{
                return a[0]<b[0];
            } });

        for (auto itr : intervals)
            cout << itr[0] << " " << itr[1] << endl;

        vector<vector<int>> res;

        int left = intervals[0][0];
        int right = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {
            if (right >= intervals[i][0])
            {
                if (right < intervals[i][1])
                {
                    right = intervals[i][1];
                }
            }
            else
            {
                res.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }

        res.push_back({left, right});

        return res;
    }
};