#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bfs(vector<vector<int>> &adj)
    {
        int vis[adj.size()] = {0};
        vector<int> bfs;
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};