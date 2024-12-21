//? Difficulty -> Easy

//? Given the root of a binary tree, return the postorder traversal of its nodes' values.

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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> vt;
        if (!root)
            return vt;

        stack<pair<TreeNode *, bool>> st;
        st.push({root, false});

        while (!st.empty())
        {
            TreeNode *current = st.top().first;
            bool visited = st.top().second;
            st.pop();

            if (visited)
            {
                vt.push_back(current->val);
            }
            else
            {
                st.push({current, true});
                if (current->right)
                    st.push({current->right, false});
                if (current->left)
                    st.push({current->left, false});
            }
        }

        return vt;
    }
};