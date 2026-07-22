#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void topo(int node, stack<int> &st, vector<int> &vis, vector<vector<pair<int, int>>> &adj)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it.first])
                topo(it.first, st, vis, adj);
        }

        st.push(node);
    }

public:
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(V);
        for (auto &it : edges)
            adj[it[0]].push_back({it[1], it[2]});
        stack<int> st;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                topo(i, st, vis, adj);
        }

        vector<int> dist(V, 1e9);
        dist[0] = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            for (auto it : adj[node])
            {

                if (dist[node] + it.second < dist[it.first])
                {
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
        for (auto &it : dist)
        {
            if (it == 1e9)
                it = -1;
        }
        return dist;
    }
};