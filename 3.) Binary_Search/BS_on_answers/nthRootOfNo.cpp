#include <bits/stdc++.h>
using namespace std;

// brute
class Solution
{
public:
    // int sqert(int i,int n){
    //     long long ans=1;
    //     while(n--){
    //         ans*=i;
    //     }
    //     return ans;
    // }
    int sqrt(int i, int n)
    {
        long long ans = pow(i, n);
        return ans;
    }
    int nthRoot(int n, int m)
    {
        // Code here
        for (int i = 1; i <= m; i++)
        {
            if (sqrt(i, n) == m)
                return i;
            else if (sqrt(i, n) > m)
                break;
        }
        return -1;
    }
};

// binary search
class Solution
{
public:
    int sqrt(int i, int n, int m)
    {
        long long ans = 1;
        while (n > 0)
        {
            ans *= i;
            if (ans > m)
                return 2;
            n--;
        }
        if (ans == m)
            return 1;
        return 0;
    }
    int nthRoot(int n, int m)
    {
        long long low = 1, high = m;

        while (low <= high)
        {
            long long mid = (low + high) / 2;
            int ans = sqrt(mid, n, m);
            if (ans == 1)
                return mid;
            else if (ans == 0)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};