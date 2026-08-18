#include <bits/stdc++.h>
using namespace std;

// ============================================================
// 1. BRUTE FORCE
// Time: O(n^3) to o(n^2) using prefix sum
// Space: O(1)
// ============================================================

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        long long sum = 0;
        int n = nums.size();
        long long ms = LLONG_MIN;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                sum = 0;

                for (int k = i; k <= j; k++)
                {
                    sum += nums[k];
                }

                ms = max(ms, sum);
            }
        }

        return ms;
    }
};

// ============================================================
// 2. OPTIMAL — KADANE'S ALGORITHM
// Time: O(n)
// Space: O(1)
// ============================================================

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            maxi = max(maxi, sum);

            if (sum < 0)
            {
                sum = 0;
            }
        }

        return maxi;
    }
};

// ============================================================
// 3. KADANE'S ALGORITHM — FIND THE MAXIMUM SUBARRAY
// Returns the elements of the maximum-sum subarray
// Time: O(n)
// Space: O(1) extra
// ============================================================

class Solution
{
public:
    vector<int> findSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        int maxi = INT_MIN;

        int as = 0;
        int start = 0;
        int ae = 0;

        vector<int> inds;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            if (sum > maxi)
            {
                maxi = sum;
                as = start;
                ae = i;
            }

            if (sum < 0)
            {
                sum = 0;
                start = i + 1;
            }
        }

        for (int i = as; i <= ae; i++)
        {
            inds.push_back(nums[i]);
        }

        return inds;
    }
};
