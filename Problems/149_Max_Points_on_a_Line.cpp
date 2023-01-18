//! Difficulty -> Hard

//? Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane,
//? return the maximum number of points that lie on the same straight line.

//! Question Tags -> Array, Hash Table, Geometry, Math

//! No link, i solved this motherfucker on my own

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();

        if (n == 1)
            return 1;

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_map<double, int> mp;
            for (int j = i + 1; j < n; j++)
            {
                double x1 = points[i][0];
                double y1 = points[i][1];
                double x2 = points[j][0];
                double y2 = points[j][1];
                double slope;
                double dx = x2 - x1;
                if (dx == 0)
                    slope = INT_MAX;
                else
                    slope = ((y2 - y1) / dx);
                mp[slope]++;
                res = max(res, mp[slope] + 1);
            }
        }

        return res;
    }
};