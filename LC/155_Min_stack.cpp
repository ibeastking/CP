//? Difficulty -> Medium

//? Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//? Implement the MinStack class:
//? MinStack() initializes the stack object.
//? void push(int val) pushes the element val onto the stack.
//? void pop() removes the element on the top of the stack.
//? int top() gets the top element of the stack.
//? int getMin() retrieves the minimum element in the stack.
//? You must implement a solution with O(1) time complexity for each function.

//! Question Tag -> Stack, Design

#include <bits\stdc++.h>
using namespace std;

class MinStack
{
public:
    stack<int> minq, q;
    MinStack()
    {
    }

    void push(int val)
    {
        q.push(val);
        if (minq.empty() || minq.top() > val)
        {
            minq.push(val);
        }
        else
        {
            minq.push(minq.top());
        }
    }

    void pop()
    {
        minq.pop();
        q.pop();
    }

    int top()
    {
        return q.top();
    }

    int getMin()
    {
        return minq.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */