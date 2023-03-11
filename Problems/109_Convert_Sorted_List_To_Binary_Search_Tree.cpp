//* Difficulty -> Medium

//? Given the head of a singly linked list where elements are sorted in ascending order,
//? convert it to a height-balanced binary search tree.

//! Question Tag -> Linked List, Divide and Conquer, Tree, Binary Search Tree, Binary Tree

#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    TreeNode *sortedArrayToBST(ListNode *head)
    {
        vector<int> vt;

        while (head)
        {
            vt.push_back(head->val);
            head = head->next;
        }

        return fun(vt, 0, vt.size() - 1);
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
