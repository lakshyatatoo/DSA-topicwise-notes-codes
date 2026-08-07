#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
private:
    int mn = INT_MAX;
    void bfs(int node, vector<vector<int>> &adj, int n)
    {
        vector<int> depth(n, -1);
        vector<int> parent(n, -1);
        depth[node] = 0;

        queue<int> q;
        q.push(node);
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (auto it : adj[x])
            {
                if (depth[it] == -1)
                {
                    depth[it] = 1 + depth[x];
                    parent[it] = x;
                    q.push(it);
                }
                else if (parent[x] != it)
                {
                    mn = min(mn, depth[x] + depth[it] + 1);
                }
            }
        }
    }

public:
    int findShortestCycle(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        vector<int> depth(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                bfs(i, adj, n);
            }
        }
        if (mn == INT_MAX)
            return -1;
        return mn;
    }
};