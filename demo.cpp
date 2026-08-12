#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
private:
    void solve(int ind, vector<int> &coins, int target, int &cnt, int currCnt)
    {
        if (target == 0)
        {
            cnt = min(cnt, currCnt);
            return;
        }
        if (ind == coins.size())
        {
            return;
        }
        for (int i = ind; i < coins.size(); i++)
        {
            if (coins[i] <= target)
            {
                target -= coins[i];
                currCnt++;
                solve(i, coins, target, cnt, currCnt);
                target += coins[i];
                currCnt--;
            }
        }
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        sort(coins.begin(), coins.end(), greater<int>());
        int cnt = INT_MAX;
        if (amount == 0)
            return 0;
        solve(0, coins, amount, cnt, 0);
        if (cnt == INT_MAX)
            return -1;
        return cnt;
    }
};