#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isSafe(int node, vector<vector<int>> &edges, vector<int> &color, int col)
    {
        for (auto it : edges[node])
        {
            if (color[it] == col)
                return false;
        }
        return true;
    }
    bool solve(int node, vector<int> &color, int m, int v, vector<vector<int>> &edges)
    {
        if (node == v)
            return true;
        for (int i = 1; i <= m; i++)
        {
            if (isSafe(node, edges, color, i))
            {
                color[node] = i;
                if (solve(node + 1, color, m, v, edges))
                    return true;
                color[node] = 0;
            }
        }
        return false;
    }

    bool graphColoring(int v, vector<vector<int>> &edges, int m)
    {
        vector<vector<int>> adj(v); // adjacency list

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u); // because graph is undirected
        }
        vector<int> color(v, 0); // to maintain which color is assigned to which node

        if (solve(0, color, m, v, adj))
            return true;
        return false;
    }
};