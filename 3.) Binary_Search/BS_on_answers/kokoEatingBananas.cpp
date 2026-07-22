#include <bits/stdc++.h>
using namespace std;

// //brute
// #include <bits/stdc++.h>
// using namespace std;w

// class Solution {
// public:
//     int hourk(vector<int>& piles, int k) {
//         int tt = 0;
//         for (int i = 0; i < piles.size(); i++) {
//             tt += ceil((double)piles[i] / k);
//         }
//         return tt;
//     }

//     int minEatingSpeed(vector<int>& piles, int h) {
// int maxVal = *max_element(piles.begin(), piles.end());
//         for (int i = 1; i <= maxVal; i++) {
//             if (hourk(piles, i) <= h) return i;
//         }
//         return -1;
//     }
// };

// binary search

class Solution
{
public:
    int maxele(vector<int> &piles)
    {
        int maxim = piles[0];
        for (int i = 0; i < piles.size(); i++)
        {
            if (piles[i] > maxim)
                maxim = piles[i];
        }
        return maxim;
    }
    long long hourk(vector<int> &piles, int k)
    {
        long long ttt = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            ttt += (piles[i] + k - 1) / k;
            // ttt += ceil((double)piles[i] / (double)k);
        }
        return ttt;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1, high = maxele(piles), ans = INT_MAX; // here low and high are ranges
        while (low <= high)
        {
            int mid = (low + high) / 2;
            long long tt = hourk(piles, mid);
            if (tt <= h)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low; // or return ans
    }
};