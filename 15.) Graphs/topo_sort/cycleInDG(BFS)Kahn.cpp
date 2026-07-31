#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        int cnt = 0;
        queue<int> q;
        vector<int> indeg(V, 0);
        vector<vector<int>> adj(V);
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            indeg[it[1]]++;
        }
        for (int i = 0; i < V; i++)
        {
            if (indeg[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto it : adj[node])
            {
                indeg[it]--;
                if (indeg[it] == 0)
                    q.push(it);
            }
        }
        if (cnt == V)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};