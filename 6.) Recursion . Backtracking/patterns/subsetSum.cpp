#include <bits/stdc++.h>
using namespace std;

// brute / optimal
void func(int index, int sum, int n, vector<int> &arr, vector<int> &ds)
{
    if (index == n)
    {
        ds.push_back(sum);
        return;
    }
    func(index + 1, sum + arr[index], n, arr, ds);
    func(index + 1, sum, n, arr, ds);
}
vector<int> subsetSum(vector<int> &arr, int n, int sum)
{
    vector<int> ds;
    func(0, 0, n, arr, ds);
    sort(ds.begin(), ds.end());
    return ds;
}

// sum check
bool func(int index, int sum, int target,
          vector<int> &arr, int n)
{
    if (sum == target)
        return true;

    if (index == n)
        return false;

    // take
    if (func(index + 1, sum + arr[index],
             target, arr, n))
        return true;

    // not take
    if (func(index + 1, sum,
             target, arr, n))
        return true;

    return false;
}

bool isSubsetSum(vector<int> &arr, int sum)
{
    // code here
    return func(0, 0, sum, arr, arr.size());
}