#include <bits/stdc++.h>
using namespace std;

// brute - genrate all subarrays and check sum and break if sum>k

// better - hashing, we check whether a subarray with the required remaining sum exists. cnt stores the number of times the remainder sum - k has appeared so far.

// optimal - no of subarrays with sum<=goal - no of subarrays with sum<=goal-1
class Solution
{
public:
    int swsleg(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0;
        long long sum = 0;
        int cnt = 0, l = 0, r = 0;
        int n = nums.size();
        while (r < n)
        {
            sum += nums[r];
            while (sum > goal)
            {
                sum -= nums[l];
                l++;
            }
            cnt = cnt + (r - l + 1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return swsleg(nums, goal) - swsleg(nums, goal - 1);
    }
};