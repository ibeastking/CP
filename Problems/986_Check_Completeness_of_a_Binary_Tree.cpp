//* Difficulty -> Medium

//? Given the root of a binary tree, determine if it is a complete binary tree.
//? In a complete binary tree, every level, except possibly the last, is completely filled,
//? and all nodes in the last level are as far left as possible.
//? It can have between 1 and 2h nodes inclusive at the last level h.

//! Question Tag -> Tree, Breadth-First Search, Binary Tree

#include <iostream>
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

//* use BFS traversal
class Solution
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        //* if root is null, it means that tree is complete
        if (root == nullptr)
        {
            return true;
        }

        queue<TreeNode *> que;
        bool flag = false;

        que.push(root);

        while (!que.empty())
        {
            TreeNode *curr = que.front();
            que.pop();

            //* if we come across a NULL value in tree then we will make the flag value true
            //* once we make flag value true, then all the values which come after this node should be NULL
            if (curr)
            {
                //* if there is a node after a NULL node, then it means that it is not a complete tree
                if (flag)
                {
                    return false;
                }
                que.push(curr->left);
                que.push(curr->right);
            }
            else
            {
                flag = true;
            }
        }

        return true;
    }
};