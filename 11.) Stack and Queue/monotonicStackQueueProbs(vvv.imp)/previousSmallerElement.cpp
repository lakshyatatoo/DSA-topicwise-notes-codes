#include <bits/stdc++.h>
using namespace std;

// brute
// tc: O(n^2)
// sc: O(n)
// tle
class Solution
{
public:
    vector<int> prevSmaller(vector<int> &arr)
    {
        //  code here
        int n = arr.size();
        vector<int> pse(n, -1);
        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (arr[j] < arr[i])
                {
                    pse[i] = arr[j];
                    break;
                }
            }
        }
        return pse;
    }
};

// optimal
// tc: O(n)
// sc: O(n)
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
            while (!st.empty() && st.top() >= arr[i])
            {
                st.pop();
            }
            nse[i] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }
        return nse;
    }
};

// optimal index based
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
};
