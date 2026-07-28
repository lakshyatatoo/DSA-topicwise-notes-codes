#include <bits/stdc++.h>
using namespace std;

// simple path no conditions
class Solution
{
public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest)
    {
        vector<vector<pair<int, int>>> adj(V + 1);
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V + 1, 1e9);
        vector<int> parent(V + 1);
        for (int i = 1; i <= V; i++)
            parent[i] = i;
        dist[src] = 0;
        pq.push({dist[src], src});
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            if (dis > dist[node])
                continue;
            for (auto [adjNode, wt] : adj[node])
            {
                if (dis + wt < dist[adjNode])
                {
                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
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

// for gfg
//  for lexicographically smallest path using reverse dijkstra algo no parent
//  calculating the min in rev makes sure that fromdes to src min is considered now we build the path from the start this
//  ensures that all nodes considered are lexicographically smaller than the next node in the path
class Solution
{
public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest)
    {
        vector<vector<pair<int, int>>> adj(V + 1);
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V + 1, 1e9);
        dist[dest] = 0;
        pq.push({dist[dest], dest});
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            if (dis > dist[node])
                continue;
            for (auto [adjNode, wt] : adj[node])
            {
                if (dis + wt < dist[adjNode])
                {
                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        // path creation
        if (dist[src] == 1e9)
            return {-1};
        vector<int> path;
        int node = src;
        while (node != dest)
        {
            int nextNode = -1;
            for (auto [adjNode, wt] : adj[node])
            {
                if (dist[node] == dist[adjNode] + wt)
                {
                    if (nextNode == -1 || adjNode < nextNode)
                        nextNode = adjNode;
                }
            }
            path.push_back(node);
            node = nextNode;
        }
        path.push_back(dest);
        return path;
    }
};