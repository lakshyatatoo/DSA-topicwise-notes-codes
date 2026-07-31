#include <bits/stdc++.h>
using namespace std;

//bfs
class Solution // for leetcode reove last 4 in delrow and for gfg remove 1 and make L
{
private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid, int delrow[], int delcol[])
    {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1')
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        int delrow[] = {0, 1, 0, -1, -1, 1, 1, -1};
        int delcol[] = {-1, 0, 1, 0, -1, -1, 1, 1};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    cnt++;
                    bfs(i, j, vis, grid, delrow, delcol);
                }
            }
        }
        return cnt;
    }
};

//dfs
class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        int dr[] = {0, -1, 0, 1};
        int dc[] = {-1, 0, 1, 0};
        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1' &&
                !vis[nr][nc]) {
                dfs(nr, nc, grid, vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(),m = grid[0].size(), cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};