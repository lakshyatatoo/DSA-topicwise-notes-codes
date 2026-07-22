#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool generateSubSequences(int index, vector<int> &arr, int n, int target, int sum = 0)
    {
        if (index == n)
        {
            if (sum == target)
            {
                return true;
            }
            return false;
        } 

        sum += arr[index];
        if (generateSubSequences(index + 1, arr, n, target, sum))
            return true;
        sum -= arr[index];
        if (generateSubSequences(index + 1, arr, n, target, sum))
            return true;
        return false;
    }
    bool numSubseq(vector<int> &nums, int target)
    {
        int n = nums.size();
        return generateSubSequences(0, nums, n, target, 0);
    }
};
