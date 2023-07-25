//* Difficulty -> Medium

//? Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 
//? Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

#include<bits\stdc++.h>
using namespace std;

class Solution_BFS{
public:
    bool isCycle(int V, vector<int> adj[]){
        vector<int> visited(V,0);

        for(int i=0;i<V;i++){
            if(!visited[i]){
                visited[i] = 1;

                queue<pair<int,int>>q;
                q.push({i,-1});

                while(!q.empty()){
                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();

                    for(auto adjnode:adj[node]){
                        if(!visited[adjnode]){
                            visited[adjnode] = 1;
                            q.push({adjnode,node});
                        }else if(parent != adjnode){
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }
};

class Solution_DFS{
public:
    bool dfs(int node, int parent, vector<int> adj[], vector<int>& visited){
        visited[node] = 1;

        for(auto itr:adj[node]){
            if(!visited[itr]){
                if(dfs(itr,node,adj,visited)){
                    return true;
                }
            }else if(itr != parent){
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[]){
        vector<int> visited(V,0);

        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,-1,adj,visited)){
                    return true;
                }
            }
        }

        return false;
    }
};