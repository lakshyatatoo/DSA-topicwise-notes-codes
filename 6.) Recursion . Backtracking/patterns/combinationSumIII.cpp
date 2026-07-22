#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void generateSubSequences(int index, int k, int n, vector<int> &arr, int size, vector<int> &ds, vector<vector<int>> &ans)
    {

        if (n == 0 && ds.size() == k)
        {
            ans.push_back(ds);
            return;
        }
        if (n < 0 || ds.size() > k)
            return;

        for (int i = index; i < size; i++)
        {
            if (i > index && arr[i] == arr[i - 1])
                continue; // skip duplicates
            if (arr[i] > n)
                break; // as the array is sorted if the current element is greater than target then we can break the loop as the next elements will also be greater than target
            ds.push_back(arr[i]);
            generateSubSequences(i + 1, k, n - arr[i], arr, size, ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> arr;
        for (int i = 1; i <= 9; i++)
            arr.push_back(i);
        int size = arr.size();
        vector<int> ds;
        vector<vector<int>> ans;
        generateSubSequences(0, k, n, arr, size, ds, ans);
        return ans;
    }
};