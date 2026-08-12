#include <bits/stdc++.h>
using namespace std;

// brute better optimal
class Solution
{
public:
    bool isSorted(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            { // or if a[i]>a[i-1];
                return false;
            }
        }
        return true;
    }
};

// sorted and if rotated
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int discrepancy = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1] && discrepancy < 1)
            {
                discrepancy++;
            }
            else if (nums[i] > nums[i + 1] && discrepancy == 1)
            {
                return false;
            }
        }
        if (nums[n - 1] > nums[0] && discrepancy == 1)
            return false;
        return true;
    }
};