#include <bits/stdc++.h>
using namespace std;

// brute - genrating all and keeping a check with map -- tle
class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_map<int, int> mp;
            for (int j = i; j < n; j++)
            {
                mp[nums[j]]++;
                if (mp.size() == k)
                    cnt++;
                else if (mp.size() > k)
                    break;
            }
        }
        return cnt;
    }
};

// optimal -- using sliding window and two pointer approach but similar to 2 pointer approach
class Solution
{
public:
    int swdk(vector<int> &nums, int k)
    {
        int n = nums.size();
        int cnt = 0, l = 0, r = 0;
        unordered_map<int, int> mp;
        while (r < n)
        {
            mp[nums[r]]++;
            while (mp.size() > k)
            {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return swdk(nums, k) - swdk(nums, k - 1);
    }
};
