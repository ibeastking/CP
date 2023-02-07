//! Difficulty -> Hard

//? You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window.
//? Each time the sliding window moves right by one position.
//? Return the max sliding window.

//! Question Tag -> Array, Queue, Sliding Window, Heap (Priority Queue), Monotonic Queue

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++)
        {

            //! check if deque is not empty and number of elements in deque should not exceed k size
            //! if number of elements exceed, remove the out of bound element
            if (!(dq.empty()) and dq.front() == i - k)
            {
                dq.pop_front();
            }

            //! keep on poping current deque elements until you get a number bigger than current element
            while (!(dq.empty()) and nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }

            //! push the current element index in deque
            dq.push_back(i);

            //! do not push into res vector until a single window in formed
            if (i >= k - 1)
            {
                res.push_back(nums[dq.front()]);
            }
        }

        return res;
    }
};