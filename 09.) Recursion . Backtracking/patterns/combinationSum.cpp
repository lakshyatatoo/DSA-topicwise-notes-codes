#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void generateSubSequences(int index, vector<int> &arr, int n, vector<int> &ds, int target, vector<vector<int>> &ans)
    {
        if (index == n)
        {
            if (target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if (arr[index] <= target)
        {
            ds.push_back(arr[index]);
            generateSubSequences(index, arr, n, ds, target - arr[index], ans);
            ds.pop_back();
        }
        generateSubSequences(index + 1, arr, n, ds, target, ans);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        int n = candidates.size();
        vector<int> ds;
        vector<vector<int>> ans;
        generateSubSequences(0, candidates, n, ds, target, ans);
        return ans;
    }
};