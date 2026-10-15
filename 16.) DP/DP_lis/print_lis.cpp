#include <bits/stdc++.h>
using namespace std;

// space optmised tabulation iykyk method
// the normal dp prev tell lis that end at each i index
// single array
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[i] > nums[prev])
                    dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// printing the lis
class Solution
{
public:
    vector<int> getLIS(vector<int> &arr)
    {
        int n = arr.size(), maxi = -1, lastind = -1;
        vector<int> dp(n, 1), hsh(n);
        for (int i = 0; i < n; i++)
        {
            hsh[i] = i;
            for (int prev = 0; prev < i; prev++)
            {
                if (arr[i] > arr[prev] && 1 + dp[prev] > dp[i])
                    dp[i] = 1 + dp[prev], hsh[i] = prev;
            }
            if (dp[i] > maxi)
                maxi = dp[i], lastind = i;
        }
        vector<int> lis(maxi);
        int j = maxi - 1;
        while (hsh[lastind] != lastind)
            lis[j--] = arr[lastind], lastind = hsh[lastind];
        lis[j] = arr[lastind];
        return lis;
    }
};