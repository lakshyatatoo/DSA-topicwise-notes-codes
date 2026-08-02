#include <bits/stdc++.h>
using namespace std;

// brute force approach
// paint all distinct islands and store size of each color and then access neighbuors for zeros
class Solution
{
private:
    void paint(int n, int m, int r, int c, vector<vector<int>> &grid, int color, int &size)
    {
        grid[r][c] = color;
        size++;
        int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1)
            {
                paint(n, m, nr, nc, grid, color, size);
            }
        }
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int color = 2;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    int size = 0;
                    paint(n, m, i, j, grid, color, size);
                    mp[color] = size;
                    color++;
                }
            }
        }
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] != 0)
                    continue;
                set<int> comp;
                int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
                for (int k = 0; k < 4; k++)
                {
                    int nr = i + dr[k], nc = j + dc[k];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] > 1)
                    {
                        comp.insert(grid[nr][nc]);
                    }
                }

                int size = 0;
                for (auto it : comp)
                {
                    size += mp[it];
                }
                mx = max(mx, size + 1);
            }
        }
        // if all 1s then we return the size of the largest island
        for (auto it : mp)
        {
            mx = max(mx, it.second);
        }
        return mx;
    }
};

// optimal and faster but linear only
// tc: O(n*m) sc: O(n*m)
// sc: O(n*m) for disjoint set and O(n*m) for set
class disjoint
{
public:
    vector<int> rank, parent, size;
    disjoint(int n)
    {
        rank.resize(n + 1, 0), size.resize(n + 1, 1), parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int findUp(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUp(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int up = findUp(u), vp = findUp(v);
        if (up == vp)
            return;
        if (rank[vp] < rank[up])
            parent[vp] = up;
        else if (rank[up] < rank[vp])
            parent[up] = vp;
        else
            parent[vp] = up, rank[up]++;
    }
    void unionBySize(int u, int v)
    {
        int up = findUp(u), vp = findUp(v);
        if (up == vp)
            return;
        if (size[vp] < size[up])
            parent[vp] = up, size[up] += size[vp];
        else
            parent[up] = vp, size[vp] += size[up];
    }
};

class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        disjoint ds(n * m);
        // connect all 1s in a single island and set a up
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                    continue;
                int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
                for (int k = 0; k < 4; k++)
                {
                    int nr = i + dr[k], nc = j + dc[k];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1)
                    {
                        int node = i * m + j, adjNode = nr * m + nc;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }
        // ocnvert 0 check
        int mx = 0;
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    continue;
                set<int> comp;
                int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
                for (int k = 0; k < 4; k++)
                {
                    int nr = i + dr[k], nc = j + dc[k];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1)
                    {
                        int adjNode = nr * m + nc;
                        comp.insert(ds.findUp(adjNode));
                    }
                }
                int size = 0;
                for (auto it : comp)
                    size += ds.size[it];
                mx = max(mx, size + 1);
            }
        }
        // if all 1s then return the size of the largest island
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    mx = max(mx, ds.size[ds.findUp(i * m + j)]);
            }
        }
        return mx;
    }
};