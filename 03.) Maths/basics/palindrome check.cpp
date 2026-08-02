// if greater than int max we return false
#include <bits/stdc++.h>
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        int y = x;
        long long rn = 0;
        while (x != 0)
        {
            int d = x % 10;
            x = x / 10;
            if (rn > INT_MAX / 10)
                return false;
            rn = (rn * 10) + d;
        }

        return (rn == y);
    }
};
