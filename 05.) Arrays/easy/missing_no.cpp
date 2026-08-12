#include <bits/stdc++.h>
using namespace std;

// ============================================================
// Brute Force — Nested Loop
// ============================================================
// Idea:
// For every number from 0 to n, check whether it exists in nums.
// If it doesn't exist, that is the missing number.
//
// TC: O(n^2)
// SC: O(1)

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 1; i <= n; i++)
        {
            bool found = false;

            for (int j = 0; j < n; j++)
            {
                if (nums[j] == i)
                {
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                return i;
            }
        }

        return -1;
    }
};

// ============================================================
// Better — Hashing
// ============================================================
// Idea:
// Create a hash array of size n + 1.
// Mark every number that appears in nums.
// The index whose value remains 0 is the missing number.
//
// TC: O(n)
// SC: O(n)

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> hash(n + 1, 0);

        // Mark existing numbers
        for (int i = 0; i < n; i++)
        {
            hash[nums[i]]++;
        }

        // Find missing number
        for (int i = 0; i <= n; i++)
        {
            if (hash[i] == 0)
            {
                return i;
            }
        }

        return -1;
    }
};

// ============================================================
// Optimal — Sum Formula
// ============================================================
// Idea:
// Expected sum of numbers from 0 to n:
//
// n * (n + 1) / 2
//
// Missing number = Expected sum - Actual sum
//
// TC: O(n)
// SC: O(1)
//
// Note: For very large n, the sum can overflow an int.
// ============================================================

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();

        long long expectedSum = 1LL * n * (n + 1) / 2;
        long long actualSum = 0;

        for (int i = 0; i < n; i++)
        {
            actualSum += nums[i];
        }

        return expectedSum - actualSum;
    }
};

// ============================================================
// Optimal — XOR (Single Loop)
// ============================================================
// Idea:
// Instead of using two separate loops, combine them.
//
// nums contains:
// 0, 1, 2, ..., n except one number.
//
// i + 1 generates:
// 1, 2, ..., n
//
// The 0 is handled automatically because:
// 0 ^ x = x
//
// TC: O(n)
// SC: O(1)

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();

        int xor1 = 0;
        int xor2 = 0;

        for (int i = 0; i < n; i++)
        {
            xor2 = xor2 ^ nums[i];
            xor1 = xor1 ^ (i + 1);
        }

        return xor1 ^ xor2;
    }
};
