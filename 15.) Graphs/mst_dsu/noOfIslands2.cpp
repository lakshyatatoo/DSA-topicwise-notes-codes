#include <bits/stdc++.h>
using namespace std;

class disjoint
{
public:
    vector<int> rank, parent, size;
    disjoint(int n)
    {
        rank.resize(n + 1, 0), size.resize(n + 1, 1), parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int findUp(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUp(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int up = findUp(u), vp = findUp(v);
        if (up == vp)
            return;
        if (rank[vp] < rank[up])
            parent[vp] = up;
        else if (rank[up] < rank[vp])
            parent[up] = vp;
        else
            parent[vp] = up, rank[up]++;
    }
    void unionBySize(int u, int v)
    {
        int up = findUp(u), vp = findUp(v);
        if (up == vp)
            return;
        if (size[vp] < size[up])
            parent[vp] = up, size[up] += size[vp];
        else
            parent[up] = vp, size[vp] += size[up];
    }
};

class Solution
{
public:
    vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &queries)
    {
        vector<int> ans;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        disjoint ds(n * m);
        int cnt = 0;
        for (auto it : queries)
        {
            int r = it[0];
            int c = it[1];
            if (vis[r][c] == 1)
            {
                ans.push_back(cnt);
            }
            else
            {
                vis[r][c] = 1;
                cnt++;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                for (int i = 0; i < 4; i++)
                {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 1)
                    {
                        int node = r * m + c;
                        int adjNode = nr * m + nc;
                        if (ds.findUp(node) != ds.findUp(adjNode))
                        {
                            cnt--;
                            ds.unionByRank(node, adjNode);
                        }
                    }
                }
                ans.push_back(cnt);
            }
        }
        return ans;
    }
};
