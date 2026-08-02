#include <bits/stdc++.h>
using namespace std;

class disjoint
{
    vector<int> rank, parent, size;

public:
    disjoint(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUp(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUp(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int up = findUp(u);
        int vp = findUp(v);
        if (up == vp)
            return;
        if (rank[vp] < rank[up])
        {
            parent[vp] = up;
        }
        else if (rank[up] < rank[vp])
        {
            parent[up] = vp;
        }
        else
        {
            parent[vp] = up;
            rank[up]++;
        }
    }
    // void unionBySize(int u, int v)
    // {
    //     int up = findUp(u);
    //     int vp = findUp(v);
    //     if (up == vp)
    //         return;
    //     if (size[vp] < size[up])
    //     {
    //         parent[vp] = up;
    //         size[up] += size[vp];
    //     }
    //     else
    //     {
    //         parent[up] = vp;
    //         size[vp] += size[up];
    //     }
    // }
};

class Solution
{
public:
    int kruskalsMST(int V, vector<vector<int>> &edges)
    {

        vector<pair<int, pair<int, int>>> ehjis;
        for (auto it : edges)
        {
            ehjis.push_back({it[2], {it[0], it[1]}});
        }
        int ans = 0;
        disjoint ds(V);
        sort(ehjis.begin(), ehjis.end());
        for (auto it : ehjis)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (ds.findUp(u) != ds.findUp(v))
            {
                ans += wt;
                ds.unionByRank(u, v);
            }
        }
        return ans;
    }
};