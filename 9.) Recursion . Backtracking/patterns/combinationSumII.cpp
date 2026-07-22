#include <bits/stdc++.h>
using namespace std;

// // brute changing the index to index+1 in the first recursive call and removing the second recursive call will give us the solution for combination sum II as we are not allowing the same element to be picked again
class Solution
{
public:
    void generateSubSequences(int index, vector<int> &arr, int n, vector<int> &ds, int target, set<vector<int>> &ans)
    {
        if (index == n)
        {
            if (target == 0)
            {
                ans.insert(ds);
            }
            return;
        }
        if (arr[index] <= target)
        {
            ds.push_back(arr[index]);
            generateSubSequences(index + 1, arr, n, ds, target - arr[index], ans);//pick
            ds.pop_back();
        }
        generateSubSequences(index + 1, arr, n, ds, target, ans);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)//not pick without i++
    {
        int n = candidates.size();
        vector<int> ds;
        set<vector<int>> ans;
        generateSubSequences(0, candidates, n, ds, target, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};






// optimal approach is to sort the array and then skip the duplicates in the recursive calls
class Solution
{
public:
    void generateSubSequences(int index, vector<int> &arr, int n, vector<int> &ds, int target, vector<vector<int>> &ans)
    {

        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }

        for (int i = index; i < n; i++)
        {
            if (i > index && arr[i] == arr[i - 1])
                continue; // skip duplicates
            if (arr[i] > target)
                break; // as the array is sorted if the current element is greater than target then we can break the loop as the next elements will also be greater than target
            ds.push_back(arr[i]);
            generateSubSequences(i + 1, arr, n, ds, target - arr[i], ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());

        vector<int> ds;
        vector<vector<int>> ans;
        generateSubSequences(0, candidates, n, ds, target, ans);
        return ans;
    }
};