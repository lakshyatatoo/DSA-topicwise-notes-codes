#include <bits/stdc++.h>
using namespace std;
// brute(nested loop for checking)
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int flag = 1;
        for (int i = 0; i <= n; i++)
        {
            flag = 0;
            for (int j = 0; j < n; j++)
            {
                if (nums[j] == i)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                return i;
            }
        }
        return n;
    }
};

// better(hasing technique)
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> hsh(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            hsh[nums[i]]++;
        }
        for (int i = 0; i <= n; i++)
        {
            if (hsh[i] == 0)
            {
                return i;
            }
        }
        return -1;
    }
};

// optimal(using sum formula)
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int sumr = 0;
        int sumf = 0;
        sumr = (n * (n + 1)) / 2;
        for (int i = 0; i < n; i++)
        {
            sumf += nums[i];
        }
        int ans = sumr - sumf;
        return ans;
    }
};

// optimal(using xor)
// 1(2loops)
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int xor1 = 0;
        int xor2 = 0;
        for (int i = 0; i < n; i++)
        {
            xor2 = xor2 ^ nums[i];
        }
        for (int i = 1; i <= n; i++)
        {
            xor1 = xor1 ^ i;
        }
        int ans = xor1 ^ xor2;
        return ans;
    }
};

// 2(1loop)
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int xor1 = 0;
        int xor2 = 0;
        for (int i = 0; i < n; i++)
        {
            xor2 = xor2 ^ nums[i];
            xor1 = xor1 ^ (i + 1);
        }

        return xor1 ^ xor2;
    }
};
