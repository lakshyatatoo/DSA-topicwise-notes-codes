#include <bits/stdc++.h>
using namespace std;

// brute
class Solution
{
public:
    void generateSubSequences(int index, vector<int> &arr, vector<int> &ds,
                              int n, set<vector<int>> &dx)
    {
        if (index == n)
        {
            dx.insert(ds);
            return;
        }
        ds.push_back(arr[index]);
        generateSubSequences(index + 1, arr, ds, n, dx);
        ds.pop_back();
        generateSubSequences(index + 1, arr, ds, n, dx);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ds;
        set<vector<int>> dx;
        generateSubSequences(0, nums, ds, n, dx);
        return vector<vector<int>>(dx.begin(), dx.end());
    }
};

// optimal no duplicates allowed
class Solution
{
public:
    void generateSubSequences(int index, vector<int> &arr, vector<int> &ds,
                              int n, vector<vector<int>> &dx)
    {
        dx.push_back(ds);
        for (int i = index; i < n; i++)
        {
            if (i > index && arr[i] == arr[i - 1])
                continue; // skip duplicates
            ds.push_back(arr[i]);
            generateSubSequences(i + 1, arr, ds, n, dx);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ds;
        vector<vector<int>> dx;
        sort(nums.begin(), nums.end());
        generateSubSequences(0, nums, ds, n, dx);
        return dx;
    }
};