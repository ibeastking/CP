//? Difficulty -> Easy

//? Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
//? determine if the input string is valid.
//? An input string is valid if:
//? Open brackets must be closed by the same type of brackets.
//? Open brackets must be closed in the correct order.
//? Every close bracket has a corresponding open bracket of the same type.

//! Question Tag -> String, Stack

#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    //* O(n) space and time complexity
    bool isValid1(string s)
    {
        bool flag = true;
        stack<char> st;

        for (int i = 0; s[i] != '\0'; i++)
        {
            if ((s[i] == '(') or (s[i] == '{') or (s[i] == '['))
                st.push(s[i]);
            else
            {
                if (st.empty() or (st.top() == '(' and s[i] != ')') or (st.top() == '{' and s[i] != '}') or (st.top() == '[' and s[i] != ']'))
                    return false;
                st.pop();
            }
        }

        return st.empty();
    }

    //* O(n) time complexity and O(1) time complexity
    bool isValid2(string s)
    {
        int top = -1;

        for (int i = 0; i < s.length(); i++)
        {
            if ((s[i] == '(') or (s[i] == '{') or (s[i] == '['))
            {
                top++;
                s[top] = s[i];
            }
            else
            {
                if (top >= 0 and ((s[top] == '(' and s[i] == ')') or (s[top] == '{' and s[i] == '}') or (s[top] == '[' and s[i] == ']')))
                {
                    top--;
                }
                else
                {
                    return false;
                }
            }
        }

        return top == -1;
    }
};