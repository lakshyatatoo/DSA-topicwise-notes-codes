#include <bits/stdc++.h>
using namespace std;

// brute force
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nge(n, -1);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] > nums[i])
                {
                    nge[i] = nums[j];
                    break;
                }
            }
        }
        return nge;
    }
};

// optimal
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                nge[i] = -1;
            }
            else
            {
                nge[i] = st.top();
            }
            st.push(nums[i]);
        }
        return nge;
    }
};

// leetcode 496. Next Greater Element I
// tc: O(n1+n2) where n1 is size of nums2 and n2 is size of nums1
// sc: O(n1+n2) for stack and map
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp;
        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                mp[nums2[i]] = -1;
            }
            else
            {
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
        {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};