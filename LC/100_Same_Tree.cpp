//? Difficulty -> Easy

//? Given the roots of two binary trees p and q, write a function to check if they are the same or not.
//? Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

//! Question Tag -> Tree, Depth-First Search, Breadth-First Search, Binary Tree

#include <bits\stdc++.h>
using namespace std;

//  * Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSameTree(TreeNode *proot, TreeNode *qroot)
    {
        if (proot == NULL and qroot == NULL)
            return true;
        if (proot == NULL or qroot == NULL)
            return false;
        if (proot->val != qroot->val)
            return false;

        return (isSameTree(proot->left, qroot->left) and isSameTree(proot->right, qroot->right));
    }
};