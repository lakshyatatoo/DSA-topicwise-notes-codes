#include <bits/stdc++.h>
using namespace std;

// ============================================================
// 1. BRUTE FORCE
// Generate every subarray and calculate its sum separately.
//
// Time: O(n^3)
// Space: O(1)
// ============================================================

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int cnt = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int sum = 0;

                for (int k = i; k <= j; k++)
                {
                    sum += nums[k];
                }

                if (sum == k)
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

// ============================================================
// 2. BETTER
// Remove the third loop by maintaining the sum while extending
// the subarray.
//
// Time: O(n^2)
// Space: O(1)
// ============================================================

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int cnt = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int sum = 0;

            for (int j = i; j < n; j++)
            {
                sum += nums[j];

                if (sum == k)
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

// ============================================================
// 3. OPTIMAL — PREFIX SUM + HASHING
//
// If:
//     current_sum - previous_sum = k
//
// Then:
//     previous_sum = current_sum - k
//
// Store how many times each prefix sum has occurred.
//
// Time: O(n log n) using map
// Space: O(n)
//
// Using unordered_map gives O(n) average time.
// ============================================================

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int sum = 0;
        int cnt = 0;

        map<int, int> mp;

        // Empty prefix
        mp[0]++;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            int rem = sum - k;

            cnt += mp[rem];

            mp[sum]++;
        }

        return cnt;
    }
};