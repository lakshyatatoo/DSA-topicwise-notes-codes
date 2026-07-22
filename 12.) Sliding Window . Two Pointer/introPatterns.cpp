#include <bits/stdc++.h>
using namespace std;

// 1.) constant window
//  ex k=3, find max sum of 3 consecutive elements in an array
int constantSlidingWindow(vector<int> &arr, int k)
{
    int n = arr.size();
    int maxSum = 0;
    for (int i = 0; i < k; i++)
    {
        maxSum += arr[i];
    }
    int sum = maxSum;
    int l = 0, r = k - 1;
    while (r < n - 1)
    {
        sum -= arr[l];
        l++;
        r++;
        sum += arr[r];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

// 2.) longest subarray/substring with <condition>
// ex: longest subarray with sum <=k
// brute - generate all subarrays and check condition
int bruteLongestSubarraySumK(vector<int> &arr, int k)
{
    int n = arr.size();
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum <= k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            else
            {
                break;
            }
        }
    }
    return maxLen;
}

// better - optimal for getting the subarray itself
int betterLongestSubaaraySumK(vector<int> &arr, int k)
{
    int n = arr.size();
    int l = 0, r = 0;
    int sum = 0;
    int maxLen = 0;
    while (l < r)
    {
        sum += arr[r];
        while (sum > k)
        {
            sum -= arr[l];
            l++;
        }
        if (sum <= k)
            maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
}

// optimal for getting the length only
int optimalLongestSubaaraySumK(vector<int> &arr, int k)
{
    int n = arr.size();
    int l = 0, r = 0;
    int sum = 0;
    int maxLen = 0;
    while (l < r)
    {
        sum += arr[r];
        if (sum > k)
        {
            sum -= arr[l];
            l++;
        }
        if (sum <= k)
            maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
}