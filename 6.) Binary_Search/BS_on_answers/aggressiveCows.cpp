#include <bits/stdc++.h>
using namespace std;

// // brute
class Solution
{
public:
    bool cwPlace(vector<int> &stalls, int dist, int k)
    {

        int n = stalls.size();
        int cowCnt = 1;
        int last = stalls[0];
        for (int i = 1; i < n; i++)
        {
            if (stalls[i] - last >= dist)
            {
                cowCnt++;
                last = stalls[i];
            }
            if (cowCnt >= k)
            {
                return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k)
    {
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        int minDist = 1; // minimum distance will be 1
        int maxDist = stalls[n - 1] - stalls[0];
        int ans = 0;
        for (int i = 1; i <= maxDist; i++)
        {
            if (cwPlace(stalls, i, k) == true) // or direct no true set
            {
                continue;
            }
            else
            {
                return i - 1;
            }
        }
        return maxDist; // if all distances are possible
    }
};

// binary search.  ans will end up on high
class Solution
{
public:
    bool cwPlace(vector<int> &stalls, int dist, int k)
    {

        int n = stalls.size();
        int cowCnt = 1;
        int last = stalls[0];
        for (int i = 1; i < n; i++)
        {
            if (stalls[i] - last >= dist)
            {
                cowCnt++;
                last = stalls[i];
            }
            if (cowCnt >= k)
            {
                return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k)
    {
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        int low = 1; // minimum distance will be 1
        int high = stalls[n - 1] - stalls[0];
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (cwPlace(stalls, mid, k) == true)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return high;
    }
};
