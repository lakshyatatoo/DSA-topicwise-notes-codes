#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest)
    {
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        vector<vector<int>> adj(V);
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        q.push(src);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                if (dist[node] + 1 < dist[it])
                {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        return dist;
    }
};
