#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights)
        {
            int from = it[0];
            int to = it[1];
            int price = it[2];
            adj[from].push_back({to, price});
        }
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if (stops > k)
                continue;
            for (auto [adjNode, wt] : adj[node])
            {
                if (cost + wt < dist[adjNode] && stops <= k)
                {
                    dist[adjNode] = cost + wt;
                    q.push({stops + 1, {adjNode, cost + wt}});
                }
            }
        }
        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};