//? Difficulty -> Easy

//? Given the root of a binary tree, return the preorder traversal of its nodes' values.

//! Question Tag -> Stack, Tree, Depth-First Search, Binary Tree

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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> vt;
        if (!root)
            return vt;

        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *current = st.top();
            st.pop();

            vt.push_back(current->val);

            if (current->right)
                st.push(current->right);
            if (current->left)
                st.push(current->left);
        }

        return vt;
    }
};