#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;

long long myPow(long long x, long long n)
{
    long long ans = 1;
    x %= mod;

    while (n)
    {
        if (n % 2 == 0)
        {
            x = (x * x) % mod;
            n /= 2;
        }
        else
        {
            ans = (ans * x) % mod;
            n--;
        }
    }

    return ans;
}

int countGoodNumbers(long long n)
{
    long long evens = (n + 1) / 2;
    long long odds = n / 2;

    return (myPow(5, evens) * myPow(4, odds)) % mod;
}




//recursion
 double solve(double x, long long n)
    {
        if (n == 0)
            return 1.0;

        if (n % 2 == 0)
        {
            return solve(x * x, n / 2);
        }
        else
        {
            return x * solve(x , n - 1);
        }
    }

    double myPow(double x, int n) {

        long long en = n;

        if (en < 0)
            return 1.0 / solve(x, -en);

        return solve(x, en);
    }
int countGoodNumbers(long long n)
{
    long long evens = (n + 1) / 2;
    long long odds = n / 2;

    return (myPow(5, evens) * myPow(4, odds)) % mod;
}