#include <bits/stdc++.h>
using namespace std;

// dfs

class Solution
{
private:
    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &grid, int n, int m)
    {
        vis[r][c] = 1;
        int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1)
                dfs(nr, nc, vis, grid, n, m);
        }
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // rows
        for (int j = 0; j < m; j++)
        {
            if (!vis[0][j] && grid[0][j] == 1)
                dfs(0, j, vis, grid, n, m);
            if (!vis[n - 1][j] && grid[n - 1][j] == 1)
                dfs(n - 1, j, vis, grid, n, m);
        }
        // columns
        for (int i = 0; i < n; i++)
        {
            if (!vis[i][0] && grid[i][0] == 1)
                dfs(i, 0, vis, grid, n, m);
            if (!vis[i][m - 1] && grid[i][m - 1] == 1)
                dfs(i, m - 1, vis, grid, n, m);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

// bfs tle on leetcode
class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        // rows
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    if (grid[i][j] == 1)
                    {
                        q.push({i, j}), vis[i][j] = 1;
                    }
                }
            }
        }
        int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
        while (!q.empty())
        {
            int r = q.front().first, c = q.front().second;
            vis[r][c] = 1;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1)
                {
                    q.push({nr, nc});
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                    cnt++;
            }
        }
        return cnt;
    }
};