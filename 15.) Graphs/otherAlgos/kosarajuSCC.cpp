#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
                dfs(it, adj, vis, st);
        }
        st.push(node);
    }

public:
    int kosaraju(int V, vector<vector<int>> &edges)
    {
        // adj
        vector<vector<int>> adj(V);
        for (auto it : edges)
            adj[it[0]].push_back(it[1]);
        // step1
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfs(i, adj, vis, st);
        }
        // step2
        vector<vector<int>> adjRev(V);
        for (int i = 0; i < V; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                adjRev[it].push_back(i);
            }
        }
        // step3;
        int scc = 0;
        vector<vector<int>> sccs;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!vis[node])
            {
                scc++;
                stack<int> res;
                dfs(node, adjRev, vis, res);
                while (!res.empty())
                {
                    vector<int> temp;
                    temp.push_back(res.top());
                    res.pop();
                    sccs.push_back(temp);
                }
            }
        }
        return scc;
    }
};