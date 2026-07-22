#include <bits/stdc++.h>
using namespace std;

// brute recursion backtracking
// can use visited array to avoid cycles
class Solution
{
public:
    bool solve(int i, int j, vector<vector<int>> &mat, int n, vector<vector<int>> &ans)
    {
        if (i == n - 1 && j == n - 1)
        {
            ans[i][j] = 1;
            return true;
        }
        ans[i][j] = 1;
        int steps = mat[i][j];
        for (int step = 1; step <= steps; step++)
        {
            if (j + step < n && mat[i][j + step] != 0 && solve(i, j + step, mat, n, ans))
                return true;
            if (i + step < n && mat[i + step][j] != 0 && solve(i + step, j, mat, n, ans))
                return true;
        }
        ans[i][j] = 0;
        mat[i][j] = 0; // mark as visited to avoid cycles
        return false;
    }
    vector<vector<int>> shortestDist(vector<vector<int>> &mat)
    {
        int n = mat.size();
        if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0)
            return {{-1}};
        vector<vector<int>> ans(n, vector<int>(n, 0));
        if (solve(0, 0, mat, n, ans))
            return ans;
        return {{-1}};
    }
};

// optimal
// need dp