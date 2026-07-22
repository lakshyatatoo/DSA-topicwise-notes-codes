#include <bits/stdc++.h>
using namespace std;

// brute basic traversal and x.x

// optimal
// traversal;
double myPow(double x, int n)
{
    double ans = 1.0;
    long long en = n;
    if (en < 0)
        en = -1 * en;
    while (en)
    {
        if (en % 2 == 0)
        {
            x *= x;
            en /= 2;
        }
        else
        {
            ans *= x;
            en = (en - 1);
        }
    }
    if (n < 0)
        ans = (double)(1.0) / (double)(ans);
    return ans;
}

// recursion
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