#include <bits/stdc++.h>
using namespace std;

// ============================================================
// SPIRAL MATRIX
//
// Traverse the matrix in spiral order.
//
// Time: O(n * m)
// Space: O(n * m) for the answer
// ============================================================

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &a)
    {
        vector<int> ans;

        int n = a.size(), m = a[0].size(), left = 0, right = m - 1, top = 0, bottom = n - 1;

        while (top <= bottom && left <= right)
        {
            // 1. Left → Right
            for (int i = left; i <= right; i++)
                ans.push_back(a[top][i]);
            top++;
            // 2. Top → Bottom
            for (int i = top; i <= bottom; i++)
                ans.push_back(a[i][right]);
            right--;
            // 3. Right → Left
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                    ans.push_back(a[bottom][i]);
                bottom--;
            }
            // 4. Bottom → Top
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(a[i][left]);
                left++;
            }
        }

        return ans;
    }
};