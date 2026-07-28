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
        int iC = image[sr][sc];
        int nC = color;
        dfs(sr, sc, iC, nC, ans, image);
        return ans;
    }
};

// bit more space compexity save approach
class Solution
{
private:
    void dfs(int row, int col, int color, int ic, vector<vector<int>> &ans)
    {
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        int n = ans.size();
        int m = ans[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if (nrow < n && nrow >= 0 && ncol >= 0 && ncol < m &&
                ans[nrow][ncol] == ic)
            {
                ans[nrow][ncol] = color;
                dfs(nrow, ncol, color, ic, ans);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int color)
    {
        vector<vector<int>> ans = image;
        int ic = image[sr][sc];
        if (ic == color)
            return ans;
        ans[sr][sc] = color;
        dfs(sr, sc, color, ic, ans);
        return ans;
    }
};