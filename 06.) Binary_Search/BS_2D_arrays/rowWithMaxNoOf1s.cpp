#include <bits/stdc++.h>
using namespace std;
// // brute
class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        int max = -1;
        int ind = -1;
        int n = mat.size();
        int m = mat[0].size();
        int cnt_row = 0;
        for (int i = 0; i < n; i++)
        {
            cnt_row = 0;
            for (int j = 0; j < m; j++)
            {
                cnt_row += mat[i][j];
            }
            if (cnt_row > max)
            {
                max = cnt_row;
                ind = i;
            }
        }
        return {ind, max};
    }
};

// binary search gfg for sorted rows else brute is optimial if rows are not sorted
class Solution
{
public:
    int firstoccurLB(vector<int> &arr, int x)
    {

        int n = arr.size();
        int ans = n;
        int l = 0;
        int h = n - 1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (arr[mid] >= x)
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
    int rowWithMax1s(vector<vector<int>> &arr)
    {
        int n = arr.size();
        int m = arr[0].size();
        int cnt_max = -1;           // set 0 if there are no occureecnes of 1 it remains 0
        int index = -1;             // bcs if it does not update its first row ans
        for (int i = 0; i < n; i++) // can also start loop from second row.
        {
            int cnt_ones = m - firstoccurLB(arr[i], 1);
            if (cnt_ones > cnt_max)
            {
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return index;
    }
};
