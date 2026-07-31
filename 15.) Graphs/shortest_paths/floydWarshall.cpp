#include <bits/stdc++.h>
using namespace std;

// this can be done using dijkstra also where for each node we do a dikstra on array or whatever
//  but dijkstra will not work on negative wt or negative cycle
class Solution
{
public:
    void floydWarshall(vector<vector<int>> &dist)
    {
        int n = dist.size();
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {

                    if (dist[i][k] != 1e8 && dist[k][j] != 1e8)
                    {
                        dist[i][j] = min(dist[i][j],
                                         dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
};
