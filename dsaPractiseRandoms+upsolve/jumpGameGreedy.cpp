#include <bits/stdc++.h>
using namespace std;

// brute on2
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int i = n - 1;
        if (n == 1)
            return true;
        while (i >= 0)
        {
            if (nums[i] != 0)
            {
                i--;
                continue;
            }
            int j = i - 1;
            int req = (i == n - 1) ? 1 : 2;
            while (j >= 0)
            {
                if (nums[j] >= req)
                    break;
                j--;
                req++;
            }
            if (j < 0)
                return false;
            i = j;
        }
        return true;
    }
};

// optimal on
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int goal = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (i + nums[i] >= goal)
            {
                goal = i;
            }
        }
        return goal == 0;
    }
};