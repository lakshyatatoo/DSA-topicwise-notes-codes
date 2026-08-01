#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(int node, int p, vector<vector<int>> &adj, vector<int> &vis,
             vector<int> &parent, unordered_set<int> &ans)
    {

        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                parent[it] = node;
                if (dfs(it, node, adj, vis, parent, ans))
                    return true;
            }
            else if (it != p)
            {
                ans.insert(it);
                int temp = node;
                while (temp != it)
                {

                    ans.insert(temp);
                    temp = parent[temp];
                }
                return true;
            }
        }
        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> parent(n + 1, -1);
        vector<int> vis(n + 1, 0);
        unordered_set<int> ans;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
                if (dfs(i, -1, adj, vis, parent, ans))
                    break;
        }

        while (!edges.empty())
        {
            if (ans.count(edges.back()[0]) &&
                ans.count(edges.back()[1]))
                return edges.back();
            edges.pop_back();
        }
        return {};
    }
};