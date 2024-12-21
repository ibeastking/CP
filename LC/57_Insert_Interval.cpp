//* Difficulty -> Medium

//? You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi]
//? represent the start and the end of the ith interval and intervals is sorted in ascending order by start.
//? You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
//? Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still
//? does not have any overlapping intervals (merge overlapping intervals if necessary).
//? Return intervals after the insertion.

//! Question Tag -> Array

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> res;
        int i = 0;

        //* first find the end times which are smaller than new interval's start time
        //* insert those values into result vector
        while (i < intervals.size() and intervals[i][1] < newInterval[0])
        {
            res.push_back(intervals[i]);
            i++;
        }

        //* find out what the new interval will be
        //* start time of new interval will be value greater than end time of previous intervals
        //* end time of new interval will be value smaller than start time of next intervals
        while (i < intervals.size() and intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }

        //* insert the new interval into vector res
        res.push_back(newInterval);

        //* iterate through remaining intervals and insert them into the vector res
        while (i < intervals.size())
        {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};