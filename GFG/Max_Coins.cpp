//* Difficulty -> Medium

//? Your are given an 2D integer array  ranges whose length is n where  ranges[i]=[starti,endi,coinsi]
//? means all integers from starti to endi inclusive starti and endi are present
//? and  we get coinsi amount of coins when we select this ith range .
//? You can select atmost two intervals so as to collect maximum coins
//? but if u select two ranges than those two ranges should not intersect or overlapp than can touch each other.

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static bool compare(const vector<int> &v1, const vector<int> &v2)
    {
        return v1[2] > v2[2];
    }

    int maxCoins(int n, vector<vector<int>> &ranges)
    {
        // Code here
        sort(ranges.begin(), ranges.end(), compare);

        int res = ranges[0][2];

        for (int i = 0; i < n; i++)
        {
            int start = ranges[i][0];
            int end = ranges[i][1];
            int currval = ranges[i][2];
            int j = i + 1;

            int candidate = 0;

            while (j < n)
            {
                if (ranges[j][2] + currval < res)
                {
                    break; //* we break it because the arrays is in decreasing order
                }

                //* the start of new interval should be equal to or greater than end of current interval
                //* or
                //* the end of new interval should be equal to or smaller than start of current interval
                if (ranges[j][0] >= end or ranges[j][1] <= start)
                {
                    candidate = max(candidate, ranges[j][2]);
                }

                j++;
            }

            res = max(res, currval + candidate);
        }

        return res;
    }
};