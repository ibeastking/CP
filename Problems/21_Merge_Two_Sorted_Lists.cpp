//? Difficulty -> Easy

//? You are given the heads of two sorted linked lists list1 and list2.
//? Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
//? Return the head of the merged linked list.

//! Question Tags -> Linked List, Recursion

#include <bits\stdc++.h>
using namespace std;

//* Definition for singly-linked list.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        //* Check if ant of the lists are null
        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }

        //* Head of the result list
        ListNode *head;

        //* Pointer for the resultant list
        ListNode *temp;

        //* Choose head which is smaller of the two lists
        if (l1->val < l2->val)
        {
            temp = head = new ListNode(l1->val);
            l1 = l1->next;
        }
        else
        {
            temp = head = new ListNode(l2->val);
            l2 = l2->next;
        }

        //* Loop until any of the list becomes null
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                temp->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else
            {
                temp->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            temp = temp->next;
        }

        //* Add all the nodes in l1, if remaining
        while (l1 != NULL)
        {
            temp->next = new ListNode(l1->val);
            l1 = l1->next;
            temp = temp->next;
        }

        //* Add all the nodes in l2, if remaining
        while (l2 != NULL)
        {
            temp->next = new ListNode(l2->val);
            l2 = l2->next;
            temp = temp->next;
        }

        return head;
    }
};