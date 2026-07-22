#include <bits/stdc++.h>
using namespace std;
// brute
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (nums[i] == nums[j])
                {
                    cnt++;
                }
            }
            if (cnt > n / 2)
            {
                return nums[i];
            }
        }
        return -1;
    }
};

// better (hashing)
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for (auto it : mp)
        {
            if (it.second > n / 2)
            {
                return it.first;
            }
        }
        return -1;
    }
};

// optimal (moore's voting algo)
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 0;
        int me = 0;

        for (int i = 0; i < n; i++)
        {
            if (cnt == 0)
            {
                me = nums[i];
                cnt = 1;
            }
            else if (nums[i] == me)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == me)
            {
                cnt++;
            }
        }
        if (cnt > n / 2)
        {
            return me;
        }
        return -1;
    }
};