#include <bits/stdc++.h>
using namespace std;

// ============================================================
// Brute Force — Generate All Subarrays
// ============================================================
// Idea:
// Use two loops to generate every subarray.
// Keep adding elements to sum instead of calculating the sum
// from scratch for every subarray.
//
// This improves the naive O(n^3) approach to O(n^2).
//
// Works for: +ve, -ve and 0
//
// TC: O(n^2)
// SC: O(1)

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        int n = arr.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            int sum = 0;

            for (int j = i; j < n; j++)
            {
                sum += arr[j];

                if (sum == k)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};

// ============================================================
// Better — Prefix Sum + Hashing
// ============================================================
// Works for: +ve, -ve and 0
//
// Idea:
// Keep a prefix sum.
//
// If:
//     currentSum - k
//
// has appeared before at index x, then the subarray from
// x + 1 to i has sum k.
//
// Store ONLY the first occurrence of each prefix sum.
// This gives the longest possible subarray.
//
// TC: O(n) average
// SC: O(n)

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        int n = arr.size();

        long long sum = 0;
        int maxLen = 0;

        unordered_map<long long, int> mp;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];

            // If the whole subarray from 0 to i has sum k
            if (sum == k)
            {
                maxLen = max(maxLen, i + 1);
            }

            // Check whether sum - k appeared before
            long long rem = sum - k;

            if (mp.find(rem) != mp.end())
            {
                maxLen = max(maxLen, i - mp[rem]);
            }

            // Store only the first occurrence
            // because the earliest index gives the longest length.
            if (mp.find(sum) == mp.end())
            {
                mp[sum] = i;
            }
        }

        return maxLen;
    }
};

// ============================================================
// Optimal — Sliding Window / Two Pointers
// ============================================================
// Works ONLY when all elements are non-negative
// (+ve and 0).
//
// Idea:
// l and r represent the current window.
//
// If sum > k:
//     Remove elements from the left.
//
// If sum == k:
//     Update maximum length.
//
// Since elements are non-negative, removing an element from
// the left can never increase the sum.
//
// TC: O(n)
// SC: O(1)

class Solution
{
public:
    int longestSubarray(vector<int> &a, int k)
    {
        int n = a.size();

        int l = 0;
        long long sum = 0;
        int maxLen = 0;

        for (int r = 0; r < n; r++)
        {
            sum += a[r];

            while (l <= r && sum > k)
            {
                sum -= a[l];
                l++;
            }

            if (sum == k)
            {
                maxLen = max(maxLen, r - l + 1);
            }
        }

        return maxLen;
    }
};