// element is sortd column wise and row wise
// Integers in each row are sorted in ascending from left to right.
//  Integers in each column are sorted in ascending from top to bottom.
#include <bits/stdc++.h>
using namespace std;
// brutee force
// 2 loops and search for target
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int ind = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == target)
                    return true;
            }
        }
        return false;
    }
};

// better binary
class Solution
{
public:
    bool search(vector<int> &arr, int target)
    {
        int m = arr.size();
        int low = 0;
        int high = m - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == target)
                return true;
            else if (arr[mid] < target)
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
            if (search(matrix[i], target) == true)
                return true;
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
        int row = 0;
        int col = matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0)
        {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                col--;
            else
                row++;
        }
        return false;
    }
};