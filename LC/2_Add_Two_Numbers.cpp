//? Difficulty -> Medium

//? You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order,
//? and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
//? You may assume the two numbers do not contain any leading zero, except the number 0 itself.

//! Question Tag -> Linked List, Math, Recursion

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode h(0);
        ListNode *head = &h;

        int sum = 0;

        while (l1 or l2 or sum)
        {
            if (l1)
            {
                sum = sum + l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum = sum + l2->val;
                l2 = l2->next;
            }

            head->next = new ListNode(sum % 10);
            sum = sum / 10;
            head = head->next;
        }

        return h.next;
    }
};