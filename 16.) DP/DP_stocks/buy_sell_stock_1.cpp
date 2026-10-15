#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = 0;
        int profit = 0;
        buy = prices[0];
        for (int i = 0; i < prices.size(); i++)
        {
            profit = max(profit, prices[i] - buy);
            if (prices[i] < buy)
            {
                buy = prices[i];
            }
        }
        return profit;
    }
};