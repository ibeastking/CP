//! Very Important Question

//* Difficulty -> Medium

//? Given a 2D grid consists of 0s (land) and 1s (water).
//? An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally
//? (all left, top, right, bottom) surrounded by 1s.
//? Return the number of closed islands.

//! Question Tag -> Array, Depth-First Search, Breadth-First Search, Union Find, Matrix

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 or i >= n or j < 0 or j >= m or grid[i][j] == 1)
        {
            return;
        }

        grid[i][j] = 1;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++)
        {
            int nx = i + dx[k];
            int ny = j + dy[k];
            dfs(nx, ny, grid);
        }
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        int res = 0;

        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i * j == 0 or i == n - 1 or j == m - 1) and (grid[i][j] == 0))
                {
                    dfs(i, j, grid);
                }
            }
        }

        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                if (grid[i][j] == 0)
                {
                    dfs(i, j, grid);
                    res++;
                }
            }
        }

        return res;
    }
};