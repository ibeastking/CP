//* Difficulty -> Medium

//? An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
//? You are also given three integers sr, sc, and color. 
//? You should perform a flood fill on the image starting from the pixel image[sr][sc].
//? To perform a flood fill, consider the starting pixel, 
//? plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, 
//? plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. 
//? Replace the color of all of the aforementioned pixels with color.
//? Return the modified image after performing the flood fill.

//! Question Tag -> Array, Depth-First Search, Breadth-First Search, Matrix

#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    void fun(int i, int j, vector<vector<int>>& image, int clr,int color){
        if(i<0 or j<0 or i>=image.size() or j>=image[0].size() or image[i][j] != clr){
            return;
        }

        image[i][j] = color;

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,1,-1};

        for(int k=0;k<4;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            fun(nx,ny,image,clr,color);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color){
            return image;
        }

        fun(sr,sc,image,image[sr][sc],color);
        return image;
    }
};