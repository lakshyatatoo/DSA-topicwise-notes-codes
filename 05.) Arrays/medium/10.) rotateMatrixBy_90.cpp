#include <bits/stdc++.h>
using namespace std;

// ============================================================
// 1. BRUTE FORCE
// Copy the matrix and put each element at its rotated position.
//
// Time: O(n^2)
// Space: O(n^2)
// ============================================================

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        vector<vector<int>> ans = matrix;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[j][n - 1 - i] = ans[i][j];
            }
        }
    }
};

// ============================================================
// 2. OPTIMAL
// Step 1: Transpose the matrix
// Step 2: Reverse every row
//
// Time: O(n^2)
// Space: O(1)
// ============================================================

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        // Step 1: Transpose
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse every row
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};