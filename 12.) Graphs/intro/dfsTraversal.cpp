#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfsCall(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &dfs)
    {
        vis[node] = 1;
        dfs.push_back(node);
        // traversing all neighbours and going deep for each
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfsCall(it, adj, vis, dfs);
            }
        }
    }

public:
    vector<int> dfs(vector<vector<int>> &adj)
    {
        vector<int> dfs;
        vector<int> vis(adj.size(), 0);
        int start = 0;
        dfsCall(start, adj, vis, dfs);
        return dfs;
    }
};
