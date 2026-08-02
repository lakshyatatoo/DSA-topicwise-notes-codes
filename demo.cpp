#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        ll n = grid.size() * grid.size();
        ll s = n * (n + 1) / 2, s2 = n * (n + 1) * (2 * n + 1) / 6;
        ll sn = 0, s2n = 0;
        for (ll i = 0; i < grid.size(); i++)
        {
            for (ll j = 0; j < grid[i].size(); j++)
            {
                sn += grid[i][j];
                s2n += grid[i][j] * grid[i][j];
            }
        }
        ll v1 = sn - s;
        ll v2 = s2n - s2;
        v2 = v2 / v1;
        ll x = (v1 + v2) / 2;
        ll y = x - v1;
        return {int(x), int(y)};
    }
};