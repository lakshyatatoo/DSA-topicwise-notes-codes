#include <bits/stdc++.h>
using namespace std;
// brute nested loops
// tle
class Solution
{
private:
    bool linear_search(vector<int> &nums, int k)
    {
        // code here
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == k)
            {
                return true;
            }
        }
        return false;
    }

public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 1;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            cnt = 1;
            while (linear_search(nums, x + 1) == true)
            {
                x += 1;
                cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};

// better
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        int n = nums.size();

        if (n == 0)
            return 0;

        sort(nums.begin(), nums.end());

        int cnt = 1;
        int ans = 1;

        for (int i = 0; i < n - 1; i++)
        {

            if (nums[i + 1] == nums[i] + 1)
            {
                cnt++;
            }

            else if (nums[i + 1] == nums[i])
            {
                continue;
            }

            else
            {
                cnt = 1;
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};

// optimal
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        int longest = 0;
        int cnt = 1;
        if (n == 0)
        {
            return 0;
        }
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(nums[i]);
        }
        for (auto it : st)
        {
            if (st.find(it - 1) == st.end())
            {
                cnt = 1;
                int x = it;
                while (st.find(x + 1) != st.end())
                {
                    x += 1;
                    cnt++;
                }
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};