#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void generateSubSequences(int index, vector<int> &arr, int n, vector<int> &ds, int target, int sum = 0)
    {
        if (index == n)
        {
            if (sum == target)
            {
                for (auto it : ds)
                {
                    cout << it << " ";
                }
                cout << endl;
            }
            return;
        }

        sum += arr[index];
        ds.push_back(arr[index]);
        generateSubSequences(index + 1, arr, n, ds, target, sum);
        ds.pop_back();
        sum -= arr[index];
        generateSubSequences(index + 1, arr, n, ds, target, sum);
    }
    void numSubseq(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> ds;
        generateSubSequences(0, nums, n, ds, target, 0);
    }
};
