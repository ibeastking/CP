//* Difficulty -> Medium

//? Given a linked list, swap every two adjacent nodes and return its head.
//? You must solve the problem without modifying the values in the list's nodes
//? (i.e., only nodes themselves may be changed.)

//! Question Tag -> Linked List, Recurrsion

#include <iostream>
#include <vector>
#include <algorithm>
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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr or head->next == nullptr)
        {
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = slow->next;

        while (fast != nullptr)
        {
            swap(slow->val, fast->val);

            if (fast->next != nullptr)
            {
                slow = fast->next;
                fast = slow->next;
            }
            else
            {
                break;
            }
        }

        return head;
    }
};