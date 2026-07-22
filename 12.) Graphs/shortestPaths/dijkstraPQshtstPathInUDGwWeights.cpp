#include <bits/stdc++.h>
using namespace std;

// code for shotest path cost from src to each node
class Solution
{
public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest)
    {
        vector<int> dist(V, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[src] = 0;
        pq.push({0, src});
        vector<vector<pair<int, int>>> adj(V);
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int wt = it.second;
                if (dis + wt < dist[adjNode])
                {
                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

// updated for src to dest path
class Solution
{
public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest)
    {
        vector<int> dist(V + 1, 1e9);
        vector<int> parent(V + 1);
        vector<vector<pair<int, int>>> adj(V + 1);
        for (int i = 1; i <= V; i++)
            parent[i] = i;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[src] = 0;
        pq.push({0, src});

        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int wt = it.second;
                if (dis + wt < dist[adjNode])
                {
                    dist[adjNode] = dis + wt;
                    parent[adjNode] = node;
                    pq.push({dist[adjNode], adjNode});
                }
                        }
        }
        if (dist[dest] == 1e9)
            return {-1};
        vector<int> path;
        int node = dest;
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(src);
        reverse(path.begin(), path.end());
        return path;
    }
};