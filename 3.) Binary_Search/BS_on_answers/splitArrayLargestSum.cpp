#include <bits/stdc++.h>
using namespace std;

// brute force approach same as allocate books

// binary search + allocate possible
class Solution
{
public:
    int allocPossible(vector<int> &arr, int pages, int n)
    {

        int student = 1;
        int pagesStudent = 0;
        for (int i = 0; i < n; i++)
        {
            if (pagesStudent + arr[i] <= pages)
            {
                pagesStudent += arr[i];
            }
            else
            {
                student++;
                pagesStudent = arr[i];
            }
        }
        return student;
    }
    int findPages(vector<int> &arr, int k)
    {
        // code here

        int n = arr.size();
        if (k > n) // if students are more than books
            return -1;
        long long low = *max_element(arr.begin(), arr.end()); // max element
        long long high =
            accumulate(arr.begin(), arr.end(), 0LL); // sum of all elements
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            int cnt = allocPossible(arr, mid, n);
            if (cnt > k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
    int splitArray(vector<int> &nums, int k)
    {
        int result = findPages(nums, k);
        return result;
    }
};