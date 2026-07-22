#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int generateSubSequences(int index, vector<int> &arr, int n, int target, int sum = 0)
    {
        if (index == n)
        {
            if (sum == target)
                return 1;
            else
                return 0;
        }

        sum += arr[index];
        int left = generateSubSequences(index + 1, arr, n, target, sum);
        sum -= arr[index];
        int right = generateSubSequences(index + 1, arr, n, target, sum);
        return left + right;
    }
    int numSubseq(vector<int> &nums, int target)
    {
        int n = nums.size();
        return generateSubSequences(0, nums, n, target, 0);
    }
};




