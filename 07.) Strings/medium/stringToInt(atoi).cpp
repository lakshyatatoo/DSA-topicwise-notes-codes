#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int myAtoi(string s)
    {
        long long res = 0;
        int sign = 1;
        int n = s.size();
        int i = 0;
        while (i < n && s[i] == ' ')
        {
            i++;
        }
        if (i < n && s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+')
        {
            sign = 1;
            i++;
        }
        while (i < n && s[i] == '0')
        {
            i++;
        }
        while (i < n && isdigit(s[i]))
        {
            res = res * 10 + (s[i] - '0');
            if (sign * res > INT_MAX)
                return INT_MAX;
            if (sign * res < INT_MIN)
                return INT_MIN;

            i++;
        }

        return (int)(sign * res);
    }
};