#include <bits/stdc++.h>
using namespace std;

// brute - look through all elements and return if found at earliest
class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (((i == 0) || (mat[i][j] > mat[i - 1][j])) &&
                    ((i == n - 1) || (mat[i][j] > mat[i + 1][j])) &&
                    ((j == 0) || (mat[i][j] > mat[i][j - 1])) &&
                    ((j == m - 1) || (mat[i][j] > mat[i][j + 1])))
                    return {i, j};
            }
        }
        return {-1, -1};
    }
};
// better - return the largest element of the matrix
class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int mx = -1;
        int x = -1, y = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] > mx)
                {
                    x = i;
                    y = j;
                    mx = mat[i][j];
                }
            }
        }
        return {x, y};
    }
};

// optimal -  binary
class Solution
{
public:
    int maxEleRowColInd(vector<vector<int>> &mat, int mid, int n)
    {
        int mx = mat[0][mid];
        int ind = 0;
        for (int i = 0; i < n; i++)
        {
            if (mat[i][mid] > mx)
            {
                mx = mat[i][mid];
                ind = i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m - 1;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            int ind = maxEleRowColInd(mat, mid, n);
            int left = (mid - 1 >= 0) ? mat[ind][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[ind][mid + 1] : -1;
            if (left < mat[ind][mid] && mat[ind][mid] > right)
                return {ind, mid};
            else if (left > mat[ind][mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return {-1, -1};
    }
};