//? Difficulty -> Easy

//? Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
//? Note: One can move from node u to node v only if there's an edge from u to v. 
//? Find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the input graph. 
//? Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.

#include<bits\stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]){
        vector<int> res;
        queue<int> q;
        int visited[V] = {0};

        q.push(0);
        visited[0] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            res.push_back(node);

            for(auto itr:adj[node]){
                if(!visited[itr]){
                    visited[itr] = 1;
                    q.push(itr);
                }
            }
        }

        return res;
    }
};