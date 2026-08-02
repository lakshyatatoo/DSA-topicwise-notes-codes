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
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        disjoint ds(n);
        int ee = 0;
        int ans = 0;
        for (auto it : connections)
        {
            int u = it[0];
            int v = it[1];
            if (ds.findUp(u) == ds.findUp(v))
                ee++;
            else
                ds.unionByRank(u, v);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
                cnt++;
        }
        int ans = cnt - 1;
        if (ee >= ans)
            return ans;
        else
            return -1;
    }
};