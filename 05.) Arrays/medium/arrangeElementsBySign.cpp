#include <bits/stdc++.h>
using namespace std;
// brute (using pos neg arrayts)
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pos, neg;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
                neg.push_back(nums[i]);
            }
            else
            {
                pos.push_back(nums[i]);
            }
        }
        for (int i = 0; i < n / 2; i++)
        {
            nums[2 * i] = pos[i];
            nums[(2 * i) + 1] = neg[i];
        }
        return nums;
    }
};

// optimal approach 2pointter
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        int pos = 0;
        int neg = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
                ans[neg] = nums[i];
                neg += 2;
            }
            else
            {
                ans[pos] = nums[i];
                pos += 2;
            }
        }
        return ans;
    }
};

// for unequal count of positives and negatives
// brute
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pos, neg;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
                neg.push_back(nums[i]);
            }
            else
            {
                pos.push_back(nums[i]);
            }
        }
        int x = pos.size();
        int y = neg.size();
        int minCount = min(x, y);

        for (int i = 0; i < minCount; i++)
        {
            nums[2 * i] = pos[i];
            nums[(2 * i) + 1] = neg[i];
        }

        int indexx = minCount * 2;

        for (int i = minCount; i < x; i++)
        {
            nums[indexx] = pos[i];
            indexx++;
        }
        // adding rem pos and negs

        for (int i = minCount; i < y; i++)
        {
            nums[indexx] = neg[i];
            indexx++;
        }

        return nums;
    }
};