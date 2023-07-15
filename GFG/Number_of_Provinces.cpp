//? Difficulty -> Easy

//? Given an undirected graph with V vertices. 
//? We say two vertices u and v belong to a single province if there is a path from u to v or v to u. 
//? Your task is to find the number of provinces.
//? Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

#include<bits\stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int node, vector<int>graph[], int visited[]){
        visited[node] = 1;
        
        for(auto itr:graph[node]){
            if(!visited[itr]){
                dfs(itr,graph,visited);
            }
        }
        
        return;
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>graph[V];
        int visited[V] = {0};
        int res = 0;
        queue<int>q;
        
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j] == 1 and i!=j){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                } 
            }
        }
        
        //! if you want to DFS traverse
        //? for(int i=0;i<V;i++){
        //?     if(!visited[i]){
        //?         res++;
        //?         dfs(i,graph,visited);
        //?     }
        //? }
        

        for(int i=0;i<V;i++){
            if(!visited[i]){
                res++;
                q.push(i);
                
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    
                    visited[node] = 1;
                    
                    for(auto itr:graph[node]){
                        if(!visited[itr]){
                            q.push(itr);
                        }
                    }
                }
            }
        }
        
        return res;
    }
};