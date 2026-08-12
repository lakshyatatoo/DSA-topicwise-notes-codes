#include <bits/stdc++.h>
using namespace std;

// ============================================================
// Brute Force
// ============================================================
// Idea:
// Store all non-zero elements in a temporary vector.
// Copy them back to nums.
// Fill the remaining positions with zero.
//
// TC: O(n)
// SC: O(n)

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> temp;

        // Store non-zero elements
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                temp.push_back(nums[i]);
            }
        }

        // Put non-zero elements back
        for (int i = 0; i < temp.size(); i++)
        {
            nums[i] = temp[i];
        }

        // Fill remaining positions with zero
        for (int i = temp.size(); i < n; i++)
        {
            nums[i] = 0;
        }
    }
};

// ============================================================
// Optimal
// ============================================================
// Idea:
// Find the first zero.
// i points to the position where the next non-zero element
// should be placed.
//
// When we find a non-zero element at j, swap it with nums[i]
// and move i forward.
//
// TC: O(n)
// SC: O(1)
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int i = 0, n = nums.size();
        while (i < n && nums[i] != 0)
        {
            i++;
        }
        int j = i;
        while (j < n)
        {
            while (j < n && nums[j] == 0)
                j++;
            if (j < n)
                swap(nums[i++], nums[j]);
        }
    }
};