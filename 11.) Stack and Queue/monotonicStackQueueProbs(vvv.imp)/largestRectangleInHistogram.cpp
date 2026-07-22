#include <bits/stdc++.h>
using namespace std;

// brute
class Solution
{
public:
    vector<int> prevSmaller(vector<int> &arr)
    {
        //  code here
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n, 0);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            nse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> nextSmaller(vector<int> &arr)
    {
        //  code here
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> nse = nextSmaller(heights);
        vector<int> pse = prevSmaller(heights);
        int maxi = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            maxi = max(maxi, heights[i] * (nse[i] - pse[i] - 1));
        }
        return maxi;
    }
};

// optimal just greater than pse nse approach see copy
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxi = INT_MIN;
        stack<int> st;
        for (int i = 0; i < heights.size(); i++)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                int ele = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxi = max(maxi, heights[ele] * (nse - pse - 1));
            }
            st.push(i);
        }
        while (!st.empty())
        {
            int ele = st.top();
            st.pop();
            int nse = heights.size();
            int pse = st.empty() ? -1 : st.top();
            maxi = max(maxi, heights[ele] * (nse - pse - 1));
        }
        return maxi;
    }
};