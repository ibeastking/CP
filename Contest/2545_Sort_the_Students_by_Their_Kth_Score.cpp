//* Difficulty -> Medium

//? There is a class with m students and n exams. You are given a 0-indexed m x n integer matrix score, where each row represents one student and score[i][j] denotes the score the ith student got in the jth exam. The matrix score contains distinct integers only.
//? You are also given an integer k. Sort the students (i.e., the rows of the matrix) by their scores in the kth (0-indexed) exam from the highest to the lowest.
//? Return the matrix after sorting it.

//! Leetcode Weekly Contest 329
//! Do not overthink the questions, sometimes just fuck the time complexity

#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>> &vt, int k)
    {
        bool flag = true;
        for (int i = 0; i < vt.size(); i++)
        {
            if (flag)
            {
                flag = false;
                for (int j = 0; j < vt.size() - 1; j++)
                {
                    if (vt[j][k] < vt[j + 1][k])
                    {
                        vt[j].swap(vt[j + 1]);
                        flag = true;
                    }
                }
            }
            else
            {
                break;
            }
        }
        return vt;
    }
};