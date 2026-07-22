#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool detect(int node, int parent, vector<vector<int>> &adj, vector<int> &vis)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (detect(it, node, adj, vis))
                    return true;
            }
            else if (parent != it)
                return true;
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
                if (detect(i, -1, adj, vis) == true)
                    return true;
        return false;
    }
};
