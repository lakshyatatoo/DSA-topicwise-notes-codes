#include <bits/stdc++.h>
using namespace std;
#define ll long long
class disjoint
{
public:
    vector<int> rank, size, parent;
    disjoint(int n)
    {
        rank.resize(n + 1, 0), size.resize(n + 1, 1), parent.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findup(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findup(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int up = findup(u);
        int vp = findup(v);
        if (up == vp)
            return;
        else if (rank[up] < rank[vp])
        {
            parent[up] = vp;
        }
        else if (rank[up] > rank[vp])
        {
            parent[vp] = up;
        }
        else
        {
            parent[up] = vp;
            rank[vp]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int up = findup(u);
        int vp = findup(v);
        if (up == vp)
            return;
        else if (size[up] < size[vp])
        {
            parent[up] = vp;
            size[vp] += size[up];
        }
        else
        {
            parent[vp] = up;
            size[up] += size[vp];
        }
    }
};
class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        unordered_map<string, int> mailNode;
        int n = accounts.size();
        disjoint ds(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if (mailNode.find(mail) != mailNode.end())
                {
                    ds.unionByRank(i, mailNode[mail]);
                }
                else
                {
                    mailNode[mail] = i;
                }
            }
        }
        vector<vector<string>> mailCollect(n);
        for (auto it : mailNode)
        {
            string mail = it.first;
            int node = ds.findup(it.second);
            mailCollect[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (mailCollect[i].size() == 0)
                continue;
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto x : mailCollect[i])
            {
                temp.push_back(x);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};