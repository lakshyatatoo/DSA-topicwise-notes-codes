#include <bits/stdc++.h>
using namespace std;

// direct metthod is pow(x,0.5) or x^(0.5)
//LARGEST I WHOSE SQUARE IS <=X
class Solution
{
public:
    int mySqrt(int x)
    {
        int ans = 0;
        for (long long i = 0; i <= x; i++)
        {
            if (i * i <= x)
                ans = i;
            else
                break;
        }
        return ans;
    }
};

// binary search on answers
class Solution
{
public:
    int mySqrt(int x)
    {
        int ans = 1; // we can use the ans also but here we use hgih approach
        long long low = 0, high = x;
        while (low <= high)
        {
            long long mid = (low + high) / 2;
            if (mid * mid <= x)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
    }
};