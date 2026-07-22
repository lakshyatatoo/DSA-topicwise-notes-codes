#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool detect(int src, vector<vector<int>> &adj, vector<int> &vis)
    {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while (!q.empty())
        {
            int node = q.front().first, parent = q.front().second;
            q.pop();
            for (auto adjNode : adj[node])
            {
                if (!vis[adjNode])
                    vis[adjNode] = 1, q.push({adjNode, node});
                else if (parent != adjNode)
                    return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        vector<int> vis(V);
        vector<vector<int>> adj(V);
        for (auto &x : edges)
        {
            int u = x[0], v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 0; i < V; i++)
            if (!vis[i])
                if (detect(i, adj, vis) == true)
                    return true;
        return false;
    }
};
