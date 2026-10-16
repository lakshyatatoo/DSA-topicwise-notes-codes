#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = 1e9;
        for (int k = i; k <= j; k++)
        {
            int cost = cuts[j + 1] - cuts[i - 1] + f(i, k - 1, cuts, dp) + f(k + 1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int> &cuts)
    {
        int c = cuts.size();
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1)); // because we are using 1 based indexing and added 0 and n in the cuts array
        return f(1, c, cuts, dp);
    }
};

// tabulation
class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {

        int c = cuts.size();
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
        for (int i = c; i >= 1; i--)
        {
            for (int j = 1; j <= c; j++)
            {
                if (i > j)
                    continue;
                int mini = 1e9;
                for (int k = i; k <= j; k++)
                {
                    int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};