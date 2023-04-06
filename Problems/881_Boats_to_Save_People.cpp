//* Difficulty -> Medium

//? You are given an array people where people[i] is the weight of the ith person,
//? and an infinite number of boats where each boat can carry a maximum weight of limit.
//? Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
//? Return the minimum number of boats to carry every given person.

//! Question Tag -> Array, Greedy, Two Pointer, Sorting

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());

        long long res = 0;
        long long slow = 0;
        long long fast = people.size() - 1;

        while (slow <= fast)
        {
            if (people[slow] + people[fast] <= limit)
            {
                slow++;
                fast--;
            }
            else
            {
                fast--;
            }

            res++;
        }

        return res;
    }
};