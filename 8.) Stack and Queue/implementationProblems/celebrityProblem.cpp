#include <bits/stdc++.h>
using namespace std;

// brute - create 2 arrays and travers the matrix.
class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        // code here
        int n = mat.size();
        vector<int> knowMe(n, 0);
        vector<int> iKnow(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue; // skipping self element in diagnols
                if (mat[i][j] == 1)
                {
                    iKnow[i]++;
                    knowMe[j]++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (iKnow[i] == 0 && knowMe[i] == n - 1)
            {
                return i;
            }
        }
        return -1;
    }
};

// optimal - use of two pointers
class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        // code here
        int n = mat.size();
        int top = 0;
        int down = n - 1;
        while (top < down)
        {
            if (mat[top][down] == 1)
                top++;
            else if (mat[down][top] == 1)
                down--;
            else
            {
                top++;
                down--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i == top || mat[i][top] == 1 && mat[top][i] == 0)
                continue;
            else
                return -1;
        }
        return top;
    }
};