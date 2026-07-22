#include <bits/stdc++.h>
using namespace std;

// brute + better + optimal
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int lsum = 0, rsum = 0, maxSum = 0;
        for (int i = 0; i < k; i++)
            lsum += cardPoints[i];
        int r = n - 1;
        maxSum = lsum;
        for (int i = k - 1; i >= 0; i--)
        {
            lsum -= cardPoints[i];
            rsum += cardPoints[r];
            maxSum = max(maxSum, lsum + rsum);
            r--;
        }
        return maxSum;
    }
};