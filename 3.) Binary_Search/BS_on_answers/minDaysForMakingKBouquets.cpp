#include <bits/stdc++.h>
using namespace std;

// // brute force. tle
class Solution
{
public:
    bool possible(vector<int> &bloomDay, int m, int k, int day)
    {
        int cnt = 0, nob = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= day)
            {
                cnt++;
            }
            else
            {
                nob += cnt / k;
                cnt = 0;
            }
        }
        nob += cnt / k;
        if (nob >= m)
            return true;
        return false;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        for (int i = mini; i <= maxi; i++)
        {

            if (possible(bloomDay, m, k, i) == true)
            {
                return i;
            }
        }
        return -1;
    }
};

// binary search on answers

class Solution
{
public:
    bool possible(vector<int> &bloomDay, int m, int k, int day)
    {
        int cnt = 0, nob = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= day)
            {
                cnt++;
            }
            else
            {
                nob += cnt / k;
                cnt = 0;
            }
        }
        nob += cnt / k;
        if (nob >= m)
            return true;
        return false;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {

        if ((long long)m * k > bloomDay.size())
            return -1;
        int low = 1;
        int high = 1e9;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (possible(bloomDay, m, k, mid) == true)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

