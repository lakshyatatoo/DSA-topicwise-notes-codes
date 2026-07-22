// the new thing here is that if the value of revnum overflows by int max value or min we return 0
#include <bits/stdc++.h>
class Solution
{
public:
    int reverse(int x)
    {

        int rn = 0;
        while (x != 0)
        {
            int d = x % 10;

            x = x / 10;
            if (rn < INT_MIN / 10 || rn > INT_MAX / 10)
                return 0;

            rn = (rn * 10) + d;
        }

        return rn;
    }
};