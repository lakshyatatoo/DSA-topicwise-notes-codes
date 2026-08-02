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

// steps of what is being done
// assuming each list is a node
//  create mapping of mail to node if already mapped then we union current node with mapped node ie we make up of current the mapped node
//  create a colection of mail where each mail is accessed from map and each mail is stored in node which is its up
//  ans declaration
//  loop for 0 to n for each node if collection exist we sort it  in a temp push name of that index/node and add the mails of that node to temp push temp to ans.
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
                if (mailNode.find(mail) == mailNode.end())
                    mailNode[mail] = i;
                else
                    ds.unionByRank(i, mailNode[mail]);
            }
        }
        vector<vector<string>> collection(n);
        for (auto it : mailNode)
        {
            string mail = it.first;
            int node = ds.findUp(it.second);
            collection[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (collection[i].size() == 0)
                continue;
            sort(collection[i].begin(), collection[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto x : collection[i])
                temp.push_back(x);
            ans.push_back(temp);
        }
        return ans;
    }
};