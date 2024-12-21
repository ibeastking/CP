//! Difficulty -> Hard

//? You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
//? Merge all the linked-lists into one sorted linked-list and return it.

//! Question Tags -> Linked List, Divide and Conquer, Priority Queue, Merge Sort

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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return NULL;
        int len = lists.size();
        while (len > 1)
        {
            for (int i = 0; i < len / 2; ++i)
            {
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }

        return lists.front();
    }

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

class Solution1
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        map<int, int> m;

        for (auto &i : lists)
        {
            while (i)
            {
                m[i->val]++;
                i = i->next;
            }
        }

        ListNode dummy(0);
        ListNode *tail = &dummy;
        if (!m.size())
            return NULL;

        for (auto &itr : m)
        {
            for (int i = 0; i < itr.second; i++)
            {
                tail->next = new ListNode(itr.first);
                tail = tail->next;
            }
        }

        return dummy.next;
    }
};