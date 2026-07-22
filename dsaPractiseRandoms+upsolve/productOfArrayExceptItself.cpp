#include <bits/stdc++.h>
using namespace std;

// brute force
// tc=O(n) sc=O(n) for front and back arrays
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> front(n, 1);
        vector<int> back(n, 1);
        int prod = 1;
        for (int i = 1; i < n; i++)
        {
            prod *= nums[i - 1];
            front[i] = prod;
        }
        prod = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            prod *= nums[i + 1];
            back[i] = prod;
        }
        for (int i = 0; i < n; i++)
        {
            nums[i] = front[i] * back[i];
        }
        return nums;
    }
};

// optimal
// tc = O(n) sc = O(1) no extra space used 
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = 1;
        for (int i = 1; i < n; i++)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        int rp = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            rp *= nums[i + 1];
            ans[i] *= rp;
        }
        return ans;
    }
};