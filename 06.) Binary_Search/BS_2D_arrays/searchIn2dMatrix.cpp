#include <bits/stdc++.h>
using namespace std;

// brute force approach
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == target)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// brute + binary
// tc: O(nlogm) sc: O(1)
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int low = 0;
        int n = nums.size();
        int high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (target == nums[mid])
                return true;
            else if (target > nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][0] <= target && target <= matrix[i][m - 1])
            {
                return search(matrix[i], target);
            }
        }
        return false;
    }
};

// optimal but code is a bit lengthy
class Solution
{
public:
    bool searchTarget(int row, int col, vector<vector<int>> &matrix,
                      int target)
    {
        int low = 0;
        int high = col - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (target == matrix[row][mid])
                return true;
            else if (target > matrix[row][mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (matrix[mid][0] <= target && target <= matrix[mid][m - 1])
                return searchTarget(mid, m, matrix, target);
            else if (target > matrix[mid][m - 1])
                low = mid + 1;
            else if (target < matrix[mid][0])
                high = mid - 1;
        }
        return false;
    }
};
// optimal binary
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = n * m - 1;
        while (low <= high)
        {
            int mid = high + (low - high) / 2;
            int row = mid / m;
            int col = mid % m;
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};