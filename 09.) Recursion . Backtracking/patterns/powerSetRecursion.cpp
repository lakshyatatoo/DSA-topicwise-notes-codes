#include <bits/stdc++.h>
using namespace std;
class Solution
{
    //   only if duplicates are not allowed
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

    vector<vector<int>> subsets(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ds;
        vector<vector<int>> dx;
        generateSubSequences(0, nums, ds, n, dx);
        return dx;
    }
};

//   else
void generateSubSequences(int index, vector<int> &arr, vector<int> &ds, int n)
{
    if (index == n)
    {
        for (int x : ds)
            cout << x << " ";
        cout << endl;
        return;
    }
    ds.push_back(arr[index]);
    generateSubSequences(index + 1, arr, ds, n);
    ds.pop_back();
    generateSubSequences(index + 1, arr, ds, n);
}
int main()
{
    vector<int> arr = {1, 2, 3};
    int n = 3;
    vector<int> ds;
    generateSubSequences(0, arr, ds, n);
    return 0;
}
