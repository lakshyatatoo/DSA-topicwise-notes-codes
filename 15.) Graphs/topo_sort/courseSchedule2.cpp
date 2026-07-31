#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> ans;
        queue<int> q;
        vector<int> indeg(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        for (int i = 0; i < numCourses; i++)
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
        if (ans.size() == numCourses)
            return ans;
        else
            return {};
    }
};