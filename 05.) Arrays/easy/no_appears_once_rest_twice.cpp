#include <bits/stdc++.h>
using namespace std;

// ============================================================
// Brute Force — Nested Loops
// ============================================================
// Idea:
// For every element, count how many times it appears.
// If its frequency is 1, that is the answer.
//
// TC: O(n^2)
// SC: O(1)

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int target = nums[i];
            int cnt = 0;

            for (int j = 0; j < n; j++)
            {
                if (nums[j] == target)
                {
                    cnt++;
                }
            }

            if (cnt == 1)
            {
                return target;
            }
        }

        return -1;
    }
};

// ============================================================
// Better — Hash Array
// ============================================================
// Idea:
// Use the number itself as an index and store its frequency.
//
// Works well when numbers are non-negative and the range
// is not too large.
//
// TC: O(n + maxi)
// SC: O(maxi)
//
// Note: This approach does NOT work directly for negative
// numbers because negative numbers cannot be used as vector
// indices.
// ============================================================

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int maxi = 0;

        // Find maximum value
        for (int x : nums)
        {
            maxi = max(x, maxi);
        }

        vector<int> hash(maxi + 1, 0);

        // Store frequencies
        for (int x : nums)
        {
            hash[x]++;
        }

        // Find element appearing once
        for (int i = 0; i < hash.size(); i++)
        {
            if (hash[i] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};

// ============================================================
// Better — Unordered Map
// ============================================================
// Idea:
// Store:
//     number -> frequency
//
// Unlike a hash array, the number does NOT have to be used
// directly as an array index.
//
// Therefore it can handle:
//     positive numbers
//     negative numbers
//     large values
//
// Example:
// nums = [-2, 3, 3, -2, 5]
//
// freq:
// -2 -> 2
//  3 -> 2
//  5 -> 1
//
// Answer = 5
//
// Average TC: O(n)
// Average SC: O(n)
// ============================================================

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> freq;

        // Store frequencies
        for (int x : nums)
        {
            freq[x]++;
        }

        // Find element appearing once
        for (auto &p : freq)
        {
            if (p.second == 1)
            {
                return p.first;
            }
        }

        return -1;
    }
};

// ============================================================
// Optimal — XOR
// ============================================================
// Idea:
//
// XOR properties:
//
// x ^ x = 0
// x ^ 0 = x
//
// Since every number except one appears twice,
// the duplicate numbers cancel each other.
//
// Example:
//
// 2 ^ 3 ^ 2 ^ 4 ^ 3
//
// = (2 ^ 2) ^ (3 ^ 3) ^ 4
//
// = 0 ^ 0 ^ 4
//
// = 4
//
// TC: O(n)
// SC: O(1)
// ============================================================

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int xory = 0;

        for (int x : nums)
        {
            xory = xory ^ x;
        }

        return xory;
    }
};