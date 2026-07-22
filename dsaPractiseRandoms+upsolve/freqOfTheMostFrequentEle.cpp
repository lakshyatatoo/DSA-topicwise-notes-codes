#include <bits/stdc++.h>
using namespace std;

// brute
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++)
        {
            long long cost = 0;
            int freq = 1;

            for (int j = i - 1; j >= 0; j--)
            {
                cost += nums[i] - nums[j];

                if (cost <= k)
                {
                    freq++;
                }
                else
                {
                    break;
                }
            }

            ans = max(ans, freq);
        }

        return ans;
    }
};

// optimal
class Solution
{
public:
    // optimal
    int maxFrequency(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = 0;
        int ans = 1;
        long long sum = 0;
        while (r < n)
        {
            sum += nums[r];
            if (1LL * nums[r] * (r - l + 1) - sum > k)
                sum -= nums[l++];
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};