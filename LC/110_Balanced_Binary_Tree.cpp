//? Difficulty -> Easy

//? Given a binary tree, determine if it is height-balanced.


//! Question Tag -> Tree, Depth-First Search, Binary Tree

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

class Solution{
public:
    int height(TreeNode* node){
        if(node == nullptr){
            return 0;
        }

        int leftH = height(node->left);
        if(leftH == -1) return -1;

        int rightH = height(node->right);
        if(rightH == -1) return -1;

        if(abs(leftH - rightH) > 1){
            return -1;
        }

        return max(leftH,rightH) + 1;
    }

    bool isBalanced(TreeNode* root){
        return height(root) != -1;
    }
};