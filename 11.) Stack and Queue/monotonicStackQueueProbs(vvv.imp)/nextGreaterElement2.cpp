#include <bits/stdc++.h>
using namespace std;

// brute force
// tc: O(n^2) sc: O(n)
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nge(n, -1);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j <= i + (n - 1); j++)
            {
                int ind = j % n;
                if (nums[ind] > nums[i])
                {
                    nge[i] = nums[ind];
                    break;
                }
            }
        }
        return nge;
    }
};

// optimal
//  tc: O(4n) sc: O(2n+n)
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nge(n, 0);
        stack<int> st;

        for (int i = (2 * n) - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i % n])
            {
                st.pop();
            }
            if (i < n)
            {
                nge[i] = st.empty() ? -1 : st.top();
                // can be not if but nge[i%n] and a if else too see sample
                //  if(st.empty()){
                //  ans[i%n]=-1;
                //  }
                //  else{
                //  ans[i%n]=st.top();
                //  }
            }
            st.push(nums[i % n]);
        }
        return nge;
    }
};