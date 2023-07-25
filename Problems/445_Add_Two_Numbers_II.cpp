//* Difficulty -> Medium

//? You are given two non-empty linked lists representing two non-negative integers.
//? The most significant digit comes first and each of their nodes contains a single digit.
//? Add the two numbers and return the sum as a linked list.
//? You may assume the two numbers do not contain any leading zero, except the number 0 itself.

//! Question Tag -> Linked List, Math, Stack

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode();
        stack<int> st1;
        stack<int> st2;
        int carry = 0;

        while (l1 != NULL)
        {
            st1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != NULL)
        {
            st2.push(l2->val);
            l2 = l2->next;
        }

        while (!st1.empty() and !st2.empty())
        {
            int num1 = st1.top();
            st1.pop();
            int num2 = st2.top();
            st2.pop();
            int sum = num1 + num2 + carry;
            if (sum > 9)
            {
                sum = sum - 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            ListNode *node = new ListNode(sum);
            if (head->next == NULL)
            {
                head->next = node;
            }
            else
            {
                node->next = head->next;
                head->next = node;
            }
        }

        while (!st1.empty())
        {
            int num1 = st1.top();
            st1.pop();
            int sum = num1 + carry;

            if (sum > 9)
            {
                carry = 1;
                sum = sum - 10;
            }
            else
            {
                carry = 0;
            }

            ListNode *node = new ListNode(sum);
            if (head->next == NULL)
            {
                head->next = node;
            }
            else
            {
                node->next = head->next;
                head->next = node;
            }
        }

        while (!st2.empty())
        {
            int num1 = st2.top();
            st2.pop();
            int sum = num1 + carry;

            if (sum > 9)
            {
                carry = 1;
                sum = sum - 10;
            }
            else
            {
                carry = 0;
            }

            ListNode *node = new ListNode(sum);
            if (head->next == NULL)
            {
                head->next = node;
            }
            else
            {
                node->next = head->next;
                head->next = node;
            }
        }

        if (carry == 1)
        {
            ListNode *node = new ListNode(carry);
            if (head->next == NULL)
            {
                head->next = node;
            }
            else
            {
                node->next = head->next;
                head->next = node;
            }
        }

        return head->next;
    }
};