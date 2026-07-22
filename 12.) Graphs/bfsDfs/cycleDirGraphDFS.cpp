#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(int node, vector<int> &vis, vector<int> &path, vector<int> adj[])
    {
        vis[node] = 1;
        path[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (dfs(it, vis, path, adj))
                    return true;
            }
            else if (path[it])
                return true;
        }
        path[node] = 0;
        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        vector<int> adj[V];
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> vis(V, 0);
        vector<int> path(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, vis, path, adj))
                    return true;
            }
        }
        return false;
    }
};

// reducing vis path to single array

class Solution
{
private:
    bool dfs(int node, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 2;
        for (auto it : adj[node])
        {
            if (vis[it] == 0)
            {
                if (dfs(it, vis, adj))
                    return true;
            }
            else if (vis[it] == 2)
                return true;
        }
        vis[node] = 1;
        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        vector<int> adj[V];
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, vis, adj))
                    return true;
            }
        }
        return false;
    }
};