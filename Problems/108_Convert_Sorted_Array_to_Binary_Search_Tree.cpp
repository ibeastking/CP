//? Difficulty -> Easy

//? Given an integer array nums where the elements are sorted in ascending order,
//? convert it to a height-balanced binary search tree.

//! Question Tag -> Array, Divide and Conquer, Tree, Binary Search Tree, Binary Tree

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(0), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return fun(nums, 0, nums.size() - 1);
    }

    TreeNode *fun(vector<int> &vt, int le, int ri)
    {
        if (le > ri)
        {
            return nullptr;
        }

        int mid = le + (ri - le) / 2;

        TreeNode *node = new TreeNode(vt[mid]);
        node->left = fun(vt, le, mid - 1);
        node->right = fun(vt, mid + 1, ri);

        return node;
    }
};
