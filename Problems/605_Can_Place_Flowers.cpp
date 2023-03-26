//? Difficulty -> Easy

//? You have a long flowerbed in which some of the plots are planted, and some are not.
//? However, flowers cannot be planted in adjacent plots.
//? Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n,
//? return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &nums, int n)
    {
        if (n == 0)
        {
            return true;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0 and (i == 0 or nums[i - 1] == 0) and (i == nums.size() - 1 or nums[i + 1] == 0))
            {
                n--;
                nums[i] = 1;
                if (n == 0)
                {
                    return true;
                }
            }
        }

        return false;
    }
};