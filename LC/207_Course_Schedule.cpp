//* Difficulty -> Medium

//? There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
//? You are given an array prerequisites 
//? where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
//? For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
//? Return true if you can finish all courses. Otherwise, return false.

#include<bits\stdc++.h>
using namespace std;

class Solution{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        
        //* declare all things you need
        vector<vector<int>> graph;
        vector<int> indegrees(numCourses,0);
        queue<int> q;

        //* first step is to create graph
        for(auto itr:prerequisites){
            int course = itr[0];
            int precourse = itr[1];
            graph[precourse].push_back(course);
            indegrees[course]++;
        }

        //* push all 0 indegree courses into queue
        for(auto itr:indegrees){
            if(itr == 0){
                q.push(itr);
            }
        }

        //* BFS traverse
        while(!q.empty()){
            int course = q.front();
            q.pop();

            for(auto next_course:graph[course]){
                indegrees[next_course]--;
                if(indegrees[next_course] == 0){
                    q.push(next_course);
                }
            }
        }

        //* check for indegrees
        for(auto itr:indegrees){
            if(itr != 0){
                return false;
            }
        }

        return true;
    }
};