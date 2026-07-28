#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mod = 1e9 + 7;

private:
    int fact(int x)
    {
        int f = 1;
        for (int i = 2; i <= x; i++)
        {
            f = (f * i) % mod;
        }
        return f;
    }

public:
    int countValidSequences(int n, int k)
    {
        if ((k == 1 && n % 2 != 0) || n == k)
            return 0;
        if ((k == 1 && n % 2 == 0) || (k == 2 && n % 2 == 0))
            return 1;
        if ((k == 2 && n % 2 != 0))
            return 2;
        int ones = 0;
        int twos = 0;
        if ((n - k - 1 % 2) == 0)
        {
            ones = k - 1;
            twos = 1;
        }
        else
        {
            ones = k - 2;
            twos = 2;
        }
        int ans = (fact(k) / (fact(ones) * fact(twos))) % mod;
        return ans;
    }
};
