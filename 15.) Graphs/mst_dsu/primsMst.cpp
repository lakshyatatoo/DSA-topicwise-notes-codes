#include <bits/stdc++.h>
using namespace std;

// Prim's Algorithm gfg
class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(V);
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({wt, v});
            adj[v].push_back({wt, u});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        int sum = 0;
        pq.push({0, 0});
        while (!pq.empty())
        {
            auto it = pq.top();
            int wt = it.first;
            int node = it.second;
            pq.pop();
            if (vis[node])
                continue;
            vis[node] = 1;
            sum += wt;
            for (auto [adjWt, adjNode] : adj[node])
            {
                if (!vis[adjNode])
                    pq.push({adjWt, adjNode});
            }
        }
        return sum;
    }
};

// leetcode 1584. Min Cost to Connect All Points
class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        vector<vector<pair<int, int>>> adj(points.size());
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = i + 1; j < points.size(); j++)
            {
                int wt = abs(points[i][0] - points[j][0]) +
                         abs(points[i][1] - points[j][1]);

                adj[i].push_back({wt, j});
                adj[j].push_back({wt, i});
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(points.size(), 0);
        int sum = 0;
        pq.push({0, 0});
        while (!pq.empty())
        {
            auto it = pq.top();
            int wt = it.first;
            int node = it.second;
            pq.pop();
            if (vis[node])
                continue;
            vis[node] = 1;
            sum += wt;
            for (auto [adjWt, adjNode] : adj[node])
            {
                if (!vis[adjNode])
                    pq.push({adjWt, adjNode});
            }
        }
        return sum;
    }
};
