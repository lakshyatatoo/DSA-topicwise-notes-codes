#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
    int cnt = 0;
    while (n > 1)
    {
        if (n % 2 == 1)
            cnt++;
        n /= 2;
    }
    if (n == 1)
        cnt++;
    return cnt;
}

/// optimal
int countSetBits(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        cnt += (n & 1);
        n >>= 1;
    }
    return cnt;
}

// optimal too
int countSetBits(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        cnt++;
    }
    return cnt;
}