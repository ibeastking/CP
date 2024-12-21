//* Difficulty -> Medium

//? Given an undirected tree consisting of n vertices numbered from 0 to n-1,
//? which has some apples in their vertices. You spend 1 second to walk over one edge of the tree.
//? Return the minimum time in seconds you have to spend to collect all apples in the tree,
//? starting at vertex 0 and coming back to this vertex.
//? The edges of the undirected tree are given in the array edges,
//? where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi.
//? Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple;
//? otherwise, it does not have any apple.

//! Question Tag -> Hash Table, Tree, Depth-First Search, Breadth-First Search
//! Youtube Link -> https://www.youtube.com/watch?v=xYzbvOJJTbM and also official solution of Leetcode

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(int node, int parent, vector<vector<int>> &vt, vector<bool> &hasApple)
    {
        int totalTime = 0, childTime = 0;
        for (auto child : vt[node])
        {
            if (child == parent)
                continue;
            childTime = dfs(child, node, vt, hasApple);
            // childTime > 0 indicates subtree of child has apples. Since the root node of the
            // subtree does not contribute to the time, even if it has an apple, we have to check it
            // independently.
            if (childTime or hasApple[child])
                totalTime += childTime + 2;
        }

        return totalTime;
    }

    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<vector<int>> vt(n); //* adjacency list

        //* creation of adjacency list
        for (auto &edge : edges)
        {
            vt[edge[0]].push_back(edge[1]);
            vt[edge[1]].push_back(edge[0]);
        }
        return dfs(0, -1, vt, hasApple);
    }
};
