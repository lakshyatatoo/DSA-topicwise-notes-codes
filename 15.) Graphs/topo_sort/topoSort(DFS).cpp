#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
                dfs(it, vis, st, adj);
        }
        st.push(node);
    }

public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        vector<int> vis(V, 0);
        stack<int> st;
        vector<vector<int>> adj(V);
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
        }
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfs(i, vis, st, adj);
        }
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};