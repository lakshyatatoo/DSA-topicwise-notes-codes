#include <bits/stdc++.h>
using namespace std;

// ============================================================
// 1. BRUTE FORCE — SORTING
// Time: O(n log n)
// Space: O(1) extra
// ============================================================

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
    }
};

// ============================================================
// 2. BETTER — COUNTING
// Time: O(n)
// Space: O(1)
// ============================================================

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;

        // Count 0s, 1s and 2s
        for (int num : nums)
        {
            if (num == 0)
                cnt0++;
            else if (num == 1)
                cnt1++;
            else
                cnt2++;
        }

        // Fill 0s
        for (int i = 0; i < cnt0; i++)
        {
            nums[i] = 0;
        }

        // Fill 1s
        for (int i = cnt0; i < cnt0 + cnt1; i++)
        {
            nums[i] = 1;
        }

        // Fill 2s
        for (int i = cnt0 + cnt1; i < nums.size(); i++)
        {
            nums[i] = 2;
        }
    }
};

// ============================================================
// 3. OPTIMAL — DUTCH NATIONAL FLAG ALGORITHM
// Time: O(n)
// Space: O(1)
// ============================================================

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);

                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);

                high--;
            }
        }
    }
};