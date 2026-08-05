#include <bits/stdc++.h>
using namespace std;

// brute
// tc=O(n)
double powxn(double x, int n)
{
    double ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans *= x;
    }
    return ans;
}

// optimal
// tc=O(logn)
long long powxN(double x, int n)
{

    long long ans = 1, y = n;
    bool isNegative = false;
    if (y < 0)
    {
        isNegative = true, y = -y;
    }
    while (n != 0)
    {

        if (n % 2 == 0)
            x *= x, n /= 2;
        else
            ans *= x, n--;
    }
    if (isNegative)
        return 1 / ans;
    return ans;
}

// optimal recurison
class Solution
{
    double pow(double x, long long n)
    {
        if (n == 0)
            return 1;
        if (n % 2 == 0)
        {
            return pow(x * x, n / 2);
        }
        else
        {
            return x * pow(x, n - 1);
        }
    }

public:
    double myPow(double x, int n)
    {
        long long y = n;
        if (y < 0)
        {
            return 1 / pow(x, -y);
        }
        return pow(x, y);
    }
};