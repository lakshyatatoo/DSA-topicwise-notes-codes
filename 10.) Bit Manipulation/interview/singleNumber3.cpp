#include <bits/stdc++.h>
using namespace std;

// brute hash map
vector<int> singleNumber3(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }
    vector<int> ans;
    for (auto it : mp)
    {
        if (it.second == 1)
        {
            ans.push_back(it.first);
        }
    }
    return ans;
}

// optimal bucket
vector<int> singleNumber(vector<int> &nums)
{
    int n = nums.size();
    long long xorAll = 0;
    for (int i = 0; i < n; i++)
    {
        xorAll ^= nums[i];
    }
    int rightMost = (xorAll & xorAll - 1) ^ xorAll;
    int b1 = 0, b2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] & rightMost)
        {
            b1 ^= nums[i];
        }
        else
        {
            b2 ^= nums[i];
        }
    }
    return {b1, b2};
}