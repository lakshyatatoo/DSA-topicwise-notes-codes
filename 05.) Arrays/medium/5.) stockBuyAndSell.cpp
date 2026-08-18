#include <bits/stdc++.h>
using namespace std;

// ============================================================
// 1. BRUTE FORCE
// Time: O(n^2)
// Space: O(1)
// ============================================================

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        int n = prices.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                profit = max(profit, prices[j] - prices[i]);
            }
        }

        return profit;
    }
};

// ============================================================
// 2. OPTIMAL
// Time: O(n)
// Space: O(1)
//
// Keep track of:
// buy    -> minimum price seen so far
// profit -> maximum profit seen so far
// ============================================================

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = prices[0];
        int profit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            int cost = prices[i] - buy;

            profit = max(cost, profit);

            buy = min(buy, prices[i]);
        }

        return profit;
    }
};