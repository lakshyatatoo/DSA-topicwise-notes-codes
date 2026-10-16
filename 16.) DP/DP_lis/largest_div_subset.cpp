#include <bits/stdc++.h>
using namespace std;

// onyl code to print lis of divisbility
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size(), maxi = -1, lastind = -1;
        vector<int> dp(n, 1), hsh(n);
        for (int i = 0; i < n; i++)
        {
            hsh[i] = i;
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i])
                    dp[i] = 1 + dp[prev], hsh[i] = prev;
            }
            if (dp[i] > maxi)
                maxi = dp[i], lastind = i;
        }
        vector<int> lis(maxi);
        int j = maxi - 1;
        while (hsh[lastind] != lastind)
            lis[j--] = nums[lastind], lastind = hsh[lastind];
        lis[j] = nums[lastind];
        return lis;
    }
};
