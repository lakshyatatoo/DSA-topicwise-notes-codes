#include <bits/stdc++.h>
using namespace std;

// brute - look through all elements and store them in a 1d array sort and find median

// better/optimal - binary
// find the first element which has greater than m*n/2 elements less than it ex if left
// total element is 15 median is the one which has 7 elements less than it and 7 elements greater than it
// so we can
// if( no of element <=median)need be >n*m/2 so we need to increase low
class Solution
{
public:
    int upperBound(vector<int> &mat, int x)
    {
        int low = 0;
        int high = mat.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (mat[mid] <= x)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
    int blackBox(vector<vector<int>> &mat, int x)
    {
        int n = mat.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += upperBound(mat[i], x);
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int low = INT_MAX;
        int high = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            low = min(mat[i][0], low);
            high = max(high, mat[i][m - 1]);
        }
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            int cnt = blackBox(mat, mid); // will return no of elements(<=mid).
            if (cnt <= (n * m) / 2)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};
