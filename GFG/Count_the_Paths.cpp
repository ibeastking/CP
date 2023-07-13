//? Difficulty -> Easy

//? Given a directed acyclic graph(DAG) with n nodes labeled from 0 to n-1. 
//? Given edges, s and d ,count the number of ways to reach from s to d.
//? There is a directed Edge from vertex edges[i][0] to the vertex edges[i][1].

#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    int path;
    vector<int> adj[15];
    
    void dfs(int node, int dest){
        if(node == dest){
            path++;
            return;
        }else{
            for(auto itr:adj[node]){
                dfs(itr,dest);
            }
        }
    }
    
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    path = 0;
	    
	    for(int i=0;i<edges.size();i++){
	        adj[edges[i][0]].push_back(edges[i][1]);
	    }
	    
	    dfs(s,d);
	    
	    return path;
	}
};