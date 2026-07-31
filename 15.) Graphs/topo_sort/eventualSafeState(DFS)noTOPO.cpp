#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(int node, vector<int> &vis, vector<int> &path, vector<int> &check,
             vector<vector<int>> &graph)
    {
        path[node] = 1;
        vis[node] = 1;
        // check[node]=0; inside for or here both same
        for (auto it : graph[node])
        {
            if (!vis[it])
            {
                if (dfs(it, vis, path, check, graph))
                {
                    check[node] = 0;
                    return true;
                }
            }
            else if (path[it])
            {
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        path[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> vis(n, 0), path(n, 0), check(n, 0), safe;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                dfs(i, vis, path, check, graph);
        }
        for (int i = 0; i < n; i++)
        {
            if (check[i])
                safe.push_back(i);
        }
        return safe;
    }
};