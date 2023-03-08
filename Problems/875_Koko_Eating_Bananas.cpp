//* Difficulty -> Medium

//? Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
//? Koko can decide her bananas-per-hour eating speed of k. Each hour,
//? she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
//? Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
//? Return the minimum integer k such that she can eat all the bananas within h hours.

//! Question Tag -> Array, Binary Search

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int res = 0;

        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            long long count = 0;

            for (int i = 0; i < piles.size(); i++)
            {
                count = count + (piles[i] / mid) + (piles[i] % mid != 0);
            }

            if (count <= h)
            {
                res = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return res;
    }
};