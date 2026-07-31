#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<ll, ll>>> adj(n);
        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]}), adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,
                       greater<pair<ll, ll>>>
            pq;
        vector<ll> ways(n, 0), dist(n, 1e18);
        ll mod = 1e9 + 7;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while (!pq.empty())
        {
            auto [dis, node] = pq.top();
            pq.pop();
            for (auto [adjNode, wt] : adj[node])
            {
                if (dis + wt < dist[adjNode])
                    ways[adjNode] = ways[node], dist[adjNode] = dis + wt, pq.push({dist[adjNode], adjNode});
                else if (dis + wt == dist[adjNode])
                    ways[adjNode] += ways[node], ways[adjNode] %= mod;
            }
        }
        return ways[n - 1] % mod;
    }
};