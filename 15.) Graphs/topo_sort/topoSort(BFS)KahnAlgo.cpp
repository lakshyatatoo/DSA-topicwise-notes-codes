#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        vector<int> ans;
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
            ans.push_back(node);
            for (auto it : adj[node])
            {
                indeg[it]--;
                if (indeg[it] == 0)
                    q.push(it);
            }
        }
        return ans;
    }
};