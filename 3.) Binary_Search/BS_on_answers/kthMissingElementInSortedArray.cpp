#include <bits/stdc++.h>
using namespace std;

// brute linear search
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= k)
                k++;
            else
                break;
        }
        return k;
    }
};

// binary search
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low + k;//or arr[high ] + more but hgih might end up on -1
    }
};