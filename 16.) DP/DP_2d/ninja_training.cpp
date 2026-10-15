#include <bits/stdc++.h>
using namespace std;

// memoization
class Solution
{
private:
    int ok(int day, int last, vector<vector<int>> &mat, vector<vector<int>> &dp)
    {
        if (day == 0)
        {
            int mx = -1;
            for (int i = 0; i < 3; i++)
            {
                if ((i != last))
                    mx = max(mx, mat[day][i]);
            }
            return mx;
        }
        if (dp[day][last] != -1)
            return dp[day][last];
        int mx = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                int points = mat[day][i] + ok(day - 1, i, mat, dp);
                mx = max(points, mx);
            }
        }
        return dp[day][last] = mx;
    }

public:
    int maximumPoints(vector<vector<int>> &mat)
    {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return ok(n - 1, 3, mat, dp);
    }
};

// tabulation

class Solution
{
public:
    int maximumPoints(vector<vector<int>> &mat)
    {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        dp[0][0] = max(mat[0][1], mat[0][2]);
        dp[0][1] = max(mat[0][0], mat[0][2]);
        dp[0][2] = max(mat[0][0], mat[0][1]);
        dp[0][3] = max(mat[0][0], max(mat[0][1], mat[0][2]));

        for (int day = 1; day < n; day++)
        {
            for (int last = 0; last < 4; last++)
            {
                dp[day][last] = 0;
                for (int task = 0; task < 3; task++)
                {
                    if (task != last)
                    {
                        int points = mat[day][task] + dp[day - 1][task];
                        dp[day][last] = max(dp[day][last], points);
                    }
                }
            }
        }
        return dp[n - 1][3];
    }
};

// tabulation space optimization

class Solution
{
public:
    int maximumPoints(vector<vector<int>> &mat)
    {
        int n = mat.size();
        vector<int> dp(4, -1);
        dp[0] = max(mat[0][1], mat[0][2]);
        dp[1] = max(mat[0][0], mat[0][2]);
        dp[2] = max(mat[0][0], mat[0][1]);
        dp[3] = max(mat[0][0], max(mat[0][1], mat[0][2]));

        for (int day = 1; day < n; day++)
        {
            vector<int> temp(4, -1);
            for (int last = 0; last < 4; last++)
            {
                temp[last] = 0;
                for (int task = 0; task < 3; task++)
                {
                    if (task != last)
                    {
                        int points = mat[day][task] + dp[task];
                        temp[last] = max(temp[last], points);
                    }
                }
            }
            dp = temp;
        }
        return dp[3];
    }
};