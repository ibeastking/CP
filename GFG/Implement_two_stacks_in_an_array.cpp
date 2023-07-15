//? Difficulty -> Easy

//? Your task is to implement  2 stacks in one array efficiently. You need to implement 4 methods.
//? push1 : pushes element into first stack.
//? push2 : pushes element into second stack.
//? pop1 : pops element from first stack and returns the popped element. If first stack is empty, it should return -1.
//? pop2 : pops element from second stack and returns the popped element. If second stack is empty, it should return -1.

#include<bits\stdc++.h>
using namespace std;

class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
    public:
    
    twoStacks(int n=100)
    {
        size = n; 
        arr = new int[n]; 
        top1 = -1; 
        top2 = size;
    }
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        top1++;
        arr[top1] = x;
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
       top2--;
       arr[top2] = x;
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(top1 == -1){
            return -1;
        }
        return arr[top1--];
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
        if(top2 == size){
            return -1;
        }
       return arr[top2++];
    }
};