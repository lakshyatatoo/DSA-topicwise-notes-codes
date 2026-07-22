#include <bits/stdc++.h>
using namespace std;

// brute tle
class Solution
{

public:
    int req(vector<int> &weights, int cap)
    {
        int day = 1;
        int load = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            if (load + weights[i] > cap)
            {
                day++;
                load = weights[i];
            }
            else
            {
                load += weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();
        int maxele = *max_element(weights.begin(), weights.end());
        int sum = accumulate(weights.begin(), weights.end(), 0);
        for (int i = maxele; i <= sum; i++)
        {
            if (req(weights, i) <= days)
                return i;
        }
        return -1;
    }
};

// binary search
class Solution
{

public:
    int req(vector<int> &weights, int cap)
    {
        int day = 1;
        int load = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            if (load + weights[i] > cap)
            {
                day++;
                load = weights[i];
            }
            else
            {
                load += weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (req(weights, mid) <= days)
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