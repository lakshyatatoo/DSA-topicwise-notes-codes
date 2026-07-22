#include <bits/stdc++.h>
using namespace std;

// tle
class Solution
{
public:
    double func(int index, vector<int> &nums, int k)
    {
        if (index == nums.size())
            return 0;
        if (k == 1)
        {
            double sum = 0;
            for (int i = index; i < nums.size(); i++)
            {
                sum += nums[i];
            }
            return sum / (nums.size() - index);
        }
        double sum = 0;
        double ans = 0;
        for (int i = index; i <= nums.size() - k; i++)
        {
            sum += nums[i];
            double avg = sum / (i - index + 1);
            ans = max(ans, avg + func(i + 1, nums, k - 1));
        }
        return ans;
    }
    double largestSumOfAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        return func(0, nums, k);
    }
};

optimal dp