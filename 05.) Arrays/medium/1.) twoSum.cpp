#include <bits/stdc++.h>
using namespace std;

// ============================================================
// 1. BRUTE FORCE
// Time: O(n^2)
// Space: O(1)
// Returns indexes
// ============================================================

class Solution
{
public:
    vector<int> twoSum(vector<int> &a, int target)
    {
        int n = a.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] + a[j] == target)
                {
                    return {i, j};
                }
            }
        }

        return {};
    }
};

// ============================================================
// 2. BETTER — HASHING
// Time: O(n log n) using map
// Space: O(n)
// Returns indexes
// ============================================================

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            int rem = target - nums[i];

            if (mp.find(rem) != mp.end())
            {
                return {i, mp[rem]};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};

// ============================================================
// 3. OPTIMAL — TWO POINTERS
// Time: O(n log n) because of sorting
// Space: O(1) extra
// Returns only YES/NO
// ============================================================

class Solution
{
public:
    bool twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int l = 0;
        int r = n - 1;

        while (l < r)
        {
            int sum = nums[l] + nums[r];

            if (sum == target)
            {
                return true;
            }
            else if (sum < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }

        return false;
    }
};