#include <bits/stdc++.h>
using namespace std;
// brute //better //optimal //allinone
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &a)
    {
        vector<int> ans;
        int n = a.size();
        int m = a[0].size();
        int left = 0;
        int right = m - 1;
        int bottom = n - 1;
        int top = 0;

        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
            {
                ans.push_back(a[top][i]);
            }
            top++;
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(a[i][right]);
            }
            right--;
            if (top <= bottom)
            { // for checking if there is no repeat of row
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(a[bottom][i]);
                }
                bottom--;
            }
            if (left <= right)
            { // for checking if there is no repeat of column
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(a[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};