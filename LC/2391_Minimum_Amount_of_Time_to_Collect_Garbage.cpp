//* Difficulty -> Medium

//? You are given a 0-indexed array of strings garbage where garbage[i] represents the assortment of garbage at the ith house. garbage[i] consists only of the characters 'M', 'P' and 'G' representing one unit of metal, paper and glass garbage respectively.
//? Picking up one unit of any type of garbage takes 1 minute.
//? You are also given a 0-indexed integer array travel where travel[i] is the number of minutes needed to go from house i to house i + 1.
//? There are three garbage trucks in the city, each responsible for picking up one type of garbage. Each garbage truck starts at house 0 and must visit each house in order; however, they do not need to visit every house.
//? Only one garbage truck may be used at any given moment. While one truck is driving or picking up garbage, the other two trucks cannot do anything.
//? Return the minimum number of minutes needed to pick up all the garbage.

//! Question Tag -> Array, String, Prefix Sum

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        int total = 0;
        int lastg = 0, lastp = 0, lastm = 0;
        int stops = 0;

        for (int i = 0; i < garbage.size(); i++)
        {
            stops = stops + garbage[i].size();
            for (auto ch : garbage[i])
            {
                if (ch == 'G')
                    lastg = i;
                if (ch == 'P')
                    lastp = i;
                if (ch == 'M')
                    lastm = i;
            }
        }

        for (int i = 1; i <= max(lastg, max(lastp, lastm)); i++)
        {
            if (i <= lastg)
                total = total + travel[i - 1];
            if (i <= lastm)
                total = total + travel[i - 1];
            if (i <= lastp)
                total = total + travel[i - 1];
        }

        return total + stops;
    }
};