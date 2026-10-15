#include <bits/stdc++.h>
using namespace std;

// memoi
class Solution
{
public:
    int f(int i, int prev, vector<vector<int>> &dp, vector<int> &nums)
    {
        if (i == nums.size())
            return 0;
        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        int len = f(i + 1, prev, dp, nums);
        if (prev == -1 || nums[i] > nums[prev])
            len = max(len, 1 + f(i + 1, i, dp, nums));
        return dp[i][prev + 1] = len;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, dp, nums);
    }
};

// tabulation
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int prev = i - 1; prev >= -1; prev--)
            {
                int len = dp[i + 1][prev + 1];
                if (prev == -1 || nums[i] > nums[prev])
                    len = max(len, 1 + dp[i + 1][i + 1]);
                dp[i][prev + 1] = len;
            }
        }
        return dp[0][0]; // right shift of prev by 1
    }
};

// tabulation space optmisation
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            vector<int> temp(n + 1, 0);
            for (int prev = i - 1; prev >= -1; prev--)
            {
                int len = dp[prev + 1];
                if (prev == -1 || nums[i] > nums[prev])
                    len = max(len, 1 + dp[i + 1]);
                temp[prev + 1] = len;
            }
            dp = temp;
        }
        return dp[0]; // right shift of prev by 1
    }
};

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