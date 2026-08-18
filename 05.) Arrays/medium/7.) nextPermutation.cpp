#include <bits/stdc++.h>
using namespace std;

// ============================================================
// 1. BRUTE FORCE
// Generate all permutations and find the next one.
// Very high time complexity, so we avoid this approach.
//
// Time: O(n!)
// Space: O(n)
// ============================================================

// ============================================================
// 2. BETTER — STL next_permutation()
// Uses the built-in C++ function.
//
// Time: O(n)
// Space: O(1)
// ============================================================

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        next_permutation(nums.begin(), nums.end());
    }
};

// ============================================================
// 3. OPTIMAL — NEXT PERMUTATION ALGORITHM
//
// Steps:
// 1. Find the first dip from the right.
// 2. Find the smallest element greater than nums[ins] from right.
// 3. Swap them.
// 4. Reverse the part after ins.
//
// Time: O(n)
// Space: O(1)
// ============================================================

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int ins = -1;
        int n = nums.size();

        // 1. Find the first dip from the right
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                ins = i;
                break;
            }
        }

        // No dip -> already the largest permutation
        if (ins == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // 2. Find the first element greater than nums[ins]
        // from the right
        for (int i = n - 1; i > ins; i--)
        {
            if (nums[i] > nums[ins])
            {
                // 3. Swap
                swap(nums[i], nums[ins]);
                break;
            }
        }

        // 4. Reverse the suffix
        reverse(nums.begin() + ins + 1, nums.end());
    }
};