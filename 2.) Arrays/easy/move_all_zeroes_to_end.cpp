#include <bits/stdc++.h>
using namespace std;
// brute
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                temp.push_back(nums[i]);
            }
        }
        for (int i = 0; i < temp.size(); i++)
        {
            nums[i] = temp[i];
        }
        for (int i = temp.size(); i < n; i++)
        {
            nums[i] = 0;
        }
    }
};

// optimal
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        bool haszero = false;
        for (int x : nums)
        {
            if (x == 0)
            {
                haszero = true;
                break;
            }
        }
        if (!haszero)
        {
            return;
        }
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                j = i;
                break;
            }

        } // j set equal to first zeros index
        for (int i = j + 1; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};