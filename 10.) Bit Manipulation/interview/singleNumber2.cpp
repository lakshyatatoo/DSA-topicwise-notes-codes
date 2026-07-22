#include <bits/stdc++.h>
using namespace std;

// brute
int singleNumber(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
    return -1;
}

// better
int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i <= 31; i++)
    {
        int cnt = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if ((nums[j] & (1 << i)) != 0)
            {
                cnt++;
            }
        }
        if (cnt % 3 != 0)
        {
            ans |= (1 << i);
        }
    }
    return ans;
}

// optimal
int singleNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 1; i < n; i += 3)
    {
        if (nums[i] != nums[i - 1])
        {
            return nums[i - 1];
        }
    }
    return nums[n - 1];
}

// optimal too