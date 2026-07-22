#include <bits/stdc++.h>
using namespace std;

// brute - loop
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            int zeros = 0;
            for (int j = i; j < n; j++)
            {
                if (nums[j] == 0)
                    zeros++;

                if (zeros <= k)
                    maxLen = max(maxLen, j - i + 1);
                else
                {
                    break;
                }
            }
        }
        return maxLen;
    }
};

// better
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int l = 0, r = 0, zeros = 0, maxLen = 0;
        int n = nums.size();
        while (r < n)
        {
            if (nums[r] == 0)
                zeros++;
            while (zeros > k)
            {
                if (nums[l] == 0)
                    zeros--;
                l++;
            }
            if (zeros <= k)
            {
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
};

// optimal
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int l = 0, r = 0, zeros = 0, maxLen = 0;
        int n = nums.size();
        while (r < n)
        {
            if (nums[r] == 0)
                zeros++;
            if (zeros > k)
            { // extra check skipped to faster.
                if (nums[l] == 0)
                    zeros--;
                l++;
            }
            if (zeros <= k)
            {
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
};