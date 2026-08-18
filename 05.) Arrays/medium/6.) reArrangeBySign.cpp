#include <bits/stdc++.h>
using namespace std;

// ============================================================
// 1. BRUTE — USING POSITIVE AND NEGATIVE ARRAYS
// Equal number of positive and negative elements
//
// Time: O(n)
// Space: O(n)
// ============================================================

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> pos, neg;

        // Separate positive and negative elements
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
                neg.push_back(nums[i]);
            }
            else
            {
                pos.push_back(nums[i]);
            }
        }

        // Place positive and negative alternately
        for (int i = 0; i < n / 2; i++)
        {
            nums[2 * i] = pos[i];
            nums[(2 * i) + 1] = neg[i];
        }

        return nums;
    }
};

// ============================================================
// 2. OPTIMAL — TWO POINTERS / POSITION POINTERS
// Equal number of positive and negative elements
//
// Time: O(n)
// Space: O(n)
// ============================================================

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> ans(n, 0);

        int pos = 0;
        int neg = 1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
                ans[neg] = nums[i];
                neg += 2;
            }
            else
            {
                ans[pos] = nums[i];
                pos += 2;
            }
        }

        return ans;
    }
};

// ============================================================
// 3. BRUTE — UNEQUAL NUMBER OF POSITIVE AND NEGATIVE ELEMENTS
//
// First arrange elements alternately until one type runs out.
// Then append the remaining elements.
//
// Time: O(n)
// Space: O(n)
// ============================================================

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> pos, neg;

        // Separate positive and negative elements
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
                neg.push_back(nums[i]);
            }
            else
            {
                pos.push_back(nums[i]);
            }
        }

        int x = pos.size();
        int y = neg.size();

        int minCount = min(x, y);

        // Arrange alternately while both are available
        for (int i = 0; i < minCount; i++)
        {
            nums[2 * i] = pos[i];
            nums[(2 * i) + 1] = neg[i];
        }

        int indexx = minCount * 2;

        // Add remaining positive elements
        for (int i = minCount; i < x; i++)
        {
            nums[indexx] = pos[i];
            indexx++;
        }

        // Add remaining negative elements
        for (int i = minCount; i < y; i++)
        {
            nums[indexx] = neg[i];
            indexx++;
        }

        return nums;
    }
};