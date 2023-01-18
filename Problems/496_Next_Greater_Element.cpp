//? Difficulty -> Easy

//? The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
//? You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
//? For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2.
//? If there is no next greater element, then the answer for this query is -1.
//? Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

//! Question Tag -> Array, Hash Table, Stack, Monotonic Stack

#include <bits\stdc++.h>
using namespace std;

//* no stack
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> vt;
        unordered_map<int, int> mp; //* unordered map to hold element and its next greater element
        for (int j = 0; j < nums2.size(); j++)
            mp[nums2[j]] = j;

        for (int i = 0; i < nums1.size(); i++)
        {
            //* store the index in j and start iterating from next element till end of vector
            for (int j = mp[nums1[i]]; j < nums2.size(); j++)
            {
                //* if you find the greater element break the for loop and push the value into the vector
                if (nums2[j] > nums1[i])
                {
                    vt.push_back(nums2[j]);
                    break;
                }

                //* if end of vector is reached it means that no greater element is found so push -1
                if (j == nums2.size() - 1)
                    vt.push_back(-1);
            }
        }
        return vt;
    }
};

//* using stack
class Solution2
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> vt;
        unordered_map<int, int> mp; //* to store value and its greater element
        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            int val = nums2[i];

            while (!st.empty() and st.top() <= val)
                st.pop();

            int greater = st.empty() ? (-1) : (st.top());
            mp.insert({val, greater});
            st.push(val);
        }

        for (auto itr : nums1)
            vt.push_back(mp[itr]);

        return vt;
    }
};