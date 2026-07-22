#include <bits/stdc++.h>
using namespace std;

// brute tle
class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int n = nums.size();
        long long sum = 0;
        int maxVal = *max_element(nums.begin(), nums.end());
        for (int i = 1; i <= maxVal; i++)
        {
            sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += ceil((double)(nums[j]) / (double)(i));
            }
            if (sum <= threshold)
                return i;
        }
        return -1;
    }
};

// binary search on answers
class Solution
{
public:
    int sumD(vector<int> &nums, int divisor)
    {
        long long sum = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            // sum += ceil((double)(nums[j]) / (double)(divisor));
            sum += (nums[j] + divisor - 1) / divisor;
        }
        return sum;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (sumD(nums, mid) <= threshold)
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