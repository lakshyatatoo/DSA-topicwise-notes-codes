#include <bits/stdc++.h>
using namespace std;

// ============================================================
// 1. BRUTE FORCE
// Mark affected cells with -1, then convert -1 to 0.
// Works only when -1 is not present in the original matrix.
//
// Time: O(n * m * (n + m))
// Space: O(1)
// ============================================================

class Solution
{
public:
    void setZeroes(vector<vector<int>> &nums)
    {
        int n = nums.size();
        int m = nums[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (nums[i][j] == 0)
                {
                    markRow(nums, i, m);
                    markCol(nums, j, n);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (nums[i][j] == -1)
                {
                    nums[i][j] = 0;
                }
            }
        }
    }

private:
    void markRow(vector<vector<int>> &nums, int i, int m)
    {
        for (int j = 0; j < m; j++)
        {
            if (nums[i][j] != 0)
            {
                nums[i][j] = -1;
            }
        }
    }

    void markCol(vector<vector<int>> &nums, int j, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (nums[i][j] != 0)
            {
                nums[i][j] = -1;
            }
        }
    }
};

// ============================================================
// 2. BETTER — ROW & COLUMN ARRAYS
// Store which rows and columns contain zero.
//
// Time: O(n * m)
// Space: O(n + m)
// ============================================================

class Solution
{
public:
    void setZeroes(vector<vector<int>> &nums)
    {
        int n = nums.size();
        int m = nums[0].size();

        vector<int> row(n, 0);
        vector<int> col(m, 0);

        // Mark rows and columns containing zero
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (nums[i][j] == 0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Set affected cells to zero
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (row[i] == 1 || col[j] == 1)
                {
                    nums[i][j] = 0;
                }
            }
        }
    }
};

// ============================================================
// 3. OPTIMAL — USE FIRST ROW & FIRST COLUMN AS MARKERS
//
// Time: O(n * m)
// Space: O(1)
// ============================================================

class Solution
{
public:
    void setZeroes(vector<vector<int>> &nums)
    {
        int n = nums.size();
        int m = nums[0].size();

        // Tracks whether the first column originally contains zero
        int colzero = 1;

        // Use first row and first column as markers
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (nums[i][j] == 0)
                {
                    nums[i][0] = 0;

                    if (j != 0)
                    {
                        nums[0][j] = 0;
                    }
                    else
                    {
                        colzero = 0;
                    }
                }
            }
        }

        // Set inner matrix to zero using markers
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (nums[i][0] == 0 || nums[0][j] == 0)
                {
                    nums[i][j] = 0;
                }
            }
        }

        // If first row needs to be zero
        if (nums[0][0] == 0)
        {
            for (int j = 0; j < m; j++)
            {
                nums[0][j] = 0;
            }
        }

        // If first column needs to be zero
        if (colzero == 0)
        {
            for (int i = 0; i < n; i++)
            {
                nums[i][0] = 0;
            }
        }
    }
};