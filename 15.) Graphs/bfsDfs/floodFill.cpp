#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int r, int c, int iColor, int nColor, vector<vector<int>> &ans, vector<vector<int>> &image)
    {
        ans[r][c] = nColor;
        int n = ans.size();
        int m = ans[0].size();
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc < m && nc >= 0 && ans[nr][nc] != nColor && image[nr][nc] == iColor)
            {
                dfs(nr, nc, iColor, nColor, ans, image);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        vector<vector<int>> ans = image;
        int iColor = image[sr][sc];
        int nColor = color;
        int srow = sr;
        int scol = sc;
        dfs(srow, scol, iColor, nColor, ans, image);
        return ans;
    }
};