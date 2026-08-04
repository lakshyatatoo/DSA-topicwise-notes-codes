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
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        int mr = 0, mc = 0;
        for (auto it : stones)
        {
            mr = max(mr, it[0]), mc = max(mc, it[1]);
        }
        disjoint ds(mr + mc + 1);
        unordered_map<int, int> mp;
        for (auto it : stones)
        {
            int nodeRow = it[0], nodeCol = it[1] + mr + 1;
            ds.unionBySize(nodeRow, nodeCol);
            mp[nodeRow] = 1, mp[nodeCol] = 1;
        }
        int cnt = 0;
        for (auto it : mp)
        {
            if (ds.findUp(it.first) == it.first)
                cnt++;
        }
        return n - cnt;
    }
};