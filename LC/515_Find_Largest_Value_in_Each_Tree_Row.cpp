//* Difficulty -> Medium

//? Given the root of a binary tree,
//? return an array of the largest value in each row of the tree (0-indexed).

//! Tree, Depth-First Search, Breadth-First Search, Binary Tree

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
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
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> res;

        if (root == NULL)
        {
            return res;
        }

        queue<pair<TreeNode *, int>> que;
        que.push({root, 0});
        int curr_level = 0;
        int max_value = root->val;

        while (!que.empty())
        {
            TreeNode *node = que.front().first;
            int level = que.front().second;
            que.pop();

            if (level != curr_level)
            {
                curr_level = level;
                res.push_back(max_value);
                max_value = node->val;
            }
            else
            {
                max_value = max(max_value, node->val);
            }

            level++;
            if (node->left != NULL)
                que.push({node->left, level});
            if (node->right != NULL)
                que.push({node->right, level});
        }

        res.push_back(max_value);

        return res;
    }
};

class Solution2
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> res;

        if (root != NULL)
        {
            return res;
        }

        queue<TreeNode *> que;
        que.push(root);

        while (!que.empty())
        {
            int len = que.size();
            int max_value = INT_MIN;
            for (int i = 0; i < len; i++)
            {
                TreeNode *node = que.front();
                que.pop();

                max_value = max(max_value, node->val);
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
            }

            res.push_back(max_value);
        }
        return res;
    }
};