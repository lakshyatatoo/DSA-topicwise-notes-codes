#include <bits/stdc++.h>
using namespace std;

// climb stairs problem using dp memoisation
// but its basically fibonacci series
//  tc: O(n) sc: O(n)
class Solution
{
private:
    int rec(int n, vector<int> &dp)
    {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];

        return dp[n] = rec(n - 1, dp) + rec(n - 2, dp);
    }

public:
    int climbStairs(int n)
    {
        if (n == 1 || n == 0)
            return n;
        vector<int> dp(n + 1, -1);
        rec(n, dp);
        return dp[n];
    }
};

// tabulation
//  tc: O(n) sc: O(1)
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 0 || n == 1)
            return n;
        int prev2 = 0;
        int prev1 = 1;
        for (int i = 2; i <= n; i++)
        {

            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};