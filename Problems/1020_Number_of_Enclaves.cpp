//* Difficulty -> Medium

//? You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
//? A move consists of walking from one land cell to another adjacent (4-directionally) land cell or
//? walking off the boundary of the grid.
//? Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

//! Question Tag -> Array, Depth-First Search, Breadth-First Search, Union Find, Matrix

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void dfs(int i, int j, vector<vector<int>> &grid, int &count)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 or i >= n or j < 0 or j >= m or grid[i][j] == 0)
        {
            return;
        }

        grid[i][j] = 0;
        count++;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++)
        {
            int nx = i + dx[k];
            int ny = j + dy[k];
            dfs(nx, ny, grid, count);
        }
    }

    int numEnclaves(vector<vector<int>> &grid)
    {
        int count = 0;

        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i * j == 0 or i == n - 1 or j == m - 1) and (grid[i][j] == 0))
                {
                    dfs(i, j, grid, count);
                }
            }
        }

        count = 0;

        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                if (grid[i][j] == 0)
                {
                    dfs(i, j, grid, count);
                }
            }
        }

        return count;
    }
};