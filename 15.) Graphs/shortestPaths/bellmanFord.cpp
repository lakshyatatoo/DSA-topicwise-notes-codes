#include <bits/stdc++.h>
using namespace std;

// bellman ford algorithm
// tc=vxe sc=v;
class Solution
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        for (int i = 0; i < V; i++)
        {
            for (auto it : edges)
            {
                int u = it[0], v = it[1], wt = it[2];
                if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                    dist[v] = dist[u] + wt;
            }
        }
        // for negative cycle
        for (auto it : edges)
        {
            int u = it[0], v = it[1], wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                return {-1};
        }
        return dist;
    }
};
