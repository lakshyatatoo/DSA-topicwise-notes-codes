#include <bits/stdc++.h>
using namespace std;
// brute
// set -1 and zeros (only for matrix elements >=0)
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
                    markRow(nums, i, n, m);
                    markCol(nums, j, n, m);
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
    void markRow(vector<vector<int>> &nums, int i, int n, int m)
    {
        for (int j = 0; j < m; j++)
        {
            if (nums[i][j] != 0)
            {
                nums[i][j] = -1;
            }
        }
    }
    void markCol(vector<vector<int>> &nums, int j, int n, int m)
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

// better row col arrays
class Solution
{
public:
    void setZeroes(vector<vector<int>> &nums)
    {
        int n = nums.size();
        int m = nums[0].size();
        vector<int> row(n, 0);
        vector<int> col(m, 0);
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
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (col[j] == 1 || row[i] == 1)
                {
                    nums[i][j] = 0;
                }
            }
        }
    }
};

// optimal - using first row and col as markers
class Solution
{
public:
    void setZeroes(vector<vector<int>> &nums)
    {
        int n = nums.size();
        int m = nums[0].size();
        int colzero = 1;
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
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (nums[0][j] == 0 || nums[i][0] == 0)
                {
                    nums[i][j] = 0;
                }
            }
        }
        if (nums[0][0] == 0)
        {
            for (int j = 0; j < m; j++)
            {
                nums[0][j] = 0;
            }
        }
        if (colzero == 0)
        {
            for (int i = 0; i < n; i++)
            {
                nums[i][0] = 0;
            }
        }
    }
};