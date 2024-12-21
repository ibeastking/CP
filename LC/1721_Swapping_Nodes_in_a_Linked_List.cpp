//* Difficutly -> Medium

//? You are given the head of a linked list, and an integer k.
//? Return the head of the linked list after swapping the values of the kth node from the beginning
//? and the kth node from the end
//? (the list is 1-indexed).

//! Question Tag -> Linked List, Two Pointer

#include <bits\stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *temp;

        while (k > 1)
        {
            fast = fast->next;
            k--;
        }

        temp = fast;

        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        swap(temp->val, slow->val);

        return head;
    }
};