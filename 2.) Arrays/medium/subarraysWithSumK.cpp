#include <bits/stdc++.h>
using namespace std;
// brute k loop tle
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int sum = 0;
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += nums[k];
                }
                if (sum == k)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

// better removing k loop
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int sum = 0;
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                if (sum == k)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

// optimal prefix sum using hashing storing count of when sum==k
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int sum = 0;
        int cnt = 0;
        int n = nums.size();
        map<int, int> mp;
        mp[0]++;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            int rem = sum - k;
            cnt += mp[rem];
            mp[sum]++;
        }
        return cnt;
    }
};