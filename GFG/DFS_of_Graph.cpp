//? Difficulty -> Easy

//? You are given a connected undirected graph. 
//? Perform a Depth First Traversal of the graph.
//? Note: Use a recursive approach to find the DFS traversal of the graph 
//? starting from the 0th vertex from left to right according to the graph.

#include<bits\stdc++.h>
using namespace std;

class Solution {
  private:
    void dfs(int node, vector<int> adj[], int visited[], vector<int>& res){
        visited[node] = 1;
        res.push_back(node);
        
        for(auto itr:adj[node]){
            if(!visited[itr]){
                dfs(itr,adj,visited,res);
            }
        }
        
        return;
    }
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> res;
        int visited[V] = {0};
        int node = 0;
        
        dfs(node,adj,visited,res);
        
        return res;
    }
};