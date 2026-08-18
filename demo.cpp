#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
public:
    int maxSum(vector<vector<int>> &grid)
    {
        int mxSum = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j + 2 < m && i + 2 < n)
                {
                    int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2] +
                              grid[i + 1][j + 1] + grid[i + 2][j] +
                              grid[i + 2][j + 1] + grid[i + 2][j + 2];
                    mxSum = max(mxSum, sum);
                }
            }
        }
        return mxSum;
    }
};