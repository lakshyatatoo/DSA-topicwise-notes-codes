#include <bits/stdc++.h>
using namespace std;
// brute
// nested loop //  each element difference check

// optimal.  checking mini on left and maxi on right and saving difference as profit
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