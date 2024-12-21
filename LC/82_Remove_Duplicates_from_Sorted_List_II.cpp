//* Difficulty -> Medium

//? Given the head of a sorted linked list,
//? delete all nodes that have duplicate numbers,
//? leaving only distinct numbers from the original list.
//? Return the linked list sorted as well.

//! Question Tag -> Linked List, Two Pointer

#include <iostream>
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;

        while (curr != nullptr)
        {
            ListNode *fast = curr->next;
            if (fast != nullptr and fast->val == curr->val)
            {
                while (fast != nullptr)
                {
                    if (fast->val == curr->val)
                    {
                        fast = fast->next;
                    }
                    else
                    {
                        break;
                    }
                }

                if (prev != nullptr)
                {
                    prev->next = fast;
                    curr = fast;
                }
                else
                {
                    head = fast;
                    curr = head;
                }
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};