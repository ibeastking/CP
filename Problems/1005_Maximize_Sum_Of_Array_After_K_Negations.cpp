//? Difficulty -> Easy

//? Given an integer array nums and an integer k, modify the array in the following way:
//? Choose an index i and replace nums[i] with -nums[i].
//? You should apply this process exactly k times.
//? You may choose the same index i multiple times.
//? Return the largest possible sum of the array after modifying it in this way.

//! Question Tag -> Array, Greedy, Sorting

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        int res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto itr : nums)
            pq.push(itr);

        while (k > 0)
        {
            int temp = -pq.top();
            pq.pop();
            pq.push(temp);
            k--;
        }

        while (!pq.empty())
        {
            res = res + pq.top();
            pq.pop();
        }

        return res;
    }
};