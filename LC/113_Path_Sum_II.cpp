//* Difficulty -> Medium

//? Given the root of a binary tree and an integer targetSum,
//? return all root-to-leaf paths where the sum of the node values in the path equals targetSum.
//? Each path should be returned as a list of the node values, not node references.
//? A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

//! Question Tag -> BackTracking, Depth-First Search, Breadth-First Search, Binary Tree

#include <vector>
#include <algorithm>
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
    void dfs(TreeNode *node, vector<vector<int>> &res, vector<int> &temp, int sum, int &target)
    {
        if (node == nullptr)
        {
            return;
        }

        if (node->left == nullptr and node->right == nullptr)
        {

            if (sum + node->val == target)
            {
                temp.push_back(node->val);
                res.push_back(temp);
                temp.pop_back();
            }

            return;
        }

        temp.push_back(node->val);
        sum = sum + node->val;

        dfs(node->left, res, temp, sum, target);
        dfs(node->right, res, temp, sum, target);

        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(root, res, temp, 0, targetSum);
        return res;
    }
};