#include <bits/stdc++.h>
using namespace std;
// brute partially passes.
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        long long sum = 0;
        int n = nums.size();
        long long ms = LLONG_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += nums[k];
                }
                ms = max(ms, sum);
            }
        }
        return ms;
    }
};

// better (partialy passes)
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        long long sum = 0;
        int n = nums.size();
        long long ms = LLONG_MIN;
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                ms = max(ms, sum);
            }
        }
        return ms;
    }
};

// optimal (kadane's algo) o(n)
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (sum > maxi)
            {
                maxi = sum;
            }
            if (sum < 0)
            {
                sum = 0;
            }
        }

        return maxi;
    }
};

// index of that maxarray

class Solution
{
public:
    vector<int> findSubarray(vector<int> &nums)
    {
        // code here
        int n = nums.size();
        int sum = 0;
        int maxi = INT_MIN;
        int as = 0;
        int start = 0;
        int ae = 0;
        vector<int> inds;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (sum > maxi)
            {
                maxi = sum;
                as = start;
                ae = i;
            }
            if (sum < 0)
            {
                sum = 0;
                start = i + 1;
            }
        }
        for (int i = as; i <= ae; i++)
        {
            inds.push_back(nums[i]);
        }

        return inds;
    }
};

// for index to with only non negative and on gfg mindfkd
// User function template for C++
class Solution
{
public:
    vector<int> findSubarray(vector<int> &nums)
    {
        // code here
        int n = nums.size();
        int sum = 0;
        int maxi = INT_MIN;
        int as = 0;
        int start = 0;
        int ae = 0;
        vector<int> inds;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
                sum = 0;
                start = i + 1;
                continue;
            }
            else
            {
                sum += nums[i];
            }

            if (sum >= maxi)
            {
                maxi = sum;
                as = start;
                ae = i;
            }
        }
        if (maxi < 0)
        {
            return {-1};
        }
        for (int i = as; i <= ae; i++)
        {
            inds.push_back(nums[i]);
        }

        return inds;
    }
};