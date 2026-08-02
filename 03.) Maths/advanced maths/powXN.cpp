#include <bits/stdc++.h>
using namespace std;

// brute
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
long long powxN(double x, int n)
{

    long long ans = 1;
    while (n != 0)
    {

        if (n % 2 == 0)
        {
            x *= x;
            n /= 2;
        }
        else
        {
            ans *= x;
            n--;
        }
    }
    return ans;
}

// optimal recurison
double powXn(double x, long long n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        return powXn(x * x, n / 2);
    }
    else
    {
        return x * powXn(x, n - 1);
    }
}

// main function
double myPow(double x, int n)
{

    long long temp = n;

    if (temp < 0)
        return 1.0 / powXn(x, -temp);

    return powXn(x, temp);
}
