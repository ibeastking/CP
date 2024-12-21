//* Difficulty -> Medium

//? Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images.

//! Question Tag -> Array, Sorting, Heap(Priority Queue)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution1
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        vector<int> res;
        vector<pair<int, pair<int, int>>> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums[i].size(); j++)
            {
                mp.push_back({i + j, {i, nums[i][j]}});
            }
        }

        sort(mp.begin(), mp.end(), [](const auto &a, const auto &b)
             {
            if(a.first == b.first){
                return a.second.first>b.second.first;
            }else{
                return a.first<b.first;
            } });

        for (auto itr : mp)
        {
            res.push_back(itr.second.second);
        }

        return res;
    }
};

class Solution2
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        class Solution
        {
        public:
            vector<int> findDiagonalOrder(vector<vector<int>> &nums)
            {
                vector<int> res;

                queue<pair<int, int>> que;
                que.push({0, 0});

                while (!que.empty())
                {
                    int size = que.size();
                    while (size > 0)
                    {
                        auto [i, j] = que.front();
                        que.pop();

                        res.push_back(nums[i][j]);

                        if (j == 0 and i + 1 < nums.size())
                        {
                            que.push({i + 1, j});
                        }

                        if (j + 1 < nums[i].size())
                        {
                            que.push({i, j + 1});
                        }

                        size--;
                    }
                }

                return res;
            }
        };
    }
};