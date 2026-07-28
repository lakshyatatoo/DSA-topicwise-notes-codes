#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] != 0 || grid[n - 1][m - 1] != 0)
            return -1;
        if (n == 1 && m == 1)
            return 1;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 1;
        q.push({1, {0, 0}});
        int dr[] = {-1, 0, 1, 0, -1, 1, -1, 1};
        int dc[] = {0, -1, 0, 1, 1, 1, -1, -1};
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            for (int i = 0; i < 8; i++)
            {
                int nr = row + dr[i];
                int nc = col + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0 && dis + 1 < dist[nr][nc])
                {
                    dist[nr][nc] = dis + 1;
                    if (nr == n - 1 && nc == m - 1)
                        return dis + 1;
                    q.push({dis + 1, {nr, nc}});
                }
            }
        }
        return -1;
    }
};