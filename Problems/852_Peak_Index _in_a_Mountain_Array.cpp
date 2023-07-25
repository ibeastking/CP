//* Difficulty -> Medium

//? An array arr a mountain if the following properties hold:
//? arr.length >= 3
//? There exists some i with 0 < i < arr.length - 1 such that:
//? arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//? arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
//? Given a mountain array arr,
//? return the index i such that
//? arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].
//? You must solve it in O(log(arr.length)) time complexity.

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int left = 0;
        int right = arr.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (mid == 0 or mid == arr.size() - 1)
            {
                if (mid == 0)
                {
                    if (arr[mid] < arr[mid + 1])
                    {
                        return mid + 1;
                    }
                }
                else
                {
                    if (arr[mid] > arr[mid - 1])
                    {
                        return mid - 1;
                    }
                }
            }
            else
            {
                if (arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1])
                {
                    return mid;
                }
                else if (arr[mid] < arr[mid - 1])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }

        return -1;
    }
};