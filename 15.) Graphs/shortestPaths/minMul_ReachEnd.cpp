#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSteps(vector<int> &arr, int start, int end)
    {
        queue<pair<int, int>> q;
        q.push({0, start});
        vector<int> dist(1000, 1e9);
        dist[start] = 0;
        int mod = 1000;
        if (start == end)
            return 0;
        while (!q.empty())
        {
            auto [steps, node] = q.front();
            if (steps > dist[node])
                continue;
            q.pop();
            for (int x : arr)
            {
                int res = node * x;
                res %= mod;
                if (steps + 1 < dist[res])
                {
                    dist[res] = steps + 1;
                    if (res == end)
                        return steps + 1;
                    q.push({steps + 1, res});
                }
            }
        }
        return -1;
    }
};