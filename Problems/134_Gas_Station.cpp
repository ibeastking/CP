//* Difficulty -> Medium

//? There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
//? You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to
//? its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.
//? Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction,
//? otherwise return -1. If there exists a solution, it is guaranteed to be unique

//! Question Tags -> Array, Greedy

//! youtube link -> https://www.youtube.com/watch?v=MWTHTDIBN0s

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int start = 0, fuel = 0;

        //* calculate the sum of both arrays and check if there is sufficient fuel for entire journey
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
            return -1;

        for (int i = 0; i < gas.size(); i++)
        {
            fuel = fuel + gas[i] - cost[i];
            if (fuel < 0)
            {
                start = i + 1; //* change the starting position because current starting position is not valid
                fuel = 0;      //* reset the fuel meter
            }
        }

        return start;
    }
};