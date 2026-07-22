#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> powerSet(vector<int> &nums)
{
    int n = nums.size();
    int subsets = (1 << n);
    vector<vector<int>> ans(subsets);
    for (int i = 0; i < subsets; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                temp.push_back(nums[j]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}