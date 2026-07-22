#include <bits/stdc++.h>
using namespace std;

// optimal
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

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        int sum = 0;
        vector<vector<int>> pS(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++)
        {
            sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += matrix[i][j] - '0';
                if (matrix[i][j] == '0')
                    sum = 0;
                pS[i][j] = sum;
            }
        }
        for (int i = 0; i < n; i++)
        {
            maxArea = max(maxArea, largestRectangleArea(pS[i]));
        }
        return maxArea;
    }
};
