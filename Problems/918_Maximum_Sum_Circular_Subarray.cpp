//* Difficulty -> Medium

//? Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
//? A circular array means the end of the array connects to the beginning of the array.
//? Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
//? A subarray may only include each element of the fixed buffer nums at most once.
//? Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

//! Question Tags -> Array, Divide and Conquer, Dynamic Programming, Queue, Montonic Queue

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int curmax = nums[0], curmin = nums[0];
        int maxsum = nums[0], minsum = nums[0];
        int totsum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {

            curmax = max(nums[i], curmax + nums[i]);
            maxsum = max(maxsum, curmax);

            curmin = min(nums[i], curmin + nums[i]);
            minsum = min(minsum, curmin);

            totsum = totsum + nums[i];
        }

        return (maxsum > 0) ? (max(maxsum, totsum - minsum)) : (maxsum);
    }
};