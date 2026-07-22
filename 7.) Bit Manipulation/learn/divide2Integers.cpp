#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // brute force
    int divide(int dividend, int divisor)
    {
        int x = 0;
        long long cnt = 0;
        bool negative =
            (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);
        while (dvs + x <= dvd)
        {
            x += dvs;
            cnt++;
        }
        if (negative)
        {
            cnt = -cnt;
        }
        if (cnt > INT_MAX)
            return INT_MAX;
        if (cnt < INT_MIN)
            return INT_MIN;
        return (int)cnt;
    }

    // optimal
    int divide(int dividend, int divisor)
    {
        if (divisor == dividend)
            return 1;
        bool negative =
            (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long cnt = 0;
        long long ans = 0;
        while (n >= d)
        {
            cnt = 0;
            while (n >= (d << (cnt + 1)))
            {
                cnt++;
            }
            ans += (1LL << cnt);
            n -= (d << cnt);
        }
        if (negative)
        {
            ans = -ans;
        }
        if (ans > INT_MAX)
            return INT_MAX;
        if (ans < INT_MIN)
            return INT_MIN;
        return (int)ans;
    }
};
