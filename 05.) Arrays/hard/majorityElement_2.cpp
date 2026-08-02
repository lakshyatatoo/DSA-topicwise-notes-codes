#include <bits/stdc++.h>
using namespace std;
// brute loops
// tc=O(n^2)
// sc=O(1)
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (ans.size() == 0 || ans[0] != nums[i])
            {
                int cnt = 0;
                for (int j = 0; j < n; j++)
                {
                    if (nums[j] == nums[i])
                    {
                        cnt++;
                    }
                }
                if (cnt > n / 3)
                {
                    ans.push_back(nums[i]);
                }
                if (ans.size() == 2)
                {
                    break;
                }
            }
        }
        return ans;
    }
};

// better
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> ans;

        int n = nums.size();
        unordered_map<int, int> hsh;
        int mini = (n / 3 + 1);
        for (int i = 0; i < n; i++)
        {
            hsh[nums[i]]++;
            if (hsh[nums[i]] == mini)
            {
                ans.push_back(nums[i]);
            }
            if (ans.size() == 2)
            {
                break;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// optimal
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        int cand1 = 0, cand2 = 0, cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (cnt1 == 0 && nums[i] != cand2)
            {
                cnt1 = 1;
                cand1 = nums[i];
            }
            else if (cnt2 == 0 && nums[i] != cand1)
            {
                cnt2 = 1;
                cand2 = nums[i];
            }
            else if (cand1 == nums[i])
            {
                cnt1++;
            }
            else if (cand2 == nums[i])
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        int cntf1 = 0;
        int cntf2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == cand1)
            {
                cntf1++;
            }
            else if (nums[i] == cand2)
            {
                cntf2++;
            }
        }
        if (cntf1 > n / 3)
        // .or >= n / 3 + 1
        {
            ans.push_back(cand1);
        }

        if (cntf2 > n / 3)
            ans.push_back(cand2);

        return ans;
    }
};