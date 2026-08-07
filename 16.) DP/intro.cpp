#include <bits/stdc++.h>
using namespace std;

// fibonacci series using dp
// tc: O(n) sc: O(n)
// brute/optimal for memoization
class Solution
{
private:
    int fifi(int n, vector<int> &dp)
    {
        if (n <= 1)
            return n;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = fifi(n - 1, dp) + fifi(n - 2, dp);
    }

public:
    int fib(int n)
    {
        if (n == 0 || n == 1)
            return n;
        vector<int> dp(n + 1, -1);
        fifi(n, dp);
        return dp[n];
    }
};

// brute tabulation
// tc : O(n) sc: O(n)
class Solution
{
public:
    int fib(int n)
    {
        if (n == 0 || n == 1)
            return n;
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

// optimal tabulation
// tc: O(n) sc: O(1)class Solution
class Solution
{
public:
    int fib(int n)
    {
        if (n == 0 || n == 1)
            return n;
        vector<int> dp(n + 1, -1);
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
