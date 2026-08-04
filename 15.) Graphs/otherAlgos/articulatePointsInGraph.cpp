#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int timer = 0;

private:
    void dfs(int node, int p, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<vector<int>> &adj, set<int> &st)
    {
        vis[node] = 1;
        int child = 0;
        low[node] = tin[node] = timer++;
        for (auto it : adj[node])
        {
            if (it == p)
                continue;
            if (!vis[it])
            {
                dfs(it, node, vis, tin, low, adj, st);
                low[node] = min(low[it], low[node]);
                if (low[it] >= tin[node] && p != -1)
                    st.insert(node);
                child++;
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (child > 1 && p == -1)
            st.insert(node);
    }

public:
    vector<int> articulationPoints(int V, vector<vector<int>> &edges)
    {

        vector<vector<int>> adj(V);
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        set<int> st;
        vector<int> tin(V);
        vector<int> low(V);
        vector<int> vis(V);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfs(i, -1, vis, tin, low, adj, st);
        }
        vector<int> ans(st.begin(), st.end());
        if (ans.size() == 0)
            return {-1};
        return ans;
    }
};