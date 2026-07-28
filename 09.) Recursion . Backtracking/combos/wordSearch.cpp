#include <bits/stdc++.h>
using namespace std;

// brute force approach
class Solution
{
private:
    void dfs(int r, int c, int size, unordered_set<string> &ans, string word,
             vector<vector<char>> &board, vector<vector<int>> &vis)
    {
        vis[r][c] = 1;
        word += board[r][c];
        int n = board.size();
        int m = board[0].size();
        if (word.size() == size)
        {
            ans.insert(word);
            vis[r][c] = 0;
            return;
        }
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < n && nr >= 0 && nc < m && nc >= 0 && !vis[nr][nc])
            {
                dfs(nr, nc, size, ans, word, board, vis);
            }
        }
        vis[r][c] = 0;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        char start = word[0];
        int s = word.size();
        unordered_set<string> ans;
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == start)
                {
                    dfs(i, j, s, ans, "", board, vis);
                }
            }
        }
        if (ans.count(word))
            return true;
        else
            return false;
    }
};

// optimized approach
class Solution
{
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

private:
    bool dfs(int r, int c, int idx,
             vector<vector<char>> &board, vector<vector<int>> &vis, string &word)
    {
        if (board[r][c] != word[idx])
            return false;
        vis[r][c] = 1;
        if (idx == word.size() - 1) // since word is same as we passed not equal step
        {
            vis[r][c] = 0;
            return true;
        }

        int n = board.size(), m = board[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr < n && nr >= 0 && nc < m && nc >= 0 && !vis[nr][nc])
            {
                if (dfs(nr, nc, idx + 1, board, vis, word))
                {
                    vis[r][c] = 0;
                    return true;
                }
            }
        }
        vis[r][c] = 0;
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (dfs(i, j, 0, board, vis, word))
                    return true;
            }
        }
        return false;
    }
};
