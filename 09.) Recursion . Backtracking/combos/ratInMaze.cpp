#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, vector<vector<int>> &maze, int n, vector<string> &ans, string move, vector<vector<int>> &visited)
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(move);
        return;
    }
    // down movement
    if (i + 1 < n && maze[i + 1][j] == 1 && !visited[i + 1][j])
    {
        visited[i][j] = 1;
        solve(i + 1, j, maze, n, ans, move + 'D', visited);
        visited[i][j] = 0;
    }
    // left movement
    if (j - 1 >= 0 && maze[i][j - 1] == 1 && !visited[i][j - 1])
    {
        visited[i][j] = 1;
        solve(i, j - 1, maze, n, ans, move + 'L', visited);
        visited[i][j] = 0;
    }
    // right movement
    if (j + 1 < n && maze[i][j + 1] == 1 && !visited[i][j + 1])
    {
        visited[i][j] = 1;
        solve(i, j + 1, maze, n, ans, move + 'R', visited);
        visited[i][j] = 0;
    }
    // up movement
    if (i - 1 >= 0 && maze[i - 1][j] == 1 && !visited[i - 1][j])
    {
        visited[i][j] = 1;
        solve(i - 1, j, maze, n, ans, move + 'U', visited);
        visited[i][j] = 0;
    }
}
vector<string> ratInMaze(vector<vector<int>> &maze)
{
    int n = maze.size();
    vector<string> ans;
    vector<vector<int>> visited(n, vector<int>(n, 0)); // nxn matrix to keep track of visited cells
    if (maze[0][0] == 1)
        solve(0, 0, maze, n, ans, "", visited);
    return ans;
}



/////////better code with less lines and more optimised
void solve(int i, int j, vector<vector<int>> &maze, int n, vector<string> &ans, string move, vector<vector<int>> &visited, int di[], int dj[])
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(move);
        return;
    }
    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++)
    {
        int nexti = i + di[ind];
        int nextj = j + dj[ind];
        if (nexti >= 0 && nexti < n && nextj >= 0 && nextj < n && maze[nexti][nextj] == 1 && !visited[nexti][nextj])
        {
            visited[i][j] = 1;
            solve(nexti, nextj, maze, n, ans, move + dir[ind], visited, di, dj);
            visited[i][j] = 0;
        }
    }
}
vector<string> ratInMaze(vector<vector<int>> &maze)
{
    int n = maze.size();
    vector<string> ans;
    vector<vector<int>> visited(n, vector<int>(n, 0)); // nxn matrix to keep track of visited cells
    int di[4] = {1, 0, 0, -1};
    int dj[4] = {0, -1, 1, 0};
    if (maze[0][0] == 1)
        solve(0, 0, maze, n, ans, "", visited, di, dj);
    return ans;
}