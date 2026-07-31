#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> topo(int k, vector<vector<int>> &adj)
    {
        queue<int> q;
        vector<int> indeg(k);
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            for (auto it : adj[i])
                indeg[it]++;
        }
        for (int i = 0; i < k; i++)
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

public:
    string findOrder(vector<string> &words)
    {
        int n = words.size();
        unordered_set<int> st;
        for (string &s : words)
        {
            for (char c : s)
            {
                st.insert(c - 'a');
            }
        }
        int k = st.size();
        vector<vector<int>> adj(26);
        for (int i = 0; i < n - 1; i++)
        {
            string s1 = words[i];
            string s2 = words[i + 1];
            bool mismatch = false;
            for (int j = 0; j < min(s1.size(), s2.size()); j++)
            {
                if (s1[j] != s2[j])
                {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    mismatch = true;
                    break;
                }
            }
            if (!mismatch && s1.size() > s2.size())
                return "";
        }
        vector<int> res = topo(26, adj);
        string s = "";
        for (auto it : res)
        {
            if (st.find(it) != st.end())
                s += char(it + 'a');
        }

        return s.size() == k ? s : "";
    }
};