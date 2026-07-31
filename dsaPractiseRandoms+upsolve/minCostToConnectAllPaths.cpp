#include <bits/stdc++.h>
using namespace std;

// leetcode 1584. Min Cost to Connect All Points
class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        vector<vector<pair<int, int>>> adj(points.size());
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = i + 1; j < points.size(); j++)
            {
                int wt = abs(points[i][0] - points[j][0]) +
                         abs(points[i][1] - points[j][1]);

                adj[i].push_back({wt, j});
                adj[j].push_back({wt, i});
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(points.size(), 0);
        int sum = 0;
        pq.push({0, 0});
        while (!pq.empty())
        {
            auto it = pq.top();
            int wt = it.first;
            int node = it.second;
            pq.pop();
            if (vis[node])
                continue;
            vis[node] = 1;
            sum += wt;
            for (auto [adjWt, adjNode] : adj[node])
            {
                if (!vis[adjNode])
                    pq.push({adjWt, adjNode});
            }
        }
        return sum;
    }
};
