#include <bits/stdc++.h>
using namespace std;
// brute 2 loops
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

// better (hashing) optimal for indexes
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        map<int, int> mp;
        int rem = 0;
        for (int i = 0; i < n; i++)
        {
            int a = nums[i];
            rem = target - a;
            if (mp.find(rem) != mp.end() && mp[rem] != i)
            {
                return {i, mp[rem]};
            }
            mp[a] = i;
        }
        return {};
    }
};

// optimal only for yes/no
class Solution
{
public:
    bool twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        sort(nums.begin(), nums.end());
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