#include <bits/stdc++.h>
using namespace std;

// optimal only one and only
class Solution
{
public:
    vector<int> nSe(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nse(n, -1);
        stack<int> st;
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
    vector<int> pSEe(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> psse(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() &&
                   arr[st.top()] >
                       arr[i]) // only> because we want to count the current
                               // element as well in case of duplicates
            {
                st.pop();
            }
            psse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psse;
    }
    long long sumSubarrayMins(vector<int> &arr)
    {
        vector<int> nse = nSe(arr);
        vector<int> psse = pSEe(arr);
        int n = arr.size();
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            int left = i - psse[i];
            int right = nse[i] - i;
            long long total_subarrays = (left * 1LL * right);
            long long contribution = (total_subarrays * arr[i]);
            sum = (sum + contribution);
        }
        return sum;
    }
    vector<int> nGe(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nge(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] <= arr[i])
            {
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int> pGEe(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> pgse(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() &&
                   arr[st.top()] <
                       arr[i]) // only< because we want to count the current
                               // element as well in case of duplicates
            {
                st.pop();
            }
            pgse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pgse;
    }
    long long sumSubarrayMaxs(vector<int> &arr)
    {
        vector<int> nge = nGe(arr);
        vector<int> pgee = pGEe(arr);
        int n = arr.size();
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            int left = i - pgee[i];
            int right = nge[i] - i;
            long long total_subarrays = (left * 1LL * right);
            long long contribution = (total_subarrays * arr[i]);
            sum = (sum + contribution);
        }
        return sum;
    }
    long long subArrayRanges(vector<int> &nums)
    {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};