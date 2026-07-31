#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int row, int col, vector<pair<int, int>> &vec, vector<vector<char>> &grid, int brow, int bcol, vector<vector<int>> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        vec.push_back({row - brow, col - bcol});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nr = row + dr[i];
            int nc = col + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 'L')
            {
                dfs(nr, nc, vec, grid, brow, bcol, vis);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 'L')
                {
                    vector<pair<int, int>> vec;
                    dfs(i, j, vec, grid, i, j, vis);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
