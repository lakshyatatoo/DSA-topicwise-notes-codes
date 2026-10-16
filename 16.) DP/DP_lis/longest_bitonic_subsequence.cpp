#include <bits/stdc++.h>
using namespace std;

// n2,n method
// not using naxi as that would be added using other dpb
class Solution
{
public:
    int longestBitonicSequence(int n, vector<int> &nums)
    {
        vector<int> dpf(n, 1), dpb(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[i] > nums[prev] && 1 + dpf[prev] > dpf[i])
                    dpf[i] = 1 + dpf[prev];
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int prev = n - 1; prev > i; prev--)
            {
                if (nums[i] > nums[prev] && 1 + dpb[prev] > dpb[i])
                    dpb[i] = 1 + dpb[prev];
            }
        }
        int maxi = -1;
        for (int i = 0; i < n; i++)
            if (dpf[i] > 1 && dpb[i] > 1) // for gfg extra condition
                maxi = max(maxi, dpf[i] + dpb[i] - 1);
        return maxi;
    }
};