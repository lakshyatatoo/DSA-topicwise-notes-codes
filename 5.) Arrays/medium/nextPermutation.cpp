#include <bits/stdc++.h>
using namespace std;
// brute
//  very high order time complexity so we avoid this approach

// better
//  next_permutation function in STL
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        next_permutation(nums.begin(), nums.end());
    }
};

// optimal
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int ins = -1;
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                ins = i;
                break;
            }
        }
        // if no dip found.
        if (ins == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = n - 1; i >= ins; i--)//can be jsut >
        {
            if (nums[i] > nums[ins])
            {
                swap(nums[i], nums[ins]);
                break;
            }
        }

        reverse(nums.begin() + ins + 1, nums.end());
    }
};
