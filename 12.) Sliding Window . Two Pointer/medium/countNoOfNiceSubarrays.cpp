#include <bits/stdc++.h>
using namespace std;

// brtue -- generate all subarrays and check count of odd numbers and break if count>k

// better --  hashing

// optimal --  binary subaaray sum prblem treat od as 1 and even as 0 by %2 and find no of subarrays with sum=k
class Solution
{
public:
    int swsleg(vector<int> &nums, int k)
    {
        if (k < 0)
            return 0;
        long long sum = 0;
        int cnt = 0, l = 0, r = 0;
        int n = nums.size();
        while (r < n)
        {
            sum += nums[r] % 2;
            while (sum > k)
            {
                sum -= nums[l] % 2;
                l++;
            }
            cnt = cnt + (r - l + 1);
            r++;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return swsleg(nums, k) - swsleg(nums, k - 1);
    }
};
