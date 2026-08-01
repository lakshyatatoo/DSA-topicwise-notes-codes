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

//
//
//
// gfg format

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
        if (up != vp)
            parent[up] = vp;
    }
};
class Solution
{
public:
    vector<int> DSU(int n, vector<vector<int>> &queries)
    {
        disjoint ds(n);
        vector<int> ans;
        for (auto it : queries)
        {
            if (it[0] == 1)
            {
                ds.unionByRank(it[1], it[2]);
            }
            else if (it[0] == 2)
            {
                int x = ds.findUp(it[1]);
                ans.push_back(x);
            }
        }
        return ans;
    }
};