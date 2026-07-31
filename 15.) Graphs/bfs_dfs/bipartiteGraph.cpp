#include <bits/stdc++.h>
using namespace std;

// my version with quueue more optimal with vis and color array id below
class Solution
{
private:
    bool dfs(int node, char color, vector<vector<int>> &graph,
             vector<pair<char, int>> &vis)
    {
        vis[node].second = 1;
        vis[node].first = color;
        for (auto it : graph[node])
        {
            if (!vis[it].second)
            {
                if (color == 'B')
                {
                    if (!dfs(it, 'W', graph, vis))
                        return false;
                }
                else
                {
                    if (!dfs(it, 'B', graph, vis))
                        return false;
                }
            }
            else if (vis[it].second)
            {
                if (vis[it].first == color)
                    return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<pair<char, int>> vis(n);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i].second)
            {
                if (!dfs(i, 'B', graph, vis))
                    return false;
            }
        }
        return true;
    }
};

// biparitite using dfs
class Solution
{
private:
    bool dfs(int node, int col, vector<vector<int>> &graph,
             vector<int> &color)
    {
        color[node] = col;
        for (auto it : graph[node])
        {
            if (color[it] == -1)
            {
                if (!dfs(it, !col, graph, color))
                    return false;
            }
            else
            {
                if (color[it] == col)
                    return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (!dfs(i, 0, graph, color))
                    return false;
            }
        }
        return true;
    }
};

// bipartite using bfs
class Solution
{
private:
    bool bfs(int node, vector<vector<int>> &adj, vector<int> &color)
    {
        color[node] = 0;
        queue<int> q;
        q.push(node);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                if (color[it] == -1)
                {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if (color[it] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (!bfs(i, graph, color))
                    return false;
            }
        }
        return true;
    }
};
