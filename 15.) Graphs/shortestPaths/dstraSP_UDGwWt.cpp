#include <bits/stdc++.h>
using namespace std;

// code for shortest path cost from src to each node
/// using priority queue and dijkstra algorithm
class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
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

            if (dis > dist[node])
                continue; // bcz we dont want to recalc for a dis that i not gonna update
            // helps in skiiping a bigger dist that got assigned early but replaced by a smaller dist later on
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

// using set
class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        vector<int> dist(V, 1e9);
        set<pair<int, int>> s;
        dist[src] = 0;
        s.insert({0, src});
        vector<vector<pair<int, int>>> adj(V);
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        while (!s.empty())
        {
            auto it = s.begin();
            int dis = it->first;
            int node = it->second;
            s.erase(it);

            // if (dis > dist[node]) //redundant here in set as we remove old pair in below section
            //     continue; // bcz we dont want to recalc for a dis that i not gonna update
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int wt = it.second;
                if (dis + wt < dist[adjNode])
                {
                    if (dist[adjNode] != 1e9)
                        s.erase({dist[adjNode], adjNode});
                    dist[adjNode] = dis + wt;
                    s.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};
