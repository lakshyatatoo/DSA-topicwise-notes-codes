#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size(), cntFresh = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                    q.push({{i, j}, 0}), vis[i][j] = 2;
                if (grid[i][j] == 1)
                    cntFresh++;
            }
        }
        int time = 0, cnt = 0, dr[] = {0, 0, -1, 1}, dc[] = {-1, 1, 0, 0};
        while (!q.empty())
        {
            int r = q.front().first.first, c = q.front().first.second, t = q.front().second;
            time = max(time, t);
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1)
                    vis[nr][nc] = 2, q.push({{nr, nc}, t + 1}), cnt++;
            }
        }
        if (cnt != cntFresh)
            return -1;
        return time;
    }
};