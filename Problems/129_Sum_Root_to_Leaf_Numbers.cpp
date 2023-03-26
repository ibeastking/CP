//* Difficulty -> Medium

//? You are given the root of a binary tree containing digits from 0 to 9 only.
//? Each root-to-leaf path in the tree represents a number.
//? For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
//? Return the total sum of all root-to-leaf numbers.
//? Test cases are generated so that the answer will fit in a 32-bit integer.
//? A leaf node is a node with no children.

//! Question Tag -> Tree, Depth-First Search, Binary Tree

#include <iostream>
using namespace std;

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
    void fun(TreeNode *node, long long &sum, long long num)
    {
        if (node == nullptr)
        {
            return;
        }

        num = num * 10 + node->val;
        fun(node->left, sum, num);
        fun(node->right, sum, num);

        if (node->left == nullptr and node->right == nullptr)
        {
            sum = sum + num;
        }
    }

    int sumNumbers(TreeNode *root)
    {
        long long sum = 0;
        fun(root, sum, 0);
        return sum;
    }
};