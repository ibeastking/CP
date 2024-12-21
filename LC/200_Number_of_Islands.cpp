//* Difficulty -> Medium

//? Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
//? An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
//? You may assume all four edges of the grid are all surrounded by water.

//! Question Tag -> Array, Depth-First Search, Breadth-First Search, Union Find, Matrix

#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    void fun(int i, int j, vector<vector<int>>& graph){
        if(i<0 or j<0 or i>=graph.size() or j>=graph[0].size() or graph[i][j] == 0){
            return;
        }

        graph[i][j] = 0;

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,-1,1};

        for(int k=0;k<4;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            fun(nx,ny,graph);
            
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> graph(grid.size(),{vector<int>(grid[0].size(),0)});
        int res = 0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == '1'){
                    graph[i][j] = 1;
                }
            }
        }

        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                if(graph[i][j] == 1){
                    res++;
                    fun(i,j,graph);
                }
            }
        }

        return res;
    }
};